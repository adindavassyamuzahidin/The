#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

long long currentTime(){
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}
struct position{
    int row, col;
};

struct anomali{
    position pos;
    bool active;

    position route[200];   
    int routeSize;
    int routeIndex;
    bool move;

    long long lastMoveTime;
    long long speed;
    
    char anomaliSymbol;
};

void initiateAnomali(anomali &a, position route[], int routeSize, long long speed, char symbol){
    a.routeSize = routeSize;
    for (int i = 0; i < routeSize;i++) a.route[i] = route[i];
    
    a.pos.row = route[0].row;
    a.pos.col = route[0].col;

    a.routeIndex = 0;
    a.move = true;

    a.lastMoveTime = currentTime();
    a.speed = speed;
    a.anomaliSymbol = symbol;
    a.active = true;
}

void moveAnomali(anomali &a, long long currentTime){
    if (!a.active) return;

    long long deltaT = currentTime - a.lastMoveTime;
    if (deltaT < a.speed) return;

    if (a.move == true){
        a.routeIndex++;
        if (a.routeIndex == a.routeSize - 1) a.move = false;
    } else {
        a.routeIndex--;
        if (a.routeIndex == 0) a.move = true;
    }
    a.pos.row = a.route[a.routeIndex].row;
    a.pos.col = a.route[a.routeIndex].col;

    a.lastMoveTime = currentTime;
}

int main(){
    long long speed = 500;
    char anomaliSymbol = '∫';
}