#include "floor.h"

#include <vector>

#include <memory>
#include <algorithm>
#include <stack>
#include <iostream>
#include <utility>
#include <random>
#include <chrono>

#include "posn.h"
#include "Cells/cell.h"
#include "Potions/potion.h"
#include "TempEffects/tempeffect.h"
#include "Potions/rh.h"
#include "Potions/ba.h"
#include "Potions/bd.h"
#include "Potions/ph.h"
#include "Potions/wa.h"
#include "Potions/wd.h"
#include "Cells/wall.h"
#include "Cells/passage.h"
#include "Cells/tile.h"
#include "Cells/door.h"
#include "Cells/space.h"
#include "Cells/stair.h"
#include "Treasure/smallgold.h"
#include "Treasure/dragongold.h"
#include "Treasure/normalgold.h"
#include "Treasure/merchantgold.h"
#include "Treasure/treasure.h"
#include "Enemies/dragon.h"
#include "Enemies/werewolf.h"
#include "Enemies/vampire.h"
#include "Enemies/goblin.h"
#include "Enemies/troll.h"
#include "Enemies/phoenix.h"
#include "Enemies/merchant.h"
#include "direction.h"
#include "TempEffects/woundattack.h"
#include "TempEffects/wounddefense.h"
#include "TempEffects/boostattack.h"
#include "TempEffects/boostdefense.h"
#include "randnum.h"

class PlayableCharacter;
class Enemy;

using namespace std;

bool cmpPair(pair<unique_ptr<Enemy>, Posn> &p1, pair<unique_ptr<Enemy>, Posn> &p2) {
    return (p1.second.y < p2.second.y || (p1.second.y == p2.second.y && p1.second.x < p2.second.x));
}

// from input file, checks if the cell is a tile
static bool isTile(char c) {
    return c != '|' && c != '-' && c != ' ' && c != '+' && c != '+';
}

