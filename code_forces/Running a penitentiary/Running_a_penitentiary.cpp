#include <iostream>

using namespace std;
typedef long long ll;

pair<ll, ll> st[800000];
int v[200000][2];

void merge(int ind1, int ind2, int ind3){
    if(st[ind2].first > st[ind3].second || st[ind3].first > st[ind2].second){
        st[ind1] = make_pair(1e10, 1e10);
        return;
    }

    st[ind1] = make_pair(max(st[ind2].first, st[ind3].first), min(st[ind2].second, st[ind3].second));
}

void build(int ind, int l, int r){
    if(l == r){
        st[ind] = make_pair(v[l][0], v[l][1]);
        return;
    }

    int mid = (l+r)/2;
    build(2*ind+1, l, mid);
    build(2*ind+2, mid+1, r);

    merge(ind, 2*ind+1, 2*ind+2);
}

void update(int ind, int l, int r, int p, int q, int x){
    if(l == r && l == x){
        st[ind] = make_pair(p, q);
        return;
    }

    if(l > x || r < x){
        return;
    }

    int mid = (l+r)/2;
    update(2*ind+1, l, mid, p, q, x);
    update(2*ind+2, mid+1, r, p, q, x);

    merge(ind, 2*ind+1, 2*ind+2);
}

pair<ll, ll> query(int ind, int l, int r, int p, int q){
    if(l >= p && r <= q){
        return st[ind];
    }

    if(l > q || r < p){
        return make_pair(-1e9, 1e9);
    }

    int mid = (l+r)/2;
    pair<ll, ll> p1 = query(2*ind+1, l, mid, p, q);
    pair<ll, ll> p2 = query(2*ind+2, mid+1, r, p, q);

    if(p1.first > p2.second || p2.first > p1.second){
        return make_pair(1e10, 1e10);
    }

    return make_pair(max(p1.first, p2.first), min(p1.second, p2.second));
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i != n; i++){
        scanf("%d %d", &v[i][0], &v[i][1]);
    }

    build(0, 0, n-1);

    for(int i = 0; i != m; i++){
        char c;
        int a, b, x;

        cin >> c;
        if(c == 'C'){
            cin >> x >> a >> b;
            x--;
            update(0, 0, n-1, a, b, x);
        }else{
            cin >> a >> b;
            a--;
            b--;
            pair<ll, ll> p = query(0, 0, n-1, a, b);
            ll asw = p.second-p.first;

            if(p.first != 1e10){
                cout << asw+1 << endl;
            }else{
                cout << 0 << endl;
            }
        }
    }
}