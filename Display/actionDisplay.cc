#include <iostream>
#include <string>
#include "actionDisplay.h"
#include "../Entities/playablecharacter.h"

using namespace std; 

Actiondisplay::Actiondisplay(PlayableCharacter * newPC) : PC{newPC} {}

void Actiondisplay::set_curAction(string newAction) {
    this->curAction = newAction;
}

void Actiondisplay::set_PC(PlayableCharacter * newPC) {
    this->PC = newPC;
}

string Actiondisplay::get_curAction() {
    return this->curAction;
}

PlayableCharacter * Actiondisplay::get_PC() {
    return this->PC;
}
        
void Actiondisplay::printActionDisplay() {
    cout << "Race: " << (this->PC)->getRace() << "Gold: " << (this->PC)->getcurGold() << endl;
    cout << "HP: " << (this->PC)->getHP() << endl;
    cout << "Atk: " << (this->PC)->getAttack() << endl;
    cout << "Def: " << (this->PC)->getDefense() << endl;
    cout << "Action: " << this->curAction << endl;
}
