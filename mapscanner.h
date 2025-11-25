#ifndef MAP_SCANNER_H
#define MAP_SCANNER_H

#include "player.h"

struct KeyItem {
    int row, col;
    bool taken;
};

struct Anomaly {
    int row, col;
};

struct Finish {
    int row, col;
};

void scanMapPositions(char map[][40], int rows,
                      Player &player, KeyItem &key,
                      Anomaly &anom, Finish &fin);

#endif
