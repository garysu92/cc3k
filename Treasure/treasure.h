#ifndef TREASURE_H
#define TREASURE_H

class Treasure {
    char sym;
    int amount;
  public:
    Treasure(int amount);
    virtual ~Treasure() = 0;
    int getAmount();
    char getSymbol();
};

#endif
