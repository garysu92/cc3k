#include "lowerattack.h"
#include "playablecharacter.h"

using namespace std;

LowerAttack::LowerAttack(PlayableCharacter *pc): TempEffect{pc, -5, 0} {}