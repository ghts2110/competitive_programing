#include <iostream>
#include <cstring>

using namespace std;

pair<double, double> v[1010];
double memo[1010];
int n;

double dp(int ind){
    if(ind == n){
        return 0;
    }

    if(memo[ind] != -1){
        return memo[ind];
    }

    double asw = 1e9;
    for(int i = ind+1; i <= n; i++){
        double dist = (v[i].first-v[ind].first);
        double vs = v[ind].second/dist;

        asw = min(asw, dp(i)+(dist/vs));
    }

    return memo[ind] = asw;
}

int main(){
    double d;
    cin >> n >> d;

    for(double & i : memo){
        i = -1;
    }

    for(int i = 0; i != n; i++){
        double p, c;
        cin >> p >> c;

        v[i] = make_pair(p, c);
    }
    v[n] = make_pair(d, 0);

    printf("%.3f\n", dp(0));
}