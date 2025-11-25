#include "player_interaction.h"

// ------------------ AMBIL KUNCI ------------------
bool checkKeyPickup(Player& p, KeyItem& key) {
    if (!key.taken && p.row == key.row && p.col == key.col) {
        key.taken = true;
        p.hasKey = true;
        return true;   // berhasil ambil kunci
    }
    return false;
}

// ------------------ CEK FINISH -------------------
bool checkFinish(const Player& p, const Finish& f) {
    return (p.row == f.row && p.col == f.col);
}

// ------------------ CEK ANOMALI (MONSTER) ------------------
bool checkAnomaly(Player& p, const Anomaly& a) {
    if (p.row == a.row && p.col == a.col) {

        // nyawa berkurang
        p.life--;

        // reset ke start level
        p.row = p.startRow;
        p.col = p.startCol;

        // reset kunci
        p.hasKey = false;

        return true;   // ketangkap anomali
    }
    return false;
}
  