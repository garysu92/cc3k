#include <iostream>
#include <memory>
#include <string>

#include "cc3kgamerunner.h"
#include "playablecharacter.h"
#include "enemy.h"
#include "human.h"
#include "goblin.h"
#include "tempeffect.h"
#include "woundattack.h"
#include "wounddefense.h"
#include "boostattack.h"
#include "boostdefense.h"
#include "potion.h"

using namespace std;

int main(int argc, char* argv[]) {
    unique_ptr<CC3KGameRunner> game;
    if (argc > 1) {
        // passed in command line arg
        string filename{argv[1]};
        game = make_unique<CC3KGameRunner>(filename);
    } else {
        // no command line arg
        game = make_unique<CC3KGameRunner>();
    }
    game->play();
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
