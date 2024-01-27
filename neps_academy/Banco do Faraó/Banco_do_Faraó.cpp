#include <iostream>

using namespace std;
typedef long long ll;

struct no{
    pair<ll, ll> p, s, t, b;
    explicit no(ll x=0, int sz=0): p(make_pair(x, sz)), s(make_pair(x, sz)),
                                   t(make_pair(x, sz)), b(make_pair(x, sz)){}
};

no st[400000],  v[100000];

void merge(no &n, no l, no r){
    if(l.t.second == 0){
        n = r;
        return;
    }
    if(r.t.second == 0){
        n = l;
        return;
    }

    n.p = max(l.p, make_pair(l.t.first + r.p.first, l.t.second + r.p.second));
    n.s = max(r.s, make_pair(r.t.first + l.s.first, r.t.second + l.s.second));
    n.t = make_pair(l.t.first + r.t.first, l.t.second + r.t.second);
    n.b = max(make_pair(l.s.first + r.p.first, l.s.second + r.p.second), max(l.b, r.b));
}

void build(int ind, int l, int r){
    if(l == r){
        st[ind] = v[l];
        return;
    }

    int mid = (l+r)/2;
    build(2*ind+1, l, mid);
    build(2*ind+2, mid+1, r);

    merge(st[ind], st[2*ind+1], st[2*ind+2]);
}

no query(int ind, int l, int r, int p, int q){
    if(l >= p && r <= q){
        return st[ind];
    }

    if(l > q || r < p){
        return no(0, 0);
    }

    int mid = (l+r)/2;
    no asw;
    merge(asw, query(2*ind+1, l, mid, p, q), query(2*ind+2, mid+1, r, p, q));

    return asw;
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        for(int i = 0; i != n; i++){
            int num;
            scanf("%d", &num);

            v[i] = no(num, 1);
        }
        build(0, 0, n-1);

        int m;
        cin >> m;

        for(int i = 0; i != m; i++){
            int p, q;
            scanf("%d %d", &p, &q);
            p--;
            q--;

            no asw = query(0, 0, n-1, p, q);
            printf("%lld %lld\n", asw.b.first, asw.b.second);
        }
    }
}