Floor::Floor(const vector<vector<char>> &v, PlayableCharacter *p, bool bs, bool exactLayout, bool save): p{p}, content{}, chambers{}, chamberMap{}, stairLocation{-1, -1}, pcLocation{-1, -1}, bsLocation{-1, -1}, bs{bs} {
    int row = v.size();
    int col = v[0].size();
    for (int i = 0; i < row; i++) {
        content.emplace_back();
        chamberMap.emplace_back();
        for (int j = 0; j < col; j++) {
            char c = v[i][j];
            chamberMap[i].emplace_back(0);
            if (c == '|' || c == '-') content[i].emplace_back(make_unique<Wall>(c));
            else if (c == '#') content[i].emplace_back(make_unique<Passage>());
            else if (c == '+') content[i].emplace_back(make_unique<Door>());
            else if (c == ' ') content[i].emplace_back(make_unique<Space>());
            else if (c == '.') content[i].emplace_back(make_unique<Tile>());

            if (exactLayout) {
                content.at(i).emplace_back(make_unique<Tile>());
                if (v[i][j] == '@') {
                    //player location
                    pcLocation.x = j;
                    pcLocation.y = i;
                    content.at(i).at(j)->setPC(p);
                }
                
                if (v[i][j] == '\\') {
                    // stair location
                    content.at(i).at(j) = make_unique<Stair>();
                    stairLocation.x = j;
                    stairLocation.y = i;
                    content.at(i).at(j)->setStair();
                }


                // potion or treasure
                unique_ptr<Potion> p{};
                unique_ptr<Treasure> t{};
                if (v[i][j] == '0') {
                    p = make_unique<RH>();
                } else if (v[i][j] == '1') {
                    p = make_unique<BA>();
                } else if (v[i][j] == '2') {
                    p = make_unique<BD>();
                } else if (v[i][j] == '3') {
                    p = make_unique<PH>();
                } else if (v[i][j] == '4') {
                    p = make_unique<WA>();
                } else if (v[i][j] == '5') {
                    p = make_unique<WD>();
                } else if (v[i][j] == '6') {
                    t = make_unique<NormalGold>();
                } else if (v[i][j] == '7') {
                    t = make_unique<SmallGold>();
                } else if (v[i][j] == '8') {
                    t = make_unique<MerchantGold>();
                } else if (v[i][j] == '9') {
                    t = make_unique<DragonGold>();
                }
                if (p != nullptr) {
                    content[i][j]->setPotion(p);
                }

                if (t != nullptr) {
                    content[i][j]->setTreasure(t);
                }

                if (v[i][j] == 'B') {
                    // barrier suit
                    content.at(i).at(j)->setBarrierSuit(true);
                }

                //enemy
                unique_ptr<Enemy> en{};
                if (v[i][j] == 'V') {
                    en = make_unique<Vampire>();
                } else if (v[i][j] == 'W') {
                    en = make_unique<Werewolf>();
                } else if (v[i][j] == 'N') {
                    en = make_unique<Goblin>();
                } else if (v[i][j] == 'M') {
                    en = make_unique<Merchant>();
                } else if (v[i][j] == 'D') {
                    // requires that dragon is not near two dragonhordes
                    // also requires dragon is spawned near the thing its protecting
                    // and that the thing is spwaned
                    for (int dy = -1; dy <= 1; dy++) {
                        for (int dx = -1; dx <= 1; dx++) {
                            if (v[i + dy][j + dx] == '9') {
                                //dragon horde
                                en = make_unique<Dragon>(j + dx, i + dy);
                            }
                            // CHECK BARRIERSUIT___________________
                            if (v[i + dy][j + dx] == 'B') {
                                en = make_unique<Dragon>(j + dx, i + dy);
                            }
                        }
                    }
                    
                } else if (v[i][j] == 'T') {
                    en = make_unique<Troll>();
                } else if (v[i][j] == 'X') {
                    en = make_unique<Phoenix>();
                }
                if (en != nullptr) {
                    enemies.emplace_back(move(en), Posn{j, i});
                }
                
            }
        }
    }

    vector<vector<bool>> isVisited(row, vector<bool>(col, false)); // initializes 2d isvisited array all false
    int chamberCount = 0;
    for (int i = 1; i < row - 1; ++i) {
        for (int j = 1; j < col - 1; ++j) {
            if (!isVisited[i][j] && isTile(v[i][j])) {
                // new chamber
                chamberCount++;
                chamberMap[i][j] = chamberCount;
                chambers.emplace_back();
                chambers[chamberCount - 1].emplace_back(j, i);

                isVisited[i][j] = true;
                stack<Posn> next{};
                next.emplace(j, i);
                while (!next.empty()) {
                    Posn tempP = next.top();
                    next.pop();
                    for (int a = -1; a <= 1; a++) {
                        for (int b = -1; b <= 1; b++) {
                            int x = tempP.x + b;
                            int y = tempP.y + a;
                            if (!isVisited.at(y).at(x) && isTile(v.at(y).at(x))) {
                                isVisited.at(y).at(x) = true;
                                chambers.at(chamberCount - 1).emplace_back(x, y);
                                chamberMap.at(y).at(x) = chamberCount;
                                next.emplace(x,y);
                            } else if (!isVisited.at(y).at(x)) {
                                isVisited.at(y).at(x) = true;
                            }
                        }
                    }
                }
            } else if (!isVisited[i][j]) {
                isVisited[i][j] = true;
            }
        }
    }
    
    if (exactLayout) {
        if (save) {
            
        } else {
            generateCompass();
        }
    } else {
        generate();
    }
}

