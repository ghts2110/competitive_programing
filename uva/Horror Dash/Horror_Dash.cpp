#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    
    int cont = 1;
    while(t--){
        int n;
        cin >> n;
        int mx = 0;

        while(n--){
            int num;
            cin >> num;

            mx = max(mx, num);
        }

        printf("Case %d: %d\n", cont, mx);
        cont++;
    }
}
