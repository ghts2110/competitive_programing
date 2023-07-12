#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    float mn = 4000000;

    int t;
    cin >> t;
    vector<vector<int> > v;
    vector<int> k;

    if(t == 0){
        cout << 0 << endl;
        return 0;
    }else if(t == 1){
        mn = 0;
    }

    int x, y;
    cin >> x >> y;

    v.push_back(k);
    v[0].push_back(x);
    v[0].push_back(y);
    t--;

    int index = 1;
    while(t--){
        cin >> x >> y;

        for(int i = 0; i != v.size(); i++){
            float a;
            if(x < 0 && v[i][0] < 0){
                int sum = x - v[i][0];
                if(sum < 0){
                    sum *= -1;
                }

                a = pow(sum, 2);
            }else if(x < 0){
                a = pow(v[i][0] - x, 2);
            }else{
                int sum = x - v[i][0];
                if(sum < 0){
                    sum *= -1;
                }

                a = pow(sum, 2);
            }


            float b;
            if(y < 0 && v[i][1] < 0){
                int sum = y - v[i][1];
                if(sum < 0){
                    sum *= -1;
                }
                b = pow(sum, 2);
            }else if(y < 0){
                b = pow(v[i][1] - y, 2);
            }else{
                int sum = y - v[i][1];
                if(sum < 0){
                    sum *= -1;
                }
                b = pow(sum, 2);
            }

            float c = sqrt(a + b);

            mn = min(mn, c);
        }

        v.push_back(k);
        v[index].push_back(x);
        v[index].push_back(y);
        index++;


    }

    printf("%.3f\n", mn);
}
