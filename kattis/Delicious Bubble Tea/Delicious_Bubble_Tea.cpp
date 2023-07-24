#include <iostream>
#include <vector>
#include <cmath>

#define pb push_back

using namespace std;

int main(){
    long long n, m;
    cin >> n;
    
    vector<long long> tea;
    for(int i = 0; i != n; i++){
        long long num; 
        cin >> num; 

        tea.pb(num);
    }

    cin >> m;
    vector<long long> top;
    for(int i = 0; i != m; i++){
        long long num;
        cin >> num;

        top.pb(num);
    }

    long long mn = 1e18;
    for(int i = 0; i != n; i++){
        int k;
        cin >> k;

        for(int j = 0; j != k; j++){
            int num;
            cin >> num;

            mn = min(tea[i] + top[num-1], mn);
        }
    }

    long long pvh;
    cin >> pvh;

    if(pvh/mn == 0){
        cout << 0 << endl;
        return 0;
    }
    cout << (pvh/mn) -1<< endl;
}
