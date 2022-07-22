#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

/*
#include "cc3kgamerunner.h"
#include "Entities/playablecharacter.h"
#include "Entities/enemy.h"
#include "Races/human.h"
#include "goblin.h"
#include "tempeffect.h"
#include "woundattack.h"
#include "wounddefense.h"
#include "boostattack.h"
#include "boostdefense.h"
#include "potion.h"
#include "floor.h"
*/

#include "floor.h"
#include "Entities/playablecharacter.h"
#include "Races/human.h"
#include "Cells/space.h"
#include "Cells/door.h"
#include "Cells/cell.h"
#include "Cells/tile.h"
#include "Cells/wall.h"
#include "Cells/stair.h"
#include "Cells/passage.h"

using namespace std;

int main(int argc, char *argv[]) {
    vector<vector<char>> v;
    ifstream file{"cc3kfloor.txt"};
    char c;
    v.emplace_back();
    for (int r = 0; r < 25; r++) {
        // loop 79 times to read the 79 columns
        for (int t = 0; t < 79; t++) {
            file >> noskipws >> c;
            v[r].emplace_back(c);
        }
        file >> noskipws >> c;
        v.emplace_back();
    }
    for (int r = 0; r < 25; r++) {
        // loop 79 times to read the 79 columns
        for (int t = 0; t < 79; t++) {
            cout << v[r][t];
        }
        cout << endl;
    }
    PlayableCharacter *p = new Human();
    Floor f{v, p};
    /*
    unique_ptr<CC3KGameRunner> game;
    if (argc == 3) {
        string filename{argv[1]};
        //game = make_uniq
    } else if (argc == 2) {
        // passed in command line arg
        string filename{argv[1]};
        game = make_unique<CC3KGameRunner>(filename);
    } else {
        // no command line arg
        game = make_unique<CC3KGameRunner>();
    }
    game->play();
    */
    // Potion p{RESTOREHEALTH};
    // if (p == RESTOREHEALTH) cout << "yes" << endl;
    // unique_ptr<PlayableCharacter> pc = make_unique<Human>();
    // //PlayableCharacter *p = new Human();
    // unique_ptr<Enemy> e = make_unique<Goblin>();
    // // e->dealDmg(move(pc));
    // cout << "goblin attack (5): " << e->getAttack() << endl;
    // cout << "player character defense (20): " << pc->getDefense() << endl;
    // unique_ptr<TempEffect> te = make_unique<WoundAttack>(move(pc));
    // unique_ptr<TempEffect> te2 = make_unique<BoostDefense>(move(te));
    // pc = move(te2);
    // cout << "player character attack (20 - 5 = 15): " << pc->getAttack() << endl;
    // cout << "player character defense (20 + 5 = 25): " << pc->getDefense() << endl;
    // cout << "player character hp (140): " << pc->getHP() << endl;
    // e->dealDmg(pc);
    // cout << "player character hp (140 - 5 = 135): " << pc->getHP() << endl;
    // pc->setHP(100);
    // cout << "player character hp (set to 100): " << pc->getHP() << endl;
    /*
    unique_ptr<WoundDefense> te = make_unique(); //new WoundDefense{pc};
    TempEffect *te2 = new WoundDefense{te};
    TempEffect *te3 = new WoundDefense{te2};
    pc = te3;
    cout << pc->getDefense() << endl;
    TempEffect *te4 = new WoundDefense{te3};
    pc = te4; // prob a mem leak
    cout << pc->getDefense() << endl;
    TempEffect *te5 = new WoundDefense{te4};
    pc = te5;
    cout << pc->getDefense() << endl;
    delete pc;
    */
    //cout << pc->getHP() << endl;
    //cout << te->getHP();
    //e->dealDmg(pc);
    //cout << pc->getHP() << endl;
}
