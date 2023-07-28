#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){
    int t;
    cin >> t;

    int test = 1;
    while(t--){
        string s;
        cin >> s;
        vector<int> v(100);

        int index = 0;
        for(int i = 0; i != s.size(); i++){
            if(s[i] == '+'){
                v[index]++;
                if(v[index] == 256){
                    v[index] = 0;
                }

            }else if(s[i] == '-'){
                v[index]--;
                if(v[index] == -1){
                    v[index] = 255;
                }

            }else if(s[i] == '>'){
                index++;
                if(index == 100){
                    index = 0;
                }

            }else if(s[i] == '<'){
                index--;
                if(index == -1){
                    index = 99;
                }
            }
        }

        cout << "Case "<<test<<": ";
        test++;

        map<int, char> mp;
        mp[10] = 'A';
        mp[11] = 'B';
        mp[12] = 'C';
        mp[13] = 'D';
        mp[14] = 'E';
        mp[15] = 'F';
        for(int i = 0;i != 100; i++){
            if(v[i]/16 >= 10){
                cout << mp[v[i]/16];
            }else{
                cout << v[i]/16;
            }

            if(v[i]%16 >= 10){
                cout << mp[v[i]%16];
            }else{
                cout << v[i]%16;
            }

            if(i != 99){
                cout << " ";
            }
        }
        cout << endl;
    }
}
