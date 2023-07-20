#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;

    int cont = 1;
    while(t--){
        cout << "Case "<<cont<<": ";
        cont++;
       
        int rry[3];
        cin >> rry[0] >> rry[1] >> rry[2];

        sort(rry, rry+3);
        cout << rry[1] << endl;
    }
}
