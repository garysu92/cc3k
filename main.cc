#include <iostream>
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
    PlayableCharacter *pc = new Human();
    Enemy *e = new Goblin{};
    e->dealDmg(pc);
    //cout << pc->getAttack() << endl;
    TempEffect *te = new WoundDefense{pc};
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
    //cout << pc->getHP() << endl;
    //cout << te->getHP();
    //e->dealDmg(pc);
    //cout << pc->getHP() << endl;
}