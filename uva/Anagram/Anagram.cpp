#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool my(string s1, string s2){
    cout << "";
    for(int i = 0; i != s1.size(); i++){
        char c1 = tolower(s1[i]), c2 = tolower(s2[i]);
        if(c1 == c2){

            int v1, v2;
            if(s1[i] >= 'A' && s1[i] <= 'Z'){
                v1 = 0;
            }else{
                v1 = 1;
            }

            if(s2[i] >= 'A' && s2[i] <= 'Z'){
                v2 = 0;
            }else{
                v2 = 1;
            }
            

            if(v1 == v2){
                continue;
            }
            return v1<v2;
        }
        return c1 < c2;
    }

    return false;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        sort(s.begin(), s.end());
        vector<string> v;

        do{
            v.push_back(s);
        }while(next_permutation(s.begin(), s.end()));

        sort(v.begin(), v.end(), my);
        for(auto it: v){
            cout << it << endl;
        }
    }
}
