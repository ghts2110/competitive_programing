#include <iostream>
#include <cstring>

using namespace std;

int st[12000000];

void update(int ind, int l, int r, int p, int q, int x){
    if(st[2*ind+1] == -1 && l != r){
        st[2*ind+1] = st[ind];
    }
    if(st[2*ind+2] == -1 && l != r){
        st[2*ind+2] = st[ind];
    }
    if(l != r){
        st[ind] = -1;
    }

    if(l >= p && r<x){
        if(st[ind] == -1){
            st[ind] = x;
        }
        return;
    }

    if(l > x && r <= q){
        if(st[ind] == -1){
            st[ind] = x;
        }
        return;
    }

    if(l > q || r < p || l == r){
        return;
    }

    int mid = (l+r)/2;
    update(2*ind+1, l, mid, p, q, x);
    update(2*ind+2, mid+1, r, p, q, x);
}


void print(int ind, int l, int r){
    if(st[2*ind+1] == -1 && l != r){
        st[2*ind+1] = st[ind];
    }
    if(st[2*ind+2] == -1 && l != r){
        st[2*ind+2] = st[ind];
    }

    if(l == r){
        cout << st[ind]+1 << " ";
        return;
    }

    int mid = (l+r)/2;
    print(2*ind+1, l, mid);
    print(2*ind+2, mid+1, r);
}

int main(){
    int n, m;
    cin >> n >> m;

    memset(st, -1, sizeof st);
    while(m--){
        int p, q, x;
        cin >> p >> q >> x;
        p--;
        q--;
        x--;

        update(0, 0, n-1, p, q, x);
    }

    print(0, 0, n-1);
    cout << endl;
}