#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k, m;
    while(cin >> n >> k >> m){
        if(!n && !k && !m){
            break;
        }

        vector<pair<int, int>> v(n+2);
        for(int i = 1; i <= n; i++){
            v[i].first = i-1;
            v[i].second = i+1;
        }
        v[1].first = n;
        v[n].second = 1;
    
        int f = 1, s = n, cont = n;
       
        vector<int> visit(n+1, true);
        while(cont != 0){
            for(int j = 0; j != k-1; j++){
                f = v[f].second;
            }
            for(int j = 0; j != m-1; j++){
                s = v[s].first;
            }

            v[v[f].first].second = v[f].second;
            v[v[f].second].first = v[f].first;
            visit[f] = false;
            cont--;
            
            printf("%3d", f);
            f = v[f].second;

            if(visit[s]){
                v[v[s].first].second = v[s].second;
                v[v[s].second].first = v[s].first;
                visit[s] = false;
                cont--;

                printf("%3d", s);
                if(f == s){
                    f = v[f].second;
                }
                s = v[s].first;
            }else{
                s = v[s].first;
            }
        
            if(cont != 0){
                printf(",");
            }
        }
        printf("\n");
    }
}
