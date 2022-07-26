#ifndef UP_H
#define UP_H

#include <string>
#include "../Entities/playablecharacter.h"
 
// For developer testing, this race dies easily
class DeveloperUP: public PlayableCharacter {
    public:
        DeveloperUP();
        std::string getRace() const override;
        ~DeveloperUP();
};
#endif
