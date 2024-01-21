#include <iostream>

using namespace std;

pair<int, int> st[400000];
int v[100000];

pair<int, int> sp(pair<int, int> p1, pair<int, int> p2){
    if(p1.first < p2.first){
        p1.first = p2.first;
    }else if(p1.second < p2.first){
        p1.second = p2.first;
    }

    if(p1.first > p1.second){
        swap(p1.first, p1.second);
    }
    if(p1.first < p2.second){
        p1.first = p2.second;
    }else if(p1.second < p2.second){
        p1.second = p2.second;
    }
    if(p1.first > p1.second){
        swap(p1.first, p1.second);
    }

    return p1;
}

void build(int ind, int l, int r){
    if(l == r){
        st[ind] = make_pair(0, v[l]);
        return;
    }

    int mid = (l+r)/2;
    build(2*ind+1, l, mid);
    build(2*ind+2, mid+1, r);

    st[ind] = sp(st[2*ind+1], st[2*ind+2]);
}

pair<int, int> query(int ind, int l, int r, int p, int q){
    if(l >= p && r <= q){
        return st[ind];
    }

    if(l > q || r < p){
        return make_pair(0, 0);
    }

    int mid = (l+r)/2;
    return sp(query(2*ind+1, l, mid, p, q), query(2*ind+2, mid+1, r, p, q));
}

void update(int ind, int l, int r, int p, int q){
    if(l == r && l == p){
        st[ind] = make_pair(0, q);
        return;
    }

    if(r < p || l > p){
        return;
    }

    int mid = (l+r)/2;
    update(2*ind+1, l, mid, p, q);
    update(2*ind+2, mid+1, r, p, q);

    st[ind] = sp(st[2*ind+1], st[2*ind+2]);
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i != n; i++){
        cin >> v[i];
    }

    build(0, 0, n-1);
    int k;
    cin >> k;

    for(int i = 0; i != k; i++){
        char c;
        int p, q;
        cin >> c >> p >> q;
        p--;

        if(c == 'Q'){
            q--;
            pair<int, int> pr = query(0, 0, n-1, p, q);
            cout << pr.first + pr.second << endl;
        }else{
            update(0, 0, n-1, p, q);
        }
    }
}