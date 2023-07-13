#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main(){
    int n,cont = 0;
    cin >> n;

    string s;
    cin >> s;
    bitset<26>  bt(0);
    char leter[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    
    for(int i = 0; i != n; i++){
        
        for(int j = 0; j != 26; j++){
            if(leter[j] == tolower(s[i]) && bt[j] == 0){
                cont++;
                bt[j] = 1;
                break;
            }
        }
    }

    if(cont == 26){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
}