void Floor::generate() {
    int numChambers = chambers.size();
    vector<vector<Posn>> tempChambers = chambers;

    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine rng{seed};

    vector<int> tempChambersIndex{};

    for (int i = 0; i < numChambers; i++) {
        tempChambersIndex.emplace_back(i);
    }
    // generate player location

    // shuffle(tempChambersIndex.begin(), tempChambersIndex.end(), rng);
    // // take the first number in tempchambersindex as index of the randomly generated floor
    // int chamberIndex = tempChambersIndex.at(0);
    // // shuffle the coordinates of tiles in that chamber
    // shuffle(tempChambers.at(chamberIndex).begin(), tempChambers.at(chamberIndex).end(), rng);
    // // choose the first in the vector
    // Posn pcPosn = tempChambers.at(chamberIndex).at(0);
    // content.at(pcPosn.y).at(pcPosn.x)->setPC(p);

    int random1 = abs(randNum()) % numChambers; // 0 to numtempChambers - 1
    int numTilesInChamber = tempChambers[random1].size();
    int random2 = abs(randNum()) % numTilesInChamber; // to numTilesInChamber - 1
    int x = tempChambers[random1][random2].x;
    int y = tempChambers[random1][random2].y;
    content[y][x]->setPC(p);
    // erase that position from available
    pcLocation.x = x;
    pcLocation.y = y;
    tempChambers[random1].erase(tempChambers[random1].begin() + random2);
    // if the chamber no longer has any that are available, then remove that whole chamber from being available
    if (tempChambers[random1].size() == 0)  {
        tempChambers.erase(tempChambers.begin() + random1);
        numChambers--;
    }
    // spawn the stair
    int random3 = abs(randNum()) % numChambers;
    // ensure that stair chamber and player chamber are not the same
    while (random3 == random1) {
        random3 = abs(randNum()) % numChambers;
    }
    numTilesInChamber = tempChambers[random3].size();
    int random4 = abs(randNum()) % numTilesInChamber;
    x = tempChambers[random3][random4].x;
    y = tempChambers[random3][random4].y;
    stairLocation.x = x;
    stairLocation.y = y;
    unique_ptr<Cell> stair = make_unique<Stair>();
    content[y][x] = move(stair);
    content[y][x]->setStair();
    tempChambers[random3].erase(tempChambers[random3].begin() + random4);
    if (tempChambers[random3].size() == 0)  {
        tempChambers.erase(tempChambers.begin() + random3);
        numChambers--;
    }
    // generate the potions
    for (int i = 0; i < 10; i++) {
        int chamb = abs(randNum()) % numChambers;
        numTilesInChamber = tempChambers[chamb].size();
        int random5 = abs(randNum()) % numTilesInChamber;
        x = tempChambers[chamb][random5].x;
        y = tempChambers[chamb][random5].y;
        int randomPotion = abs(randNum()) % 6 + 1;
        // RH = restore health
        // BA = boost attack
        // BD = boost defense
        // PH = poison health
        // WA = wound attack
        // WD = wound defense
        if (randomPotion == 1) {
            unique_ptr<Potion> ptr = make_unique<RH>();
            content[y][x]->setPotion(ptr);
        } else if (randomPotion == 2) {
            unique_ptr<Potion> ptr = make_unique<BA>();
            content[y][x]->setPotion(ptr);
        } else if (randomPotion == 3) {
            unique_ptr<Potion> ptr = make_unique<BD>();
            content[y][x]->setPotion(ptr);
        } else if (randomPotion == 4) {
            unique_ptr<Potion> ptr = make_unique<PH>();
            content[y][x]->setPotion(ptr);
        } else if (randomPotion == 5) {
            unique_ptr<Potion> ptr = make_unique<WA>();
            content[y][x]->setPotion(ptr);
        } else if (randomPotion == 6) {
            unique_ptr<Potion> ptr = make_unique<WD>();
            content[y][x]->setPotion(ptr);
        }
        tempChambers[chamb].erase(tempChambers[chamb].begin() + random5);
        if (tempChambers[chamb].size() == 0)  {
            tempChambers.erase(tempChambers.begin() + chamb);
            numChambers--;
        }
    }
	for (int i = 0; i < 10; i++) {
		int whichChamber = abs(randNum()) % tempChambers.size();
		while (tempChambers[whichChamber].size() < 1) {
			whichChamber = abs(randNum()) % tempChambers.size();
		}
		int whichTile = abs(randNum()) % tempChambers[whichChamber].size();
		x = tempChambers[whichChamber][whichTile].x;
		y = tempChambers[whichChamber][whichTile].y;
		vector<Posn> neighbours = Floor::neighbours(x, y, false);
		int whichGold = abs(randNum()) % 8 + 1;
		if (whichGold <= 5) {
            unique_ptr<Treasure> sg = make_unique<SmallGold>();
            content[y][x]->setTreasure(sg);
        } else if (whichGold <= 7) {
            unique_ptr<Treasure> ng = make_unique<NormalGold>();
            content[y][x]->setTreasure(ng);
        } else {
        	// ensure that at least one neighbour
        	while (neighbours.size() <= 0) {
            	whichChamber = abs(randNum()) % tempChambers.size();
            	while (tempChambers[whichChamber].size() < 1) {
                	whichChamber = abs(randNum()) % tempChambers.size();
                }
                whichTile = abs(randNum()) % tempChambers[whichChamber].size();
                x = tempChambers[whichChamber][whichTile].x;
                y = tempChambers[whichChamber][whichTile].y;
                neighbours = Floor::neighbours(x, y, false);
        	}
        	unique_ptr<Treasure> dg = make_unique<DragonGold>();
        	content[y][x]->setTreasure(dg);
        	// spawn the dragon guarding the hoarde
            neighbours = Floor::neighbours(x, y, false);
            int numNeighbours = neighbours.size();
            int where = abs(randNum()) % numNeighbours;
		    unique_ptr<Enemy> dragon = make_unique<Dragon>(x, y);
            enemies.emplace_back(move(dragon), Posn{neighbours[where].x, neighbours[where].y});
            content[neighbours[where].y][neighbours[where].x]->setEnemy(enemies.back().first.get());
			// delete the dragon position from the available generation spots
            for (int w = 0; w < tempChambers[whichChamber].size(); w++) {
                if (tempChambers[whichChamber][w].x == neighbours[where].x && tempChambers[whichChamber][w].y == neighbours[where].y) {
                    tempChambers[whichChamber].erase(tempChambers[whichChamber].begin() + w);
                    if (w < whichTile) {
                        whichTile--;
                    }
                    break;
                }
            }
        }
        tempChambers[whichChamber].erase(tempChambers[whichChamber].begin() + whichTile);
        if (tempChambers[whichChamber].size() == 0)  {
            tempChambers.erase(tempChambers.begin() + whichChamber);
        	numChambers--;
        }
	}
    if (bs) {
        int whichC = abs(randNum()) % tempChambers.size();
        int whichTile = abs(randNum()) % tempChambers[whichC].size();
        x = tempChambers[whichC][whichTile].x;
		y = tempChambers[whichC][whichTile].y;
		vector<Posn> neighbours = Floor::neighbours(x, y, false);
        while (neighbours.size() < 1) {
            int whichC = abs(randNum()) % tempChambers.size();
            int whichTile = abs(randNum()) % tempChambers[whichC].size();
            x = tempChambers[whichC][whichTile].x;
		    y = tempChambers[whichC][whichTile].y;
		    vector<Posn> neighbours = Floor::neighbours(x, y, false);
        }
        // set this cell to barriersuit
        content[y][x]->setBarrierSuit(true);
        int where = abs(randNum()) % neighbours.size();
        bsLocation.x = x;
        bsLocation.y = y;
        // set a random neighbour (where) to have a dragon
        unique_ptr<Enemy> dragon = make_unique<Dragon>(x, y);
        enemies.emplace_back(move(dragon), Posn{neighbours[where].x, neighbours[where].y});
        content[neighbours[where].y][neighbours[where].x]->setEnemy(enemies.back().first.get());
        // delete the dragon position from the available generation spots
        for (int w = 0; w < tempChambers[whichC].size(); w++) {
            if (tempChambers[whichC][w].x == neighbours[where].x && tempChambers[whichC][w].y == neighbours[where].y) {
                tempChambers[whichC].erase(tempChambers[whichC].begin() + w);
                break;
            }
        }
    }
    // generate the enemies
    while (enemies.size() < 20) {
        int chamb = abs(randNum()) % tempChambers.size();
        numTilesInChamber = tempChambers[chamb].size();
        int random6 = abs(randNum()) % numTilesInChamber;
        x = tempChambers[chamb][random6].x;
        y = tempChambers[chamb][random6].y;
        // randomly pick an enemy
        // content[y][x].setItem(some enemy)

        int whichEnemy = abs(randNum()) % 18 + 1;
        if (whichEnemy <= 4) {
            unique_ptr<Enemy> e = make_unique<Werewolf>();
            enemies.emplace_back(move(e), Posn{x, y});
            content[y][x]->setEnemy(enemies.back().first.get());
        } else if (whichEnemy <= 7) {
            unique_ptr<Enemy> e = make_unique<Vampire>();
			enemies.emplace_back(move(e), Posn{x, y});
            content[y][x]->setEnemy(enemies.back().first.get());
        } else if (whichEnemy <= 12) {
            unique_ptr<Enemy> e = make_unique<Goblin>();
			enemies.emplace_back(move(e), Posn{x, y});
            content[y][x]->setEnemy(enemies.back().first.get());
        } else if (whichEnemy <= 14) {
            unique_ptr<Enemy> e = make_unique<Troll>();
			enemies.emplace_back(move(e), Posn{x, y});
            content[y][x]->setEnemy(enemies.back().first.get());
        } else if (whichEnemy <= 16) {
            unique_ptr<Enemy> e = make_unique<Phoenix>();
			enemies.emplace_back(move(e), Posn{x, y});
            content[y][x]->setEnemy(enemies.back().first.get());
        } else {
            unique_ptr<Enemy> e = make_unique<Merchant>();
			enemies.emplace_back(move(e), Posn{x, y});
            content[y][x]->setEnemy(enemies.back().first.get());
        }
        tempChambers[chamb].erase(tempChambers[chamb].begin() + random6);
        if (tempChambers[chamb].size() == 0)  {
            tempChambers.erase(tempChambers.begin() + chamb);
            numChambers--;
        }
    }
    // give compass to one of the enemies
    int whichEnemy = abs(randNum()) % 20;
    enemies[whichEnemy].first->giveCompass();
}

