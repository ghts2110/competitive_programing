#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    float f, v;

    cin >> s >> f >> v;

    printf("TOTAL = R$ %.2f\n", f+(v*15/100));
}
