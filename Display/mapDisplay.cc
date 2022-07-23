#include <iostream>
#include "cell.h"
#include "mapDisplay.h"

Mapdisplay::Mapdisplay(std::vector<std::vector<std::unique_ptr<Cell>>> newFloor) : map{newFloor} {}

void Mapdisplay::printMap() {
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[0].size(); j++) {
            if (map.at(i).at(j)->hasPC()) cout << "\033[1;31m" << '@' << "\033[0m";
            else if (map.at(i).at(j)->hasEnemy()) cout << map.at(i).at(j)->getEnemy()->getSymbol();
            else if (map.at(i).at(j)->hasPotion()) cout << map.at(i).at(j)->getPotion()->getSymbol();
            else if (map.at(i).at(j)->hasTreasure()) cout << map.at(i).at(j)->getTreasure()->getSymbol();
            else cout << map.at(i).at(j)->getsymbolRep();
        }
        cout << endl;
    }
}
