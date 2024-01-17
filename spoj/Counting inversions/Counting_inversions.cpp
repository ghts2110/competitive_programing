#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    int rry[250001];
    int ndx[250001];
    long long asw = 0, ind = 0;
    vector<vector<int> > v1(50, vector<int> (50001));

    for(int i = 1; i <= n; i++){
        ndx[i] = ind;

        if(i <= n){
            asw += i-1;
            scanf("%d", rry+i);
            for(int j = 0; j <= ind; j++){
                for(int k = rry[i]; k > 0; k -= k&-k){
                    asw -= v1[j][k];
                }
            }
        }else{
            rry[i] = 0;
        }

        for(int j = rry[i]; j <= 50000; j += j&-j){
            v1[ind][j]++;
        }

        if(i%5000 == 0){
            ind++;
        }
    }


    int m;
    scanf("%d", &m);
    for(int i = 0; i != m; i++){
        int x, y;
        scanf("%d %d", &x, &y);

        long long cnt1 = 0, cnt2 = 0;

        int save = x-1;
        while(save % 5000 != 0){
            if(rry[save] > rry[x]){
                cnt1++;
            }

            if(rry[save] > y){
                cnt2++;
            }
            save--;
        }

        save = x+1;
        while(save % 5000 != 1){
            if(rry[save] < rry[x]){
                cnt1++;
            }

            if(rry[save] < y){
                cnt2++;
            }
            save++;
        }

        for(int j = ndx[x]-1; j >= 0; j--){
            cnt1 += 5000;
            cnt2 += 5000;
            for(int k = rry[x]; k > 0; k -= k&-k){
                cnt1 -= v1[j][k];
            }

            for(int k = y; k > 0; k -= k&-k){
                cnt2 -= v1[j][k];
            }
        }

        for(int j = ndx[x]+1; j < 50; j++){
            for(int k = rry[x]-1; k > 0; k -= k&-k){
                cnt1 += v1[j][k];
            }

            for(int k = y-1; k > 0; k -= k&-k){
                cnt2 += v1[j][k];
            }
        }

        for(int j = rry[x]; j <= 50000; j += j&-j){
            v1[ndx[x]][j]--;
            if(j == 0){
                j++;
                v1[ndx[x]][j]--;
            }
        }
        rry[x] = y;
        for(int j = rry[x]; j <= 50000; j += j&-j){
            v1[ndx[x]][j]++;
            if(j == 0){
                j++;
                v1[ndx[x]][j]++;
            }
        }

        asw += cnt2 - cnt1;
        printf("%lld\n", asw);
    }
}