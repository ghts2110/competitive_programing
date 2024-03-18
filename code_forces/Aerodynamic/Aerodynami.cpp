#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

struct Point{
    ll x, y;
};


ll dist(Point p1, Point p2){
    return abs(p1.x-p2.x)*abs(p1.x-p2.x) + abs(p1.y-p2.y)*abs(p1.y-p2.y); 
}

int main(){
    ll n;
    cin >> n;
    
    vector<Point> v(n);
    ll mxX = -1e9, mnX = 1e9, mxY = -1e9, mnY = 1e9;
    for(int i = 0; i != n; i++){
        ll x, y;
        cin >> x >> y;
        x*=10;
        y*=10;
        mxX = max(mxX, x);
        mnX = min(mnX, x);
        mxY = max(mxY, y);
        mnY = min(mnY, y);

        v[i] = {x, y};
    }

    Point mid = {(mxX+mnX)/2, (mxY+mnY)/2};

    map<ll, ll> mp;
    for(int i = 0; i != n ; i++){
        if(v[i].x >= mid.x){
            mp[dist(v[i], mid)]++;
        }
    }
    
    for(int i = 0; i != n ; i++){
        if(v[i].x <= mid.x){
            mp[dist(v[i], mid)]--;
        }
    }

    bool b = true;
    for(auto it : mp){
        if(it.second != 0){
            b = false;
            break;
        }
    }
    
    for(int i = 0; i != n ; i++){
        if(v[i].y >= mid.y){
            mp[dist(v[i], mid)]++;
        }
    }
    
    for(int i = 0; i != n ; i++){
        if(v[i].y <= mid.y){
            mp[dist(v[i], mid)]--;
        }
    }

    for(auto it : mp){
        if(it.second != 0){
            b = false;
            break;
        }
    }


    if(b && n%2 == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
