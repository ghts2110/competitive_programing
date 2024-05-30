#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> v;
        double avg = 0;
        for(int i = 0; i != n; i++){
            int num;
            cin >> num;

            v.push_back(num);
            avg += num;
        }

        avg /= n;
        int cont = 0;
        for(int i = 0;i != n; i++){
            if(v[i] > avg){
                cont++;
            }
        }
        
        double asw = double(cont * 100) / double(n);
        printf("%.3lf", asw);
        cout << '%' << endl;
    }
}
