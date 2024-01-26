#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int st[400000];

void merge(int ind){

}

void build(int ind, int l, int r){
    if(l == r){

        return;
    }

    int mid = (l+r)/2;
    build(2*ind+1, l, mid);
    build(2*ind+2, mid+1,  r);

    merge(ind);
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);


        vector<vector<int> > v(n, vector<int> (3));
        for(int i = 0; i != n; i++){
            scanf("%d %d %d", &v[i][0], &v[i][1], &v[i][2]);
        }

        sort(v.begin(), v.end());

        build(0, 0, n-1);

        vector<int> bit(100001, 1e9);

        int asw = 0;
        for(int i = 0; i != n; i++){
            int mn = 1e9;

            for(int j = v[i][1]; j != 0; j -= j&-j){
                mn = min(mn, bit[j]);
            }

            if(v[i][2] < mn){
                asw++;
            }

            for(int j = v[i][1]; j <= 100000; j += j&-j){
                bit[j] = min(bit[j], v[i][2]);
            }
        }

        printf("%d\n", asw);
    }

}
