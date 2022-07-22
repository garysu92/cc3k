#include <vector>
#include <memory>
#include <algorithm>
#include <stack>
#include <cstdlib>
#include <iostream>
#include "floor.h"
#include "posn.h"
#include "playablecharacter.h"
#include "cell.h"
#include "potion.h"
#include "rh.h"
#include "ba.h"
#include "bd.h"
#include "ph.h"
#include "wa.h"
#include "wd.h"
#include "wall.h"
#include "passage.h"
#include "tile.h"
#include "door.h"
#include "space.h"
#include "stair.h"
#include "smallgold.h"
#include "normalgold.h"
#include "dragongold.h"
#include "merchantgold.h"
#include "dragon.h"
#include "werewolf.h"
#include "vampire.h"
#include "goblin.h"
#include "troll.h"
#include "phoenix.h"
#include "merchant.h"

using namespace std;

Floor::Floor(const vector<vector<char>> &v, PlayableCharacter *p, bool exactLayout, bool save): p{p}, content{}, chambers{}, chamberMap{}, stairLocation{-1, -1} {
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
    // // make a temp 2D array that stores the positions of floors in chambers that are already visited
    // int temp[row][col] = {0};
    // for (int i = 1; i < row - 1; i++) {
    //     for (int j = 1; j < col - 1; j++) {
    //         if (v[i][j] == '.') {
    //             // check neighbours
    //             // bool newChamber = true;
    //             for (int a = -1; a <= 1; a++) {
    //                 for (int b = -1; b <= 1; b++) {
    //                     // if neighbour is found to already be in chamber
    //                     if (!(b == 0 && a == 0) && temp[i + a][j + b] != 0) {
    //                         chambers[temp[i + a][j + b] - 1].emplace_back(i, j);
    //                         temp[i][j] = temp[i + a][j + b];
    //                         // newChamber = false;
    //                         goto label;
    //                     }
    //                 }
    //             }
    //             //if (newChamber) {
    //             // all neighbours are not in a chamber (yet?)
    //             chambers.emplace_back();
    //             chambers[chambers.size() - 1].emplace_back(i, j);
    //             temp[i][j] = chambers.size();
    //             //}
    //         }
    //         label:
    //     }
    // }

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
    
    if (save && exactLayout) {
        //for () {

        //}
    } else if (exactLayout) {
        
    } else {
        //generate();
    }
}

