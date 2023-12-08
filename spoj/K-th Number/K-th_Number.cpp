#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> st[400000];
pair<int, int> rry[100000];

void merge(vector<int> &v, vector<int> &l, vector<int> &r){
    int sz1 = l.size();
    int sz2 = r.size();

    int i = 0, j = 0;
    v = vector<int> (sz1+sz2);
    for(int k = 0; k != sz1+sz2; k++){
        if(j == sz2 || (i != sz1 && l[i] < r[j])){
            v[k] = l[i];
            i++;
        }else{
            v[k] = r[j];
            j++;
        }
    }
}

void build(int ind, int l, int r){
    if(l == r){
        st[ind].push_back(rry[l].second);
        return;
    }

    int mid = (l+r)/2;
    build(2*ind+1, l, mid);
    build(2*ind+2, mid+1, r);

    merge(st[ind], st[2*ind+1], st[2*ind+2]);
}

vector<int> v;

int query(int a, int b, int ind, int l, int r, int c){
    if(l == r){
        return st[ind][0];
    }

    int mid = (l+r)/2;
    int i = upper_bound(st[2*ind+1].begin(), st[2*ind+1].end(), b) -
            lower_bound(st[2*ind+1].begin(), st[2*ind+1].end(), a);

    if(i > c) {
        return query(a, b, 2 * ind + 1, l, mid, c);
    }
    return query(a, b, 2*ind+2, mid+1, r, c-i);

}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int save[n];
    for(int i = 0; i != n; i++){
        int num;
        cin >> num;
        save[i] = num;
        rry[i] = make_pair(num, i);
    }

    sort(rry, rry+n);
    build(0, 0, n-1);

    while(m--){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--;
        b--;
        c--;

        v.clear();
        int ind = query(a, b, 0, 0, n-1, c);

        printf("%d\n", save[ind]);
    }
}