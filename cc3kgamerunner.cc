#include <iostream>
#include <string>
#include <memory>

#include "cc3kgamerunner.h"
#include "direction.h"
#include "Races/dwarf.h"
#include "Races/elf.h"
#include "floor.h"
#include "Races/human.h"
#include "Races/orc.h"
#include "Display/mapDisplay.h"

using namespace std;

static bool isDirection(string s) {
    if (s == "no" || s == "so" || s == "ea" || s == "we" || s == "ne" || s == "nw" 
        || s == "se" || s == "sw") {
            return true;
    }
    return false;
}

// MAYBE handle non-direction strings
static Direction getDirection(string s) {
    if (s == "no" ) {
        return Direction::no;
    } else if (s == "so") {
        return Direction::so;
    } else if (s == "ea") {
        return Direction::ea;
    } else if (s == "we") {
        return Direction::we;
    } else if (s == "ne") {
        return Direction::ne;
    } else if (s == "nw") {
        return Direction::nw;
    } else if (s == "se") {
        return Direction::se;
    } else {
        //sw
        return Direction::sw;
    }
}

CC3KGameRunner::CC3KGameRunner() : game{}, p{make_shared<Human>()}, d{}, filename{} {}

CC3KGameRunner::CC3KGameRunner(string filename) : game{}, p{make_shared<Human>()},
                                                     d{}, filename{make_unique<string>(filename)} {}

using namespace std;
void CC3KGameRunner::play() {
    // reinitializing fields
    game = unique_ptr<Dungeon>{};
    p = make_unique<Human>();
    // d = unique_ptr<TextDisplay>{};// maybe not necessary

    bool gameStarted = false;
    cin.exceptions(ios::eofbit | ios::failbit);
    string cmd;
    bool newFloorDisplay;
    int curFloor;
    Mapdisplay * curMap;
    try {
        // running game
        while (true) {

            cin >> cmd;
            bool invalidInput = false;
            char directionCommandType = '\0'; // default is move, not used if not move, use potion, attack
            if (!gameStarted) {
                // game has not started, so choosing race is valid input, can choose multiple
                // times

                // choose race
                // cout << "Select a race, type \"Human\" is the default" << endl;
                // cout << "[Type] - [Enter to Select]:" << endl;
                // cout << "Human - h" << endl;
                // cout << "Elf - e" << endl;
                // cout << "Dwarf - d" << endl;
                // cout << "Orc - o" << endl;

                // cout << "Enter your race: ";

                if (cmd == "h") {
                    p = make_shared<Human>();
                    continue;
                } else if (cmd == "e") {
                    p = make_shared<Elf>();
                    continue;
                } else if (cmd == "d") {
                    p = make_shared<Dwarf>();
                    continue;
                } else if (cmd == "o") {
                    p = make_shared<Orc>();
                    continue;
                }
                // else do nothing
            }

            // play game commands
            if (cmd == "r") {
                //restart
                // NOTE need to reinitialize fields
                play();
                return;
            } else if (cmd == "q") {
                // quit
                return;
            } else if (cmd == "u") {
                // use potion
                cin >> cmd;
                directionCommandType = 'u';
            } else if (cmd == "a") {
                // attack
                cin >> cmd;
                directionCommandType = 'a';
            }
            
            if (!isDirection(cmd)) {
                invalidInput = true;
            }

            if (invalidInput) {
                cout << "Invalid Input" << endl;
                continue;
            }

            // game starts when first valid command that is not choosing a character
            // is given
            if (!gameStarted) {
                gameStarted = true; // if this line runs, then game has started, 
                                // cannot choose race anymore
                // this part only runs when user executes a valid non-choose race command
                if (filename != nullptr) {
                    // this means the filename for floor layout was specified
                    game = make_unique<Dungeon>(*filename, p.get());
                } else {
                    game = make_unique<Dungeon>(p.get());
                }
                newFloorDisplay = true;
                curFloor = 1;
            }

            // Ensure going up a staircase sets newFloorDisplay = true, increment curFloor when going up stairs?
            if (newFloorDisplay) {
                newFloorDisplay = false; 
                curDisplay{game->getFloor(curFloor)};
            }

            Direction temp = getDirection(cmd);
            if (directionCommandType = 'a') {
                //game.playerAttack(temp);
            } else if (directionCommandType = 'u') {
                //game.playerUsePotion(temp);
            } else {
                // move
                //game.playerMove(temp);
            }
        }
    } catch (ios::failure &) {
    }
}
