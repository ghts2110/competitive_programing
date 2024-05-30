#include <iostream>

using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m){
        int ou = n | m;
        int e = n & m;
        cout << ou - e << endl;
    }
}
