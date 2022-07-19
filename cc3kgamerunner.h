#ifndef CC3KGAMERUNNER_H
#define CC3KGAMERUNNER_H

#include "dungeon.h"
#include "playablecharacter.h"
#include "textdisplay.h"

#include <memory>

class CC3KGameRunner{
    Dungeon game;
    std::unique_ptr<PlayableCharacter> p;
    TextDisplay d;

    public: 
        CC3KGameRunner();
        void play();

};
#endif
