#include <iostream>
#include <string>
#include <cmath>
#include <map>

using namespace std;

unsigned long int factorial(unsigned long int k){
    if(k == 0){
        return 1;
    }

    if(k == 1){
        return 1;
    }else{
        return k * factorial(k - 1);
    }
}

int main(){
    unsigned long int n;
    cin >> n;
    int cont = 1;
    
    while(n--){
        string s;
        cin >> s;

        map<int,int>mp;
        
        for(int i = 0; i < s.size(); i++){
           mp[s[i] - 65]++;
        }

        unsigned long int nume = factorial((unsigned long int)s.size());
        unsigned long int den = 1;

    
        for(int i = 0; i < 26; i++){
            den *=(unsigned long int) factorial((unsigned long int)mp[i]);
        }
        
        unsigned long int div = nume / den;
        printf("Data set %d: %lu\n", cont, div);
        cont++;
    }
}
