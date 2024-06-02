#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;

    int f = true;
    while(t--){
        if(!f){
            cout << endl;
        }
        f=false;

        vector<vector<char>> v(20, vector<char>(20, ' '));
        int year;
        cin >> year;

        string s;
        getline(cin, s);
        while(getline(cin, s)){
            if(s == ""){
                break;
            }

            string save="";
            int x, y;

            for(int i = 0; i != s.size(); i++){
                if(s[i] != ' '){
                    save += s[i];
                }
                
                if(s[i] == ' '){
                    x = stoi(save)-1;
                    save = "";
                }else if(i == s.size()-1){
                    y = stoi(save)-1;
                }
            }
            
            v[x][y] = 'O'; 
        }

        while(year--){
            for(int i = 0; i != 20; i++){
                cout << '*';
            }
            cout << endl;

            for(int i = 0; i != 20; i++){
                for(int j = 0; j != 20; j++){
                    cout << v[i][j];
                }
                cout << endl;
            }

            vector<vector<char>> save(20, vector<char>(20, ' '));
            for(int i = 0; i != 20; i++){
                for(int j = 0; j != 20; j++){
                    int cont = 0;
                    if(i-1 != -1 && v[i-1][j] == 'O'){
                        cont++;
                    }
                    if(i+1 != 20 && v[i+1][j] == 'O'){
                        cont++;
                    }
                    if(j-1 != -1 && v[i][j-1] == 'O'){
                        cont++;
                    }
                    if(j+1 != 20 && v[i][j+1] == 'O'){
                        cont++;
                    }
                    if(i-1 != -1 && j-1 != -1 && v[i-1][j-1] == 'O'){
                        cont++;
                    }
                    if(i+1 != 20 && j-1 != -1 && v[i+1][j-1] == 'O'){
                        cont++;
                    }
                    if(i-1 != -1 && j+1 != 20 && v[i-1][j+1] == 'O'){
                        cont++;
                    }
                    if(i+1 != 20 && j+1 != 20 && v[i+1][j+1] == 'O'){
                        cont++;
                    }
                    
                    if(cont == 3){
                        save[i][j] = 'O';
                    }if(cont == 2 && v[i][j] == 'O'){
                        save[i][j] = 'O';
                    }
                }
            }

            v = save;
        }

        for(int i = 0; i != 20; i++){
            cout << '*';
        }
        cout << endl;
    }
}
