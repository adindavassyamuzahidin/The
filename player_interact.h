#ifndef PLAYER_INTERACTION_H
#define PLAYER_INTERACTION_H

struct Player {
    int row;
    int col;
    int startRow;
    int startCol;
    int life;
    bool hasKey;
};

struct KeyItem {
    int row;
    int col;
    bool taken;
};

struct Finish {
    int row;
    int col;
};

struct Anomaly {
    int row;
    int col;
};

// ================ PROTOTYPE =================
bool checkKeyPickup(Player& p, KeyItem& key);
bool checkFinish(const Player& p, const Finish& f);
bool checkAnomaly(Player& p, const Anomaly& a);

#endif
