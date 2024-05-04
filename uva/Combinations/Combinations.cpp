#include <iostream>

using namespace std;

int main(){
    double v[101];
    v[1] = 1;
    for(int i = 2; i != 101; i++){
        v[i] = v[i-1]*i;
    }

    int n, m;
    while(cin >> n >> m){
        if(!n && !m){
            break;
        }

        printf("%d things taken %d at a time is ", n, m);
        if(n == m){
            printf("1 exactly.\n");
            continue;
        }
        double asw = v[n]/(v[n-m]*v[m]);
        printf("%.0f exactly.\n", asw);
    }
}
