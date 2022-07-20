#include <vector>
#include "floor.h"

/*
#include "wall.h"
#include "passage.h"
#include "stair.h"
#include "tile.h"
*/

using namespace std;

Floor::Floor(vector<vector<char>> v) {
    int x = v.size();
    int y = v[0].size();
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            char c = v[i][j];
            if (c == '|' || c == '-') content.emplace_back(Wall(x, y, c));
            else if (c == '#') content.emplace_back(Passage(x, y, c));
            else if (c == '+') content.emplace_back(Door(x, y, c));
            else if (c == '.') content.emplace_back(Tile(x, y, c));
            else content.emplace_back(Space(x, y, c));
        }
    }
    // make a temp 2D array that stores the positions of floors in chambers that are already visited
    int temp[x][y] = {0};
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (v[x][y] == '.') {
                // check neighbours
                for (int a = -1; a <= 1; a++) {
                    for (int b = -1; b <= 1; b++) {
                        // if neighbour is found to already be in chamber
                        if (b != a && i + a >= 0 && i + a < x && j + b >= 0 && j + b < y && temp[i + a][j + b] != 0) {
                            chambers[temp[i + a][j + b] - 1].emplace_back(i, j);
                            temp[i][j] = temp[i + a][j + b] - 1;
                            goto label;
                        }
                    }
                }
                // all neighbours are not in a chamber (yet?)
                chambers.emplace_back();
                chambers[chambers.size() - 1].emplace_back(i, j);
                temp[i][j] = chambers.size() - 1;
            }
            label:
        }
    }
}