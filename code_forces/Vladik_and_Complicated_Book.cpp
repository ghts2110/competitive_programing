#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> newV;
    vector<int> vec;

    for(int i = 0; i != n; i++){
        int num;
        cin >> num;  
        vec.push_back(num);
    }
    
    while(m--){
        int l, r, x, cont = 0;
        cin >> l >> r >> x;
 
        x--;
        l--;
    

        for(int i = l; i != r; i++){
            if(vec[i] < vec[x]){
                cont++;
            }
        }


        if(cont == x-l){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    

}
