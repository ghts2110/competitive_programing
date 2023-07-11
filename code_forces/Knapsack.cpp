#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

int fist, num_item;
long long w;

vector<int> v;
vector<int> cob;

int dp(int k, int n){
    if(k < cob.size()){
        return cob[k];
    }

    int b = 0, cont = 0, index = -1;
    bitset<200000> b1(k);
    for(int i = n - 1; i >= 0 ; i--){
        if(index != -1){
            b += (1 << i) * b1[i];
        }

        if(index == -1 && b1[i] == 1){
            index = i;
        }

        if(b1[i] == 1){
            num_item++;
        }
    }

    if(index == -1){
        b = 0;
    }    

    cont += dp(b, index);
    cont += v[index];

    if(k == fist){
        cob.push_back(cont);
    }

    return cont;
}

int main(){
    long long t, n, max_sum;

    cin >> t;
    while(t--){
        max_sum = 0;
        v.clear();
        cob.clear();
        cob.push_back(0);

        cin >> n >> w;

        for(int i = 0; i != n; i++){
            int num;
            cin >> num;
            max_sum += num;
            v.push_back(num);
        }

        int mw = w/2;
        if(w%2 == 1){
            mw++;
        }

        fist = 0;

        while(1){
            fist++; 

            num_item = 0;
            int cont = dp(fist, n);

            if(cont >= mw && cont <= w){
                bitset<200000> b1(fist);

                cout << num_item << endl; 
                for(int i = 0; i != n; i++){
                    if(b1[i] == 1){
                        cout << i + 1 << " ";
                    }
                }
                cout << endl;

                break;
            }

            if(cont == max_sum){
                cout << -1 << endl;
                break;
            }
        }
    }
}

