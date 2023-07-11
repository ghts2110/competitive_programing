#include <iostream>
#include <string> 
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    int c = 1;
    while(t--){
        int n;
        cin >> n;

        vector<string> v;

        for(int i = 0; i != n; i++){
            string s;
            cin >> s;

            v.push_back(s);
        }

        int cont = 0;
        for(int i = 0; i != n; i++){
            for(int j = 0; j != n; j++){
                if(v[i][j] == 'x'){
                    cont++;

                    for(int k = j; k != n; k++){
                        if(v[i][k] == 'x' || v[i][k] == '@'){
                            v[i][k] = '@';
                        }else{
                            break;
                        }
                    }

                    for(int k = i; k != n; k++){
                        if(v[k][j] == 'x' || v[k][j] == '@'){
                            v[k][j] = '@';
                        }else{
                            break;
                        }
                    }

                }
            }
        }

        printf("Case %d: %d\n",c, cont);
        c++;
    }
}
