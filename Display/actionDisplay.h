#ifndef ACTIONDISPLAY_H
#define ACTIONDISPLAY_H

#include <string>
#include "../Entities/playablecharacter.h"

class Actiondisplay {
    PlayableCharacter * PC; 
    std::string curAction;
    int curFloor;
    
    public:
        // Constructor
        Actiondisplay(PlayableCharacter *newPC, int curFloor);

        // Setters
        void set_curAction(std::string newAction);
        void set_PC(PlayableCharacter *newPC);

        // Getters
        std::string get_curAction();
        PlayableCharacter * get_PC();

        // Misc
        void printActionDisplay();
};

#endif
