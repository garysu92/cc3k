#include <iostream>
#include "playablecharacter.h"
#include "enemy.h"
#include "human.h"
#include "goblin.h"
#include "tempeffect.h"
#include "woundattack.h"
#include "wounddefense.h"

using namespace std;

int main() {
    PlayableCharacter *pc = new Human();
    Enemy *e = new Goblin{};
    e->dealDmg(pc);
    cout << pc->getAttack() << endl;
    TempEffect *te = new WoundAttack{pc};
    cout << te->getAttack() << endl;
    TempEffect *te2 = new WoundAttack{te};
    cout << te2->getAttack() << endl;
    TempEffect *te3 = new WoundAttack{te2};
    cout << te3->getAttack() << endl;
}