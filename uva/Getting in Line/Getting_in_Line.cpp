#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

pair<double, vector<pair<int, int>>> asw;
int n, test = 1;

double dist(pair<double, double> p1, pair<double, double> p2){
    return sqrt((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second));
}

void dp(vector<pair<int, int>> &v, vector<bool> &visit, int ind, vector<pair<int, int>> &save, double sum){
    if(ind == n){
        if(sum < asw.first){
            asw.first = sum;
            asw.second = save;
            return;
        }
    }    

    double d = -16;
    for(int i = 0; i != n; i++){
        if(!visit[i]){
            save[ind] = v[i];
            visit[i] = true;
            if(ind != 0){
                d = dist(save[ind-1], save[ind]);
            }
            sum += d+16;

            dp(v, visit, ind+1, save, sum);
            visit[i] = false;
            sum -= d+16;
        }
    }
}

int main(){
    while(cin >> n){
        if(!n){
            break;
        }

        printf("**********************************************************\n");
        printf("Network #%d\n", test);
        test++;
        
        vector<pair<int, int>> v(n);
        for(int i = 0; i != n; i++){
            scanf("%d %d", &v[i].first, &v[i].second);
        }
        
        asw = {1e9, vector<pair<int, int>> (0)};
        vector<bool> visit(n, false);
        vector<pair<int, int>> save(n);
 
        dp(v, visit, 0, save, 0);

        for(int i = 1; i < asw.second.size(); i++){
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",
                    asw.second[i-1].first, asw.second[i-1].second, 
                    asw.second[i].first, asw.second[i].second, dist(asw.second[i-1], asw.second[i])+16); 
        }
        printf("Number of feet of cable required is %.2f.\n", asw.first);
    }
}
