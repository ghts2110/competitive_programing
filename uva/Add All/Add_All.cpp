#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }

        multiset<int> st;
        for(int i = 0; i != n; i++){
            int num;
            cin >> num;

            st.insert(num);
        }
            
        int asw = 0;
        while(st.size() != 1){
            int sum = 0;
            sum += *st.begin();
            st.erase(st.begin());
            sum += *st.begin();
            st.erase(st.begin());

            asw += sum;
            st.insert(sum);
        }

        cout << asw << endl;
    } 
}
