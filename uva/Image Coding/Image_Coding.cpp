#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

int file_size(map<char,int> &arr, int M, int N){
    int mx = -100000, sum_max = 0,sum_min = 0,total;
    for (auto i : arr){
        mx = max(mx, i.second);
    }
    for (auto i : arr){
        if (i.second == mx){
            sum_max += i.second;
        }
        else{
            sum_min += i.second;
        }
    }

    total = sum_max * M + N * sum_min;
    return total;
}
int main(){
    int tc, k = 1;
    scanf("%d", &tc);
    int R, C, M, N;
    while (tc--){
        char temp;
        scanf("%d %d %d %d", &R, &C, &M, &N);
        map<char, int> arr;

        for (int i = 0; i < R; i++){
            for (int j = 0; j < C; j++){
                scanf(" %c", &temp);
                arr[temp]++;
            }
        }

        printf("Case %d: %d\n", k++,file_size(arr, M, N));
    }

    return 0;
}