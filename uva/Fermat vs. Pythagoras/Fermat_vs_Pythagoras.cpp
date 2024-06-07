#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

bool memo[1000002];

ll gcd(ll a, ll b){
    if(b ==0){
        return a;
    }
    return gcd(b, a%b);
}

int main() {
    ll n;
    while(cin >> n){
        ll r, s, x, y, k, z;
        ll up;
        ll tri = 0, total = 0;
        ll end = sqrt(n);
        if(end*end < n){
            end++;
        }

        for(r = 1; r<= end; r++) {
            up = min((n - r*r),r-1);
            for(s = 1; s<= up; s++) {
                x = r*r - s*s;
                y = 2*r*s;
                z = r*r + s*s;
                if(x*x + y*y == z*z && z<=n) {
                    if(gcd(x,y) == 1) {
                        tri++;
                        for(k = 1; k*z<=n; k++) {
                            memo[k*x] = 1;
                            memo[k*y] = 1;
                            memo[k*z] = 1;
                        }
                    }
                }
            }
        }
        for(k = 1; k<= n; k++) {
            if(memo[k] == 0) total++;
            memo[k] = 0;
        }
        printf("%lld %lld\n",tri, total);
    }
}
