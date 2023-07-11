#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> v;
    int n, q;
    cin >> n;

    while(n--){
        int num;
        cin >> num;

        v.push_back(num);
    }

    cin >> q;

    while(q--){
        int i, j, cont = 0;
        cin >> i >> j;

        for(int k = i; k <= j; k++){
            cont += v[k];
        }

        cout << cont << endl;
    }
}
