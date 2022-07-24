#include <string>
#include "Entities/playablecharacter.h"

using namespace std; 

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
    // curGold getter field
    //cout << "Race: " << (this->PC).getRace() << " Gold: " << (this->PC).
}
