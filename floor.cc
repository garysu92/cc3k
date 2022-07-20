#include <vector>
#include <stack>
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

Floor::Floor(vector<vector<char>> v, PlayableCharacter *p): p{p}, content{}, chambers{}, chamberMap{} {
    int row = v.size();
    int col = v[0].size();
    for (int i = 0; i < row; i++) {
        content.emplace_back();
        chamberMap.emplace_back();
        for (int j = 0; j < col; j++) {
            char c = v[i][j];
            chamberMap[i].emplace_back(0);
            if (c == '|' || c == '-') content[i].emplace_back(Wall(col, row, c));
            else if (c == '#') content[i].emplace_back(Passage(col, row, c));
            else if (c == '+') content[i].emplace_back(Door(col, row, c));
            else if (c == '.') content[i].emplace_back(Tile(col, row, c));
            else content[i].emplace_back(Space(col, row, c));
        }
    }
    // make a temp 2D array that stores the positions of floors in chambers that are already visited
    int temp[row][col] = {0};
    for (int i = 1; i < row - 1; i++) {
        for (int j = 1; j < col - 1; j++) {
            if (v[i][j] == '.') {
                // check neighbours
                // bool newChamber = true;
                for (int a = -1; a <= 1; a++) {
                    for (int b = -1; b <= 1; b++) {
                        // if neighbour is found to already be in chamber
                        if (!(b == 0 && a == 0) && temp[i + a][j + b] != 0) {
                            chambers[temp[i + a][j + b] - 1].emplace_back(i, j);
                            temp[i][j] = temp[i + a][j + b];
                            // newChamber = false;
                            goto label;
                        }
                    }
                }
                //if (newChamber) {
                // all neighbours are not in a chamber (yet?)
                chambers.emplace_back();
                chambers[chambers.size() - 1].emplace_back(i, j);
                temp[i][j] = chambers.size();
                //}
            }
            label:
        }
    }

    // vector<vector<bool>> isVisited(row, vector<bool>(col, false)); // initializes 2d isvisited array all false
    // int chamberCount = 0;
    // for (int i = 1; i < row - 1; ++i) {
    //     for (int j = 1; j < col - 1; ++j) {
    //         if (!isVisited[i][j] && v[i][j] == '.') {
    //             // new chamber
    //             chamberCount++;
    //             chamberMap[i][j] = chamberCount;
    //             chambers.emplace_back();
    //             chambers[chamberCount - 1].emplace_back(j, i);

    //             isVisited[i][j] = true;
    //             stack<Posn> next{};
    //             next.emplace(j, i);
    //             while (!next.empty()) {
    //                 Posn tempP = next.top();
    //                 next.pop();
    //                 for (int a = -1; a <= 1; a++) {
    //                     for (int b = -1; b <= 1; b++) {
    //                         if (!isVisited[i][j] && v[i][j] == '.') {
    //                             isVisited[i][j] = true;
    //                             chambers[chamberCount - 1].emplace_back(j, i);
    //                             chamberMap[i][j] = chamberCount;
    //                             next.emplace(j,i);
    //                         } else if (!isVisited[i][j]) {
    //                             isVisited[i][j] = true;
    //                         }
    //                     }
    //                 }
    //             }
    //         } else if (!isVisited[i][j]) {
    //             isVisited[i][j] = true;
    //         }
    //     }
    // }
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
