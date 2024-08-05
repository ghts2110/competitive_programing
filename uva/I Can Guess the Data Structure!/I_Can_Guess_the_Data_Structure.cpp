#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        int a, b;
        bool b1 = true, b2 = true, b3 = true;
        
        queue<int> q;
        stack<int> st;
        priority_queue<int, vector<int>, less<int>> pq;

        for(int i = 0; i != n; i++){
            cin >> a >> b;

            if(a == 1){
                q.push(b);
                st.push(b);
                pq.push(b);
            }else{
                if(b1 && !q.empty() && q.front() == b){
                    q.pop();
                }else{
                    b1 = false;
                }

                if(b2 && !st.empty() && st.top() == b){
                    st.pop();
                }else{
                    b2 = false;
                }
                
                if(b3 && !pq.empty() && pq.top() == b){
                    pq.pop();
                }else{
                    b3 = false;
                }
            }
        }

        if(b1 && !b2 && !b3){
            cout << "queue" << endl;
        }else if(b2 && !b1 && !b3){
            cout << "stack" << endl;
        }else if(b3 && !b1 && !b2){
            cout << "priority queue" << endl;
        }else if(!b1 && !b2 && !b3){
            cout << "impossible" << endl;
        }else{
            cout << "not sure" << endl;
        }
    }
}
