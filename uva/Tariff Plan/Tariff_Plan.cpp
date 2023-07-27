#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    int cont = 1;
    while(t--){
        cout << "Case "<<cont<<": ";
        cont++;

        int n;
        cin >> n;

        int cm = 0, cj = 0;
        
        for(int i = 0; i != n; i++){
            int num;
            cin >> num;

            cm += (num/30 +1) * 10;
            cj += (num/60 +1) * 15;
        }

        if(cm < cj){
            cout << "Mile " << cm << endl;
        }else if(cm > cj){
            cout << "Juice " << cj << endl;
        }else{
            cout << "Mile Juice " << cm << endl;
        }
    }
}
