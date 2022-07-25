#include "floor.h"

#include <vector>
#include <memory>
#include <algorithm>
#include <stack>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <random>
#include <chrono>

#include "posn.h"
#include "Cells/cell.h"
#include "Potions/potion.h"
#include "TempEffects/tempeffect.h"
#include "Potions/rh.h"
#include "Potions/ba.h"
#include "Potions/bd.h"
#include "Potions/ph.h"
#include "Potions/wa.h"
#include "Potions/wd.h"
#include "Cells/wall.h"
#include "Cells/passage.h"
#include "Cells/tile.h"
#include "Cells/door.h"
#include "Cells/space.h"
#include "Cells/stair.h"
#include "Treasure/smallgold.h"
#include "Treasure/dragongold.h"
#include "Treasure/normalgold.h"
#include "Treasure/merchantgold.h"
#include "Treasure/treasure.h"
#include "Enemies/dragon.h"
#include "Enemies/werewolf.h"
#include "Enemies/vampire.h"
#include "Enemies/goblin.h"
#include "Enemies/troll.h"
#include "Enemies/phoenix.h"
#include "Enemies/merchant.h"
#include "direction.h"
#include "TempEffects/woundattack.h"
#include "TempEffects/wounddefense.h"
#include "TempEffects/boostattack.h"
#include "TempEffects/boostdefense.h"
#include "dungeon.h"
#include "cc3kgamerunner.h"

using namespace std;

int main(int argc, char *argv[]) {
	CC3KGameRunner game{};
	game.play();
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
    //PlayableCharacter *p = new Human();
    // unique_ptr<Enemy> e = make_unique<Goblin>();
    // // e->dealDmg(move(pc));
    // cout << "goblin attack (5): " << e->getAttack() << endl;
    // cout << "player character defense (20): " << pc->getDefense() << endl;
    //unique_ptr<TempEffect> te = make_unique<WoundAttack>(move(p));
    // unique_ptr<TempEffect> te2 = make_unique<BoostDefense>(move(te));
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
