#ifndef TREASURE_H
#define TREASURE_H

class Treasure : public Item {
    int amount;
  public:
    Treasure(int amount);
    virtual ~Treasure() = 0;
    int getAmount();
};

#endif