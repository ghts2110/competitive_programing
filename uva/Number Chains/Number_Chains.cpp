#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool my(int p1, int p2){
    if(p1 > p2){
        return true;
    }
    return false;
}

int main(){
    string s;

    int f = true;
    while(cin >> s){
        if(s == "0"){
            break;
        }

        cout << "Original number was " << s << endl;
    
        vector<int> v1(s.size()), v2(s.size());
        for(int i = 0; i != s.size(); i++){
            v1[i] = s[i]-'0';
            v2[i] = v1[i];
        }
    
        map<int, bool> mp;
        int cont = 0;
        while(true){
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end(), my);
            
            cont++;
            int n1 = 0, n2 = 0, d = 1;
            for(int i = 1; i <= v1.size(); i++){
                n1 += v1[i-1] * d;
                n2 += v2[i-1] * d;
                d *= 10;
            }
           
            int num = n1-n2;
            

            cout << n1 << " - " << n2 << " = " << num << endl;
            if(mp[num] == true){
                break;
            }

            s = to_string(num);
            v1 = vector<int>(s.size());
            v2 = vector<int>(s.size());
            for(int i = 0; i != v1.size(); i++){
                v1[i] = s[i]-'0';
                v2[i] = s[i]-'0';
            } 

            mp[num] = true;
        }
       
        cout << "Chain length " << cont << endl << endl; 
    }
}
