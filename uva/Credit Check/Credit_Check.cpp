#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    while(n--){
        int sum = 0;
        for(int i = 0; i != 4; i++){
            cin >> s;
            for(int i = 0; i != 4; i++){
                int num = s[i]-'0';
                if(i % 2 == 0){
                    num *= 2;
                }
                sum += num/10;
                sum += num%10;
            }
        }

        if(sum % 10 == 0){
            cout << "Valid" << endl;
        }else{
            cout << "Invalid" << endl;
        }
    }
}