vector<Posn> Floor::neighbours(int x, int y, bool isGold, bool isPlayer) {
    vector<Posn> tmp;
    for (int i = -1; i <= 1; i++) {
        for (int k = -1; k <= 1; k++) {
            if (i == 0 && k == 0) continue;
        	if (isGold && !isPlayer) {
				if (k + y < content.size() && x + i < content[0].size() && !content[k + y][x + i]->hasPC() \
             	   && !content[k + y][x + i]->hasPotion() && !content[k + y][x + i]->hasTreasure() && !content[k + y][x + i]->getisEffWall() \
                   && content[k + y][x + i]->getsymbolRep() == '.') {
                   tmp.emplace_back(x + i, y + k);
                }
        	} else if (!isGold && !isPlayer) {
                if (k + y < content.size() && x + i < content[0].size() && !content[k + y][x + i]->hasEnemy() && !content[k + y][x + i]->hasPC() \
             	   && !content[k + y][x + i]->hasPotion() && !content[k + y][x + i]->hasTreasure() && !content[k + y][x + i]->getisEffWall() \
                   && content[k + y][x + i]->getsymbolRep() == '.' && !content[k + y][x + i]->hasBarrierSuit()) {
                   tmp.emplace_back(x + i, y + k);
                }
        	} else if (isPlayer) {
                if (k + y < content.size() && x + i < content[0].size()) {
                   tmp.emplace_back(x + i, y + k);
                }
            }
        }
    }
    return tmp;
}

