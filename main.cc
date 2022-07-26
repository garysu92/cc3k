#include <memory>
#include <string>
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
