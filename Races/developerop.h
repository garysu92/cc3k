#ifndef OP_H
#define OP_H

#include <string>
#include "../Entities/playablecharacter.h"
 
// For developer testing, this race is over-powered!
class DeveloperOP: public PlayableCharacter {
    public:
        DeveloperOP();
        std::string getRace() const override;
        ~DeveloperOP();
};
#endif
