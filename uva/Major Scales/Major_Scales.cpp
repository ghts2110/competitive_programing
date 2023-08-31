#include <iostream>
#include <map>
#include <vector>
#include <string>

#define pb push_back

using namespace std;

int main(){ 
    string nota[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    map<string, vector<string>> mp;

    for(int i = 0; i != 12; i++){
        int index = i+2;
        for(int j = 0; j != 7; j++){
            if(index >= 12){
                index -= 12;
            }

            mp[nota[i]].pb(nota[index]);
            if(j == 1 || j == 5){
                index += 1;
            }else{
                index += 2;
            }
        }
    }

    string s;
    while(getline(cin, s)){
        if(s == "END"){
            break;
        }

        vector<string> asw;
        for(auto it : nota){
            bool value = true;

            for(int i = 0; i < s.size(); i+=2){
                string no = "";
                no += s[i];

                if(s[i+1] == '#'){
                    i++;
                    no += s[i];
                }
            
                bool val = true;
                for(auto j : mp[it]){
                    if(j == no){
                        val = false;
                        break;
                    }
                }

                if(val){
                    value = false;
                    break;
                }
            }

            if(value){
                asw.pb(it);
            }
        }
    
        for(int i = 0; i != asw.size(); i++){
            if(i != asw.size()-1){
                cout << asw[i] << " ";
                continue;
            }
            cout << asw[i];
        }

        cout << endl;
    }

}
