#include <iostream>
#include <vector>
#include "../Cells/cell.h"
#include "mapDisplay.h"

using namespace std;

Mapdisplay::Mapdisplay(vector<vector<unique_ptr<Cell>>> & newFloor) : gameMap{} {
    int dimx_len = newFloor.size();
    int dimy_len = (newFloor.at(0)).size();
    for (int i = 0; i < dimx_len; i++) {
        for (int j = 0; j < dimy_len; j++) {
            (gameMap.at(i)).emplace_back((newFloor.at(i).at(j)).get());
        }
    }
}

void Mapdisplay::printMap() {
    for (int i = 0; i < gameMap.size(); i++) {
        for (int j = 0; j < gameMap[0].size(); j++) {
            if (gameMap.at(i).at(j)->hasPC()) cout << "\033[1;31m" << '@' << "\033[0m";
            else if (gameMap.at(i).at(j)->hasEnemy()) cout << gameMap.at(i).at(j)->getEnemy()->getSymbol();
            else if (gameMap.at(i).at(j)->hasPotion()) cout << gameMap.at(i).at(j)->getPotion()->getSymbol();
            else if (gameMap.at(i).at(j)->hasTreasure()) cout << gameMap.at(i).at(j)->getTreasure()->getSymbol();
            else cout << gameMap.at(i).at(j)->getsymbolRep();
        }
        cout << endl;
    }
}
