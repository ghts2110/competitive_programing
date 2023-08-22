#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n==0){
            break;
        }

        int p=1;
        while(p*2 < n){
            p++;
        }
        if(p%2==1 && n != 1){
            p++;
        }

        int page = p;
        

        vector<pair<int, int>> v(page);
        bool l = true;
        int x = 0, y = 1;
        for(int j = 1; j <= n; j++){
            if(l){
                if(y){
                    v[x].second = j;
                }else{
                    v[x].first = j;
                }
                if(x == page-1){
                    l = false;
                    y ^= 1;
                    continue;
                }
                x++;
                y ^= 1;
            }else{
                if(y){
                    v[x].second = j;
                }else{
                    v[x].first = j;
                }
                x--;
                y^=1;
            }
        }

        cout << "Printing order for "<<n<<" pages:" << endl;
        
        int sht = 0;
        for(int i = 0; i != page; i++){
            if(i % 2 == 0){
                sht++;
                cout << "Sheet "<<sht<<", front: ";
            }else{
                cout << "Sheet "<<sht<<", back : ";
            }
            if(v[i].first == 0){
                cout << "Blank, ";
            }else{
                cout << v[i].first << ", ";
            }

            if(v[i].second == 0){
                cout << "Blank" << endl;;
            }else{
                cout << v[i].second << endl;
            }
        }
    }
}
