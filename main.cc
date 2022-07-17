#include <iostream>
#include "playablecharacter.h"
#include "entity.h"
#include "enemy.h"
#include "human.h"
#include "goblin.h"

using namespace std;

int main() {
    Entity *pc = new Human();
    Entity *e = new Goblin{};
    e->dealDmg(pc);
}