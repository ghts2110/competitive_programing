#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int> > v(n);
    vector<int> line(n);
    vector<int> colum(n);

    for(int i = 0; i != n; i++){
        for(int j = 0; j != n; j++){
            int num;
            cin >> num;

            v[i].push_back(num);
        }
    }

    for(int i = 0; i != n; i++){
        for(int j = 0; j != n; j++){
            line[i] += v[i][j];
            colum[i] += v[j][i];
        }
    }

    int max = 0, sum;

    for(int i = 0; i != n; i++){
        for(int j = 0; j != n; j++){
            sum =  line[i] + colum[j] - (2*v[i][j]);
            if(max < sum){
                max = sum;
            }
        }
    }

    cout << max << endl;
}
