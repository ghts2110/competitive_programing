#include <iostream>
#include <string>

using namespace std;

int main(){
    string s = "", line;
    int pm;
    cin >> pm;

    for(int i = 0; i != 4; i++){
        cin >> line;
        s += line;
    }

    int num = 0;


    int cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0, cont5 = 0, cont6 = 0, cont7 = 0, cont8 = 0, cont9 = 0;
    for(int i = 0; i != s.size(); i++){
        if(s[i] == '1'){
            cont1++;
        }else if(s[i] == '2'){
            cont2++;
        }else if(s[i] == '3'){
            cont3++;
        }else if(s[i] == '4'){
            cont4++;
        }else if(s[i] == '5'){
            cont5++;
        }else if(s[i] == '6'){
            cont6++;
        }else if(s[i] == '7'){
            cont7++;
        }else if(s[i] == '8'){
            cont8++;
        }else if(s[i] == '9'){
            cont9++;
        }
    }

    if(pm*2 < cont1 || pm*2 < cont2 || pm*2 < cont3 || pm*2 < cont4 || pm*2 < cont5 || pm*2 < cont6 || pm*2 < cont7 || pm*2 < cont8 || pm*2 < cont9){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }

}
