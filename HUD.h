#ifndef HUD_H
#define HUD_H

#include <ncurses.h>
#include "player.h"

struct HUD {
    int lives;        // jumlah nyawa pemain
    int level;        // level sekarang
    int timeLeft;     // waktu tersisa (detik)
};

void drawHUD(const Player& p, const HUD& hud);
bool checkGameOver(const HUD& hud);
void updateTimer(HUD& hud, int delta);

#endif
