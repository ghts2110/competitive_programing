#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;

    vector<long long> max_p, mid_p;
    vector<int> value;

    for(int i = 0; i != t; i++){
        long long a, b, c;
        long long mx;
        scanf("%lld %lld %lld", &a, &b, &c);

        mx = max(a, b);
        mx = max(mx, c);

        mid_p.push_back(a+b+c-mx);
        max_p.push_back(a+b+c);
    
        if(max_p[i] >= mid_p[i] + 2){
            value.push_back(-1);
        }else{
            value.push_back(0);
        }
    }

    sort(mid_p.begin(), mid_p.end());

    for(int i = 0; i != t; i++){
        int cont = upper_bound(mid_p.begin(), mid_p.end(), max_p[i]-2) - mid_p.begin();

        value[i] += cont;
    }

    for(int i = 0; i != t; i++){
        if(i == t-1){
            printf("%d\n", value[i]);
            return 0;
        }
        printf("%d ", value[i]);
    }
}
