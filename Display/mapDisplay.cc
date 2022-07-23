#include <iostream>

void mapDisplay::printMap() {
    for (int i = 0; i < content.size(); i++) {
        for (int j = 0; j < content[0].size(); j++) {
            if (content.at(i).at(j)->hasPC()) cout << '@';
            else if (content.at(i).at(j)->hasEnemy()) cout << content.at(i).at(j)->getEnemy()->getSymbol();
            else if (content.at(i).at(j)->hasPotion()) cout << content.at(i).at(j)->getPotion()->getSymbol();
            else if (content.at(i).at(j)->hasTreasure()) cout << content.at(i).at(j)->getTreasure()->getSymbol();
            else cout << content.at(i).at(j)->getsymbolRep();
        }
        cout << endl;
    }
}
