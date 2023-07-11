#include <iostream>

using namespace std;

int main(){
    int t, nume, deno;
    cin >> t;
    if(t%2==0){
        nume = t/2 - 1;
        deno = t/2 + 1;
    }else{
        nume = t/2;
        deno = t/2 + 1;
    }

    for(int i = 2; i <= nume; i++){
        if(nume % i == 0 && deno % i == 0){
            i = 1;
            nume--;
            deno++;
        }
    }

    cout << nume << " " << deno << endl;
        
}
