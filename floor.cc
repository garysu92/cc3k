#include "floor.h"

#include <vector>
#include <memory>
#include <algorithm>
#include <stack>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <random>
#include <chrono>

#include "posn.h"
#include "Cells/cell.h"
#include "potion.h"
#include "tempeffect.h"
#include "rh.h"
#include "ba.h"
#include "bd.h"
#include "ph.h"
#include "wa.h"
#include "wd.h"
#include "Cells/wall.h"
#include "Cells/passage.h"
#include "Cells/tile.h"
#include "Cells/door.h"
#include "Cells/space.h"
#include "Cells/stair.h"
#include "smallgold.h"
#include "dragongold.h"
#include "normalgold.h"
#include "merchantgold.h"
#include "Enemies/dragon.h"
#include "Enemies/werewolf.h"
#include "Enemies/vampire.h"
#include "Enemies/goblin.h"
#include "Enemies/troll.h"
#include "Enemies/phoenix.h"
#include "Enemies/merchant.h"
#include "direction.h"
#include "woundattack.h"
#include "wounddefense.h"
#include "boostattack.h"
#include "boostdefense.h"

class PlayableCharacter;
class Enemy;

using namespace std;

Floor::Floor(const vector<vector<char>> &v, std::shared_ptr<PlayableCharacter> p, bool exactLayout, bool save): p{p}, content{}, chambers{}, chamberMap{}, stairLocation{-1, -1}, pcLocation{-1, -1} {
    // hi
    int row = v.size();
    int col = v[0].size();
    for (int i = 0; i < row; i++) {
        content.emplace_back();
        chamberMap.emplace_back();
        for (int j = 0; j < col; j++) {
            char c = v[i][j];
            chamberMap[i].emplace_back(0);
            if (c == '|' || c == '-') content[i].emplace_back(make_unique<Wall>(col, row, c));
            else if (c == '#') content[i].emplace_back(make_unique<Passage>(col, row));
            else if (c == '+') content[i].emplace_back(make_unique<Door>(col, row));
            else if (c == ' ') content[i].emplace_back(make_unique<Space>(col, row));
            else content[i].emplace_back(make_unique<Tile>(col, row));
        }
    }

    vector<vector<bool>> isVisited(row, vector<bool>(col, false)); // initializes 2d isvisited array all false
    int chamberCount = 0;
    for (int i = 1; i < row - 1; ++i) {
        for (int j = 1; j < col - 1; ++j) {
            if (!isVisited[i][j] && v[i][j] == '.') {
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
                            if (!isVisited.at(y).at(x) && v.at(y).at(x) == '.') {
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
    /*
    if (exactLayout) {
        for () {
            
        }
        if (save) {
            
        }
    } else {
        generate();
    }
    */
}

static unsigned int randnum() {
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine rng{seed};

    vector<int> v{};

    for (int i = 0; i < 10000; i++) {
        v.emplace_back(i);
    }
    shuffle(v.begin(), v.end(), rng);
    return v[0];
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


    int random1 = randnum() % numChambers; // 0 to numtempChambers - 1
    int numTilesInChamber = tempChambers[random1].size();
    int random2 = randnum() % numTilesInChamber; // to numTilesInChamber - 1
    int x = tempChambers[random1][random2].x;
    int y = tempChambers[random1][random2].y;
    content[y][x]->setPC(p.get());
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
    int random3 = randnum() % numChambers;
    // ensure that stair chamber and player chamber are not the same
    while (random3 != random1) {
        random3 = randnum() % numChambers;
    }
    numTilesInChamber = tempChambers[random3].size();
    int random4 = randnum() % numTilesInChamber;
    x = tempChambers[random3][random4].x;
    y = tempChambers[random3][random4].y;
    stairLocation.x = x;
    stairLocation.y = y;
    unique_ptr<Cell> stair = make_unique<Stair>(x, y);
    content[y][x] = move(stair);
    tempChambers[random3].erase(tempChambers[random3].begin() + random4);
    if (tempChambers[random3].size() == 0)  {
        tempChambers.erase(tempChambers.begin() + random3);
        numChambers--;
    }
    // generate the potions
    for (int i = 0; i < 10; i++) {
        int chamb = randnum() % numChambers;
        numTilesInChamber = tempChambers[chamb].size();
        int random5 = randnum() % numTilesInChamber;
        x = tempChambers[chamb][random5].x;
        y = tempChambers[chamb][random5].y;
        int randomPotion = randnum() % 6 + 1;
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
		int whichChamber = randnum() % tempChambers.size();
		while (tempChambers[whichChamber].size() <= 1) {
			whichChamber = randnum() % tempChambers.size();
		}
		int whichTile = randnum() % tempChambers[whichChamber].size();
		x = tempChambers[whichChamber][whichTile].x;
		y = tempChambers[whichChamber][whichTile].y;
		vector<Posn> neighbours = Floor::neighbours(x, y);
		int whichGold = randnum() % 8 + 1;
		if (whichGold <= 5) {
            unique_ptr<Treasure> sg = make_unique<SmallGold>();
            content[y][x]->setTreasure(sg);
        } else if (whichGold <= 7) {
            unique_ptr<Treasure> ng = make_unique<NormalGold>();
            content[y][x]->setTreasure(ng);
        } else {
        	// ensure that at least one neighbour
        	while (neighbours.size() <= 0) {
            	whichChamber = randnum() % tempChambers.size();
            	while (tempChambers[whichChamber].size() <= 1) {
                	whichChamber = randnum() % tempChambers.size();
                }
                whichTile = randnum() % tempChambers[whichChamber].size();
                x = tempChambers[whichChamber][whichTile].x;
                y = tempChambers[whichChamber][whichTile].y;
                neighbours = Floor::neighbours(x, y);
        	}
        	unique_ptr<Treasure> dg = make_unique<DragonGold>();
        	content[y][x]->setTreasure(dg);
        	// spawn the dragon guarding the hoarde
            neighbours = Floor::neighbours(x, y);
            int numNeighbours = neighbours.size();
            int where = randnum() % numNeighbours;
		    unique_ptr<Enemy> dragon = make_unique<Dragon>(x, y);
            enemies.emplace_back(move(dragon), Posn{neighbours[where].x, neighbours[where].y});
            content[neighbours[where].y][neighbours[where].x]->setEnemy(enemies.back().first.get());
			// delete the dragon position from the available generation spots
            //     MIGHT    //
            //     NEED     //
            //     TO       //
            //     DOUBLE   //
            //     CHECK    //
            //     THIS     //
            for (int i = 0; i < tempChambers[whichChamber].size(); i++) {
                if (tempChambers[whichChamber][i].x == x && tempChambers[whichChamber][i].y == y) {
                    tempChambers[whichChamber].erase(tempChambers[whichChamber].begin() + i);
                }
            }
        }
        tempChambers[whichChamber].erase(tempChambers[whichChamber].begin() + whichTile);
        if (tempChambers[whichChamber].size() == 0)  {
            tempChambers.erase(tempChambers.begin() + whichChamber);
        	numChambers--;
        }
	}
    // generate the enemies
    while (enemies.size() < 20) {
        int chamb = randnum() % chambers.size();
        numTilesInChamber = tempChambers[chamb].size();
        int random6 = randnum() % numTilesInChamber;
        x = tempChambers[chamb][random6].x;
        y = tempChambers[chamb][random6].y;
        // randomly pick an enemy
        // content[y][x].setItem(some enemy)

        int whichEnemy = randnum() % 18 + 1;
        if (whichEnemy <= 4) {
            unique_ptr<Enemy> e = make_unique<Werewolf>();
            enemies.emplace_back(move(e), Posn{y, x});
            content[y][x]->setEnemy(enemies.back().first.get());
        } else if (whichEnemy <= 7) {
            unique_ptr<Enemy> e = make_unique<Vampire>();
			enemies.emplace_back(move(e), Posn{y, x});
            content[y][x]->setEnemy(enemies.back().first.get());
        } else if (whichEnemy <= 12) {
            unique_ptr<Enemy> e = make_unique<Goblin>();
			enemies.emplace_back(move(e), Posn{y, x});
            content[y][x]->setEnemy(enemies.back().first.get());
        } else if (whichEnemy <= 14) {
            unique_ptr<Enemy> e = make_unique<Troll>();
			enemies.emplace_back(move(e), Posn{y, x});
            content[y][x]->setEnemy(enemies.back().first.get());
        } else if (whichEnemy <= 16) {
            unique_ptr<Enemy> e = make_unique<Phoenix>();
			enemies.emplace_back(move(e), Posn{y, x});
            content[y][x]->setEnemy(enemies.back().first.get());
        } else {
            unique_ptr<Enemy> e = make_unique<Merchant>();
			enemies.emplace_back(move(e), Posn{y, x});
            content[y][x]->setEnemy(enemies.back().first.get());
        }
        tempChambers[chamb].erase(tempChambers[chamb].begin() + random6);
        if (tempChambers[chamb].size() == 0)  {
            tempChambers.erase(tempChambers.begin() + chamb);
            numChambers--;
        }
    }
}

vector<Posn> Floor::neighbours(int x, int y) {
    vector<Posn> tmp;
    for (int i = -1; i <= 1; i++) {
        for (int k = -1; k <= 1; k++) {
            if (x + i >= 0 && x + i < 25 && y + k >= 0 && y + k < 79 && \
            	!content[k + y][x + i]->hasEnemy() && !content[k + y][x + i]->hasPC() \
            	&& !content[k + y][x + i]->hasPotion() && !content[k + y][x + i]->hasTreasure() && !content[k + y][x + i]->getisEffWall()) {
                tmp.emplace_back(x + i, y + k);
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
    return this->content; //
}

void Floor::movePC(Direction d) {
    Posn pos = getCoords(d);
    int cx = pos.x;
    int cy = pos.y;
    if (!content[cy][cx]->hasEnemy() && !content[cy][cx]->hasPotion() && !content[cy][cx]->hasTreasure() && \
        (content[cy][cx]->getsymbolRep() == '.' || content[cy][cx]->getsymbolRep() == '+' \
        || content[cy][cx]->getsymbolRep() == '#')) {
        cout << "movable: " << content[cy][cx]->getsymbolRep() << endl;
        content[pcLocation.y][pcLocation.x]->clear();
        pcLocation.x = cx;
        pcLocation.y = cy;
        content[pcLocation.y][pcLocation.x]->setPC(p.get());
    }
}

void Floor::attack(Direction d) {
    Posn pos = getCoords(d);
    int ax = pos.x;
    int ay = pos.y;
    if (ax >= 0 && ay >= 0 && ax <= content.size() && ay <= content[0].size() \
        && content[ay][ax]->hasEnemy()) {
        p->dealDmg(content[ay][ax]->getEnemy());
    }
}

void Floor::usePotion(Direction d) {
    Posn pos = getCoords(d);
    int px = pos.x;
    int py = pos.y;
    if (px >= 0 && py >= 0 && px <= content.size() && py <= content[0].size() \
        && content[py][px]->hasPotion()) {
        content[py][px]->getPotion()->setVisible();
        if (content[py][px]->getPotion()->getType() == Potion::BA) {
            shared_ptr<PlayableCharacter> tmp = p;
            p = make_shared<BoostAttack>(tmp);
        } else if (content[py][px]->getPotion()->getType() == Potion::PH) {
            int hp = p->getHP();
            hp = max(0, hp - 10);
            p->setHP(hp);
        } else if (content[py][px]->getPotion()->getType() == Potion::RH) {
            int hp = p->getHP();
            hp = min(p->getMaxHP(), hp + 10);
            p->setHP(hp);
        } else if (content[py][px]->getPotion()->getType() == Potion::BD) {
            shared_ptr<PlayableCharacter> tmp = p;
            p = make_shared<BoostDefense>(tmp);
        } else if (content[py][px]->getPotion()->getType() == Potion::WA) {
            shared_ptr<PlayableCharacter> tmp = p;
            p = make_shared<WoundAttack>(tmp);
        } else if (content[py][px]->getPotion()->getType() == Potion::WD) {
            shared_ptr<PlayableCharacter> tmp = p;
            p = make_shared<WoundDefense>(tmp);
        }
    }
}

bool cmpPair(pair<unique_ptr<Enemy>, Posn> p1, pair<unique_ptr<Enemy>, Posn> p2) {
    return (p1.second.x < p2.second.x || (p1.second.x == p2.second.x && p1.second.y < p2.second.y));
}

void Floor::moveEnemies() {
    sort(enemies.begin(), enemies.end(), cmpPair);
}