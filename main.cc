#include <iostream>
#include "playablecharacter.h"
#include "enemy.h"
#include "human.h"
#include "goblin.h"
#include "tempeffect.h"
#include "lowerattack.h"

using namespace std;

int main() {
    PlayableCharacter *pc = new Human();
    Enemy *e = new Goblin{};
    e->dealDmg(pc);
    cout << pc->getAttack() << endl;
    TempEffect *te = new LowerAttack{pc};
    cout << te->getAttack() << endl;
}