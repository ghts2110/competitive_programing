#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, m;
        char p;

        cin >> p >> n >> m;
        if(p == 'r'){
            cout << min(n, m) << endl;
        }else if(p == 'k'){
            int sum = (m*n)/2;
            if((m*n)%2 == 1){
                sum++;
            }
            cout << sum << endl;

        }else if(p == 'Q'){
            cout << min(n, m) << endl;
        }else{
            int line = m/2;
            if(m % 2 == 1){
                line++;
            }
            int colun = n/2;
            if(n%2 == 1){
                colun++;
            }
            
            cout << colun * line << endl;
        }
    }
}
