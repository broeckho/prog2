#include <iostream>
#include "logic.hpp"
#include "gravity.hpp"
using namespace std;

int main() {
    cout << "This is a Pong game. I swear." << endl;
    cout << "g = " << Physics::EARTH_GRAVITY << endl;
    cout << "If you have 10 points, " <<
        (is_winner(10) ? "you're a winner!" : "you haven't won yet.") << endl;
}
