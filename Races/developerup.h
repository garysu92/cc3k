#ifndef UP_H
#define UP_H
#include "../Entities/playablecharacter.h"
#include <string>
 
// for testing, instantly dies if attacked
class DeveloperUP: public PlayableCharacter {
    public:
        DeveloperUP();
        std::string getRace() const override;
        ~DeveloperUP();
};
#endif
