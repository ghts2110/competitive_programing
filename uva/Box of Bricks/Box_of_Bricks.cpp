#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    int t = 1;
    while(cin >> n){
        vector<int> v;
        if(!n){
            break;
        }
   
        int cont = 0;
        for(int i = 0; i != n; i++){
            int num;
            cin >> num;

            cont += num;
            v.push_back(num);
        }
        cont /= n;

        int asw = 0;
        for(auto it : v){
            if(it > cont){
                asw += it - cont;
            }
        }

        cout << "Set #"<<t << endl;
        t++;
        cout << "The minimum number of moves is "<<asw<<"." << endl;
        cout << endl;
    }
}
