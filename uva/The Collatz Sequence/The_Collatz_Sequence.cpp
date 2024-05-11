#include <iostream>

using namespace std;

int main(){
    long long n, m;
    int test = 1;
    while(cin >> n >> m){
        if(n < 0 && m < 0){
            break;
        }
        cout << "Case "<<test<<": A = "<<n<<", limit = "<<m<<", number of terms = ";
        test++;

        long long asw = 0;
        while(n <= m){
            asw++;
            if(n == 1){
                break;
            }
            if(n%2 == 0){
                n /=2;
            }else{
                n *= 3;
                n++;
            }
        }
        
        cout << asw << endl;
    }
}
