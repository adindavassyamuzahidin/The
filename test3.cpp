#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

struct entitas {
	int x,y;
	char simbol;
	bool bawakunci;
};
const int Max_Y=100;
const int Max_X=100;
char peta[Max_X][Max_Y];
int X = 0, Y = 0;



void bacaFilePeta(string namaFile,entitas &player,entitas &anomali){
 ifstream file(namaFile.c_str());
    if (!file.is_open()) {
        cout << "Error: File " << namaFile << " tidak ditemukan!" << endl;
        exit(1);
    }
    string line;
    while (getline(file, line)&&X<Max_X){
    	for(int i=0;i<line.length()&&Y<Max_Y;i++){
    		peta[X][i]=line[i];
    		if (peta[X][i]== 'R' || peta[X][i]== 'S' || peta[X][i]== 'T') {
                peta[X][i] = ' ';
            }
    		 if (peta[X][i] == 'O') {
                player.x = i;
                player.y = X;
                peta[X][i]= ' ';
            }else if (peta[X][i] == 'A') {
			    anomali.x = i;
                anomali.y = X;
                peta[X][i]= ' ';
			}
		}
		if (line.length()>Y)
		Y=line.length();
		X++;
	}
    file.close();
}

void tampilkanPeta(entitas player,entitas anomali) {
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
        	if (i==player.y && j==player.x){
        		cout<<player.simbol;
        		}else if (i==anomali.y && j==anomali.x) {
                cout << anomali.simbol;
            } else {
        	cout << peta[i][j];
            }
		}
        cout<<endl;
    }
}
        
void gerakanplayer(entitas &player,entitas &anomali,bool &game_berjalan, bool &menang, char input){
	int dx=0,dy=0;
	switch (input){
		case 'w': case 'W': dy=-1;break;
		case 's': case 'S': dy=1;break;
		case 'a': case 'A': dx=-2;break;
		case 'd': case 'D': dx=2;break;
	}
	int Xsetelah=player.x+dx;
	int Ysetelah=player.y+dy;
	if (peta[Ysetelah][Xsetelah]== '+'||peta[Ysetelah][Xsetelah]=='-'||peta[Ysetelah][Xsetelah]=='|'){
		return;
	}
	char pemain=peta[Ysetelah][Xsetelah];
	if (pemain=='K'){
		player.bawakunci=true;
		peta[Ysetelah][Xsetelah]= ' ';
	}
	if (pemain=='E'){
		if(player.bawakunci){
			menang=true;
			game_berjalan=false;
		}
	}
	if (Xsetelah == anomali.x && Ysetelah == anomali.y) {
        game_berjalan = false;
        menang = false;
    }
	player.x=Xsetelah;
	player.y=Ysetelah;
}

    int main(){
    	char input;
    	entitas player = {0, 0, 'O', false};
    	entitas anomali = {0, 0, 'A', false}; 
    	bacaFilePeta("Level3.txt",player,anomali);
    	bool game_berjalan = true;
    	bool menang = false;
    	tampilkanPeta(player,anomali);
    	
    	while (game_berjalan) {
    	system("cls");
        tampilkanPeta(player, anomali);
        input=_getch(); 
        gerakanplayer(player, anomali, game_berjalan, menang, input);
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
