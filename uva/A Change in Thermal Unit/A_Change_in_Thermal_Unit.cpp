#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    int test = 1;
    while(t--){
        cout << "Case "<<test<<": ";
        test++;

        double c, f;
        cin >> c >> f;

        f += ((9*c)/5) + 32;
        c = ((f-32)*5)/9;
    
        printf("%.2f\n", c);
    }
}
