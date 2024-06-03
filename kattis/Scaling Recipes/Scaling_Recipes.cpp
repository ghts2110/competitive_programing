#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;

    int test = 1;
    while(t--){
        int r, p, d;
        cin >> r >> p >> d;

        vector<pair<string, pair<double, double>>> v;
        double Baker = double(d)/double(p), w;
        for(int i= 0; i != r; i++){
            string s;
            double weight, perc;
            cin >> s >> weight >> perc;
            
            if(perc == 100){
                w = weight;
            }

            v.push_back({s, {weight, perc}});
        }

        cout << "Recipe # "<< test << endl;
        test++;
        for(auto it : v){
            cout << it.first << " ";
            printf("%.1lf\n", double(w * (it.second.second/100) * Baker));
        }

        cout << "----------------------------------------" << endl;
    }
}
