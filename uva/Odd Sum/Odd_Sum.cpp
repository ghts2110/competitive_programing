#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    int test = 1;
    while(t--){
        int a, b;
        cin >> a >> b;

        int sum = 0;
        for(int i = a; i <= b; i++){
            if(i%2==1){
                sum += i;
            }
        }
    
        cout << "Case "<<test<<": "<<sum << endl;
        test++;
    }
}
