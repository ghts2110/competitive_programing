#include <iostream>

using namespace std;

int main(){
    long long n;
    long long rry[50001];

    for(long long i = 0; i <= 50000; i++){
        rry[i] = i*i*i;
    }

    while(cin >> n){
        long long asw = 0;
        for(int i = 0; i <= n; i++){
            asw += rry[i];
        }

        cout << asw << endl;
    }
}
