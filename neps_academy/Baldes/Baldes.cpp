#include <iostream>

using namespace std;
int v[100000];
pair<int, pair<int, int> > st[400000];

void merge1(int ind){
    st[ind].second.first = min(st[2*ind+1].second.first, st[2*ind+2].second.first);

    st[ind].second.second = max(st[2*ind+1].second.second, st[2*ind+2].second.second);

    st[ind].first = max(st[2*ind+1].first, st[2*ind+2].first);
    st[ind].first = max(st[ind].first, st[2*ind+1].second.second - st[2*ind+2].second.first);
    st[ind].first = max(st[ind].first, st[2*ind+2].second.second - st[2*ind+1].second.first);
}

void build(int ind, int l, int r){
    if(l == r){
        st[ind] = make_pair(0, make_pair(v[l], v[l]));
        return;
    }

    int mid = (l+r)/2;
    build(2*ind+1, l, mid);
    build(2*ind+2, mid+1, r);

    merge1(ind);
}

void update(int ind, int l, int r, int p, int q){
    if(l == r && l == q){
        st[ind].second.first = min(st[ind].second.first, p);
        st[ind].second.second = max(st[ind].second.second, p);
        return;
    }

    if(l > q || r < q){
        return;
    }

    int mid = (l+r)/2;
    update(2*ind+1, l, mid, p, q);
    update(2*ind+2, mid+1, r, p, q);

    merge1(ind);
}

pair<int, pair<int, int> > merge2(pair<int, pair<int, int> > p1, pair<int, pair<int, int> > p2){
    if(p1.first == -1){
        return p2;
    }

    if(p2.first == -1){
        return p1;
    }

    p1.first = max(p1.first, p2.first);
    p1.first = max(p1.first, p1.second.second - p2.second.first);
    p1.first = max(p1.first, p2.second.second - p1.second.first);

    p1.second.first = min(p1.second.first, p2.second.first);
    p1.second.second = max(p1.second.second, p2.second.second);

    return p1;
}

pair<int, pair<int, int> > query(int ind, int l, int r, int p, int q){
    if(l >= p && r <= q){
        return st[ind];
    }

    if(r < p || l > q){
        return make_pair(-1, make_pair(-1, -1));
    }

    int mid = (l+r)/2;

    return merge2(query(2*ind+1, l, mid, p, q), query(2*ind+2, mid+1, r, p, q));
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i != n; i++){
        cin >> v[i];
    }

    build(0, 0, n-1);

    for(int i = 0; i != m; i++){
        int x, p, q;
        cin >> x >> p >> q;

        if(x == 1){
            q--;
            update(0, 0, n-1, p, q);
        }else{
            p--;
            q--;

            cout << query(0, 0, n-1, p, q).first << endl;
        }
    }
}