#ifndef CC3KGAMERUNNER_H
#define CC3KGAMERUNNER_H

#include <string>
#include <memory>
#include "dungeon.h"
#include "playablecharacter.h"
#include "textdisplay.h"

class CC3KGameRunner{
    std::unique_ptr<Dungeon> game;
    std::unique_ptr<PlayableCharacter> p;
    std::unique_ptr<TextDisplay> d;
    std::unique_ptr<string> filename;

    public: 
        CC3KGameRunner(string filename);
        CC3KGameRunner();
        void play();

};

#endif
