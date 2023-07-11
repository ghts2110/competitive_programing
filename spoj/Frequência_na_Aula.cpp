#include <iostream>
#include <bitset>

using namespace std;

int main(){
    int n, cont = 0;
    cin >> n;
    bitset<1000000> bt(0);

    while(n--){
        int num;
        cin >> num;
        if(bt[num] == 0){
            cont++;
            bt[num] = 1;
        }
    }

    cout << cont << endl;
}
