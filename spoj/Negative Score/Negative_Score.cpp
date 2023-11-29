#include <iostream>
#include <vector>

using namespace std;

int st[4 * 1000000], v[1000000];

int build(int ind, int l, int r){
    if(l == r){
        return st[ind] = v[l];
    }

    int mid = (l+r)/2;
    return st[ind] = min(build(2*ind+1, l, mid), build(2*ind+2, mid+1, r));
}

int query(int a, int b, int ind, int l, int r){
    if(r < a || l > b){
        return 1000000000;
    }
    if(l >= a && r <= b){
        return st[ind];
    }

    int mid = (l+r)/2;
    return min(query(a, b, 2*ind+1, l, mid), query(a, b, 2*ind+2, mid+1, r));
}

int main(){
    int t;
    cin >> t;

    for(int test = 1; test <= t; test++){
        int n, q;
        scanf("%d %d", &n, &q);

        for(int i = 0; i != n; i++){
            scanf("%d", v+i);
        }

        build(0, 0, n-1);

        printf("Scenario #%d:\n", test);
        for(int i = 0; i != q; i++){
            int a, b;
            scanf("%d %d", &a, &b);

            printf("%d\n",query(a-1, b-1, 0, 0, n-1));
        }
    }
}