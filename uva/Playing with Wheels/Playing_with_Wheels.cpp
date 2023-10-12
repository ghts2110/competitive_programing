#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>

using namespace std;

int main(){
    vector<vector<int> > adj(10000);
    for(int i = 0; i != 10000; i++){
        int num;
        if(i%10 == 0){
            num = i+9;
        }else{
            num = i-1;
        }
        adj[i].push_back(num);

        if(i%10 == 9){
            num = i-9;
        }else{
            num = i+1;
        }
        adj[i].push_back(num);

        if(i/10%10 == 0){
            num = i+90;
        }else{
            num = i-10;
        }
        adj[i].push_back(num);

        if(i/10%10 == 9){
            num = i-90;
        }else{
            num = i+10;
        }
        adj[i].push_back(num);

        if(i/100%10 == 0){
            num = i+900;
        }else{
            num = i-100;
        }
        adj[i].push_back(num);

        if(i/100%10 == 9){
            num = i-900;
        }else{
            num = i+100;
        }
        adj[i].push_back(num);

        if(i/1000%10 == 0){
            num = i+9000;
        }else{
            num = i-1000;
        }
        adj[i].push_back(num);

        if(i/1000%10 == 9){
            num = i-9000;
        }else{
            num = i+1000;
        }
        adj[i].push_back(num);
    }

    int t;
    cin >> t;

    while(t--){
        string start, finish;
        for (int i = 0; i < 4; i++) {
            char c;
            cin >> c;

            start+=c;
        }
        for (int i = 0; i < 4; i++) {
            char c;
            cin >> c;

            finish+=c;
        }

        int n;
        cin >> n;

        map<int, bool> mp;
        for(int i = 0; i != n; i++){
            string s;
            for (int j = 0; j < 4; j++) {
                char c;
                cin >> c;

                s+=c;
            }

            mp[stoi(s)] = true;
        }

        queue<int> q;
        q.push(stoi(start));
        vector<int> visit(10000, -1);
        visit[stoi(start)] = 0;

        while(!q.empty()){
            int no = q.front();
            q.pop();

            for(auto it : adj[no]){
                if(visit[it] == -1 && !mp[it]){
                    visit[it] = visit[no]+1;
                    q.push(it);
                }
            }
        }

        int asw = stoi(finish);
        cout << visit[asw] << endl;
    }
}