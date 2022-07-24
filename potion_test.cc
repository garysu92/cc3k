#include <iostream>
#include <memory>
#include <string>

#include "Races/dwarf.h"
#include "Races/human.h"
#include "Races/orc.h"
#include "Races/elf.h"
#include "Entities/playablecharacter.h"
#include "Potions/potion.h"
#include "Potions/ba.h"
#include "Potions/bd.h"
#include "Potions/wa.h"
#include "Potions/wd.h"
#include "Potions/rh.h"
#include "Potions/ph.h"

using namespace std;
int main(){
    unique_ptr<PlayableCharacter> pc = make_unique<Human>();
    unique_ptr<Potion> p = make_unique<BA>();
    pc->usePotion(p.get());
    cout << pc->getAttack() << endl;
    cout << pc->getDefense() << endl;
    cout << pc->getHP() << endl;
}
