#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

int main() {
    time_point<system_clock> now = system_clock::now(), then = now + hours(2);
    time_t then_time = system_clock::to_time_t(then);
    cout << "2 hours later... " << ctime(&then_time) << endl; 
}