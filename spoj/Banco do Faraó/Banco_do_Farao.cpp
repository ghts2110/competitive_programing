#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct no{
    pair<ll, ll> p, s, t, b;
    explicit no(ll x=0, int sz=0): p(make_pair(x, sz)), s(make_pair(x, sz)),
                            t(make_pair(x, sz)), b(make_pair(x, sz)){}
};

no st[400000];
no rry[100000];

no merge(no l, no r){
    if(!l.t.second){
        return r;
    }else if(!r.t.second){
        return l;
    }

    no asw;
    asw.p = max(l.p, make_pair(l.t.first + r.p.first, l.t.second + r.p.second));
    asw.s = max(r.s, make_pair(l.s.first + r.t.first, l.s.second + r.t.second));
    asw.t = make_pair(l.t.first + r.t.first, l.t.second + r.t.second);
    asw.b = max(l.b, max(r.b, make_pair(l.s.first + r.p.first, l.s.second + r.p.second)));

    return asw;
}

void build(int ind, int l, int r){
    if(l == r){
        st[ind] = rry[l];
        return;
    }

    int mid = (l+r)/2;
    build(2*ind+1, l, mid);
    build(2*ind+2, mid+1, r);

    st[ind] = merge(st[2*ind+1], st[2*ind+2]);
}

no query(int a, int b, int ind, int l, int r){
    if(a > r || b < l){
        return no(0, 0);
    }

    if(a <= l && b >= r){
        return st[ind];
    }

    int mid = (l+r)/2;
    no n1 = query(a, b, 2*ind+1, l, mid);
    no n2 = query(a, b, 2*ind+2, mid+1, r);

    return merge(n1, n2);
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

            rry[i] = no(num, 1);
        }

        build(0, 0, n-1);

        int q;
        scanf("%d", &q);
        while(q--){
            int a, b;
            scanf("%d %d", &a, &b);
            a--;
            b--;

            no best = query(a, b, 0, 0, n-1);
            printf("%lld %lld\n", best.b.first, best.b.second);
        }
    }
}