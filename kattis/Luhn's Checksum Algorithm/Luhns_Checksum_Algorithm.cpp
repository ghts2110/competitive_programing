#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        string num; 
        cin >> num;
    
        int asw = 0;
        for(int i = num.size()-1; i != -1; i--){
            int cont = (num[i]-'0') * 2;
            if(i%2!=(num.size()-2)%2){
                cont/=2;
            }

            while(cont > 9){
                cont = (cont/10) + (cont%10);
            }

            asw += cont;
        }        

        if(asw % 10 == 0){
            cout << "PASS" << endl;
        }else{
            cout << "FAIL" << endl;
        }
    }
}
