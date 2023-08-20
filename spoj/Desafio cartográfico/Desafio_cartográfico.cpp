#include <iostream>
#include <vector>

#define pb push_back

using namespace std;

int mx = 0;
    
vector<int> adj[1000001];
int visit[1000001] = {0};
int cont2[1000001] = {0}, cont[1000001] = {0};

int main(){
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n-1; i++){
        int a, b;
        scanf("%d %d", &a, &b);    

        adj[a].pb(b);
        adj[b].pb(a);
    }
 
    vector<int> s;
    s.reserve(1000001);

    s.pb(1);
    int start=1;
    while(!s.empty()){
        int num = s.back();
        s.pop_back();
        visit[num] = 1;
        cont[num]++;

        for(std::vector<int>::iterator i = adj[num].begin(); i != adj[num].end(); i++){
            if(visit[*i] == 0){
                s.push_back(*i);
                cont[*i] = cont[num];
            }
        }

        if(mx < cont[num]){
            mx = cont[num];
            start = num;
        }
    }
    
    s.pb(start);
    mx = 0;
    
    while(!s.empty()){
        int num = s.back();
        s.pop_back();
        visit[num] = 2;
        cont2[num]++;
    
        for(std::vector<int>::iterator i = adj[num].begin(); i != adj[num].end(); i++){
            if(visit[*i] == 1){
                s.push_back(*i);
                cont2[*i] = cont2[num];
            }
        }

        if(mx < cont2[num]){
            mx = cont2[num];
        }
    }


    printf("%d\n", mx-1);
    return 0;
}

