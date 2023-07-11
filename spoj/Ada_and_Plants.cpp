#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        int array[n];

        int p1 = 0, p2 = min(k+1, n-1);
        int mx = 0, index_mx = 0, index_mn, mn = 1e9;

        for(int i = 0; i != n; i++){
            scanf("%d", array+i);
            if(i <= p2 && i > p1){
                if(mx <= *(array+i)){
                    mx = *(array+i);
                    index_mx = i;
                }
                if(mn >= *(array+i)){
                    mn = *(array+i);
                    index_mn = i;
                }
            }
        }

        int value = 0;
        for(int i = 0; i != n; i++){
            int v = array[p1] - mx;
            if(mx != -1){
                if(v < 0){
                    v *= -1;
                }
                value = max(value, v);
            }

            v = array[p1] - mn;
            if(mn != 1e9){
                if(v < 0){
                    v *= -1;
                }
                value = max(value, v);
            }

            if(p2 != n-1){
                p2++;
            }
            p1++;

            if(mx <= array[p2]){
                mx = array[p2];
                index_mx = p2;
            }

            if(mn >= array[p2]){
                mn = array[p2];
                index_mn = p2; 
            }

            if(p1 == index_mx){
                mx = -1;
                for(int j = p1+1; j <= p2; j++){
                    if(mx <= array[j]){
                        mx = array[j];
                        index_mx = j;
                    }
                }
            }

            if(p1 == index_mn){
                mn = 1e9;
                for(int j = p1+1; j <= p2; j++ ){
                    if(mn >= array[j]){
                        mn = array[j];
                        index_mn = j;
                    }
                }
            }

        }

        cout << value << endl;
    }
}
