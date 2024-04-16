#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> adj;
vector<int> deep, first, euler, visit;

void dfs(int no, int d){
    visit[no] = 1;
    deep[no] = d;
    first[no] = euler.size();
    euler.push_back(no);

    for(auto it : adj[no]){
        if(!visit[it]){
            dfs(it, d+1);
            euler.push_back(no);
        }
    }
}

int rry[100000];
void build(int ind, int l, int r){
    if(r == l){
        rry[ind] = euler[r];
        return;
    }

    int mid = (r+l)/2;
    build(2*ind+1, l, mid);
    build(2*ind+2, mid+1, r);

    int p = rry[2*ind+1];
    int q = rry[2*ind+2];
    if(deep[p] < deep[q]){
        rry[ind] = p;
    }else{
        rry[ind] = q;
    }
}

int asw;
void query(int ind, int l, int r, int p, int q){
    if(l >= p && r <= q){
        if(deep[asw] > deep[rry[ind]]){
            asw = rry[ind];
        }
        return ;
    }

    if(r < p || q < l){
        return;
    }

    int mid = (r+l)/2;
    query(2*ind+1, l, mid, p, q);
    query(2*ind+2, mid+1, r, p, q);
}


int main(){
    int t;
    cin >> t;

    int test = 1;
    while(t--){
        int n;
        cin >> n;
        adj = vector<vector<int>>(n+1);
        for(int i = 1; i <= n; i++){
            int m;
            cin >> m;

            for(int j = 0; j != m; j++){
                int num;
                cin >> num;
                adj[i].push_back(num);
                adj[num].push_back(i);
            }
        }
        deep = vector<int>(n+1, 1e9);
        first = vector<int>(n+1);
        visit = vector<int>(n+1);
        euler = vector<int>(0);

        dfs(1, 0);

        int q;
        cin >> q;
        build(0, 0, euler.size()-1);

        cout << "Case "<<test<<":"<<endl;
        test++;
        for(int i = 0; i != q; i++){
            int p, q;
            cin >> p >> q;

            asw = 0;
            if(first[p]-1 > first[q]-1){
                swap(p, q);
            }

            query(0, 0, euler.size()-1, first[p], first[q]);
            cout << asw << endl;
        }
    }
}
