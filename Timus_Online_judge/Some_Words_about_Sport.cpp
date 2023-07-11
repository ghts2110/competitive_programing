#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<vector<int> > v(n);
    for(int i = 0; i != n; i++){
        for(int j = 0; j != n; j++){
            int num;
            cin >> num;
            v[i].push_back(num);
        }
    }
  
    for(int i = 0; i < n; i++){
        int line = i, colum = 0;
    
        while(line != -1 && colum != n){
            cout << v[line][colum] << " ";
            line--;
            colum++;
        } 
    }

    for(int i = 1; i < n; i++){
        int line = n-1, colum = i;
        
        while(line != -1 && colum != n){
            cout << v[line][colum] << " ";
            line--; 
            colum++;
        }
    }

    cout << endl;
}
