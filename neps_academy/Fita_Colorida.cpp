#include <iostream>

using namespace std;

int v[10000];
int t;

int main(){
    cin >> t;

    for(int i = 0; i != t; i++){
        cin >> v[i];
    }

    for(int i = 0; i != t; i++){
        int r = 0, l = 0, j = i;
        while(1){
            if(j == -1){
                r = 9;
                break;
            }if(v[j] == 0){
                break;
            }

            r++;
            if(r == 9){
                break;
            }
            j--;
        }

        
        j = i;
        while(1){
            if(j == t){
                l = 9;
                break;
            }if(v[j] == 0){
                break;
            }

            l++;
            if(l == 9){
                break;
            }
            j++;
        }

        if(i == t -1){
            cout << min(l, r) << endl;
            return 0;
        }
        cout << min(l, r) << " ";
    }
}
