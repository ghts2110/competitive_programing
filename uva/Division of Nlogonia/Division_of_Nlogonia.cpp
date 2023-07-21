#include <iostream>

using namespace std;

int main(){
    int t;
    while(1){
        cin >> t;
        if(t == 0){
            break;
        }

        int n, m;
        cin >> n >> m;

        for(int i = 0; i != t; i++){
            int x, y;
            cin >> x >> y;

            if(x == n || y == m){
                cout << "divisa" << endl;
            }else if(x > n && y > m){
                cout << "NE" << endl;
            }else if(x < n && y > m){
                cout << "NO" << endl;
            }else if(x < n && y < m){
                cout << "SO" << endl;
            }else{
                cout << "SE" << endl;
            }
        }
    }
}
