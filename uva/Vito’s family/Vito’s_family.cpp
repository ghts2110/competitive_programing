#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int test;

    scanf("%d", &test);

    while(test--){
        int parent;
        scanf("%d", &parent);

        float sum = 0;
        int distancias[510];
        
        int mx = -1, mn = 1e9;
        for(int i = 0; i < parent; i++){
            scanf("%d", (distancias + i));

            mx = max(mx, *(distancias+i));
            mn = min(mn, *(distancias+i));
        }

        int value = 1e9;
        for(int i = mn; i <= mx; i++){
            int sum = 0;
            for(int j = 0; j != parent; j++){
                sum += abs(distancias[j] - i);
            }

            value = min(sum, value);
        }
    
        printf("%d\n", value);
    }
}
