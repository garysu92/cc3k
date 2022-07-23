#include <iostream>
#include "mapDisplay.h"

Mapdisplay::Mapdisplay(std::vector<std::vector<std::unique_ptr<Cell>>> newFloor);

void Mapdisplay::printMap() {
    for (int i = 0; i < content.size(); i++) {
        for (int j = 0; j < content[0].size(); j++) {
            if (content.at(i).at(j)->hasPC()) cout << "\033[1;31m" << '@' << "\033[0m";
            else if (content.at(i).at(j)->hasEnemy()) cout << content.at(i).at(j)->getEnemy()->getSymbol();
            else if (content.at(i).at(j)->hasPotion()) cout << content.at(i).at(j)->getPotion()->getSymbol();
            else if (content.at(i).at(j)->hasTreasure()) cout << content.at(i).at(j)->getTreasure()->getSymbol();
            else cout << content.at(i).at(j)->getsymbolRep();
        }
        cout << endl;
    }
}
