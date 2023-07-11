#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    vector<int> v;
    cin >> n;
    
    while(n--){
        int num;
        cin >> num;

        v.push_back(num);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i != v.size(); i++){
        cout << v[i] << " ";
    }

    cout << endl;
}
