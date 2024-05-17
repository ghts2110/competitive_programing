#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }

        vector<double> v(n);
        double sum = 0;
        for(int i = 0; i != n; i++){
            double d;
            cin >> d;
            sum += d;

            v[i] = d;
        }

        sum /= n;
        long long aswP = 0;
        long long aswN = 0;
        for(auto it : v){
            if(it > sum){
                aswP += (int)((it-sum)*100);
            }else{
                aswN += (int)((sum-it)*100);
            }
        }

        long long asw = max(aswP, aswN);
        printf("$%.2lf\n", (double)asw/100.0);
    }
}
