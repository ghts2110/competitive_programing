#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, bool> mp;

bool rec(string end, string no, bool first){
  if(no == end){
    return true;
  }

  if(mp[no]){
    return false;
  }

  mp[no] = true;

  string s = no;
  char save = s[0];
  s[0] = s[1];
  s[1] = s[5];
  s[5] = s[4];
  s[4] = save;

  bool b = rec(end, s, false);
  
  s = no;
  save = s[0];
  s[0] = s[2];
  s[2] = s[5];
  s[5] = s[3];
  s[3] = save;

  b |= rec(end, s, false);

  s = no;
  save = s[1];
  s[1] = s[2];
  s[2] = s[4];
  s[4] = s[3];
  s[3] = save;

  b |= rec(end, s, false);

  return b;
}

int main(){
  string s;
  while(cin >> s){
    mp.clear();
    string s1, s2;
    for(int i = 0; i != 12; i++){
      if(i < 6){
        s1+=s[i];
      }else{
        s2+=s[i];
      }
    }

    bool b = rec(s1, s2, true);
    if(b){
      cout << "TRUE" << endl;
    }else{
      cout << "FALSE" << endl;
    }
  }  
}
