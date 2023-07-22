#include <iostream>
#include <string>
#include <vector>

#define pb push_back
#define p v[x][y] 

using namespace std;

int main(){
    int r, c;
    cin >> r >> c;
    string s;
    vector<string> v;

    for(int i= 0; i != r; i++){
        cin >> s;
        v.pb(s);
    }

    int x = 0, y = 0, cont = 0;
    while(p != 'T'){
        cont++;
        if(p == 'N'){
            x--;
        }else if(p == 'S'){
            x++;
        }else if(p == 'W'){
            y--;
        }else{
            y++;
        }

        if(x < 0 || x >= r || y < 0 || y >= c){
            cout << "Out" << endl;
            return 0;
        }

        if(cont > r*c){
            cout << "Lost" << endl;
            return 0;
        }
    }

    cout << cont << endl;
}
