#ifndef MOVEMENT_H
#define MOVEMENT_H

struct Player {
    int row;
    int col;
};

void atas(Player &p, char map[][40]);
void bawah(Player &p, char map[][40]);
void kiri(Player &p, char map[][40]);
void kanan(Player &p, char map[][40]);

#endif
