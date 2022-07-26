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

int main(int argc, char **argv) {
    unique_ptr<CC3KGameRunner> game{};
    bool developerMode = false;
    string filename = "";
    if (argc == 1) {
        // no command line args
	    game = make_unique<CC3KGameRunner>();
    } else if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            string s = argv[i];
            if (s == "-d") {
                // developer mode flag
                developerMode = true;
            } else if (s == "num") {
                // NOTE, check number
            } else {
                // assume filename
                filename = s;
            }
            if (filename != "") {
                game = make_unique<CC3KGameRunner> (filename, developerMode);
            } else {
                game = make_unique<CC3KGameRunner> (developerMode);
            }
        }
    }
	game->play();
}
