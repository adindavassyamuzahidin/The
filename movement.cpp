//WASD, MOVEMENT

#include <iostream>
#include <ncurses.h>
#include <unistd.h>
using namespace std;

// ------------------ DATA LABIRIN ------------------

// Peta labirin (HARUS ada array "line" dari level)
extern char line[10][40];  

int curline = 1;  // baris pemain
int posisi = 0;   // kolom pemain
int skor = 0;

// KOORDINAT FINISH (flexible)
int finishRow = 5;
int finishCol = 28;

// ------------------ FUNCTION PROTOTYPE ------------------
void board();
void atas();
void bawah();
void kiri();
void kanan();
void finishCheck();

// ------------------ FUNCTION ------------------
void board(){
    clear();
    mvprintw(0,0,"   +-----------------------------+--------------+");
    mvprintw(1,0,"   |   L A B I R I N   G A M E   |  SKOR : %d  |", skor);
    mvprintw(2,0,"   +-----------------------------+--------------+");
    mvprintw(3,0,"   |                                            |");

    for(int i=0;i<7;i++){
        if(i==1)
            mvprintw(4+i,0,"   | START %s          |", line[i]);
        else if(i==5)
            mvprintw(4+i,0,"   |       %s FINISH |", line[i]);
        else
            mvprintw(4+i,0,"   |       %s          |", line[i]);
    }

    mvprintw(11,0,"   |                                            |");
    mvprintw(12,0,"   +-----------------------------+--------------+");
    mvprintw(14,0,"          ^   W - atas");
    mvprintw(15,0,"         < A |   | D > - kiri/kanan");
    mvprintw(16,0,"          v   S - bawah");
    refresh();
}

// GERAK KE ATAS
void atas(Player &p, char map[][40]) {
    // validasi tembok: hanya boleh pindah ke spasi
    if (p.row > 0 && map[p.row - 1][p.col] == ' ') {
        map[p.row][p.col] = ' ';
        p.row--;
        map[p.row][p.col] = 'O';
    }
}

// GERAK KE BAWAH
void bawah(Player &p, char map[][40]) {
    if (map[p.row + 1][p.col] == ' ') {
        map[p.row][p.col] = ' ';
        p.row++;
        map[p.row][p.col] = 'O';
    }
}

// GERAK KE KIRI
void kiri(Player &p, char map[][40]) {
    // karena ASCII map, gerak 2 kolom
    if (p.col - 2 >= 0 && map[p.row][p.col - 2] == ' ') {
        map[p.row][p.col] = ' ';
        p.col -= 2;
        map[p.row][p.col] = 'O';
    }
}

// GERAK KE KANAN
void kanan(Player &p, char map[][40]) {
    if (map[p.row][p.col + 2] == ' ') {
        map[p.row][p.col] = ' ';
        p.col += 2;
        map[p.row][p.col] = 'O';
    }
}


// ------------------ FINISH CHECK (SUDAH FLEX) ------------------
void finishCheck(){
    if(curline == finishRow && posisi == finishCol){
        line[curline][posisi]=' ';
        curline = 1;
        posisi = 0;
        line[curline][posisi] = 'O';

        skor += 10;
        if(skor >= 1000) skor = 0;

        mvprintw(18,0,"SELAMAT ANDA BERHASIL!");
        refresh();
        usleep(1000000);
    }
}

// ------------------ MAIN ------------------
int main(){
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0); // sembunyikan kursor

    line[curline][posisi]='O';
    int ch;

    while(true){
        board();
        finishCheck();

        ch = getch(); // menunggu user input
        switch(ch){
            case 'w':
            case 'W': atas(); break;
            case 'a':
            case 'A': kiri(); break;
            case 's':
            case 'S': bawah(); break;
            case 'd':
            case 'D': kanan(); break;
            case 'q':
            case 'Q': finishCheck(); return 0;
            default: break; 
        }
    }
}