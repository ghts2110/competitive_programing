#include <iostream>

using namespace std;

int main(){
    int n;
    while(1){
        cin >> n;

        if(n == -1){
            break;
        }

        int cont = 0, l, r, num;
        cin >> num >> l;
        cont += l * num;

        for(int i = 1; i != n; i++){
            cin >> num >> r;
            cont += num * (r-l);
            l = r;
        }

        cout << cont << " miles" << endl;
    }
}
