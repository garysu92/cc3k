#include <iostream>
#include <vector>
#include "../Cells/cell.h"
#include "mapDisplay.h"

using namespace std;

Mapdisplay::Mapdisplay(vector<vector<unique_ptr<Cell>>> & newFloor) : gameMap{} {
    int dimx_len = newFloor.size();
    int dimy_len = (newFloor.at(0)).size();
    for (int i = 0; i < dimx_len; i++) {
        gameMap.emplace_back();
        for (int j = 0; j < dimy_len; j++) {
            (gameMap.at(i)).emplace_back((newFloor.at(i).at(j)).get());
        }
    }
}

void Mapdisplay::printMap() {
    for (int i = 0; i < gameMap.size(); i++) {
        for (int j = 0; j < gameMap[0].size(); j++) {
            if (gameMap.at(i).at(j)->hasPC()) cout << "\033[1;32m" << '@' << "\033[0m";
            else if (gameMap.at(i).at(j)->s()) cout << "/" << endl;
            else if (gameMap.at(i).at(j)->hasEnemy() && gameMap.at(i).at(j)->getEnemy()->checkCompass()) cout << "\033[1;31m" << gameMap.at(i).at(j)->getEnemy()->getSymbol()<< "\033[0m";
            else if (gameMap.at(i).at(j)->hasEnemy() && !gameMap.at(i).at(j)->getEnemy()->checkCompass()) cout << "\033[1;34m" << gameMap.at(i).at(j)->getEnemy()->getSymbol()<< "\033[0m";
            else if (gameMap.at(i).at(j)->hasPotion()) cout << "\033[1;36m" << gameMap.at(i).at(j)->getPotion()->getSymbol()<< "\033[0m";
            else if (gameMap.at(i).at(j)->hasTreasure()) cout << "\033[1;33m" << gameMap.at(i).at(j)->getTreasure()->getSymbol() << "\033[0m";
            else if (gameMap.at(i).at(j)->hasCompass()) cout << "\033[1;35m" << gameMap.at(i).at(j)->getTreasure()->getSymbol() << "\033[0m";
            else cout << gameMap.at(i).at(j)->getsymbolRep();
        }
        cout << endl;
    }
}
