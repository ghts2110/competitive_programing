#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    long long contp = 0, contn = 0;
    while(t--){
        int num;
        cin >> num;

        if(num < 0){
            contn += num;
        }else{
            contp += num;
        }
    }

    if(contp > contn){
        cout << -contn << endl;
    }else{
        cout << contp << endl;
    }
}