void Floor::print() {
    for (int i = 0; i < content.size(); i++) {
        for (int j = 0; j < content[0].size(); j++) {
            if (content.at(i).at(j)->hasPC()) cout <<"\033[1;31m" << '@' << "\033[0m" ;
            else if (content.at(i).at(j)->hasEnemy()) cout << content.at(i).at(j)->getEnemy()->getSymbol();
            else if (content.at(i).at(j)->hasPotion()) cout << content.at(i).at(j)->getPotion()->getSymbol();
            else if (content.at(i).at(j)->hasTreasure()) cout << content.at(i).at(j)->getTreasure()->getSymbol();
            else cout << content.at(i).at(j)->getsymbolRep();
        }
        cout << endl;
    }
}

Posn Floor::getCoords(Direction d) {
    int ax, ay;
    if (d == Direction::no) {
        ax = pcLocation.x;
        ay = pcLocation.y - 1;
    } else if (d == Direction::ea) {
        ax = pcLocation.x + 1;
        ay = pcLocation.y;
    } else if (d == Direction::so) {
        ax = pcLocation.x;
        ay = pcLocation.y + 1;
    } else if (d == Direction::we) {
        ax = pcLocation.x - 1;
        ay = pcLocation.y;
    } else if (d == Direction::ne) {
        ax = pcLocation.x + 1;
        ay = pcLocation.y - 1;
    } else if (d == Direction::nw) {
        ax = pcLocation.x - 1;
        ay = pcLocation.y - 1;
    } else if (d == Direction::se) {
        ax = pcLocation.x + 1;
        ay = pcLocation.y + 1;
    } else if (d == Direction::sw) {
        ax = pcLocation.x - 1;
        ay = pcLocation.y + 1;
    }
    return Posn(ax, ay);
}

