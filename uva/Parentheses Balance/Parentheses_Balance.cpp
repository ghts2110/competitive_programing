#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    int t;
    cin >> t;
    string s;
    getline(cin, s);
    while(t--){
        getline(cin, s);

        stack<char> st;
        for(auto it : s){
            if(it == '(' || it == '['){
                st.push(it);
            }else if(!st.empty() && ((st.top() == '(' && it == ')') || (st.top() == '[' && it == ']'))){
                st.pop();
            }else{
                st.push(it);
                break;
            }
        }

        if(st.empty()){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}
