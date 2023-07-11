#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v;
    bitset<1000000> bt(0);
    int cont = n;
    
    for(int i = 0; i != n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    for(int i = n-1; i > 0; i--){
        for(int j = i-v[i]; j < i; j++){
            if(j < 0){
                j=0;
            }else if(bt[j] == 1){
                break;
            }

            if(bt[j] == 0){
                bt[j] = 1;
                cont--;
            }
        }

        if(bt[0] == 1){
            break;
        }
    }

    cout << cont << endl;
}