std::vector<std::vector<std::unique_ptr<Cell>>> &Floor::getContents() {
    return this->content;
}

void Floor::movePC(Direction d) {
    Posn pos = getCoords(d);
    int cx = pos.x;
    int cy = pos.y;
    vector<Posn> nbrs = Floor::neighbours(cx, cy, true);
    bool hasDragNbr = false;
    for (int i = 0; i < nbrs.size(); i++) {
        int x = nbrs[i].x;
        int y = nbrs[i].y;
        if (content[y][x]->hasEnemy() && content[y][x]->getEnemy()->isDragon()) {
            hasDragNbr = true;
            break;
        }
    }
    // make sure cannot jump diagonally in chambers
    //   #           @
    // @ # -> (ne) # #
    //   #           #
    if (content[pcLocation.y][pcLocation.x]->getsymbolRep() == '#' && (d == Direction::nw || d == Direction::ne || d == Direction::sw || d == Direction::se)) {
        p->appendcurAction("Invalid Move. ");
        return;
    }
	if (cy < content.size() && cx < content[0].size() && !content[cy][cx]->hasEnemy() && !content[cy][cx]->hasPotion() && \
        (content[cy][cx]->getsymbolRep() == '.' || content[cy][cx]->getsymbolRep() == '+' || content[cy][cx]->getsymbolRep() == '\\' \
        || content[cy][cx]->getsymbolRep() == '#') && (!content[cy][cx]->hasTreasure() || (content[cy][cx]->hasTreasure() && !content[cy][cx]->getTreasure()->isDragonHoarde()) || \
        (content[cy][cx]->getTreasure()->isDragonHoarde() && !hasDragNbr)) && (!content[cy][cx]->hasBarrierSuit() || (content[cy][cx]->hasBarrierSuit() && !hasDragNbr))) {
        if (!content[cy][cx]->hasTreasure()) cout << 1 << endl;
        if (content[cy][cx]->hasTreasure() && !content[cy][cx]->getTreasure()->isDragonHoarde()) cout << 1 << endl;
        if(content[cy][cx]->hasTreasure() && content[cy][cx]->getTreasure()->isDragonHoarde() && !hasDragNbr) cout << 3 << endl;
        content[pcLocation.y][pcLocation.x]->clear();
        pcLocation.x = cx;
        pcLocation.y = cy;
        content[pcLocation.y][pcLocation.x]->setPC(p);
    } else {
        p->appendcurAction("Invalid Move. ");
        return;
    }
    if (pcLocation.x == stairLocation.x && pcLocation.y == stairLocation.y) {
        isOnStair = true;
        p->setCompass(false);
    } else if (content[pcLocation.y][pcLocation.x]->hasCompass()) {
        content[pcLocation.y][pcLocation.x]->setCompass(false);
        content[stairLocation.y][stairLocation.x]->setVisibility();
        p->setCompass(true);
    } else if (pcLocation.x == bsLocation.x && pcLocation.y == bsLocation.y) {
        content[pcLocation.y][pcLocation.x]->setBarrierSuit(false);
        p->setBarrierSuit(true);
    }
    if (content[pcLocation.y][pcLocation.x]->hasTreasure()) {
        p->pickupTreasure(content[pcLocation.y][pcLocation.x]->getTreasure().get());
        content[pcLocation.y][pcLocation.x]->clear();
        content[pcLocation.y][pcLocation.x]->setPC(p);
    }
    if (d == Direction::no) {
        p->appendcurAction("PC moved North. ");
    } else if (d == Direction::so) {
        p->appendcurAction("PC moved South. ");
    } else if (d == Direction::we) {
        p->appendcurAction("PC moved West. ");
    } else if (d == Direction::ea) {
        p->appendcurAction("PC moved East. ");
    } else if (d == Direction::ne) {
        p->appendcurAction("PC moved North-East. ");
    } else if (d == Direction::nw) {
        p->appendcurAction("PC moved North-West. ");
    } else if (d == Direction::se) {
        p->appendcurAction("PC moved South-East. ");
    } else if (d == Direction::sw) {
        p->appendcurAction("PC moved South-West. ");
    }
    vector<Posn> neighbours = Floor::neighbours(pcLocation.x, pcLocation.y, false, true);
    for (int i = 0; i < neighbours.size(); i++) {
        int x = neighbours[i].x;
        int y = neighbours[i].y;
        if (content[y][x]->hasPotion()) {
            p->appendcurAction("PC sees a " + content[y][x]->getPotion()->getPotType() + " potion to the ");
            if (x == pcLocation.x && y == pcLocation.y - 1) {
                p->appendcurAction("North. ");
            } else if (x == pcLocation.x && y == pcLocation.y + 1) {
                p->appendcurAction("South. ");
            } else if (x == pcLocation.x + 1 && y == pcLocation.y) {
                p->appendcurAction("East. ");
            } else if (x == pcLocation.x - 1 && y == pcLocation.y) {
                p->appendcurAction("West. ");
            } else if (x == pcLocation.x + 1 && y == pcLocation.y - 1) {
                p->appendcurAction("North-East. ");
            } else if (x == pcLocation.x + 1 && y == pcLocation.y + 1) {
                p->appendcurAction("South-East. ");
            } else if (x == pcLocation.x - 1 && y == pcLocation.y + 1) {
                p->appendcurAction("South-West. ");
            } else if (x == pcLocation.x - 1 && y == pcLocation.y - 1) {
                p->appendcurAction("North-West. ");
            }
        }
    }
    updateEnemies();
}

