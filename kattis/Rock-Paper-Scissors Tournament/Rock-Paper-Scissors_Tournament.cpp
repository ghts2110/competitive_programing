#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n, k;
   
    int test = 1;
    while(cin >> n >> k){
        if(n == 0){
            break;
        }

        if(test != 1){
            cout << endl;
        }
        test++;

        vector<pair<int, int>> v(n+1);
        k = k * n * (n-1) / 2;
        for(int i = 0; i != k; i++){
            int n1, n2;
            string s1, s2;

            cin >> n1 >> s1 >> n2 >> s2;
            if(s1 == s2){
                continue;
            }else if(s1 == "rock" && s2 == "scissors"){
                v[n1].first++;
                v[n2].second++;
            }else if(s1 == "rock" && s2 == "paper"){
                v[n1].second++;
                v[n2].first++;
            }else if(s1 == "paper" && s2 == "rock"){
                v[n1].first++;
                v[n2].second++;
            }else if(s1 == "paper" && s2 == "scissors"){
                v[n1].second++;
                v[n2].first++;
            }else if(s1 == "scissors" && s2 == "paper"){
                v[n1].first++;
                v[n2].second++;
            }else if(s1 == "scissors" && s2 == "rock"){
                v[n1].second++;
                v[n2].first++;
            }
        }

        for(int i = 1; i <= n; i++){
            if(v[i].first == 0 && v[i].second == 0){
                cout << '-' << endl;
                continue;
            }
            printf("%.3f\n", (double)v[i].first/(v[i].first+v[i].second));
        }
    }
}
