#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
int st[400000][9];
int lz[400000];

void build(int ind, int l, int r){
    st[ind][1] = r-l+1;
    if(l == r){
        return;
    }

    int mid = (l+r)/2;
    build(2*ind+1, l, mid);
    build(2*ind+2, mid+1, r);
}

void push(int ind, int l, int r){
    if(lz[ind] == 0){
        return;
    }

    if(l != r){
        lz[2*ind+1] += lz[ind];
        lz[2*ind+2] += lz[ind];
    }

    int save[9];
    for(int i = 0; i != 9; i++){
        save[i] = st[ind][i];
    }

    for(int i = 0; i != 9; i++){
        st[ind][(i+lz[ind])%9] = save[i];
    }

    lz[ind] = 0;
}

vector<int> save;
void query(int ind, int l, int r, int p, int q){
    push(ind, l, r);
    if(l >= p && r <= q){
        for(int i = 0; i != 9; i++){
            save[i] += st[ind][i];
        }
        return;
    }

    if(l > q || r < p){
        return;
    }

    int mid = (l+r)/2;
    query(2*ind+1, l, mid, p, q);
    query(2*ind+2, mid+1, r, p, q);
}

void update(int ind, int l, int r, int p, int q, int x){
    push(ind, l, r);

    if(l >= p && r <= q){
        lz[ind] = x;
        push(ind, l, r);
        return;
    }

    if(l > q || r < p){
        return;
    }

    int mid = (l+r)/2;
    update(2*ind+1, l, mid, p, q, x);
    update(2*ind+2, mid+1, r, p, q, x);

    for(int i = 0; i != 9; i++){
        st[ind][i] = st[2*ind+1][i] + st[2*ind+2][i];
    }
}

void print(int ind, int l, int r){
    push(ind, l, r);
    if(l == r){
        for(int i = 0; i != 9; i++){
            if(st[ind][i] == 1){
                cout << i << endl;
                break;
            }
        }
        return;
    }

    int mid = (l+r)/2;
    print(2*ind+1, l, mid);
    print(2*ind+2, mid+1, r);
}
int main(){
    int n, m;
    cin >> n >> m;

    build(0, 0, n-1);
    for(int i = 0; i != m; i++){
        int p, q;
        cin >> p >> q;

        save = vector<int> (9);
        query(0, 0, n-1, p, q);
        int mn = -1, ndx = -1;
        for(int j = 0; j != 9; j++){
            if(mn <= save[j]){
                ndx = j;
                mn = save[j];
            }
        }

        update(0, 0, n-1, p, q, ndx);
    }

    print(0, 0, n-1);
}