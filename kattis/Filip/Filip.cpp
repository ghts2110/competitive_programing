#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    string a, b;
    cin >> a >> b;

    string save = "";
    for(int i = a.size()-1; i != -1; i--){
        save += a[i];
    }

    a = save;

    save = " ";
    for(int i = b.size()-1; i != -1; i--){
        save += b[i];
    }

    b = save;

    int mx = max(stoi(a), stoi(b));

    cout << mx << endl;
}
