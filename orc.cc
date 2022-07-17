#include "orc.h"

using namespace std;

Orc::Orc(): PlayableCharacter{30, 25, 180} {}

string Orc::getRace() const {
    return "Orc";
}