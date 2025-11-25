#include "HUD.h"
#include <ncurses.h>

// ============ DRAW HUD ============
// Menampilkan nyawa, level, status kunci, timer
void drawHUD(const Player& p, const HUD& hud) {
    mvprintw(0, 0, "Level: %d", hud.level);
    mvprintw(1, 0, "Nyawa : %d", hud.lives);
    mvprintw(2, 0, "Kunci : %s", p.hasKey ? "✔ DIPEGANG" : "✘ BELUM");
    mvprintw(3, 0, "Waktu : %d detik", hud.timeLeft);
}

// ============ TIMER UPDATE ============
void updateTimer(HUD& hud, int delta) {
    hud.timeLeft -= delta;
    if (hud.timeLeft < 0) {
        hud.timeLeft = 0;
    }
}

// ============ GAME OVER CHECK ============
bool checkGameOver(const HUD& hud) {
    return (hud.lives <= 0 || hud.timeLeft <= 0);
}
