#include <iostream>
#include <vector>

using namespace std;

struct point{
    long long x,y;
};

long long h(point p1, point p2, point p3){
    return (p2.x-p1.x)*(p3.y-p1.y) - (p3.x-p1.x)*(p2.y-p1.y);
}

int ind = 0;

bool bs(int l, int r, point p, vector<point>&v){
    if(l > r){
        if(ind == v.size()-1){
            ind--;
        }

        return h(v[ind], v[ind+1], p) >= 0;
    }


    int mid = (l + r) / 2;
    if(h(v[0], v[mid], p) >= 0){
        ind = mid;
        return bs(mid+1, r, p, v);
    }

    return bs(l, mid-1, p, v);
        
}

int main() {
    int n,m,k;
    cin >> n >> m >> k;

    vector<point>v(n);

    for(int i=0;i<n;i++){
        cin >> v[i].x >> v[i].y;
    }

    int asw = 0;
    for(int i=0;i<m;i++){
        long long x,y;
        cin>>x>>y;

        if(!(h(v[0], v[n-1], {x, y}) <= 0 && h(v[0], v[1], {x, y}) >= 0)){
            continue;
        }

        ind = 1;
        if(bs(1, n-1, {x,y}, v)){
            asw++;
        }
    }

    if(asw >= k){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
