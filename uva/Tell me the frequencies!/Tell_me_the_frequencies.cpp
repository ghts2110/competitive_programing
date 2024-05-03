#include<iostream>
#include<map>
#include<string>
#include<vector>
#include <algorithm>

using namespace std;

bool comparar2(const pair <int, int>& a, const pair <int, int>& b){
    if(a.second < b.second){
        return true;
    }
    else if(a.second==b.second && a.first>b.first){
        return true;
    }
    return false;
}

int main(){
    string s;
    bool f=true;
    while(getline(cin, s)){

        if(!f){
            cout<<endl;
        }

        map<int, int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }

        vector < pair <int, int> > v(m.begin(), m.end());
        sort(v.begin(), v.end(), comparar2);

        for(int i=0;i<v.size();i++){
            printf("%d %d\n",v[i].first, v[i].second);
        }

        f=false;
    }

    return 0;
}
