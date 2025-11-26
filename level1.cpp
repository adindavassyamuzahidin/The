#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

long long currentTime(){
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

struct position{
    int y, x;
};

//struct entitas (player dan objek game)
struct entitas {
    int x, y;
    string simbol;
    bool bawakunci;
};

//struct anomali dengan patrol route
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
const int MAX_ANOMALI = 10;

char map[Max_X][Max_Y];
int X = 0;
int Y = 0;

int hitungRoute(position route[], int index, int size){
    if (index == size) return 0;
    return 1 + hitungRoute(route, index + 1, size);
}

//fungsi untuk menginisialisasi anomali
void initiateAnomali(anomali &a, 
    position route[], int routeSize, 
    long long speed, string symbol){
    a.routeSize = hitungRoute(route, 0, routeSize);

    for (int i = 0; i < routeSize; i++){
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


//fungsi untuk menggerakkan anomali
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

//fungsi membaca file map
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
            /*if (map[X][i] == 'O') {
                player.x = i;
                player.y = X;
                map[X][i] = ' ';
            } else if (map[X][i] == 'A') {
                map[X][i] = ' ';
            }*/
        }
        if (line.length() > Y) {
            Y = line.length();
        }
        X++;
    }
    file.close();
}

//fungsi menampilkan map dengan multiple anomali
void tampilkanmap(entitas player, anomali anomaliList[], int jumlahAnomali) {
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            bool anomaliDitemukan = false;
            
            //cek apakah ada anomali di posisi ini
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

//fungsi cek collision dengan semua anomali
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

//fungsi gerakan player
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
    
    //cek tabrakan dengan setiap anomali
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

//fungsi menampilkan HUD
void tampilkanHUD(int nyawa, bool bawakunci, entitas player) {
    cout << "   +-----------------------------+--------------+\n";
    cout << "   | ESCAPE FROM CALCULUS |  NYAWA : ";
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
    
    //array anomali
    anomali anomaliList[0];
    int jumlahAnomali = 0;
    
    bacaFilemap("level1.txt", player);

    bool game_berjalan = true;
    bool menang = false;

    while (game_berjalan) {
        system("cls");    
        
        //cek collision dengan semua anomali setelah mereka bergerak
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
