#include <iostream>
#include <set>

using namespace std;

int main(){
    set<long long> st;
    st.insert(1);

    int n = 1499;
    while(n){
        long long it = *st.begin();
        st.erase(st.begin());

        st.insert(it*2);
        st.insert(it*3);
        st.insert(it*5);
        n--;
    }

    cout << "The 1500'th ugly number is "<<*st.begin()<<"."<<endl;
}
