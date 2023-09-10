#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        int index = -1;
        vector<int> v;

        int mx = 0, cont = 0;
        for(int i = 0; i != n; i++){
            int num;
            cin >> num;

            if(num > mx){
                mx = num;
                v.push_back(mx);
                cont++;
            }
        }

        cout << cont << endl;
        for(int i = 0; i != v.size(); i++){
            if(i == v.size()-1){
                cout << v[i] << endl;
                break;
            }
            cout << v[i] << " ";
        }

    }
}
