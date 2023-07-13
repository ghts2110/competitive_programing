#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
    
long long cont = 0;

int main(){
    long long n, sum = 0;
    cin >> n;

    deque<int> v;
    for(int i = 0; i != n; i++){
        int num;
        scanf("%d", &num);

        sum += num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    
    for(int i = 0; i != n; i++){
        cont += sum;
        if(i != n-1){
            cont += v[i];
        }
        sum -= v[i];
    }
    cout << cont << endl;    
}
