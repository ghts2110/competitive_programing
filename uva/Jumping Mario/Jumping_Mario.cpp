#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    int cont = 1;
    while(t--){
        int n;
        cin >> n;

        int b;
        int mx = 0, mn = 0;
        for(int i = 0; i != n; i++){
            int num;
            cin >> num;

            if(i == 0){
                b = num;
                continue;
            }

            if(b > num){
                mn++;
            }else if(b < num){
                mx++;
            }

            b = num;
        }

        printf("Case %d: %d %d\n", cont, mx, mn);
        cont++;
    }
}
