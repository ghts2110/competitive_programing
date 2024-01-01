#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll Merge(vector<int> &a, vector<int> &b, vector<int> &v){
    int i = 0, j = 0;

    int asw = 0;
    for(auto &it : v){
        if(j == b.size() || (i != a.size() && a[i] < b[j])){
            it = a[i];
            i++;
        }else{
            asw += a.size()-i;
            it = b[j];
            j++;
        }
    }

    return asw;
}

ll MergeSort(vector<int> &v){
    if(v.size() == 1){
        return 0;
    }

    vector<int> a, b;
    for(int i = 0; i != v.size()/2; i++){
        a.push_back(v[i]);
    }

    for(int i = v.size()/2; i != v.size(); i++){
        b.push_back(v[i]);
    }

    ll asw = MergeSort(a) + MergeSort(b);
    return Merge(a, b, v) + asw;
}

int main(){
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i != n; i++){
        cin >> v[i];
    }

    cout << MergeSort(v) << endl;
}