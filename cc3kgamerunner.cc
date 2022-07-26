#include <iostream>
#include <string>
#include <memory>
#include "cc3kgamerunner.h"
#include "direction.h"
#include "Races/dwarf.h"
#include "Races/elf.h"
#include "Races/human.h"
#include "Races/orc.h"
#include "Races/developerop.h"
#include "Races/developerup.h"
#include "Races/orc.h"
#include "dungeon.h"
#include "floor.h"
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

CC3KGameRunner::CC3KGameRunner(bool developerMode) : game{}, p{make_unique<Human>()}, filename{}, developerMode{developerMode} {}

CC3KGameRunner::CC3KGameRunner(string filename, bool developerMode) : game{}, p{make_unique<Human>()},
                                                     filename{make_unique<string>(filename)}, developerMode{developerMode} {}

using namespace std;
void CC3KGameRunner::play() {
    // Reinitializing fields
    game = unique_ptr<Dungeon>{};
    p = make_unique<Human>();
    //bool gameStarted = false;
    //bool raceChosen = false;
    cin.exceptions(ios::eofbit | ios::failbit);
    string cmd;
    try {
        // choosing race

        cout << "Select a race, \"Human\" is the default race" << endl;
        cout << "[Type] - [Enter to Select]:" << endl;
        cout << "Human - h      HP: 120  ATK: 20  DEF: 20  MISC: Endgame score is doubled" << endl;
        cout << "Elf - e        HP: 140  ATK: 30  DEF: 10  MISC: All negative effect potions are converted to their postive counterpart" << endl;
        cout << "Dwarf - d      HP: 100  ATK: 20  DEF: 30  MISC: All gold is doubled" << endl;
        cout << "Orc - o        HP: 180  ATK: 30  DEF: 25  MISC: All gold is halved" << endl;

        if (developerMode) {
            cout << "OP Dev - d1    HP: 1000000  ATK: 1000000  DEF: 0" << endl;
            cout << "UP Dev - d2    HP: 1  ATK: 1  DEF: 1" << endl;
        }

        cout << "Enter your race OR Enter a valid command OR press q to quit the game: ";
        cout << endl;

        cin >> cmd;

        if (cmd == "h") {
            p = make_unique<Human>();
            cin >> cmd;
        } else if (cmd == "e") {
            p = make_unique<Elf>();
            cin >> cmd;
        } else if (cmd == "d") {
            p = make_unique<Dwarf>();
            cin >> cmd;
        } else if (cmd == "o") {
            p = make_unique<Orc>();
            cin >> cmd;
        } else if (developerMode && cmd == "d1") {
            p = make_unique<DeveloperOP>();
            cin >> cmd;
        } else if (developerMode && cmd == "d2") {
            p = make_unique<DeveloperUP>();
            cin >> cmd;
        } else if (cmd == "q") {
            return; 
        } else if (cmd != "a" && cmd != "u" && cmd != "r" && cmd != "q" && !isDirection(cmd)) {
            // invalid command quit
            return;
        }

        // initialize game
        if (filename != nullptr) {
            // this means the filename for floor layout was specified
            game = make_unique<Dungeon>(*filename, p.get());
        } else {
            game = make_unique<Dungeon>(p.get());
        }
        game->printGame();

        //raceChosen = true;
    
        // running game
        while (true) {
            bool invalidInput = false;

            /*if (gameStarted && raceChosen) {
                cin >> cmd;
            }*/

            char directionCommandType = '\0'; // Default command is move

            /*if (!raceChosen) {
                // game has not started, so choosing race is valid input, can choose multiple
                // times

                // choose race
                cout << endl;
                cout << "Select a race, \"Human\" is the default race" << endl;
                cout << "[Type] - [Enter to Select]:" << endl;
                cout << "Human - h      HP: 120  ATK: 20  DEF: 20  MISC: Endgame score is doubled" << endl;
                cout << "Elf - e        HP: 140  ATK: 30  DEF: 10  MISC: All negative effect potions are converted to their postive counterpart" << endl;
                cout << "Dwarf - d      HP: 100  ATK: 20  DEF: 30  MISC: All gold is doubled" << endl;
                cout << "Orc - o        HP: 180  ATK: 30  DEF: 25  MISC: All gold is halved" << endl;

                if (developerMode) {
                    cout << "OP Dev - d1    HP: 1000000  ATK: 1000000  DEF: 0" << endl;
                    cout << "UP Dev - d2    HP: 1  ATK: 1  DEF: 1" << endl;
                }

                cout << "Enter your race OR press q to quit the game: ";
                cout << endl;

                cin >> cmd;

                if (cmd == "h") {
                    p = make_unique<Human>();
                } else if (cmd == "e") {
                    p = make_unique<Elf>();
                } else if (cmd == "d") {
                    p = make_unique<Dwarf>();
                } else if (cmd == "o") {
                    p = make_unique<Orc>();
                } else if (developerMode && cmd == "d1") {
                    p = make_unique<DeveloperOP>();
                } else if (developerMode && cmd == "d2") {
                    p = make_unique<DeveloperUP>();
                } else if (cmd == "q") {
                    return; 
                }
                raceChosen = true;
            }*/

            // game starts when first valid command that is not choosing a character
            // is given
            /*if (!gameStarted) {
                gameStarted = true; // If this line runs, then game has started
                if (filename != nullptr) {
                    // this means the filename for floor layout was specified
                    game = make_unique<Dungeon>(*filename, p.get());
                } else {
                    game = make_unique<Dungeon>(p.get());
                }
                game->printGame();
            }*/

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
                cin >> cmd;
                continue;
            }

            Direction temp = getDirection(cmd);
            if (directionCommandType == 'a') {
                game->playerAttack(temp);
            } else if (directionCommandType == 'u') {
                game->playerUsePotion(temp);
            } else {
                game->playerMove(temp);
            }
            if (p->getDead()) {
                // print end message
                cout << "Nice Try" << endl;
                return;
            } else if (game->end()) {
                // print message
                cout << "game end" << endl;
                return;
            }

            cin >> cmd;
        }
    } catch (ios::failure &) {
    }
}
