#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    int test = 1;
    while(t--){
        long long a, b, c;
        cin >> a >> b >> c;

        cout << "Case "<<test<<": ";
        test++;
        if(a + b <= c || a + c <= b || b + c <= a){
            cout << "Invalid" << endl;
        }else{
            if(a == b && a == c){
                cout << "Equilateral" << endl;
            }else if(a == b || a == c || b == c){
                cout << "Isosceles" << endl;
            }else{
                cout << "Scalene" << endl;
            }
        }
    }
}
