#include <iostream>

using namespace std;

int main(){
    int t, s = 100, ms = 100;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        ms += n;

        if(ms > s){
            s = ms;
        }
    }

    cout << s << endl;
}
