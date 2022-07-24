#ifndef WOUNDDEFENSE_H
#define WOUNDDEFENSE_H

#include <memory>
#include "tempeffect.h"

class PlayableCharacter;

class WoundDefense : public TempEffect {
  public:
    WoundDefense();
    ~WoundDefense();
};

#endif
