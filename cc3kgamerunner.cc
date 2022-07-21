#include <iostream>
#include <string>
#include <memory>

#include "cc3kgamerunner.h"
#include "direction.h"
#include "dwarf.h"
#include "elf.h"
#include "floor.h"
#include "human.h"
#include "orc.h"

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
    } else if (s == "NE") {
        return Direction::ne;
    } else if (s == "NW") {
        return Direction::nw;
    } else if (s == "SE") {
        return Direction::se;
    } else {
        //sw
        return Direction::sw;
    }
}

CC3KGameRunner::CC3KGameRunner() : game{}, p{make_unique<Human>()}, d{}, filename{} {}

CC3KGameRunner::CC3KGameRunner(string filename) : game{}, p{make_unique<Human>()},
                                                     d{}, filename{make_unique<string>(filename)} {}

using namespace std;
void CC3KGameRunner::play() {
    bool gameStarted = false;
    cin.exceptions(ios::eofbit | ios::failbit);
    string cmd;
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
                    p = make_unique<Human>();
                } else if (cmd == "e") {
                    p = make_unique<Elf>();
                } else if (cmd == "d") {
                    p = make_unique<Dwarf>();
                } else if (cmd == "o") {
                    p = make_unique<Orc>();
                }
                // else do nothing
                continue;
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
                // if (isDirection(cmd)){
                //     Direction temp = getDirection(cmd);
                //     //game.usePotion(temp);
                // } else {
                //     invalidInput = true;
                // }
            } else if (cmd == "a") {
                // attack
                cin >> cmd;
                directionCommandType = 'a';
                // if (isDirection(cmd)){
                //     Direction temp = getDirection(cmd);
                //     //game.usePotion(temp);
                // } else {
                //     invalidInput = true;
                // }
            }
            

            if (isDirection(cmd)) {
                Direction temp = getDirection(cmd);
                if (directionCommandType = 'a') {
                    //game.attack(temp);
                } else if (directionCommandType = 'u') {
                    //game.usePotion(temp);
                } else {
                    // move
                    //game.move(temp);
                }
            } else {
                // else invalid input
                invalidInput = true;
            }

            if (invalidInput) {
                cout << "Invalid Input" << endl;
                continue;
            }


            if (!gameStarted) {
                gameStarted = true; // if this line runs, then game has started, 
                                // cannot choose race anymore
                // this part only runs when user executes a valid non-choose race command
                if (filename != nullptr) {
                    // this means the filename for floor layout was specified
                    game = make_unique<Dungeon>(filename.get());
                } else {
                    game = make_unique<Dungeon>();
                }
            }
        }
    } catch (ios::failure &) {
    }
}
