#include <iostream>
#include <memory>
#include "playablecharacter.h"
#include "enemy.h"
#include "human.h"
#include "goblin.h"
#include "tempeffect.h"
#include "woundattack.h"
#include "wounddefense.h"
#include "boostattack.h"
#include "boostdefense.h"

using namespace std;

int main() {
    unique_ptr<PlayableCharacter> pc = make_unique<Human>();
    //PlayableCharacter *p = new Human();
    unique_ptr<Enemy> e = make_unique<Goblin>();
    // e->dealDmg(move(pc));
    cout << e->getAttack() << endl;
    cout << pc->getDefense() << endl;
    unique_ptr<TempEffect> te = make_unique<WoundAttack>(move(pc));
    unique_ptr<TempEffect> te2 = make_unique<BoostDefense>(move(te));
    pc = move(te2);
    cout << pc->getAttack() << endl;
    cout << pc->getDefense() << endl;
    cout << pc->getHP() << endl;
    pc->setHP(100);
    cout << pc->getHP() << endl;
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