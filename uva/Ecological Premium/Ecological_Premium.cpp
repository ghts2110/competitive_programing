#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int f;
        cin >> f;
        
        double sum = 0;
        
        for(int i = 0; i != f; i++){
            double m, a, v;
            cin >> m >> a >> v;

            if(a == 0){
                continue;
            }
            sum += ((m/a)*v)*a;
        }

        cout << (long long)sum << endl;
    }
}
