#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;
pair<int, int> v[100];
int memo[10010][10010];
int n, a, b;

double area(int x1, int y1, int x2, int y2, int x3, int y3){
    return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

int solution(pair<int, int> no){
    if(memo[no.first][no.second] != -1){
        return memo[no.first][no.second];
    }

    int asw = 1;
    double A = area (no.first, no.second, a, 0, b, 0);
    for(int i = 0; i != n;i ++){
        double A1 = area (v[i].first, v[i].second, a, 0, b, 0);
        double A2 = area (no.first, no.second, v[i].first, v[i].second, b, 0);
        double A3 = area (no.first, no.second, a, 0, v[i].first, v[i].second);

        if(A == A1 + A2 + A3 && v[i] != no){
            asw = max(asw, solution(v[i]) + 1);
        }
    }

    return memo[no.first][no.second] = asw;
}

int main(){
    cin >> n >> a >> b;
    memset(memo, -1, sizeof memo);

    for(int i = 0; i != n; i++){
        int p1, p2;
        cin >> p1 >> p2;

        v[i] = make_pair(p1, p2);
    }

    int asw = 0;
    for(int i = 0; i != n; i++){
        asw = max(asw, solution(v[i]));
    }

    cout << asw << endl;
}