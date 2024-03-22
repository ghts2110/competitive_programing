#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> dp(14);
    for(int i = 2; i <= 13; i++){
        int num = i*2;
        int j = i+1;
        int rest = 0;
        while(true){
            if(num == i){
                dp[i] = j;
                break;
            }

            int mod = (j-rest) % num;

            if(mod <= i && mod != 0){
                j++;
                num = i*2;
                rest = 0;
                continue;
            }
            
            if(mod == 0){
                rest = 0;
            }else{
                rest = num-mod;
            }
            num--;
        }
    }

    dp[1] = 2;


    int n; 
    while(cin >> n){
        if(!n){
            break;
        }

        cout << dp[n] << endl;
    }
}
