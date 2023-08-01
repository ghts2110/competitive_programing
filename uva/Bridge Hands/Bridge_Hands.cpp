#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#define pb push_back

using namespace std;

int main(){
    char c;
    map<int, char> t, value;
    t[0] = 'C';
    t[1] = 'D';
    t[2] = 'S';
    t[3] = 'H';
    value[10] = 'T';
    value[11] = 'J';
    value[12] = 'Q';
    value[13] = 'K';
    value[14] = 'A';

    while(cin >> c){
        if(c == '#'){
            break;
        }

        string s1, s2, s;
        cin >> s1 >> s2;
        s = s1 + s2;

        int cont = 0;
        vector<pair<int, int>> v1, v2, v3, v4;
        for(int i = 0; i < s.size(); i+=2){
            int tip, num;
            if(s[i] == 'C'){
                tip = 0;
            }else if(s[i] == 'D'){
                tip = 1;
            }else if(s[i] == 'S'){
                tip = 2;
            }else{
                tip = 3;
            }

            if(s[i+1] == 'A'){
                num = 14;
            }else if(s[i+1] == 'K'){
                num = 13;
            }else if(s[i+1] == 'Q'){
                num = 12;
            }else if(s[i+1] == 'J'){
                num = 11;
            }else if(s[i+1] == 'T'){
                num = 10;
            }else{
                num = s[i+1] - '0';
            }

            pair<int, int> p(tip, num);
            if(cont % 4 == 0){
                v1.pb(p);
            }else if(cont % 4 == 1){
                v2.pb(p);
            }else if(cont % 4 == 2){
                v3.pb(p);
            }else{
                v4.pb(p);
            }
            cont++;
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        sort(v3.begin(), v3.end());
        sort(v4.begin(), v4.end());

        
        vector<pair<int, int>> v;
        if(c == 'N'){
            for(int i = 0; i != 13; i++){
                v.pb(v2[i]);
            }
            for(int i = 0; i != 13; i++){
                v.pb(v3[i]);
            }
            for(int i = 0; i != 13; i++){
                v.pb(v4[i]);
            }
            for(int i = 0; i != 13; i++){
                v.pb(v1[i]);
            }
        }else if(c == 'S'){
            for(int i = 0; i != 13; i++){
                v.pb(v4[i]);
            }
            for(int i = 0; i != 13; i++){
                v.pb(v1[i]);
            }
            for(int i = 0; i != 13; i++){
                v.pb(v2[i]);
            }
            for(int i = 0; i != 13; i++){
                v.pb(v3[i]);
            }          
        }else if(c == 'W'){
            for(int i = 0; i != 13; i++){
                v.pb(v3[i]);
            }
            for(int i = 0; i != 13; i++){
                v.pb(v4[i]);
            }
            for(int i = 0; i != 13; i++){
                v.pb(v1[i]);
            }
            for(int i = 0; i != 13; i++){
                v.pb(v2[i]);
            }
        }else{
            for(int i = 0; i != 13; i++){
                v.pb(v1[i]);
            }
            for(int i = 0; i != 13; i++){
                v.pb(v2[i]);
            }
            for(int i = 0; i != 13; i++){
                v.pb(v3[i]);
            }
            for(int i = 0; i != 13; i++){
                v.pb(v4[i]);
            }
        }
      
        cont = 0;
        for(int i = 0; i != 52; i++){
            if(i % 13 == 0){
                if(cont == 0){
                    cout << "S: ";
                }else if(cont == 1){
                    cout << "W: ";
                }else if(cont == 2){
                    cout << "N: ";
                }else{
                    cout << "E: ";
                }
                cont++;
            }
            
            cout << t[v[i].first];

            if(i % 13 == 12){
                if(v[i].second >= 10){
                    cout << value[v[i].second] << endl; 
                }else{
                    cout << v[i].second << endl;
                }
                continue;
            }
            
            if(v[i].second >= 10){
                cout << value[v[i].second] << " "; 
            }else{
                cout << v[i].second << " ";
            }
            
        }
    }
}
