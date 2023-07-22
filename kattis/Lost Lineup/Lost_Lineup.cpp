#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> v(n);
    v[0] = 1;

    for(int i = 2; i <= n; i++){
        int num;
        cin >> num;
        
        v[num+1] = i; 
    }

    for(int i = 0; i != n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
