#include <iostream>
#include <cstring>

using namespace std;

long long st[400000], lz[400000];

void push(int ind, int l, int r){
    if(lz[ind]){
        st[ind] += lz[ind] * (r-l+1);
        if(l != r){
            lz[2*ind+1] += lz[ind];
            lz[2*ind+2] += lz[ind];
        }

        lz[ind] = 0;
    }
}

long long update(int a, int b, int ind, int l, int r, int val){
    push(ind, l, r);
    if(l > b || r < a){
        return st[ind];
    }

    if(a <= l && b >= r){
        lz[ind] += val;
        push(ind, l, r);

        return st[ind];
    }

    int mid = (l+r)/2;
    return st[ind] = update(a, b, 2*ind+1, l, mid, val) + update(a, b, 2*ind+2, mid+1, r, val);
}

long long query(int a, int b, int ind, int l, int r){
    push(ind, l, r);
    if(l > b || r < a){
        return 0;
    }

    if(a <= l && b >= r){
        return st[ind];
    }

    int mid = (l+r)/2;
    return query(a, b, 2*ind+1, l, mid) + query(a, b, 2*ind+2, mid+1, r);
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n, c;
        scanf("%d %d", &n, &c);

        memset(st, 0, sizeof(st));
        memset(lz, 0, sizeof(lz));

        while(c--){
            int num, p, q;
            scanf("%d %d %d", &num, &p, &q);
            p--;
            q--;

            if(!num){
                int val;
                scanf("%d", &val);

                update(p, q, 0, 0, n-1, val);
            }else{
                printf("%lld\n", query(p, q, 0, 0, n-1));
            }
        }
    }
}