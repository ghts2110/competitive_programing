#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
 
struct Point{
    double x, y;
};

int main(){
    int n;
    cin >> n;
    
    vector<Point> v(n+1);

    for(int i = 0; i != n; i++){
        int x, y;
        cin >> x >> y;
        v[i].x = x;
        v[i].y = y;
    }
    v[n] = v[0];
    
    double asw = 0;
    for(int i = 0; i != n; i++){
        asw += (v[i].x-v[i+1].x)*(v[i].y+v[i+1].y);
    }

    printf("%.1f\n", asw/2);
}
