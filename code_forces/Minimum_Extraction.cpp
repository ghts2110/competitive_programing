#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int x, y;

    scanf("%d", &x);

    while(x--){
        scanf("%d", &y); 
        vector<int> v(y);
        
        for(int i = 0; i != y; i++){
            scanf("%d", &v[i]);
        }

        sort(v.begin(), v.end());
        
        int  cont = 0, mx = v[0];

        for(int i = 0; i != y-1; i++){
            cont += v[i];

            v[i+1] -= cont;

            mx = max(mx, v[i+1]);
        }

        printf("%d\n", mx);

    }
}
