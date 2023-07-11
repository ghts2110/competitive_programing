#include <iostream>

using namespace std;

int main(){
    int t, num, max, c;
    cin >> t;

    t--;
    cin >> c;
    max = c;

    while(t--){
        cin >> num;
        if(max < num){
            max = num;
        }
    }

    if(max == c){
        cout << "S" << endl;
    }else{
        cout << "N" << endl;
    }
}
