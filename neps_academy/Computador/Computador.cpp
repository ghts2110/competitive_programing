#include <iostream>

using namespace std;
typedef long long ll;

ll st[200000];
pair<ll, int> lz1[800000], lz2[800000];

void push1(int ind, int l, int r){
    if(lz1[ind].first == 0){
        return;
    }

    if(l != r){
        lz1[2*ind+1].first += lz1[ind].first;
        lz1[2*ind+1].second += lz1[ind].second;

        int mid = (l+r)/2;
        lz1[2*ind+2].first += lz1[ind].first-lz1[ind].second*(mid+1-l);
        lz1[2*ind+2].second += lz1[ind].second;
    }

    if(l == r){
        st[l] += lz1[ind].first;
    }

    lz1[ind] = make_pair(0, 0);
}

void push2(int ind, int l, int r){
    if(lz2[ind].first == 0){
        return;
    }

    if(l != r){
        int mid = (l+r)/2;
        lz2[2*ind+1].first += lz2[ind].first-lz2[ind].second*(r-mid);
        lz2[2*ind+1].second += lz2[ind].second;

        lz2[2*ind+2].first += lz2[ind].first;
        lz2[2*ind+2].second += lz2[ind].second;
    }

    if(l == r){
        st[l] += lz2[ind].first;
    }

    lz2[ind] = make_pair(0, 0);
}


void update1(int ind, int l, int r, int p, int q, int x){
    push2(ind, l, r);
    push1(ind, l, r);

    if(l >= p && r <= q){
        lz1[ind] = make_pair(x-(l-p), 1);
        push1(ind, l, r);
        return;
    }

    if(l > q || r < p){
        return;
    }

    int mid = (l+r)/2;
    update1(2*ind+1, l, mid, p, q, x);
    update1(2*ind+2, mid+1, r, p, q, x);
}

void update2(int ind, int l, int r, int p, int q, int x){
    push2(ind, l, r);
    push1(ind, l, r);

    if(l >= p && r <= q){
        lz2[ind] = make_pair(x-(q-r), 1);
        push2(ind, l, r);
        return;
    }

    if(l > q || r < p){
        return;
    }

    int mid = (l+r)/2;
    update2(2*ind+1, l, mid, p, q, x);
    update2(2*ind+2, mid+1, r, p, q, x);
}

void query(int ind, int l, int r, int x){
    push2(ind, l, r);
    push1(ind, l, r);

    if(l == r && l == x){
        cout << st[l] << endl;
        return;
    }
    if(l > x || r < x){
        return;
    }

    int mid = (l+r)/2;
    query(2*ind+1, l, mid, x);
    query(2*ind+2, mid+1, r, x);
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i != m; i++){
        int o, p, q, x;
        cin >> o;

        if(o == 1){
            cin >> p >> q;
            p--;

            update1(0, 0, n-1, p, p+q-1, q);
        }else if(o == 2){
            cin >> p >> q;
            p--;

            update2(0, 0, n-1, p-q+1, p, q);
        }else{
            cin >> x;
            x--;

            query(0, 0, n-1, x);
        }
    }

}