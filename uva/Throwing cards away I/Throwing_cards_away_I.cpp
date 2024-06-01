#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }

        vector<pair<int, int>> v(n);
        for(int i = 0; i != n; i++){
            v[i] = {i-1, i+1};
        }
        v[0].first = n-1;
        v[n-1].second = 0;

        vector<int> disc;
        int ind = 0;
        for(int i = 0; i != n-1; i++){
            disc.push_back(ind+1);
            v[v[ind].first].second = v[ind].second;
            v[v[ind].second].first = v[ind].first;
            ind = v[ind].second;
            ind = v[ind].second;
        }

        cout << "Discarded cards:";
        for(int i = 0; i != disc.size(); i++){
            cout<< " " << disc[i];
            if(i != disc.size() -1){
                cout << ",";
            }
        }

        cout << endl;
        cout << "Remaining card: " << ind+1 << endl;
    }
}
