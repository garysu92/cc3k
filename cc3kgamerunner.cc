#include "cc3kgamerunner.h"

#include <iostream>
#include <string>

#include "dwarf.h"
#include "elf.h"
#include "floor.h"
#include "human.h"
#include "orc.h"

CC3KGameRunner::CC3KGameRunner() : game{}, p{make_unique<Human>()}, d{} {}

using namespace std;
void CC3KGameRunner::play() {
    bool gameStarted = false;
    cin.exceptions(ios::eofbit | ios::failbit);
    string cmd;
    try {
        cin >> cmd;

        // running game
        while (true) {
            cin >> cmd;
            if (!gameStarted) {
                // choose race
                cout << "Select a race, type \"Human\" is the default" << endl;
                cout << "[Type] - [Enter to Select]:" << endl;
                cout << "Human - h" << endl;
                cout << "Elf - e" << endl;
                cout << "Dwarf - d" << endl;
                cout << "Orc - o" << endl;

                cout << "Enter your race: ";

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
            }

            // play game commands

            if (cmd == "r") {
                //restart
            } else if (cmd == "q") {
                // quit
                return;
            } else if (cmd == "u") {
                // use potion
            } else if (cmd == "a") {
                // attack
            }
        }
    } catch (ios::failure &) {
    }
}
