#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Fungsi untuk mendapatkan waktu saat ini dalam milidetik
long long currentTime(){
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

// Struktur untuk posisi
struct position{
    int y, x;
};

// Struktur entitas (player dan objek game)
struct entitas {
    int x, y;
    string simbol;
    bool bawakunci;
};

// Struktur anomali dengan patrol route
struct anomali{
    int x, y;
    bool active;

    position route[200];   
    int routeSize;
    int routeIndex;
    bool move;

    long long lastMoveTime;
    long long speed;
    
    string anomaliSymbol;
};

const int Max_Y = 100;
const int Max_X = 100;
const int MAX_ANOMALI = 10; // Maksimum jumlah anomali

char map[Max_X][Max_Y];
int X = 0;
int Y = 0;

// Fungsi untuk menginisialisasi anomali
void initiateAnomali(anomali &a, position route[], int routeSize, long long speed, string symbol){
    a.routeSize = routeSize;
    for (int i = 0; i < routeSize; i++) {
        a.route[i] = route[i];
    }
    
    a.y = route[0].y;
    a.x = route[0].x;

    a.routeIndex = 0;
    a.move = true;

    a.lastMoveTime = currentTime();
    a.speed = speed;
    a.anomaliSymbol = symbol;
    a.active = true;
}

// Fungsi untuk menggerakkan anomali
void moveAnomali(anomali &a, long long currentT){
    if (!a.active) return;

    long long deltaT = currentT - a.lastMoveTime;
    if (deltaT < a.speed) return;

    if (a.move == true){
        a.routeIndex++;
        if (a.routeIndex == a.routeSize - 1) {
            a.move = false;
        }
    } else {
        a.routeIndex--;
        if (a.routeIndex == 0) {
            a.move = true;
        }
    }
    a.y = a.route[a.routeIndex].y;
    a.x = a.route[a.routeIndex].x;

    a.lastMoveTime = currentT;
}

// Fungsi membaca file map
void bacaFilemap(string namaFile, entitas &player){
    ifstream file(namaFile.c_str());
    if (!file.is_open()) {
        cout << "Error: File " << namaFile << " tidak ditemukan!" << endl;
        exit(1);
    }
    string line;
    while (getline(file, line) && X < Max_X){
        for(int i = 0; i < line.length() && i < Max_Y; i++){
            map[X][i] = line[i];
            if (map[X][i] == 'R' || map[X][i] == 'S' || map[X][i] == 'T') {
                map[X][i] = ' ';
            }
            if (map[X][i] == 'O') {
                player.x = i;
                player.y = X;
                map[X][i] = ' ';
            } else if (map[X][i] == 'A') {
                // Hapus marker anomali dari map
                map[X][i] = ' ';
            }
        }
        if (line.length() > Y) {
            Y = line.length();
        }
        X++;
    }
    file.close();
}

// Fungsi menampilkan map dengan multiple anomali
void tampilkanmap(entitas player, anomali anomaliList[], int jumlahAnomali) {
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            bool anomaliDitemukan = false;
            
            // Cek apakah ada anomali di posisi ini
            for (int k = 0; k < jumlahAnomali; k++) {
                if (anomaliList[k].active && i == anomaliList[k].y && j == anomaliList[k].x) {
                    cout << anomaliList[k].anomaliSymbol;
                    anomaliDitemukan = true;
                    break;
                }
            }
            
            if (!anomaliDitemukan) {
                if (i == player.y && j == player.x){
                    cout << player.simbol;
                } else {
                    cout << map[i][j];
                }
            }
        }
        cout << endl;
    }
}

// Fungsi cek collision dengan semua anomali
bool cekCollisionAnomali(entitas &player, anomali anomaliList[], int jumlahAnomali, int &nyawa, bool &game_berjalan, bool &menang){
    for (int i = 0; i < jumlahAnomali; i++) {
        if (anomaliList[i].active && player.x == anomaliList[i].x && player.y == anomaliList[i].y) {
            nyawa--;
            if (nyawa > 0){
                player.x = 0;
                player.y = 1;
                return true;
            } else {
                game_berjalan = false;
                menang = false;
                return true;
            }
        }
    }
    return false;
}

// Fungsi gerakan player
void gerakanplayer(entitas &player, anomali anomaliList[], int jumlahAnomali, bool &game_berjalan, bool &menang, int &nyawa, char input){
    int dx = 0;
    int dy = 0;
    
    switch (input){
        case 'w': 
        case 'W': 
            dy = -1; 
            break;
        case 's': 
        case 'S': 
            dy = 1; 
            break;
        case 'a': 
        case 'A': 
            dx = -2; 
            break;
        case 'd': 
        case 'D': 
            dx = 2; 
            break;
    }
    
    int Xsetelah = player.x + dx;
    int Ysetelah = player.y + dy;
    
    if (map[Ysetelah][Xsetelah] == '+' || map[Ysetelah][Xsetelah] == '-' || map[Ysetelah][Xsetelah] == '|'){
        return;
    }
    
    char pemain = map[Ysetelah][Xsetelah];
    if (pemain == 'K'){
        player.bawakunci = true;
        map[Ysetelah][Xsetelah] = ' ';
    }
    if (pemain == 'E'){
        if(player.bawakunci){
            menang = true;
            game_berjalan = false;
        }
    }
    
    // Cek tabrakan dengan semua anomali
    for (int i = 0; i < jumlahAnomali; i++) {
        if (Xsetelah == anomaliList[i].x && Ysetelah == anomaliList[i].y) {
            nyawa--;
            if (nyawa > 0){
                player.x = 0;
                player.y = 1;
                return;
            } else {
                game_berjalan = false;
                menang = false;    
                return;
            }    
        }
    }
    
    player.x = Xsetelah;
    player.y = Ysetelah;
}

