#include <iostream>
#include <vector>

using namespace std;

int main(){
    int s, t, n;
    while(cin >> s >> t >> n){

        vector<int> dist(n+1);
        for(int i = 0; i <= n; i++){
            cin >> dist[i];
        }

        vector<int> time(n);
        for(int i = 0; i != n; i++){
            cin >> time[i];
        }

        vector<int> v(n);
        for(int i = 0; i != n; i++){
            cin >> v[i];
        }

        int cont = 0;
        for(int i = 0; i != n; i++){
            cont += dist[i];

            if(cont < v[i]){
                cont += v[i]-cont;
            } 

            cont += time[i];
        }

        cont += dist[n];

        if(cont <= t){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
}
