#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <iomanip>
#include <conio.h>
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;


struct waktu{
    int detik=0;
    int menit=5;
};
int main(){
    
    int milih;
    int milihdeui;
    int n;
    waktu timer;
    menu:
    system("clear");
    cout << "=================THE LOST PATH=============="<<endl;
    cout << "1. Main yuk!"<<endl;
    cout << "2. Atau mau keluar?"<<endl;
    cout << "3. Perform game over screen"<<endl;
    cout << "4. Perform selebrasi kemenangan"<<endl;
    cin>>milih;
    switch(milih){
        case 1:
        cout << "mau pilih level berapa, ganteng? ^U^"<<endl;
        cout << "1.Level 1"<<endl;
        cout << "2.Level 2"<<endl;
        cout << "3.Level 3"<<endl;
        cin>>milihdeui;
        switch(milihdeui){
            case 1:
                {cout << "Selamat menjalankan tutorial"<<endl;
                waktu timer;
    timer.detik=10;
    timer.menit=0;
    do{
        cout << "\r"<< timer.menit << ":" << setfill('0') << setw(2) << timer.detik << flush;
        timer.detik-= 1;
        sleep_for(seconds(1));
        if(timer.detik<0){
            if(timer.menit==0)break;
            timer.menit--;
            timer.detik=59;
        }
      }while(timer.menit >=0);
    cout << "Waktu habis!" << endl;
    system("clear");
        cout << "oooooooooooo oooooooo oooooooooo oooooooo" << endl;
        cout << "oooooooooooo oo    oo oooooooooo oooooooo" << endl;
        cout << "ooo      ooo       oo oo  oo  oo oo    oo" << endl;
        cout << "ooo      ooo oooooooo oo  oo  oo oo    oo" << endl;
        cout << "oooooooooooo oooooooo oo  oo  oo oooooooo" << endl;
        cout << "oooooooooooo oo    oo oo  oo  oo oooooooo" << endl;
        cout << "         ooo oo    oo oo  oo  oo oo      " << endl;
        cout << "         ooo oo    oo oo  oo  oo oo    oo" << endl;
        cout << "oo       ooo oooooooo oo  oo  oo oo    oo" << endl;
        cout << "oooooooooooo oooooooo oo  oo  oo oooooooo" << endl;
        cout << "                                         " << endl;
        cout << "oooooooooooo oooooooo oooooooooo oooooooo" << endl;
        cout << "                                         " << endl;
        cout << "oooooooooooo o      o oooooooooo ooooooo " << endl;
        cout << "ooo      ooo o      o oo      oo oo    oo" << endl;
        cout << "ooo      ooo o      o oo      oo oo    oo" << endl;
        cout << "oo       ooo o      o oooooooooo oooooooo" << endl;
        cout << "oo       ooo o      o oooo       ooooooo " << endl;
        cout << "oo       ooo oo    oo oo         oo    o " << endl;
        cout << "oo       ooo  oo  oo  oo         o     oo" << endl;
        cout << "oo       ooo   oooo   oo      oo o      o" << endl;
        cout << "oooooooooooo    oo    oooooooooo o       o" << endl;
        cout << "ke main menu?[1]"<<endl;
        cin >> n;
        if(n==1){
            goto menu;
        }
                };
        case 2:
            cout << "Selamat memulai permainan!"<<endl;
             break;
            case 3:
            cout << "Selamat Berjuang!!! Sukses!!!! *tepuk tangan*"<<endl;
            break;
        }
        break;
        case 2:
        cout << "okehh, good byee" << endl;
        break;
        case 3:
        system("clear");
        cout << "oooooooooooo oooooooo oooooooooo oooooooo" << endl;
        cout << "oooooooooooo oo    oo oooooooooo oooooooo" << endl;
        cout << "ooo      ooo       oo oo  oo  oo oo    oo" << endl;
        cout << "ooo      ooo oooooooo oo  oo  oo oo    oo" << endl;
        cout << "oooooooooooo oooooooo oo  oo  oo oooooooo" << endl;
        cout << "oooooooooooo oo    oo oo  oo  oo oooooooo" << endl;
        cout << "         ooo oo    oo oo  oo  oo oo      " << endl;
        cout << "         ooo oo    oo oo  oo  oo oo    oo" << endl;
        cout << "oo       ooo oooooooo oo  oo  oo oo    oo" << endl;
        cout << "oooooooooooo oooooooo oo  oo  oo oooooooo" << endl;
        cout << "                                         " << endl;
        cout << "oooooooooooo oooooooo oooooooooo oooooooo" << endl;
        cout << "                                         " << endl;
        cout << "oooooooooooo o      o oooooooooo ooooooo " << endl;
        cout << "ooo      ooo o      o oo      oo oo    oo" << endl;
        cout << "ooo      ooo o      o oo      oo oo    oo" << endl;
        cout << "oo       ooo o      o oooooooooo oooooooo" << endl;
        cout << "oo       ooo o      o oooo       ooooooo " << endl;
        cout << "oo       ooo oo    oo oo         oo    o " << endl;
        cout << "oo       ooo  oo  oo  oo         o     oo" << endl;
        cout << "oo       ooo   oooo   oo      oo o      o" << endl;
        cout << "oooooooooooo    oo    oooooooooo o       o" << endl;
        break;
        case 4:
        system("clear");
        cout << "ooooooooooo    oooo       ooo      oooooooo" << endl;
        cout << "oooooooooooo oo    oo     ooo      oooooooo" << endl;
        cout << "oo        oo o      oo    ooo      o      oo" << endl;
        cout << "oo        oo o      ooo oooooooooo o      oo" << endl;
        cout << "oooooooooooo o      ooo oooooooooo oooooooo" << endl;
        cout << "ooooooooooo  o      ooo   ooo      o       " << endl;
        cout << "oo           o      ooo   ooo      oo      " << endl;
        cout << "o            o      ooo   ooo      oo     o" << endl;
        cout << "oo         o o      ooo    ooooo   o      o" << endl;
        cout << " oooooooooo  o      ooo     oooooo  ooooooo" << endl;
        cout << "                                         " << endl;
        cout << " o      oo      o ooo   oooooo         o    " << endl;
        cout << " oo    oooo    oo ooo  ooooooooo      ooo     " << endl;
        cout << " oo   oooooo   oo      oo      oo    ooooo       " << endl;
        cout << " oo   oooooo   oo ooo  oo       oo    ooo        " << endl;
        cout << " ooo  oooooo  ooo ooo  oo       oo    ooo           " << endl;
        cout << " oooooooooooooooo ooo  oo       oo    ooo           " << endl;
        cout << "  oooooooooooooo  ooo  oo       oo              " << endl;
        cout << "                                      ooo       " << endl;
        cout << "                                     ooooo       " << endl;
        cout << "                                      ooo      " << endl;
        cout << "                                            " << endl;
        cout << "MAHKOTAMU SEDANG DIPOLES KING! " << endl;
        cout << "ooooooooooooooooooooooooooooooooooooooooo" << endl;
        break;
    }
}