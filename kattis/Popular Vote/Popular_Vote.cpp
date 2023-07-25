#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int mx = -1, c, cont = 0;
        for(int i = 0; i != n; i++){
            int num;
            cin >> num;
                    
            cont += num;
            if(num >= mx){
                if(num == mx){
                    c = 0;
                    continue;
                }
                mx = num;
                c = i+1;
            }
        }

        if(c == 0){
            cout << "no winner" << endl;
        }else if(mx > cont/2){
            cout << "majority winner " << c << endl; 
        }else{
            cout << "minority winner " << c << endl;
        }
    }
}
