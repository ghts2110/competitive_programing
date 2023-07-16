#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int n, k;
string s;
int value = 0;
vector<int> v;
int mid;

int validate(){
    int cont = 0, sub = k, start = 0;
    
    for(int i = 0; i != v.size(); i++){
        if(cont >= mid){
            mid = cont;
            return 1;
        }

        if(i % 2 == 0){
            cont += v[i];
            continue;
        }

        sub -= v[i];
        if(sub >= 0){
            cont += v[i];
            continue;
        }

        cont += v[i] + sub;
        if(cont >= mid){
            mid = cont;
            return 1;
        }
        cont -= v[i] + sub;
        
        if(k < v[i]){
            cont = 0;
            start = i+1;
            sub = k;
            continue;
        }

        while(sub < 0){
            cont -= v[start];
            start++;
            cont -= v[start];
            sub += v[start];
            start++;
        }
        
        cont += v[i];
    }
    if(start > 0){
        cont += min(sub, v[start-1]);
    }

    if(cont >= mid){
        mid = cont;
        return 1;
    }
    
    cont = 0; sub = k, start = 1; 
    for(int i = 1; i != v.size(); i++){
        if(cont >= mid){
            mid = cont;
            return 1;
        }

        if(i % 2 == 1){
            cont += v[i];
            continue;
        }

        sub -= v[i];
        if(sub >= 0){
            cont += v[i];
            continue;
        }
        
        cont += v[i] + sub;
        if(cont >= mid){
            mid = cont;
            return 1;
        }
        cont -= v[i] + sub;

        if(k < v[i]){
            cont = 0;
            start = i+1;
            sub = k;
            continue;
        }
        
        while(sub < 0){
            cont -= v[start];
            start++;
            cont -= v[start];
            sub += v[start];
            start++;
        }

        cont += v[i];
    }
    cont += min(sub, v[start-1]);

    if(cont >= mid){
        mid = cont;
        return 1;
    }

    return 0;
}

int bs(int low, int high){
    mid = (low + high)/2;

    if(low > high){
        return value;
    }

    if(validate() == 1){
        value = mid;
        return bs(mid + 1, high);
    }

    return bs(low, mid-1);
}

int main(){
    cin >> n >> k;
    cin >> s;

    int cont = 1;
    for(int i = 1; i != n; i++){
        if(s[i] == s[i-1]){
            cont++;
        }else{
            v.push_back(cont);
            cont = 1;
        }
    }

    v.push_back(cont);

    cout << bs(k, n) << endl;
}
