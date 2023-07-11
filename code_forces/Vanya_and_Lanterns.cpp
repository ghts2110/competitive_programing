#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    double n, l;
    vector<double> v;

    cin >> n >> l;
    
    for(int i = 0; i != n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    
    double mx = 0;
    for(int i = 0; i != n-1; i++){     
        mx = max(mx, v[i+1] - v[i]);
    }

    mx = mx/2;
    mx = max(mx, v[0]);
    mx = max(mx, l - v[n-1]);

    printf("%.8f\n", mx);
}
