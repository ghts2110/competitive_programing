#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    map<string, string> mp;
    mp["Ab"] = "G#";
    mp["Gb"] = "F#";
    mp["Eb"] = "D#";
    mp["Db"] = "C#";
    mp["Bb"] = "A#";

    mp["A#"] = "Bb";
    mp["C#"] = "Db";
    mp["F#"] = "Gb";
    mp["D#"] = "Eb";
    mp["G#"] = "Ab";

    string s1,s2;

    int test = 1;
    while(cin >> s1 >> s2){
        cout << "Case "<<test<<": ";
        test++;
        if(mp.find(s1) != mp.end()){
            cout << mp[s1] << " " << s2 << endl;
        }else{
            cout << "UNIQUE" << endl;
        }
    }

}
