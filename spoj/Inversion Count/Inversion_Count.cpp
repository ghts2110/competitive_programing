#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int n;

ll Merge(vector<int> &A, vector<int> &B, vector<int> &v){
    int i = 0, j = 0;

    ll asw = 0;
    for(auto &it : v){
        if(j == B.size() || (i != A.size() && A[i] <= B[j])){
            it = A[i];
            i++;
        }else{
            it = B[j];
            j++;
            asw += A.size()-i;
        }
    }

    return asw;
}

ll MergeSort(vector<int> &v){
    if(v.size() == 1){
        return 0;
    }

    vector<int> A, B;
    for(int i = 0; i != v.size()/2; i++){
        A.push_back(v[i]);
    }

    for(int i = v.size()/2; i != v.size(); i++){
        B.push_back(v[i]);
    }

    ll asw = MergeSort(A) + MergeSort(B);

    return Merge(A, B, v) + asw;
}
int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);

        vector<int> v;
        for(int i = 0; i != n; i++){
            int num;
            scanf("%d", &num);

            v.push_back(num);
        }

        cout << MergeSort(v) << endl;
    }
}