#include <iostream>
#include <vector>

using namespace std;

int main(){
    int d, sumTime;
    cin >> d >> sumTime;

    int validate = 1, mn = 0, mx = 0;
    vector<int> v(d);
    vector<vector<int> > time(d, vector<int>(2));
    for(int i = 0; i != d; i++){
        cin >> time[i][0] >> time[i][1];

        mn += time[i][0];
        mx += time[i][1];
    }

    if(sumTime < mn || sumTime > mx){
        cout << "NO" << endl;
        return 0;
    }else{
        cout << "YES" << endl;
    }

    for(int i = 0; i != d; i++){
        sumTime -= time[i][0];
        v[i] = time[i][0];
    }

    for(int i = 0; i != d && sumTime != 0; i++){
        v[i] += min(sumTime, time[i][1] - time[i][0]);
        sumTime -= min(sumTime, time[i][1] - time[i][0]);
    }
    
    for(int i = 0; i != d; i++){
        if(i == d-1){
            cout << v[i] << endl;
            break;
        }

        cout << v[i] << " ";
    }

}
