#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct word{
    string word;
    int freq;
    int fontsize;
    int width;
    int height;
};

int dv(int t, int b){
    return (t+b-1)/b;
}

int main(){
    int w, n;
    int t = 1;

    while(cin >> w >> n){
        if(!w && !n){
            break;
        }

        vector<word> v;
        int cm = 0;
 
        for(int i = 0; i != n; i++){
            string s;
            int c;

            cin >> s >> c;
            cm = max(cm, c);
            if(c >= 5){
                v.push_back({s, c});
            }
        }

        for(auto &it : v){
            it.fontsize = 8 + dv(40*(it.freq-4), (cm-4));
            it.height = it.fontsize;
            it.width = dv(9 * it.word.length() * it.height , 16);
        }

        int asw = 0;
        int width = 0;
        int height = 0;

        for(auto it : v){
            if(width + it.width > w){
                asw += height;
                width = 0;
                height = 0;
            }    

            width += it.width + 10;
            height = max(height, it.height);
        }

        asw += height;
        cout << "CLOUD " << t << ": " << asw << endl;
        t++;
    }
}
