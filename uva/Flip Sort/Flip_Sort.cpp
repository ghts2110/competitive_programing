#include <iostream>
#include <vector>

using namespace std;

int cont = 0;

void merge(vector<int> &a, vector<int> &b, vector<int> &c){
    int i = 0; 
    int j = 0;

        
    for(auto &it : c){
        if(j == b.size() || (i != a.size() && a[i] > b[j])){
            cont+= b.size() - j;
            it = a[i];
            i++;
        }else{
            it = b[j];
            j++;
        }
    }
}

void mergeSort(vector<int> &v){
    if(v.size() <= 1){
        return;
    }

    vector<int> a, b;
    for(int i = 0; i != v.size(); i++){
        if(v.size()%2 >= i){
            a.push_back(v[i]);
        }else{
            b.push_back(v[i]);
        }
    }
    
    mergeSort(a);
    mergeSort(b);

    merge(a, b, v);
}

int main(){
    int n;
    while(cin >> n){
        cont = 0;
        vector<int> v;
        for(int i = 0; i != n; i++){
            int x;
            cin >> x;

            v.push_back(x);
        }

        mergeSort(v);
        cout << "Minimum exchange operations : " << cont << endl;
    }
}