bool Floor::PConStair() {
    return isOnStair;
}

void Floor::updateEnemies() {
    sort(enemies.begin(), enemies.end(), cmpPair);
    for (int i = 0; i < enemies.size(); i++) {
        // check if enemy is hostile and is close to PC
        // if so, then enemy does not attack
        if (enemies[i].first->isHostile()) {
            int xx, yy;
            int xxx = enemies[i].second.x;
            int yyy = enemies[i].second.y;
            if (enemies[i].first->isDragon()) {
                xx = enemies[i].first->getProtect().x;
                yy = enemies[i].first->getProtect().y;
                if (abs(pcLocation.x - xxx) <= 1 && abs(pcLocation.y - yyy) <= 1 && abs(pcLocation.x - xx) <= 1 && abs(pcLocation.y - yy) <= 1) {
                    enemies[i].first->attackPlayer(p);
                    continue;
                }
            } else {
                if (abs(pcLocation.x - xxx) <= 1 && abs(pcLocation.y - yyy) <= 1) {
                    enemies[i].first->attackPlayer(p);
                    continue;
                }
            }
        }
        if (!enemies[i].first->isDragon()) {
            int x = enemies[i].second.x;
            int y = enemies[i].second.y;
            // find the neighbours of this enemy
            vector<Posn> nbrs = Floor::neighbours(x, y, false);
            if (nbrs.size() == 0) continue;
            // pick a random neighbour
            int which = abs(randNum()) % nbrs.size();
            int x2 = nbrs[which].x;
            int y2 = nbrs[which].y;
            // move enemy to new cell
            content[y2][x2]->setEnemy(content[y][x]->getEnemy());
            content[y][x]->clear();
            enemies[i].second.x = x2;
            enemies[i].second.y = y2;
        } else {
            int x = enemies[i].first->getProtect().x;
            int y = enemies[i].first->getProtect().y;
            vector<Posn> protectNeigbours = neighbours(x, y, false);
            int x2 = enemies[i].second.x;
            int y2 = enemies[i].second.y;
            vector<Posn> myNeighbours = neighbours(x2, y2, false);
            vector<Posn> ourNeighbours;
            int sz1 = protectNeigbours.size();
            int sz2 = myNeighbours.size();
            for (int i = 0; i < sz1; i++) {
                for (int k = 0; k < sz2; k++) {
                    if (protectNeigbours[i].x == myNeighbours[k].x && protectNeigbours[i].y == myNeighbours[k].y) {
                        ourNeighbours.emplace_back(protectNeigbours[i]);
                    }
                }
            }
            if (ourNeighbours.size() == 0) continue;
            int which = abs(randNum()) % ourNeighbours.size();
            int x3 = ourNeighbours[which].x;
            int y3 = ourNeighbours[which].y;
            content[y3][x3]->setEnemy(content[y2][x2]->getEnemy());
            content[y2][x2]->clear();
            enemies[i].second.x = x3;
            enemies[i].second.y = y3;
		}
    }
}

