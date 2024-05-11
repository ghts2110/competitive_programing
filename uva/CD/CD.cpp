#include <iostream>
#include <vector>

using namespace std;
int n, t;
int asw;
vector<int> save;

void dp(int ind, vector<int> v, int sum, vector<int> &num){
    if(ind == t){
        if(sum > asw){
            asw = sum;
            save = num;
        }        
        return;
    }   


    if(sum + v[ind] <= n){
        num.push_back(v[ind]);
        dp(ind+1, v, sum+v[ind], num);
        num.erase(num.end()-1);
    }
    dp(ind+1, v, sum, num);
}

int main(){
    while(cin >> n >> t){
        vector<int> v(t);
        for(int i = 0; i != t; i++){
            cin >> v[i];
        }
        
        vector<int> num;
        asw = 0;
        save.clear();

        dp(0, v, 0, num);
        for(auto it : save){
            cout << it << " "; 
        }
        cout << "sum:" << asw << endl; 
    }
}