void Floor::generate() {
    
    int numChambers = chambers.size();

    vector<vector<Posn>> tempChambers{chambers};

    // generate player location
    int random1 = rand() % numChambers; // 0 to numtempChambers - 1
    int numTilesInChamber = tempChambers[random1].size();
    int random2 = rand() % numTilesInChamber; // to numTilesInChamber - 1
    int x = tempChambers[random1][random2].x;
    int y = tempChambers[random1][random2].y;
    content[y][x]->setPC(p);
    // erase that position from available
    tempChambers[random1].erase(tempChambers[random1].begin() + random2);
    // if the chamber no longer has any that are available, then remove that whole chamber from being available
    if (tempChambers[random1].size() == 0)  {
        tempChambers.erase(tempChambers.begin() + random1);
        numChambers--;
    }

    // spawn the stair
    int random3 = rand() % numChambers;
    // ensure that stair chamber and player chamber are not the same
    while (random3 != random1) {
        random3 = rand() % numChambers;
    }
    numTilesInChamber = tempChambers[random3].size();
    int random4 = rand() % numTilesInChamber;
    int x = tempChambers[random3][random4].x;
    int y = tempChambers[random3][random4].y;
    stairLocation.x = x;
    stairLocation.y = y;
    unique_ptr<Cell> stair = make_unique<Stair>();
    content[y][x] = stair.get();
    tempChambers[random3].erase(tempChambers[random3].begin() + random4);
    if (tempChambers[random3].size() == 0)  {
        tempChambers.erase(tempChambers.begin() + random3);
        numChambers--;
    }

    // generate the potions
    for (int i = 0; i < 10; i++) {
        int chamb = rand() % numChambers;
        numTilesInChamber = tempChambers[chamb].size();
        int random5 = rand() % numTilesInChamber;
        int x = tempChambers[chamb][random5].x;
        int y = tempChambers[chamb][random5].y;
        int randomPotion = rand() % 6 + 1;
        // RH = restore health
        // BA = boost attack
        // BD = boost defense
        // PH = poison health
        // WA = wound attack
        // WD = wound defense
        if (randomPotion == 1) {
            unique_ptr<Item> ptr = make_unique<RH>();
            content[y][x]->setItem(ptr.get());
        } else if (randomPotion == 2) {
            unique_ptr<Item> ptr = make_unique<BA>();
            content[y][x]->setItem(ptr.get());
        } else if (randomPotion == 3) {
            unique_ptr<Item> ptr = make_unique<BD>();
            content[y][x]->setItem(ptr.get());
        } else if (randomPotion == 4) {
            unique_ptr<Item> ptr = make_unique<PH>();
            content[y][x]->setItem(ptr.get());
        } else if (randomPotion == 5) {
            unique_ptr<Item> ptr = make_unique<WA>();
            content[y][x]->setItem(ptr.get());
        } else if (randomPotion == 6) {
            unique_ptr<Item> ptr = make_unique<WD>();
            content[y][x]->setItem(ptr.get());
        }
        tempChambers[chamb].erase(tempChambers[chamb].begin() + random5);
        if (tempChambers[chamb].size() == 0)  {
            tempChambers.erase(tempChambers.begin() + chamb);
            numChambers--;
        }
    }

    // generate the gold
    for (int i = 0; i < 10; i++) {
        int chamb = rand() % numChambers;
        numTilesInChamber = tempChambers[chamb].size();
        int random6 = rand() % numTilesInChamber;
        int x = tempChambers[chamb][random6].x;
        int y = tempChambers[chamb][random6].y;
        // randomly pick a gold
        int whichGold = rand() % 8 + 1;
        if (whichGold <= 5) {
            unique_ptr<Item> sg = make_unique<SmallGold>();
            content[y][x]->setItem(sg.get());
        } else if (whichGold <= 7) {
            unique_ptr<Item> ng = make_unique<NormalGold>();
            content[y][x]->setItem(ng.get());
        } else {
            unique_ptr<Item> dg = make_unique<SmallGold>();
            content[y][x]->setItem(dg.get());
            // spawn the dragon guarding the hoarde
            vector<Posn> neighbours = Floor::neighbours(x, y);
            int numNeighbours = neighbours.size();
            int where = rand() % numNeighbours + 1;
            // ensure that we are not generating an enemy on a stair
            while (neighbours[where].x == stairLocation.x && neighbours[where].y == stairLocation.y) {
                int where = rand() % numNeighbours + 1;
            }
            unique_ptr<Enemy> dragon = make_unique<Dragon>();
            enemies.emplace_back(dragon.get());
            content[y][x]->setEnemy(dragon.get());
        }
        // content[y][x].setItem(some gold)
        tempChambers[chamb].erase(tempChambers[chamb].begin() + random6);
        if (tempChambers[chamb].size() == 0)  {
            tempChambers.erase(tempChambers.begin() + chamb);
            numChambers--;
        }
    }

    // generate the enemies
    while (enemies.size() < 20) {
        int chamb = rand() % numChambers;
        numTilesInChamber = tempChambers[chamb].size();
        int random6 = rand() % numTilesInChamber;
        int x = tempChambers[chamb][random6].x;
        int y = tempChambers[chamb][random6].y;
        // randomly pick an enemy
        // content[y][x].setItem(some enemy)
        tempChambers[chamb].erase(tempChambers[chamb].begin() + random6);

        int whichEnemy = rand() % 18 + 1;
        if (whichEnemy <= 4) {
            unique_ptr<Enemy> e = make_unique<Werewolf>();
            content[y][x]->setEnemy(e.get());
            enemies.emplace_back(e.get());
        } else if (whichEnemy <= 7) {
            unique_ptr<Enemy> e = make_unique<Vampire>();
            content[y][x]->setEnemy(e.get());
        } else if (whichEnemy <= 12) {
            unique_ptr<Enemy> e = make_unique<Goblin>();
            content[y][x]->setEnemy(e.get());
        } else if (whichEnemy <= 14) {
            unique_ptr<Enemy> e = make_unique<Troll>();
            content[y][x]->setEnemy(e.get());
        } else if (whichEnemy <= 16) {
            unique_ptr<Enemy> e = make_unique<Phoenix>();
            content[y][x]->setEnemy(e.get());
        } else {
            unique_ptr<Enemy> e = make_unique<Merchant>();
            content[y][x]->setEnemy(e.get());
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
            if (x + i >= 0 && x + i < 25 && y + k >= 0 && y + k < 79 && content[i][k]->getsymbolRep() == '.') {
                tmp.emplace_back(x + i, y + k);
            }
        }
    }
    return tmp;
}

void Floor::print() {
    for (int i = 0; i < content.size(); i++) {
        for (int j = 0; j < content[0].size(); j++) {
            if (content[i][j]->hasPC()) cout << '@';
            else if (content[i][j]->hasEnemy()) cout << content[i][j]->getEnemy()->getSymbol();
            else if (content[i][j]->hasItem()) cout << content[i][j]->getItem()->getSymbol();
            else cout << content[i][j]->getsymbolRep();
        }
        cout << endl;
    }
}