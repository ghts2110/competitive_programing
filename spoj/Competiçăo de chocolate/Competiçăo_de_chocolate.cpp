#include <iostream>

using namespace std;

int main(){
    int n, m;

    cin >> n >> m;

    if(n % (m+1) == 0){
        cout << "Carlos" << endl;
    }else{
        cout << "Paula" << endl;
    }
}
