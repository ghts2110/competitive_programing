#include <iostream>

using namespace std;

int st[400000][9];
int lz[400000];
int n, q;

void build(int ind, int l, int r){
    for(int i = 0; i != 9; i++){
        if(i == 1){
            *((*(st+ind))+i) = r-l+1;
        }else{
            *((*(st+ind))+i) = 0;
        }
    }

    if(l == r){
        return;
    }

    int mid = (l+r)/2;

    build(2*ind+1, l, mid);
    build(2*ind+2, mid+1, r);
}

void push(int ind, int l, int r){
    if(lz[ind] != -1){
        int v[9];
        for(int i = 0; i != 9; i++){
            v[(i+(*(lz+ind)))%9] = (*(st+ind))[i];
        }
        for(int i = 0; i != 9; i++){
            (*(st+ind))[i] = v[i];
        }


        if(l != r) {
            if (*(lz+(2 * ind + 1)) != -1) {
                *(lz+(2 * ind + 1)) += lz[ind];
            } else {
                *(lz+(2 * ind + 1)) = lz[ind];
            }

            if (*(lz+(2 * ind + 2)) != -1) {
                *(lz+(2 * ind + 2)) += lz[ind];
            } else {
                *(lz+(2 * ind + 2)) = lz[ind];
            }
        }

        *(lz+ind) = -1;
    }
}

int save[9];
void query(int a, int b, int ind, int l, int r){
    push(ind, l, r);
    if(a > r || b < l){
        return;
    }
    push(ind, l, r);

    if(a <= l && b >= r){
        for(int i = 0; i != 9; i++){
            save[i] += (*(st+ind))[i];
        }

        return;
    }

    int mid = (l+r)/2;
    query(a, b, 2*ind+1, l, mid);
    query(a, b, 2*ind+2, mid+1, r);
}

void update(int a, int b, int ind, int l, int r, int val){
    if(a > r || b < l){
        return;
    }

    if(a <= l && b >= r){
        if(*(lz+ind) != -1){
            *(lz+ind) += val;
        }else{
            *(lz+ind) = val;
        }

        push(ind, l, r);
        return;
    }

    int mid = (l+r)/2;
    update(a, b, 2*ind+1, l, mid, val);
    update(a, b, 2*ind+2, mid+1, r, val);

    for(int i = 0; i != 9; i++){
        (*(st+ind))[i] = (*(st+(2*ind+1)))[i] + (*(st+(2*ind+2)))[i];
    }
}

void print(int ind, int l, int r){
    push(ind, l, r);
    if(l == r){
        for(int i = 0; i != 9; i++){
            if((*(st+ind))[i]){
                printf("%d\n", i);
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
    scanf("%d %d", &n, &q);

    build(0, 0, n-1);
    for(int i = 0; i != 400000; i++){
        *(lz+i) = -1;
    }

    while(q--){
        int a, b;
        scanf("%d %d", &a, &b);

        for(int & i : save){
            i = 0;
        }

        query(a, b, 0, 0, n-1);

        int mx = 0, val = 0;
        for(int i = 0;i != 9; i++){
            if(mx <= save[i]){
                mx = save[i];
                val = i;
            }
        }

        update(a, b, 0, 0, n-1, val);
    }

    print(0, 0, n-1);
}