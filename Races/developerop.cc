#include <string>
#include "developerop.h"
#include "../Entities/playablecharacter.h"

DeveloperOP::DeveloperOP(): PlayableCharacter{1000000, 0, 1000000} {}

std::string DeveloperOP::getRace() const {
    return "OP";
}

DeveloperOP::~DeveloperOP() {}
