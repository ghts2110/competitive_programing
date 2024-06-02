#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;

    bool f = true;
    while(t--){
        if(!f){
            cout << endl;
        }
        f=false;
        vector<int> v(10);
        for(int i = 0; i != 10; i++){
            cin >> v[i];
        }

        vector<int> p(40);
        p[19] = 1;

        vector<int> save(40);
        for(int i = 0; i != 50; i++){
            for(auto it : p){
                if(it == 0){
                    cout << ' ';
                }else if(it == 1){
                    cout << '.';
                }else if(it == 2){
                    cout << 'x';
                }else{
                    cout << 'W';
                }
            }
            cout << endl;
        
            for(int j = 0; j != 40; j++){
                int sum = 0;
                sum += p[j];
                if(j != 0){
                    sum += p[j-1];
                }
                if(j != 39){
                    sum += p[j+1];
                }

                save[j] = v[sum];
            }

            p = save;
        }
    }
}
