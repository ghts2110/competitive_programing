#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n;

    for(int j = 0; j != n; j++){
        int index = 0;
        cin >> s;    

        vector<string> vs(s.size(), "");

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '+' || s[i] == '*'){
                index++;  
            }

            vs[index] += s[i];

            if(s[i] == '+' || s[i] == '*'){
                index++;
            }
        }
        
        for(int i = 0; i != vs.size(); i++){
            if(vs[i] == ""){
                vs.erase(vs.begin() + i);
                i--;
            }
        }

        if(vs.size() == 1){
            printf("The maximum and minimum are %ld and %ld.\n", stol(vs[0]), stol(vs[0]));
            continue;
        }

        vector<string> vvs = vs;

        for(int i = 1; i < vs.size(); i+=2){
            if(vs[i] == "+"){
                long long value = stol(vs[i-1]) +stol(vs[i+1]);
                vs[i-1] = to_string(value);
                vs.erase(vs.begin() + i);
                vs.erase(vs.begin() + i);
                i = -1;
            }
        }


        long long max = 1;
        for(int i = 0; i < vs.size(); i+= 2){
            max *= stol(vs[i]);
        }

        for(int i = 1; i < vvs.size(); i+=2){
            if(vvs[i] == "*"){
                long long value = stol(vvs[i-1]) * stol(vvs[i+1]);
                vvs[i-1] = to_string(value);
                vvs.erase(vvs.begin() + i);
                vvs.erase(vvs.begin() + i);
                i = -1;
   
            }
        }

        long long  min = 0;
        for(int i = 0; i < vvs.size(); i+= 2){
            min += stol(vvs[i]);
        }
        
        if(min > max){
            long long save = max;
            max = min;
            min = save;
        }
        printf("The maximum and minimum are %lld and %lld.\n", max, min);

    }
}

