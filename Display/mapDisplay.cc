#include <iostream>
#include <vector>
#include <string>
#include "../Cells/cell.h"
#include "mapDisplay.h"

using namespace std;

const string RED = "\033[1;31m";
const string BLUE = "\033[1;34m";
const string YELLOW = "\033[1;33m";
const string CYAN = "\033[1;36m";
const string GREEN = "\033[1;32m";
const string MAGENTA = "\033[1;35m";
const string RESET = "\033[0m";

Mapdisplay::Mapdisplay(vector<vector<unique_ptr<Cell>>> &newFloor, bool dm) : gameMap{}, dm{dm} {
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
            if (gameMap.at(i).at(j)->hasPC()) cout << GREEN << '@' << RESET;
            else if (gameMap.at(i).at(j)->hasBarrierSuit()) cout << 'B';
            else if (gameMap.at(i).at(j)->stair() && dm) cout << '\\';
            else if (gameMap.at(i).at(j)->hasEnemy() && gameMap.at(i).at(j)->getEnemy()->checkCompass()) {
				if (dm) cout << RED << gameMap.at(i).at(j)->getEnemy()->getSymbol()<< RESET;
				else  cout << CYAN << gameMap.at(i).at(j)->getEnemy()->getSymbol()<< RESET;
            }
            else if (gameMap.at(i).at(j)->hasEnemy() && !gameMap.at(i).at(j)->getEnemy()->checkCompass()) cout << CYAN << gameMap.at(i).at(j)->getEnemy()->getSymbol()<< RESET;
            else if (gameMap.at(i).at(j)->hasPotion()) cout << BLUE << gameMap.at(i).at(j)->getPotion()->getSymbol()<< RESET;
            else if (gameMap.at(i).at(j)->hasTreasure()) cout << YELLOW << gameMap.at(i).at(j)->getTreasure()->getSymbol() << RESET;
			else if (gameMap.at(i).at(j)->hasCompass()) cout << MAGENTA << 'C' << RESET;
            else cout << gameMap.at(i).at(j)->getsymbolRep();
        }
        cout << endl;
    }
}
