#ifndef ITEM_H
#define ITEM_H

class Item {
    char sym;
  public:
    Item(char c);
    virtual ~Item() = 0;
    char getSymbol() {
      return sym;
    }
};

#endif
