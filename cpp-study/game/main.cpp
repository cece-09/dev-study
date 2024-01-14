#include <string>
#include <iostream>

using namespace std;

class Marine {
    int hp;                // 체력
    int coord_x, coord_y;  // 현재 위치
    int damage;            // 공격력
    bool is_dead;          // 사망 여부
    char* name;            // 이름

    
    public:
        Marine();
        Marine(int x, int y);
        Marine(int x, int y, const char* name);
        ~Marine();

        int attack();
        void be_attacked(int damage_earn);
        void move(int x, int y);

        void show_status();
};

Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
}
Marine::Marine(int x, int y) {
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}
Marine::Marine(int x, int y, const char* name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}
Marine::~Marine() {
    cout << name << "의 소멸자 호출" << endl;
    if(name != NULL && name != nullptr) {
        delete[] name;
    }
}
void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if(hp <= 0) is_dead = true;
}
void Marine::show_status() {
    cout << "*** Marine: " << name << " ***" << endl;
    cout << "Location: (" << coord_x
         << ", " << coord_y << ") " << endl;
    cout << "HP: " << hp << endl;
}

int main() {
    Marine* marines[100];

    marines[0] = new Marine(2, 3, "Marine 1");
    marines[1] = new Marine(3, 5, "Marine 2");

    marines[0]->show_status();
    marines[1]->show_status();

    cout << endl << "마린 1이 마린 2를 공격! " << endl;
    marines[1]->be_attacked(marines[0]->attack());

    marines[0]->show_status();
    marines[1]->show_status();

    delete marines[0];
    delete marines[1];
}