#include <iostream>
#include <vector>

using namespace std;

int n, k, value;
vector<int> v;

int bs(int start, int end){
    if(start > end){
        return -1;
    }

    int mid = (start + end)/2;
    
    if(v[mid] == value){
        return value;
    }

    if(v[mid] > value){
        return bs(start, mid-1);
    }
    
    return bs(mid+1, end);
    
}

int main(){
    cin >> n;   
    
    for(int i = 0; i != n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    cin >> k;

    for(int i = 0; i != n; i++){
        value = k - v[i]; 
        
        if(bs(i-1, n) == value){
            cout << v[i] << " " << value << endl;
            return 0;
        }
    }
    
}
