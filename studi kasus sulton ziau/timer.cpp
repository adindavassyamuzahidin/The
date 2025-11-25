#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

struct waktu{
    int detik=0;
    int menit=5;
};
int main()
{
    waktu timer;
    timer.detik=59;
    timer.menit=4;
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
    return 0;
}