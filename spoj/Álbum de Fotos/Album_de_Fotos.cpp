#include <iostream>

using namespace std;

int main(){
    char s = 'N';
    int x, y;
    cin >> x >> y;
    int l1, h1, l2, h2;
    cin >> l1 >> h1;
    cin >> l2 >> h2;

    if((l1 + l2 <= x && max(h1, h2) <= y) || (l1 + l2 <= y && max(h1, h2) <= x)){
        s = 'S';
    }else if((h1 + h2 <= x && max(l1, l2) <= y) || (h1 + h2 <= y && max(l1, l2) <= x)){
        s = 'S';
    }else if((l1 + h2 <= x && max(l2, h2) <= y) || (l1 + h2 <= y && max(l2, h2) <= x)){
        s = 'S';
    }else if((l2 + h1 <= x && max(l1, h2) <= y) || (l2 + h1 <= y && max(l1, h2) <= x)){
        s = 'S';
    }

    cout << s << endl;
}
