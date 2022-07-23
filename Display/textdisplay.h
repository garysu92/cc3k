#ifndef TEXTDISPLAY_H
#define  TEXTDISPLAY_H

#include <iostream>
#include <vector>

class  TextDisplay: Observer<> {
    vector<vector<char>> floorGrid;
    friend std::ostream &<<(std::ostream &out, const TextDisplay t);
};

#endif
