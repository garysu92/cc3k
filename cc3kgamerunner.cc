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
    cout << endl;
    cout << endl;
    cout << "________/\\\\\\\\\\\\\\\\\\________/\\\\\\\\\\\\\\\\\\_____/\\\\\\\\\\\\\\\\\\___/\\\\\\________/\\\\\\_        " << endl;
    cout << " _____/\\\\\\////////______/\\\\\\////////____/\\\\\\///////\\\\\\_\\/\\\\\\_____/\\\\\\//__       " << endl;
    cout << "  ___/\\\\\\/_____________/\\\\\\/____________\\///______/\\\\\\__\\/\\\\\\__/\\\\\\//_____" << endl;      
    cout << "   __/\\\\\\______________/\\\\\\_____________________/\\\\\\//___\\/\\\\\\//\\\\\\_____" << endl;    
    cout << "    _\\/\\\\\\_____________\\/\\\\\\____________________\\////\\\\\\__\\/\\\\\\//_\\//\\\\\\____" << endl; 
    cout << "     _\\//\\\\\\____________\\//\\\\\\______________________\\//\\\\\\_\\/\\\\\\____\\//\\\\\\___" << endl;
    cout << "      __\\///\\\\\\___________\\///\\\\\\___________/\\\\\\______/\\\\\\__\\/\\\\\\_____\\//\\\\\\__" << endl;  
	cout << "       ____\\////\\\\\\\\\\\\\\\\\\____\\////\\\\\\\\\\\\\\\\\\_\\///\\\\\\\\\\\\\\\\\\/___\\/\\\\\\______\\//\\\\\\_" << endl;
    cout << "        _______\\/////////________\\/////////____\\/////////_____\\///________\\///__" << endl;
    try {
        // choosing race
		cout << endl;
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

        cout << "Enter s when you are ready to start. OR press q to quit the game: " << endl;

        while (true) {
            cin >> cmd;
            if (cmd == "s") {
                break;
            }

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
            } else {
                // invalid command quit
                return;
            }
        }

        // initialize game
        if (filename != nullptr) {
            // this means the filename for floor layout was specified
            game = make_unique<Dungeon>(*filename, p.get(), developerMode);
        } else {
            game = make_unique<Dungeon>(p.get(), developerMode);
        }
        game->printGame();

        //raceChosen = true;
    
        // running game
        while (true) {
            cin >> cmd;
            bool invalidInput = false;

            char directionCommandType = '\0'; // Default command is move

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

            Direction temp = getDirection(cmd);
            if (directionCommandType == 'a') {
                game->playerAttack(temp);
            } else if (directionCommandType == 'u') {
                game->playerUsePotion(temp);
            } else {
                game->playerMove(temp);
            }

            bool gameEnd = false;
            if (p->getDead()) {
                // print end message
                cout << "___________" << endl;
                cout << "Nice Try..." << endl;
                cout << "___________" << endl;
                gameEnd = true;                
            } else if (game->end()) {
                // print message
                cout << "Game End" << endl;
                cout <<  "Your score was: " << p->getScore() << endl;
                gameEnd = true;
            }

            if (gameEnd) {
                cout << "To play again, enter r:" << endl;
                cin >> cmd;
                if (cmd == "r") {
                    play();
                }
                return;
            }

        }
    } catch (ios::failure &) {
        
    }
}
