#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int t;
    while(cin >> t){
        if(t == 0){
            break;
        }
        vector<int> v(6);
        v[2] = 1;
        
        for(int i = 1; i != t; i++){
            string s;
            cin >> s;

            if(s == "+y"){
                int save = v[0];
                v[0] = v[2];
                v[2] = v[1];
                v[1] = v[3];
                v[3] = save;
            }else if(s == "-y"){
                int save = v[1];
                v[1] = v[2];
                v[2] = v[0];
                v[0] = v[3];
                v[3] = save;
            }else if(s == "+z"){
                int save = v[4];
                v[4] = v[2];
                v[2] = v[5];
                v[5] = v[3];
                v[3] = save;
            }else if(s == "-z"){
                int save = v[5];
                v[5] = v[2];
                v[2] = v[4];
                v[4] = v[3];
                v[3] = save;
            }
        }

        for(int i = 0; i != 6; i++){
            if(v[i] == 1 && i == 0){
                cout << "+y" << endl;
                break;
            }else if(v[i] == 1 && i == 1){
                cout << "-y" << endl;
                break;
            }else if(v[i] == 1 && i == 2){
                cout << "+x" << endl;
                break;
            }else if(v[i] == 1 && i == 3){
                cout << "-x" << endl;
                break;
            }else if(v[i] == 1 && i == 4){
                cout << "+z" << endl;
                break;
            }else if(v[i] == 1 && i == 5){
                cout << "-z" << endl;
                break;
            }
        }
    }
}
