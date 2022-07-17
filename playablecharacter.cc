#include <string>
#include "playablecharacter.h"
#include "enemy.h"
#include <iostream>
#include "entity.h"

using namespace std;

PlayableCharacter::PlayableCharacter(int atk, int def, int hp): Entity{atk, def, hp}, currGold{0} {}

string PlayableCharacter::getRace() const { return ""; }

PlayableCharacter::~PlayableCharacter() {}