#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;

    int cont1 = 0, cont2 = 0;
    for(int i = 0; i != n; i++){
        string s;
        cin >> s;

        for(int j = 0; j != 4; j++){
            if(j <= 1 && s[j] == '0'){
                cont1++;
            }else if(j > 1 && s[j] == '0'){
                cont2++;
            }
        }
    }

    cout << min(cont1/2, cont2/2) << " ";
    cout << cont1 - (2 * min(cont1/2, cont2/2)) << " " << cont2 - (2 * min(cont1/2, cont2/2)) << endl;
}