// Fungsi menampilkan HUD
void tampilkanHUD(int nyawa, bool bawakunci, entitas player) {
    cout << "   +-----------------------------+--------------+\n";
    cout << "   |     L A B I R I N   G A M E |  NYAWA : ";
    cout << nyawa;
    cout << "  |\n";
    cout << "   +-----------------------------+--------------+\n";
    cout << "   | KUNCI : " 
         << (bawakunci ? "V" : "X")
         << "   | POS : (" << player.x << ", " << player.y << ")";
    
    int panjang = 12 + (bawakunci ? 1 : 1) + 12;
    for (int i = panjang; i < 43; i++) {
        cout << " ";
    }
    
    cout << "|\n";
    cout << "   +-------------------------------------------+\n\n";
}

int main(){
    char input;
    entitas player;
    player.x = 2;
    player.y = 1;
    player.simbol = 'O';
    player.bawakunci = false;
    
    int nyawa = 2;

    // Setup routes untuk 3 anomali
    position routeA1[] = {
        {5,54}, {5,52}, {5,50}, {5,48}, {5,46}, {5,44}, {5,42}, {5,40}, 
        {5,38}, {5,36}, {5,34}, {6,34}, {7,34}, {7,32}, {7,30}, {8,30}, 
        {9,30}, {9,28}, {9,26}, {9,24}, {9,22}, {10,22}, {11,22}, {12,22}, 
        {13,22}, {13,20}, {13,18}, {14,18}, {15,18}, {15,16}, {15,14}, {14,14}, 
        {13,14}, {13,12}, {13,10}, {12,10}, {11,10}, {11,12}, {11,14}, {11,16}, 
        {11,18}, {10,18}, {9,18}, {8,18}, {7,18}, {7,16}, {7,14}, {8,14}, 
        {9,14}, {9,12}, {9,10}, {8,10}, {7,10}, {7,8}, {7,6}
    };

    position routeA2[] = {
        {27,62}, {27,60}, {27,58}, {27,56}, {27,54}, {27,52}, {27,50}, {26,50},
        {25,50}, {24,50}, {23,50}, {23,52}, {23,54}, {24,54}, {25,54}, {25,56},
        {25,58}, {25,60}, {25,62}, {25,64}, {25,66}, {24,66}, {23,66}, {23,64},
        {23,62}, {23,60}, {23,58}, {22,58}, {21,58}, {21,56}, {21,54}, {21,52},
        {21,50}, {21,48}, {21,46}, {22,46}, {23,46}, {23,44}, {23,42}, {23,40},
        {23,38}, {23,36}, {23,34}
    };

    position routeA3[] = {
        {25,30}, {26,30}, {27,30}, {28,30}, {29,30}, {29,28}, {29,26}, {29,24},
        {29,22}, {29,20}, {29,18}, {28,18}, {27,18}, {27,20}, {27,22}, {27,24},
        {27,26}, {26,26}, {25,26}, {24,26}, {23,26}, {23,24}, {23,22}, {23,20},
        {23,18}
    };

    // Array anomali
    anomali anomaliList[3];
    int jumlahAnomali = 3;
    
    // Inisialisasi setiap anomali dengan route dan kecepatan berbeda
    initiateAnomali(anomaliList[0], routeA1, sizeof(routeA1)/sizeof(routeA1[0]), 100, u8"∫");
    initiateAnomali(anomaliList[1], routeA2, sizeof(routeA2)/sizeof(routeA2[0]), 500, u8"∫");
    initiateAnomali(anomaliList[2], routeA3, sizeof(routeA3)/sizeof(routeA3[0]), 450, u8"∫");

    bacaFilemap("Level3.txt", player);

    bool game_berjalan = true;
    bool menang = false;

    while (game_berjalan) {
        system("cls");
        
        // Update posisi semua anomali berdasarkan waktu
        for (int i = 0; i < jumlahAnomali; i++) {
            moveAnomali(anomaliList[i], currentTime());
        }
        
        // Cek collision dengan semua anomali setelah mereka bergerak
        cekCollisionAnomali(player, anomaliList, jumlahAnomali, nyawa, game_berjalan, menang);
        
        tampilkanmap(player, anomaliList, jumlahAnomali);
        tampilkanHUD(nyawa, player.bawakunci, player);
        
        input = _getch();
        gerakanplayer(player, anomaliList, jumlahAnomali, game_berjalan, menang, nyawa, input);
    }
    
    system("cls");
    if (menang) {
        cout << "\n==================================\n";
        cout << " SELAMAT! KAMU BERHASIL KELUAR! \n";
        cout << "==================================\n";
    } else {
        cout << "\n==================================\n";
        cout << " GAME OVER! KAMU TERTANGKAP ANOMALI \n";
        cout << "==================================\n";
    }
    return 0;
}
