#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    while(cin >> t){
        if(t == 0){
            break;
        }

        int v[7];
        v[1] = 1;
        v[2] = 2;
        v[3] = 3;
        v[4] = 4;
        v[5] = 5;
        v[6] = 6;

        while(t--){
            string s;
            cin >> s;

            if(s == "north"){
                int save = v[1];
                v[1] = v[5];
                v[5] = v[6];
                v[6] = v[2];
                v[2] = save;
            }else if(s == "south"){
                int save = v[1];
                v[1] = v[2];
                v[2] = v[6];
                v[6] = v[5];
                v[5] = save;
            }else if(s == "east"){
                int save = v[1];
                v[1] = v[3];
                v[3] = v[6];
                v[6] = v[4];
                v[4] = save;
            }else{
                int save = v[1];
                v[1] = v[4];
                v[4] = v[6];
                v[6] = v[3];
                v[3] = save;
            }
        }

        cout << v[1] << endl;
    }
}
