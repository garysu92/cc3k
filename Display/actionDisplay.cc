#include <string>
#include "Entities/playablecharacter.h"

Actiondisplay::Actiondisplay(PlayableCharacter * newPC) : PC{newPC} {}

void set_curAction(string newAction) {
    this->curAction = newAction;
}

void set_PC(PlayableCharacter * newPC) {
    this->PC = newPC;
}

string get_curAction() {
    return this->curAction;
}

PlayableCharacter * get_PC() {
    return this->PC;
}
        
void printActionDisplay() {
    
}
