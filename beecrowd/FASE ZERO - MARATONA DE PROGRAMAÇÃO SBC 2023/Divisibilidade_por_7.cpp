#include <iostream>
#include <string>

using namespace std;

int main(){
    long long n;
    cin >> n;

    while(1){
        cout << n << endl;
        
        string s = to_string(n);
        if(s.size() == 1){
            break;
        }

        long long ultimo = n % 10;
        n = (n/10) * 3 + ultimo;
    }
}
