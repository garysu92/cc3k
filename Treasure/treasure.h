#ifndef TREASURE_H
#define TREASURE_H

class PlayableCharacter;
class Treasure {
    char sym;
    int amount;
    bool isPickedUp;
  public:
    Treasure(int amount);
    virtual ~Treasure() = 0;
    int getAmount();
    char getSymbol();
};

#endif