void Floor::attack(Direction d) {
    Posn pos = getCoords(d);
    int ax = pos.x;
    int ay = pos.y;
    if (content[ay][ax]->hasEnemy()) {
        p->attackEnemy(content[ay][ax]->getEnemy());
    } else return;
    
    if (content[ay][ax]->getEnemy()->isDead()) {
        // remove from enemies vector
        bool m = content[ay][ax]->getEnemy()->isMerchant();
        bool hasCompass = false;
        for (int i = 0; i < enemies.size(); i++) {
            if (enemies[i].second.x == ax && enemies[i].second.y == ay) {
                hasCompass = enemies[i].first->checkCompass();
                enemies.erase(enemies.begin() + i);
                break;
            }
        }
        // detach from cell
        content[ay][ax]->clear();     
        if (hasCompass) {
            content[ay][ax]->setCompass(true);
            return;
        }
        if (m) {
            unique_ptr<Treasure> mg = make_unique<MerchantGold>();
            content[ay][ax]->setTreasure(mg);
        }
    }
    updateEnemies();
}

void Floor::usePotion(Direction d) {
    Posn pos = getCoords(d);
    int px = pos.x;
    int py = pos.y;
    if (px >= 0 && py >= 0 && py <= content.size() && px <= content[0].size() \
        && content[py][px]->hasPotion()) {
        p->usePotion(content[py][px]->getPotion().get());
        content[py][px]->clear();
    } else {
        // MAKE CHANGE NO POTION DO SOMETHING_____________________________________________
    }
    updateEnemies();
}

void Floor::generateCompass(){
    int random = abs(randNum());
    int enemyIndex = random % enemies.size();
    enemies.at(enemyIndex).first->giveCompass();
}
