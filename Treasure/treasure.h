#ifndef TREASURE_H
#define TREASURE_H

class PlayableCharacter;
class Treasure {
    char sym;
    int amount;
    bool isPickedUp;
    bool dh;
  public:
    Treasure(int amount, bool dh = false);
    virtual ~Treasure() = 0;
    int getAmount();
    char getSymbol();
    bool isDragonHoarde();
};

#endif
