#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main(){
    int t;
    while(cin >> t){
        if(t==-1){
            break;
        }

        int w=0;

        cout << "Round " << t << endl;
        string s, p;
        cin >> s >> p;
        
        bitset<26> bt(0);
        for(int i = 0; i != p.size(); i++){
            bool validate = true;
            
            if(bt[p[i]-'a'] == 1){
                validate = false;
            }
            bt[p[i]-'a'] = 1;

            for(int j = 0; j != s.size(); j++){
                if(p[i] == s[j]){
                    validate = false;
                    s.erase(s.begin()+j);
                    j--;
                }
            }

            if(s.size() == 0){
                cout << "You win." << endl;
                break;
            }
            if(validate){
                w++;
                if(w == 7){
                    cout << "You lose." << endl;
                    break;
                }
            }
            if(i == p.size()-1){
                cout << "You chickened out." << endl;
                break;
            }
        }
    }
}
