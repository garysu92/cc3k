#include <vector>
#include <cstdlib>
#include "floor.h"
#include "posn.h"
#include "playablecharacter.h"
#include "cell.h"
/*
#include "wall.h"
#include "passage.h"
#include "stair.h"
#include "tile.h"
*/

using namespace std;

Floor::Floor(vector<vector<char>> v, PlayableCharacter *p): p{p} {
    int x = v.size();
    int y = v[0].size();
    for (int i = 0; i < x; i++) {
        content.emplace_back();
        for (int j = 0; j < y; j++) {
            char c = v[i][j];
            if (c == '|' || c == '-') content[i].emplace_back(Wall(x, y, c));
            else if (c == '#') content[i].emplace_back(Passage(x, y, c));
            else if (c == '+') content[i].emplace_back(Door(x, y, c));
            else if (c == '.') content[i].emplace_back(Tile(x, y, c));
            else content[i].emplace_back(Space(x, y, c));
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

void Floor::generate() {
    int numChambers = chambers.size();
    // generate player location
    int random1 = rand() % numChambers; // 0 to numChambers - 1
    int numTilesInChamber = chambers[random1].size();
    int random2 = rand() % numTilesInChamber; // to numTilesInChamber - 1
    int x = chambers[random1][random2].x;
    int y = chambers[random1][random2].y;
    content[x][y].setPC(p);
    // chambers[random1][random2] would be the posn that we spawn the character in

    // spawn the stair
    int random3 = rand() % numChambers;
    // ensure that stair chamber and player chamber are not the same
    while (random3 != random1) {
        random3 = rand() % numChambers;
    }
    numTilesInChamber = chambers[random3].size();
    int random4 = rand() % numTilesInChamber;
    int x = chambers[random3][random4].x;
    int y = chambers[random3][random4].y;    
    // chambers[random3][random4]  would be the posn that we spawn the stair in

}