#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<vector<char> > v(n);
        for(int i = 0; i != n; i++){
            v[i].push_back('A');
            v[i].push_back('B');
            v[i].push_back('C');
            v[i].push_back('D');
        }

        for(int i = 0; i != m; i++){
            for(int j = 0; j != n; j++){
                char a, b;

                cin >> a >> b;

                if(b == 'T'){
                    v[j] = vector<char> (1, a);
                }else{
                    for(int k = 0; k < v[j].size(); k++){
                        if(v[j][k] == a){
                            v[j].erase(v[j].begin()+k);
                        }
                    }
                }
            }
        }

        for(int i = 0; i != n; i++){
            if(v[i].size() != 1){
                cout << "?";
            }else{
                cout << v[i][0];
            }

            if(i != n-1){
                cout << " ";
            }
        }

        cout << endl;
    }
}