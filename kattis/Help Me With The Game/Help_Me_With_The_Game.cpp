#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

#define pb push_back

using namespace std;

int main(){
    map<int, char> mp;
    mp[1] = 'a';
    mp[2] = 'b';
    mp[3] = 'c';
    mp[4] = 'd';
    mp[5] = 'e';
    mp[6] = 'f';
    mp[7] = 'g';
    mp[8] = 'h';
    string s;

    vector<string> v;
    cout << "White: ";

    bool validate = false;
    int i = 9;
    for(int l = 0; l != 17; l++){
        cin >> s;

        if(l % 2 == 1){
            i--;
            v.pb(s);
        }
    }

    for(int i = 7; i >= 0;i--){
        int colun = 0;
        for(int j = 2; j <= v[i].size(); j+=4){
            colun++;
            if(v[i][j] == 'K'){
                if(validate){
                    cout<<",";
                }
                validate = true;
                cout << "K"<<mp[colun]<<abs(i-7)+1;
            }
        }
    }
    for(int i = 7; i >= 0;i--){
        int colun = 0;
        for(int j = 2; j <= v[i].size(); j+=4){
            colun++;
            if(v[i][j] == 'Q'){
                if(validate){
                    cout<<",";
                }
                validate = true;
                cout << "Q"<<mp[colun]<<abs(i-7)+1;
            }
        }
    }
    for(int i = 7; i >= 0; i--){
        int colun = 0;
        for(int j = 2; j <= v[i].size(); j+=4){
            colun++;
            if(v[i][j] == 'R'){
                if(validate){
                    cout<<",";
                }
                validate = true;
                cout << "R"<<mp[colun]<<abs(i-7)+1;
            }
        }
    }
    for(int i = 7; i >= 0; i--){
        int colun = 0; 
        for(int j = 2; j <= v[i].size(); j+=4){
            colun++;
            if(v[i][j] == 'B'){
                if(validate){
                    cout<<",";
                }
                validate = true;
                cout << "B"<<mp[colun]<<abs(i-7)+1;
            }
        }
    }
    for(int i = 7; i >= 0; i--){
        int colun = 0;
        for(int j = 2; j <= v[i].size(); j+=4){
            colun++;
            if(v[i][j] == 'N'){
                if(validate){
                    cout<<",";
                }
                validate = true;
                cout << "N"<<mp[colun]<<abs(i-7)+1;
            }
        }
    }
    for(int i = 7; i >= 0; i--){
        int colun = 0;
        for(int j = 2; j <= v[i].size(); j+=4){
            colun++;
            if(v[i][j] == 'P'){
                if(validate){
                    cout<<",";
                }
                validate = true;
                cout << mp[colun]<<abs(i-7)+1;
            }
        }
    }

    validate = false;
    cout << endl;
    cout << "Black: ";
    for(int i = 0; i <= 7; i++){
        int colun = 0;
        for(int j = 2; j <= v[i].size(); j+=4){
            colun++;
            if(v[i][j] == 'k'){
                if(validate){
                    cout<<",";
                }
                validate = true;
                cout << "K"<<mp[colun]<<abs(i-7)+1;
            }
        }
    } 
    for(int i = 0; i <= 7; i++){
        int colun = 0;
        for(int j = 2; j <= v[i].size(); j+=4){
            colun++;
            if(v[i][j] == 'q'){
                if(validate){
                    cout<<",";
                }
                validate = true;
                cout << "Q"<<mp[colun]<<abs(i-7)+1;
            }
        }
    }
    for(int i = 0; i <= 7; i++){
        int colun = 0;
        for(int j = 2; j <= v[i].size(); j+=4){
            colun++;
            if(v[i][j] == 'r'){
                if(validate){
                    cout<<",";
                }
                validate = true;
                cout << "R"<<mp[colun]<<abs(i-7)+1;
            }
        }
    }
    for(int i = 0; i <= 7; i++){
        int colun = 0; 
        for(int j = 2; j <= v[i].size(); j+=4){
            colun++;
            if(v[i][j] == 'b'){
                if(validate){
                    cout<<",";
                }
                validate = true;
                cout << "B"<<mp[colun]<<abs(i-7)+1;
            }
        }
    }
    for(int i = 0; i <= 7; i++){
        int colun = 0;
        for(int j = 2; j <= v[i].size(); j+=4){
            colun++;
            if(v[i][j] == 'n'){
                if(validate){
                    cout<<",";
                }
                validate = true;
                cout << "N"<<mp[colun]<<abs(i-7)+1;
            }
        }
    }
    for(int i = 0; i <= 7; i++){
        int colun = 0;
        for(int j = 2; j <= v[i].size(); j+=4){
            colun++;
            if(v[i][j] == 'p'){
                if(validate){
                    cout<<",";
                }
                validate = true;
                cout << mp[colun]<<abs(i-7)+1;
            }
        }
    }

    cout << endl;
}
