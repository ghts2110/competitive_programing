#include <iostream>
#include <string>

using namespace std;

int v[100000];
char st[400000];

char build(int ind, int l, int r){
    if (l == r){
        if(v[l] == 0){
            return st[ind] = '0';
        }else if(v[l] > 0) {
            return st[ind] = '+';
        }
        return st[ind] = '-';
    }

    int mid = (l+r)/2;
    char c1 = build(2*ind+1, l, mid), c2 = build(2*ind+2, mid+1, r);
    if(c1 == '0' || c2 == '0'){
        return st[ind] = '0';
    }else if(c1 == c2){
        return st[ind] = '+';
    }
    return st[ind] = '-';
}

char update(int a, int b, int ind, int l, int r){
    if(a > r || a < l){
        return st[ind];
    }
    if(l == r){
        if(b == 0){
            return st[ind] = '0';
        }else if(b > 0){
            return st[ind] = '+';
        }else{
            return st[ind] = '-';
        }
    }

    int mid = (l+r)/2;
    char c1 = update(a, b, 2*ind+1, l, mid), c2 = update(a, b, 2*ind+2, mid+1, r);
    if(c1 == '0' || c2 == '0'){
        return st[ind] = '0';
    }else if(c1 == c2){
        return st[ind] = '+';
    }
    return st[ind] = '-';
}

char query(int a, int b, int ind, int l, int r){
    if(a > r || b < l){
        return '+';
    }

    if(l >= a && r <= b){
        return st[ind];
    }

    int mid = (l+r)/2;
    char c1 = query(a, b, 2*ind+1, l, mid), c2 = query(a, b, 2*ind+2, mid+1, r);
    if(c1 == '0' || c2 == '0'){
        return '0';
    }else if(c1 == c2){
        return '+';
    }
    return '-';
}

int main(){
    int n, k;
    while(cin >> n >> k){
        string s;

        for(int i = 0; i != n; i++){
            cin >> v[i];
        }

        build(0, 0, n-1);
        for(int i = 0; i != k; i++){
            char c;
            int a, b;
            cin >> c >> a >> b;
            a--;

            if(c == 'C'){
                update(a, b, 0, 0, n-1);
            }else{
                b--;
                s += query(a, b, 0, 0, n-1);
            }
        }

        cout << s << endl;
    }
}