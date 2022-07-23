#ifndef CC3KGAMERUNNER_H
#define CC3KGAMERUNNER_H

#include <string>
#include <memory>
#include "dungeon.h"
#include "Entities/playablecharacter.h"
#include "Display/textdisplay.h"

class CC3KGameRunner{
    std::unique_ptr<Dungeon> game;
    std::shared_ptr<PlayableCharacter> p;
    std::unique_ptr<TextDisplay> d;
    std::unique_ptr<std::string> filename;

    public: 
        CC3KGameRunner(std::string filename);
        CC3KGameRunner();
        void play();

};

#endif
