#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        bool val = true;
        for(int i = 2; i*i <= n; i++){
            if(n % i == 0){
                val = false;
                break;
            }
        }

        if(val){
            string s = to_string(n), save = "";
            for(int i = s.size()-1; i != -1; i--){
                save += s[i];
            }

            int num = stoi(save);
            for(int i = 2; i*i <= num; i++) {
                if(num % i == 0){
                    val = false;
                    break;
                }
            }

            if(n == num){
                val = false;
            }

            if(val){
                cout << n << " is emirp." << endl;
            }else{
                cout << n << " is prime." << endl;
            }
        }else{
            cout << n << " is not prime." << endl;
        }
    }
}
