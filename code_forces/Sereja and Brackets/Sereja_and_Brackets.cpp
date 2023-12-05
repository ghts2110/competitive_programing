#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;
int st[4000000][3];

void build(int ind, int l, int r){
    if(l == r){
        if(s[l] == '('){
            st[ind][0] = 1;
            st[ind][1] = 0;
            st[ind][2] = 0;
        }else{
            st[ind][0] = 0;
            st[ind][1] = 1;
            st[ind][2] = 0;
        }

        return;
    }

    int mid = (l+r)/2;
    build(2*ind+1, l, mid);
    build(2*ind+2, mid+1, r);

    int t = min(st[2*ind+1][0], st[2*ind+2][1]) * 2;
    st[ind][2] = t + st[2*ind+1][2] + st[2*ind+2][2];
    st[ind][0] = st[2*ind+1][0] + st[2*ind+2][0] - (t/2);
    st[ind][1] = st[2*ind+1][1] + st[2*ind+2][1] - (t/2);
}

vector<int> query(int a, int b, int ind, int l, int r){
    if(l > b || r < a){
        vector<int> v(3);
        v[0] = 0;
        v[1] = 0;
        v[2] = 0;
        return v;
    }

    if(l >= a && r <= b){
        vector<int> v(3);

        v[0] = st[ind][0];
        v[1] = st[ind][1];
        v[2] = st[ind][2];
        return v;
    }

    int mid = (l+r)/2;
    vector<int> v1 = query(a, b, 2*ind+1, l, mid);
    vector<int> v2 = query(a, b, 2*ind+2, mid+1, r);

    vector<int> v(3);
    int t = min(v1[0], v2[1]) * 2;
    v[2] = t + v1[2] + v2[2];
    v[0] = v1[0] + v2[0] - (t/2);
    v[1] = v1[1] + v2[1] - (t/2);

    return v;
}

int main(){
    cin >> s;

    int n;
    scanf("%d", &n);

    int sz = s.size();
    build(0, 0, sz-1);

    while(n--){
        int a,b;
        scanf("%d %d", &a, &b);

        a--;
        b--;
        printf("%d\n", query(a, b, 0, 0, sz-1)[2] );
    }
}