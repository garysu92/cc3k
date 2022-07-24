#ifndef ACTIONDISPLAY_H
#define ACTIONDISPLAY_H

#include <string>
#include "Entities/playablecharacter.h"

class Actiondisplay {
    PlayableCharacter * PC; 
    string curAction;
    
    public:
        // Constructor
        Actiondisplay();

        // Setters
        void set_curAction(string newAction);
        void set_PC(PlayableCharacter * newPC);

        // Getters
        string get_curAction();
        PlayableCharacter * get_PC();

        // Misc
        void printActionDisplay();
};

#endif
