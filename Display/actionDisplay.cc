#include <iostream>
#include <iomanip>
#include <string>
#include "actionDisplay.h"
#include "../Entities/playablecharacter.h"

using namespace std; 

Actiondisplay::Actiondisplay(PlayableCharacter * newPC, int curFloor) : PC{newPC}, curFloor{curFloor} {}

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
    cout << "Race: " << (this->PC)->getRace() << ", Gold: " << (this->PC)->getcurGold() << setw(60) << "Floor: " << right << this->curFloor << endl; // Fix setw
    cout << "HP: " << (this->PC)->getHP() << endl;
    cout << "Atk: " << (this->PC)->getAttack() << endl;
    cout << "Def: " << (this->PC)->getDefense() << endl;
    cout << "Action: " << this->curAction << endl;
}
