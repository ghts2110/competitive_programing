#include <iostream>
#include <vector>
#include <cmath>

#define pb push_back

using namespace std;

int main(){
    long long n, t;
    
    while(cin >> n >> t){
        long long v[n];
        for(int i = 0;i != n; i ++){
            cin >> v[i];
        
        }

        if(t == 1){
            cout << 7 << endl;
        }else if(t == 2){
            if(v[0] > v[1]){
                cout << "Bigger" << endl;
            }else if(v[0] == v[1]){
                cout << "Equal" << endl;
            }else{
                cout << "Smaller" << endl;
            }
        }else if(t == 3){
            long long sum = v[0] + v[1] + v[2];
            sum -= max(v[0], max(v[2], v[1]));
            sum -= min(v[0], min(v[2], v[1]));
            
            cout << sum << endl;
        }else if(t == 4){
            long long cont = 0;
            for(int i = 0; i != n; i ++){
                cont += v[i];
            }

            cout << cont << endl;
        }else if(t == 5){
            long long cont = 0;
            for(int i = 0; i != n; i ++){
                if(v[i] % 2 == 0){
                    cont += v[i];
                }
            }

            cout << cont << endl;
        }else if(t == 6){
            char mp[26];
            mp[0] = 'a';
            mp[1] = 'b';
            mp[2] = 'c';
            mp[3] = 'd';
            mp[4] = 'e';
            mp[5] = 'f';
            mp[6] = 'g';
            mp[7] = 'h';
            mp[8] = 'i';
            mp[9] = 'j';
            mp[10] = 'k';
            mp[11] = 'l';
            mp[12] = 'm';
            mp[13] = 'n';
            mp[14] = 'o';
            mp[15] = 'p';
            mp[16] = 'q';
            mp[17] = 'r';
            mp[18] = 's';
            mp[19] = 't';
            mp[20] = 'u';
            mp[21] = 'v';
            mp[22] = 'w';
            mp[23] = 'x';
            mp[24] = 'y';
            mp[25] = 'z';
            for(int i = 0; i != n; i++){
                int index = v[i]%26;
                cout << mp[index];
            }
            cout << endl;
        }else{
            long long i = 0, cont = 0;
            i = v[i];
            if(i < 0 || i >= n){
                 cout << "Out" << endl;
                 continue;
            }
            while(i >= 0 && i <= n-1){
                if(i < 0 || i >= n){
                    cout << "Out" << endl;
                    break;
                }else if(i == n-1){
                    cout << "Done" << endl;
                    break;
                }
                i = v[i];
                cont ++;
                if(cont > n+n){
                    cout << "Cyclic" << endl;
                    break;
                }
            }
            
        }
    }
}
