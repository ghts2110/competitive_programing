#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool my(pair<int, pair<int, pair<int, pair<string, int> > > > i, pair<int, pair<int, pair<int, pair<string, int> > > > j){
    if(i.first != j.first){
        return i.first < j.first;
    }

    if(i.second.first != j.second.first){
        return i.second.first < j.second.first;
    }

    if(i.second.second.first != j.second.second.first){
        return i.second.second.first < j.second.second.first;
    }

    string s1, s2;
    for(auto it : i.second.second.second.first){
        s1 += tolower(it);
    }
    for(auto it : j.second.second.second.first){
        s2 += tolower(it);
    }

    if(s1 != s2){
        return s1 < s2;
    }

    return i.second.second.second.second < j.second.second.second.second;
}

int main(){
    int n;

    while(cin >> n){
        vector<pair<int, pair<int, pair<int, pair<string, int> > > > > v(n);
        for(int i = 0; i != n; i++){
            string s;
            cin >> s;

            int a, b, c;
            scanf(" : %d min %d sec %d ms", &a, &b, &c);

            v[i] = make_pair(a, make_pair(b, make_pair(c, make_pair(s, i))));
        }

        sort(v.begin(), v.end(), my);

        int cont = 1;
        for(int i = 0; i != n; i++){
            if(i % 2 == 0){
                cout << "Row " << cont << endl;
                cont++;
            }

            cout << v[i].second.second.second.first << endl;
        }

        cout << endl;
    }
}
