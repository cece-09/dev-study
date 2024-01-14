#include <string>
#include <iostream>

using namespace std;

class Photon_Cannon {
    int hp, shield;
    int coord_x, coord_y;
    int damage;

    public:
        Photon_Cannon(int x, int y);
        Photon_Cannon(const Photon_Cannon& pc);
        
        void show_status();
};

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
    cout << "copy constructor" << endl;
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;
}
Photon_Cannon::Photon_Cannon(int x, int y) {
    cout << "constructor" << endl;
}