#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


string comb(char c1, char c2){
    map<string, string> mp;
    mp["AA"] = "A";
    mp["BB"] = "B";
    mp[" B"] = "B";
    mp["B "] = "B";
    mp["A "] = "A";
    mp[" A"] = "A";
    mp["OB"] = "B";
    mp["BO"] = "B";
    mp["AO"] = "A";
    mp["OA"] = "A";
    mp["OO"] = "O";
    mp[" O"] = "O";
    mp["O "] = "O";
    mp["AB"] = "AB";
    mp["BA"] = "AB";
    mp["  "] = "O";

    string s = "";
    s += c1;
    s += c2;
    return mp[s];
}

void prnts3(vector<string> &v, bool val){
    if(v.size() == 0){
        cout << "IMPOSSIBLE";
    }else if(v.size() == 1 && !val){
        cout << *v.begin() << "-";
    }else{
        cout << "{";
        bool f = true;
        for(auto it : v){
            if(it == ""){
                continue;
            }

            if(!f){
                cout << ", ";
            }
            f=false;

            cout << it << "-";
            
            if(val){
                cout << ", " << it << "+";
            }
        }
        cout << "}";
    }
}

void prnt(vector<string> &v, bool val){
    if(v.size() == 0){
        cout << "IMPOSSIBLE";
    }else if(v.size() == 1 && !val){
        cout << *v.begin() << "-";
    }else{
        cout << "{";
        bool f = true;
        for(auto it : v){
            if(it == ""){
                continue;
            }

            if(!f){
                cout << ", ";
            }
            f=false;

            
            if(val){
                cout << it << "-, ";
            }
            cout << it << "+";
        }
        cout << "}";
    }
}

set<string> allcomb(string s2, string s3){
    set<string> st;
    // A
    string save = comb(s2[0], ' ');
    if(save == s3){
        st.insert("A");
    }
    save = comb(s2[0], 'A');
    if(save == s3){
        st.insert("A");
    }
    save = comb(s2[1], ' ');
    if(save == s3){
        st.insert("A");
    }
    save = comb(s2[1], 'A');
    if(save == s3){
        st.insert("A");
    }
    // B
    save = comb(s2[0], ' ');
    if(save == s3){
        st.insert("B");
    }
    save = comb(s2[0], 'B');
    if(save == s3){
        st.insert("B");
    }
    save = comb(s2[1], ' ');
    if(save == s3){
        st.insert("B");
    }
    save = comb(s2[1], 'B');
    if(save == s3){
        st.insert("B");
    }
    // O
    save = comb(s2[0], ' ');
    if(save == s3){
        st.insert("O");
    }
    save = comb(s2[0], 'O');
    if(save == s3){
        st.insert("O");
    }
    save = comb(s2[1], ' ');
    if(save == s3){
        st.insert("O");
    }
    save = comb(s2[1], 'O');
    if(save == s3){
        st.insert("O");
    }
    // AB
    save = comb(s2[0], 'A');
    if(save == s3){
        st.insert("AB");
    }
    save = comb(s2[0], 'B');
    if(save == s3){
        st.insert("AB");
    }
    save = comb(s2[1], 'A');
    if(save == s3){
        st.insert("AB");
    }
    save = comb(s2[1], 'B');
    if(save == s3){
        st.insert("AB");
    }

    return st;
}

bool my(string s1, string s2){
    if(s1 == "O"){
        return true;
    }
    if(s2 == "O"){
        return false;
    }
    if(s1 == "AB"){
        return true;
    }
    if(s2 == "AB"){
        return false;
    }
    if(s1 == "B"){
        return true;
    }
    return false;
}

int main(){
    string s1, s2, s3;
    int test = 1;
    while(cin >> s1 >> s2 >> s3){
        if(s1+s2+s3 == "END"){
            break;
        }
        cout << "Case "<<test<<": ";
        test++;

        if(s3 == "?"){
            cout << s1 << " " << s2 << " ";
            if(s1.size() != 3){
                s1 = " " + s1;
            }
            if(s2.size() != 3){
                s2 = " " + s2;
            }

            set<string> st;
            st.insert(comb(s1[0], s2[0]));
            st.insert(comb(s1[0], s2[1]));
            st.insert(comb(s1[1], s2[0]));
            st.insert(comb(s1[1], s2[1]));

            bool val = (s1[2] == '+' || s2[2] == '+');

            vector<string> v;
            for(auto it : st){
                v.push_back(it);
            }
            sort(v.begin(), v.end(), my);

            prnts3(v, val);
            cout << endl;

        }else{
            string save1 = s1, save2 = s2, save3 = s3;
            if(s1 == "?"){
                bool val = !(s2[s2.size()-1] == '-' && s3[s3.size()-1] == '+');

                if(s2.size() != 3){
                    s2 = " " +s2;
                }
                s3.erase(s3.end()-1);

                set<string> st = allcomb(s2, s3);

                vector<string> v;
                for(auto it : st){
                    v.push_back(it);
                }
                sort(v.begin(), v.end(), my);


                prnt(v, val);
                cout << " " << save2 << " " << save3 << endl;
            }else{
                bool val = !(s1[s1.size()-1] == '-' && s3[s3.size()-1] == '+');

                if(s1.size() != 3){
                    s1 = " " + s1;
                }
                s3.erase(s3.end()-1);

                set<string> st = allcomb(s1, s3);

                vector<string> v;
                for(auto it : st){
                    v.push_back(it);
                }
                sort(v.begin(), v.end(), my);


                cout << save1 << " ";
                prnt(v, val);
                cout << " " << save3 << endl;
            }
        }
    }
}
