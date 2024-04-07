#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        long long p, q;
        cin >> p >> q;

        pair<int, int> pr = {0, 0};
        for(long long i = p; i <= q; i++){
            long long cont = 0;
            for(long long j = 1; j*j <= i; j++){
                if(i % j == 0){
                    cont += 2;
                }        

                if(j*j == i){
                    cont--;
                }
            }
            
            if(pr.first < cont){
                pr = {cont, i};
            }
        }

        cout << "Between "<<p<<" and "<<q<<", "<<pr.second<<" has a maximum of "<<pr.first<<" divisors." << endl;

    }
}
