#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<string, int> > v(n);

    int last;
    for(int i = 0; i != n; i++){
        string s;
        cin >> s;

        int n = 0;
        if(s == "?"){
            n = 1e9;
        }else{
            last = i;
        }

        v[i] = make_pair(s, n);
    }

    for(int i = 1; i < v.size(); i++){
        if(v[i].second > v[i-1].second+1){
            v[i].second = v[i-1].second+1;
            v[i].first = "right of " + v[i-1].first;
        }
    }

    for(int i = last-1; i > -1; i--){
        if(v[i].second > v[i+1].second+1){
            v[i].second = v[i+1].second+1;
            v[i].first = "left of " + v[i+1].first;
        }else if(v[i].second == v[i+1].second+1 ){
            v[i].first = "middle of ";
            string save;
            int cont = 1;
            int sz = v[i-1].first.size();
            while(v[i-1].first[sz-cont] != ' ' && sz-cont > -1){
                save = v[i-1].first[v[i-1].first.size()-cont] + save;
                cont++;
            }

            v[i].first += save;
            v[i].first +=" and ";

            save = "";
            cont = 1;
            sz = v[i+1].first.size();
            while(v[i+1].first[sz-cont] != ' ' && sz-cont > -1){
                save = v[i+1].first[v[i+1].first.size()-cont] + save;
                cont++;
            }
            v[i].first += save;
        }
    }

    cin >> n;
    for(int i = 0; i != n; i++){
        int num;
        cin >> num;

        cout << v[num-1].first << endl;
    }


}