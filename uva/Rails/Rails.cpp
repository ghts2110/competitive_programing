#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }

        while(true){
            int num = 1;
            
            queue<int> q;
            for(int i = 0; i != n && num !=0; i++){
                cin >> num;
                q.push(num);
            }
            if(!num){
                break;
            }
        
            int ind = 1;
            stack<int> st;
            while(true){
                if(!st.empty() && st.top() == q.front()){
                    st.pop();
                    q.pop();
                    continue;
                }

                if(!q.empty() && q.front() == ind){
                    ind++;
                    q.pop();
                }else if(ind <= n){
                    st.push(ind);
                    ind++;
                }else{
                    break;
                }
            }

            if(st.empty()){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }

        cout << endl;
    }
}
