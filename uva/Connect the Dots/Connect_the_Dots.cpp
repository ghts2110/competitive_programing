#include <iostream>
#include <string>
#include <vector>
#include <map>

#define pb push_back

using namespace std;

int main(){
    map<int, char> mp;
    mp[0] = '0';
    mp[1] = '1';
    mp[2] = '2';
    mp[3] = '3';
    mp[4] = '4';
    mp[5] = '5';
    mp[6] = '6';
    mp[7] = '7';
    mp[8] = '8';
    mp[9] = '9';
    mp[10] = 'a';
    mp[11] = 'b';
    mp[12] = 'c';
    mp[13] = 'd';
    mp[14] = 'e';
    mp[15] = 'f';
    mp[16] = 'g';
    mp[17] = 'h';
    mp[18] = 'i';
    mp[19] = 'j';
    mp[20] = 'k';
    mp[21] = 'l';
    mp[22] = 'm';
    mp[23] = 'n';
    mp[24] = 'o';
    mp[25] = 'p';
    mp[26] = 'q';
    mp[27] = 'r';
    mp[28] = 's';
    mp[29] = 't';
    mp[30] = 'u';
    mp[31] = 'v';
    mp[32] = 'w';
    mp[33] = 'x';
    mp[34] = 'y';
    mp[35] = 'z';
    mp[36] = 'A';
    mp[37] = 'B';
    mp[38] = 'C';
    mp[39] = 'D';
    mp[40] = 'E';
    mp[41] = 'F';
    mp[42] = 'G';
    mp[43] = 'H';
    mp[44] = 'I';
    mp[45] = 'J';
    mp[46] = 'K';
    mp[47] = 'L';
    mp[48] = 'M';
    mp[49] = 'N';
    mp[50] = 'O';
    mp[51] = 'P';
    mp[52] = 'Q';
    mp[53] = 'R';
    mp[54] = 'S';
    mp[55] = 'T';
    mp[56] = 'U';
    mp[57] = 'V';
    mp[58] = 'W';
    mp[59] = 'X';
    mp[60] = 'Y';
    mp[61] = 'Z';
    
    string s;
    int test = 0;
    vector<string> mat;
    while(getline(cin, s)){
        if(test != 0){
            cout << endl;
        }
        test++;
        mat.clear();
        mat.pb(s);

        int linha = 0;
        vector<pair<int, int>> v(63, pair<int,int>(-1, -1));

        for(int i = 0; i != s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                v[s[i]-'a'+10] = pair<int, int>(linha, i);
            }else if(s[i] >= 'A' && s[i] <= 'Z'){
                v[s[i]-'A'+36] = pair<int, int>(linha, i);
            }else if(s[i] != '.'){
                v[s[i]-'0'] = pair<int, int>(linha, i);
            }
        }

        while(getline(cin, s)){
            if(s.size() < 1){
                break;
            }
            mat.pb(s);

            linha++;

            for(int i = 0; i != s.size(); i++){
                if(s[i] >= 'a' && s[i] <= 'z'){
                    v[s[i]-'a'+10] = pair<int, int>(linha, i);
                }else if(s[i] >= 'A' && s[i] <= 'Z'){
                    v[s[i]-'A'+36] = pair<int, int>(linha, i);
                }else if(s[i] != '.'){
                    v[s[i]-'0'] = pair<int, int>(linha, i);
                }
            }
        }

        for(int i = 0; i <= 61; i++){
            if(v[i].first == -1 || v[i].second == -1){
                break;
            }
            mat[v[i].first][v[i].second] = mp[i];
        
            if(v[i+1].first == -1 || v[i+1].second == -1){
                break;
            }

            if(v[i].first == v[i+1].first){
                int p;
                if(v[i].second > v[i+1].second){
                    p = -1;
                }else{
                    p = 1;
                }

                for(int j = v[i].second; j != v[i+1].second; j+=p){
                    if(mat[v[i].first][j] == '|'){
                        mat[v[i].first][j] = '+';
                    }else if(mat[v[i].first][j] == '.'){
                        mat[v[i].first][j] = '-';
                    }
                }
            }else if(v[i].second == v[i+1].second){
                int p;
                if(v[i].first > v[i+1].first){
                    p = -1;
                }else{
                    p = 1;
                }

                for(int j = v[i].first; j != v[i+1].first; j+=p){
                    if(mat[j][v[i].second] == '-'){
                        mat[j][v[i].second] = '+';
                    }else if(mat[j][v[i].second] == '.'){
                        mat[j][v[i].second] = '|';
                    }
                }
            }
        }

        for(auto& i : mat){
            for(char j : i ){
                cout << j;
            }
            cout << endl;
        }
    }

}
