#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string>dic;
vector<vector<int> >v(100,vector<int>(27));
vector<int>wor(27);


int main(){
    string s;

    int index = 0;
    while(true){
        getline(cin, s);
        if(s == "XXXXXX"){
            break;
        }
        dic.push_back(s);
        for(auto it: s){
            if(it == ' '){
                v[index][26]++;
                continue;
            }
            v[index][it - 'a']++;
        }
        index++;
    }

    while(true){
        getline(cin, s);
        if(s == "XXXXXX") {
            break;
        }


        for(auto it : s) {
            if(it == ' '){
                wor[26]++;
                continue;
            }
            wor[it - 'a']++;
        }

        bool entrou = false;
        vector<string>myout;
        for(int i = 0; i < index; i++){
            string name = dic[i];
            if(v[i] == wor){
                myout.push_back(name);
                entrou = true;
            }
        }

        sort(myout.begin(), myout.end());

        for(int i = 0; i < myout.size(); i++){
            cout << myout[i] << endl;
        }

        if(!entrou){
            cout << "NOT A VALID WORD" << endl;
        }
        cout << "******" << endl;
        wor = vector<int>(27);
    }

}
