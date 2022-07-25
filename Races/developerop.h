#ifndef OP_H
#define OP_H
#include "../Entities/playablecharacter.h"
#include <string>
 
// for testing has a lot of attack, defense, and hp
class DeveloperOP: public PlayableCharacter {
    public:
        DeveloperOP();
        std::string getRace() const override;
        ~DeveloperOP();
};
#endif
