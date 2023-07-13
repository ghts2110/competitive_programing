#include <iostream>
#include <algorithm>

using namespace std;
    
int main(){
    int n, k;
    cin >> n >> k;

    long long v[100000];

    for(int i = 0; i != n; i++){
        scanf("%lld", v+i);

    }

    sort(v, v+n);

    pair<int, int> answer;
    answer.first = 1;
    answer.second = v[0];

    long long p = 0, cont = 0;
    for(int i = 1; i < n; i++){
        cont += (v[i] - v[i-1]) * (i - p);
        if(k >= cont){
            if(answer.first <= i-p){
                answer.first = i-p + 1;
                answer.second = v[i];
            }
        }else{
            while(cont > k && cont > 0){
                cont -= v[i] - v[p];
                p++;
            }
        } 
    }

    cout << answer.first << " " << answer.second << endl;
}
