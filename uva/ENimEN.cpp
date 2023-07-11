#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int cont1 = 0, contN = 0;
        for(int i = 0; i != n; i++){
            int num;
            cin >> num;
            
            if(num == 1){
                cont1++;
            }else{
                contN++;
            }
        }
    
        if(contN != 0){
            cout << "poopi" << endl;
        }else if(cont1 % 2 == 1){
            cout << "poopi" << endl;
        }else{
            cout << "piloop" << endl;
        }
    }
}
