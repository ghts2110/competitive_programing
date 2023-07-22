#include <iostream>
#include <cmath>
#include <vector>

#define pb push_back

using namespace std;

int main(){
    double p, a, b, c, d, n;
    while(cin >> p >> a >> b >> c >> d >> n){
        vector<double> v;

        for(int i = 1; i <= n; i++){
            v.pb(p * (sin((a * i)+b) + cos((c * i)+d) + 2.0));
        }

        double mx = 0, l = 0;
        for(int i = 1; i != n; i++){
            if(v[l] > v[i]){
                mx = max(mx, v[l]-v[i]);
            }else{
                l = i;
            }
        }

        printf("%.6f\n", mx);

    }

}
