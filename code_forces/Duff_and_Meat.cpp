#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> num_meat;
    vector<int> value_meat;
    
    for(int i = 0; i != n; i++){
        int nm, vm;
        cin >> nm >> vm;
        
        num_meat.push_back(nm);
        value_meat.push_back(vm);
    }

    int cont = num_meat[0] * value_meat[0];
    for(int i = 1; i != n; i++){
        if(value_meat[i-1] < value_meat[i]){
            value_meat[i] = value_meat[i-1];
        } 

        cont += num_meat[i] * value_meat[i];
    }

    cout << cont << endl;
}
