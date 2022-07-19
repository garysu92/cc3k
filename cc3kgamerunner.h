#ifndef CC3KGAMERUNNER_H
#define CC3KGAMERUNNER_H

#include <string>
#include <memory>
#include "dungeon.h"
#include "playablecharacter.h"
#include "textdisplay.h"

class CC3KGameRunner{
    Dungeon game;
    std::unique_ptr<PlayableCharacter> p;
    TextDisplay d;
    string filename;

    public: 
        CC3KGameRunner(string filename);
        CC3KGameRunner();
        void play();

};

#endif
