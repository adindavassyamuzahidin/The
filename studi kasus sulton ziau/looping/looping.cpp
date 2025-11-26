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




    menu:{
    system("clear");
    waktu timer;
    bool menang=false;
    char milih,n,milihdeui;
    int s;
    cout << "=================THE LOST PATH=============="<<endl;
    cout << "1. Main yuk!"<<endl;
    cout << "2. Atau mau keluar?"<<endl;
    milih = getch();
    switch(milih){
        case '1':{
        cout << "mau pilih level berapa, ganteng? ^U^"<<endl;
        cout << "1.Level 1"<<endl;
        cout << "2.Level 2"<<endl;
        cout << "3.Level 3"<<endl;
        milihdeui=getch();
        switch(milihdeui){
            case '1':{
            hiji:
            system("clear");
                {cout << "Selamat menjalankan tutorial"<<"                          "<<"Menang?[3]"<<endl;
                waktu timer;
    timer.detik=0;
    timer.menit=1;
    do{
        cout << "\r"<< timer.menit << ":" << setfill('0') << setw(2) << timer.detik << flush;
        if (kbhit()) {           // Cek: Ada tombol dipencet gak?
                    char tombol = getch(); // Ambil tombolnya
                    if (tombol == '3') {
                        menang=true;
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
        cout << "Ngulang[1]?" << endl;
        cout << "Lanjut?[2]?" << endl;
        cout << "Pulang[3]?" << endl;
        char p = getch();
        if(p=='u'){
            goto hiji;
        }else if(p=='i'){
            goto dua;
        }else if(p=='o'){
            goto menu;
        }
        getch();
                    }
                }
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
        cout << "ke mau ngulang ora?[2]"<<endl;
        n=getch();
        if(n=='1'){
            goto menu;
        }
        if(n=='2'){
            goto hiji;
        }
                }}
        case '2':{dua:
            system("clear");
                {cout << "Selamat menjalankan level 2"<<"                          "<<"Menang?[3]"<<endl;
                waktu timer2;
    timer2.detik=0;
    timer2.menit=3;
    do{
        cout << "\r"<< timer2.menit << ":" << setfill('0') << setw(2) << timer2.detik << flush;
        if (kbhit()) {
                    char tombol = getch();
                    if (tombol == '3') {
                        menang=true;
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
        cout << "Ngulang[1]?" << endl;
        cout << "Lanjut?[2]?" << endl;
        cout << "Pulang[3]?" << endl;
        char p = getch();
        if(p=='u'){
            goto dua;
        }else if(p=='i'){
            goto tilu;
        }else if(p=='o'){
            goto menu;
        }
        getch();
                    }
                }
        timer2.detik-= 1;
        sleep_for(seconds(1));
        if(timer2.detik<0){
            if(timer2.menit==0)break;
            timer2.menit--;
            timer2.detik=59;
        }
      }while(timer2.menit >=0);
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
        cout << "ke mau ngulang ora?[2]"<<endl;
        n=getch();
        if(n=='1'){
            goto menu;
        }
        if(n=='2'){
            goto hiji;
        }
                }}
            case '3':{tilu:
            system("clear");
                {cout << "Selamat menjalankan level 3"<<"                          "<<"Menang?[3]"<<endl;
                waktu timer3;
    timer3.detik=0;
    timer3.menit=5;
    do{
        cout << "\r"<< timer3.menit << ":" << setfill('0') << setw(2) << timer3.detik << flush;
        if (kbhit()) {
                    char tombol = getch();
                    if (tombol == '3') {
                        menang=true;
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
        cout << "Ngulang[1]?" << endl;
        cout << "Lanjut?[2]?" << endl;
        cout << "Pulang[3]?" << endl;
        char p = getch();
        if(p=='u'){
            goto tilu;
        }else if(p=='i'){

        }else if(p=='o'){
            goto menu;
        }
        getch();
                    }
                }
        timer3.detik-= 1;
        sleep_for(seconds(1));
        if(timer3.detik<0){
            if(timer3.menit==0)break;
            timer3.menit--;
            timer3.detik=59;
        }
      }while(timer3.menit >=0);
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
        cout << "ke mau ngulang ora?[2]"<<endl;
        n=getch();
        if(n=='1'){
            goto menu;
        }
        if(n=='2'){
            goto tilu;
        }
                }}
        }}
        break;
        case '2':{
        cout << "okehh, good byee" << endl;
        return 0;
        break;}
        }
    }
}
