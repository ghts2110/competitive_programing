#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll v[100000], st[400000];

void build(int ind, int l, int r){
    if(l == r){
        if(v[l] > 0){
            st[ind] = 1;
        }else if(v[l] < 0){
            st[ind] = -1;
        }else{
            st[ind] = 0;
        }
        return;
    }

    int mid = (r+l)/2;
    build(2*ind+1, l, mid);
    build(2*ind+2, mid+1, r);

    st[ind] = st[2*ind+1] * st[2*ind+2];
}

void update(int ind, int l, int r, int p, int q){
    if(l == r && l == p){
        if(q > 0){
            st[ind] = 1;
        }else if(q < 0){
            st[ind] = -1;
        }else{
            st[ind] = 0;
        }
        return;
    }

    if(l > p || r < p){
        return;
    }

    int mid = (r+l)/2;
    update(2*ind+1, l, mid, p, q);
    update(2*ind+2, mid+1, r, p, q);

    st[ind] = st[2*ind+1] * st[2*ind+2];
}

ll query(int ind, int l, int r, int p, int q){
    if(l >= p && r <= q){
        return st[ind];
    }

    if(l > q || r < p){
        return 1;
    }

    int mid = (r+l)/2;
    return query(2*ind+1, l, mid, p, q) * query(2*ind+2, mid+1, r, p, q);
}

int main(){
    int n, k;
    while(cin >> n >> k){
        for(int i = 0; i != n; i++){
            cin >> v[i];
        }

        build(0, 0, n-1);

        for(int i = 0; i != k; i++){
            char c;
            int p, q;
            cin >> c >> p >> q;
            p--;

            if(c == 'C'){
                update(0, 0, n-1, p, q);
            }else{
                q--;
                ll num = query(0, 0, n-1, p, q);
                if(num == 0){
                    cout << 0;
                }else if(num > 0){
                    cout << '+';
                }else{
                    cout << '-';
                }
            }
        }

        cout << endl;
    }


}