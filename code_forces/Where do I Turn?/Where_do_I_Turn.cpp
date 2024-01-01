#include <iostream>

using namespace std;

int main(){
    pair<int, int> a, b, c;
    while(cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second) {

        bool b1 = a.first == b.first, b2 = b.first != c.first;
        if (b1 && b2 && a.second > b.second) {
            bool b3 = c.first < b.first;
            if (b3) {
                cout << "RIGHT" << endl;
            } else {
                cout << "LEFT" << endl;
            }
            continue;
        } else if (b1 && b2 && a.second < b.second) {
            bool b3 = c.first > b.first;
            if (b3) {
                cout << "RIGHT" << endl;
            } else {
                cout << "LEFT" << endl;
            }
            continue;
        } else if (b1 && !b2) {
            cout << "TOWARDS" << endl;
            continue;
        }

        b1 = a.second == b.second;
        b2 = b.second != c.second;
        if (b1 && b2 && a.first > b.first) {
            bool b3 = c.second > b.second;
            if (b3) {
                cout << "RIGHT" << endl;
            } else {
                cout << "LEFT" << endl;
            }
            continue;
        } else if (b1 && b2 && a.first < b.first) {
            bool b3 = c.second < b.second;
            if (b3) {
                cout << "RIGHT" << endl;
            } else {
                cout << "LEFT" << endl;
            }
            continue;
        } else if (b1 && !b2) {
            cout << "TOWARDS" << endl;
            continue;
        }

        bool b4 = a.first < b.first, b5 = a.second > b.second;
        if (b4 && b5) {
            bool b6 = c.first < b.first, b7 = c.second > b.second;
            if (b6 && !b7) {
                cout << "RIGHT" << endl;
            } else if (!b6 && b7) {
                cout << "LEFT" << endl;
            } else {
                cout << "TOWARDS" << endl;
            }
        } else if (b4 && !b5) {
            bool b6 = c.first < b.first, b7 = c.second > b.second;
            if (!b6 && !b7) {
                cout << "RIGHT" << endl;
            } else if (b6 && b7) {
                cout << "LEFT" << endl;
            } else {
                cout << "TOWARDS" << endl;
            }
        } else if (!b4 && b5) {
            bool b6 = c.first < b.first, b7 = c.second > b.second;
            if (b6 && b7) {
                cout << "RIGHT" << endl;
            } else if (!b6 && !b7) {
                cout << "LEFT" << endl;
            } else {
                cout << "TOWARDS" << endl;
            }
        } else {
            bool b6 = c.first < b.first, b7 = c.second > b.second;
            if (!b6 && b7) {
                cout << "RIGHT" << endl;
            } else if (b6 && !b7) {
                cout << "LEFT" << endl;
            } else {
                cout << "TOWARDS" << endl;
            }
        }
    }
}