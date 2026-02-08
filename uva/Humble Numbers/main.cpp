#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string suffix(int n) {
    int last2 = n % 100;
    if (last2 >= 11 && last2 <= 13) return "th";
    int last = n % 10;
    if (last == 1) return "st";
    if (last == 2) return "nd";
    if (last == 3) return "rd";
    return "th";
}

int main(){
    int n;

    vector<long long> h(5843);
    h[1] = 1;

    int p2 = 1, p3 = 1, p5 = 1, p7 = 1;

    for (int i = 2; i <= 5842; i++) {
        long long c2 = h[p2] * 2, c3 = h[p3] * 3, c5 = h[p5] * 5, c7 = h[p7] * 7;

        long long nxt = min(min(c2, c3), min(c5, c7));
        h[i] = nxt;

        if (nxt == c2) p2++;
        if (nxt == c3) p3++;
        if (nxt == c5) p5++;
        if (nxt == c7) p7++;
    }

    while (cin >> n) {
        if(!n){
            break;
        }
        cout << "The "<<n<<suffix(n)<< " humble number is " << h[n] << ".\n";
    }
}