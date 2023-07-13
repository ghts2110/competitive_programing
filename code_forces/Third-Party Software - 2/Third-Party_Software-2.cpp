#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int> > v(n, vector<int> (3));
    for(int i = 0; i !=n; i++){
        scanf("%d %d", &v[i][0], &v[i][1]);
        v[i][2] = i+1;
    }

    sort(v.begin(), v.end());

    vector<int> index(n);
    int mn = v[0][0], mx = 0, ndx = 0;
    for(int i = 0; i != n; i++){
        int melhor = mx;
        for(int j = i; j != n; j++){
            if(v[j][0] <= mx+1 && v[j][1] > melhor){
                index[ndx] = v[j][2];
                melhor = v[j][1];
            }else if(v[j][0] > mx+1){
                break;
            }
            i = j;
        }

        if(index[ndx] != 0){
            ndx++;
        }
        mx = melhor;
    }


    if(mn != 1 || mx != m){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << ndx << endl;
    for(int i = 0; i != ndx; i++){
        if(i == ndx-1){
            printf("%d\n", index[i]);
            return 0;
        }

        printf("%d ", index[i]);
    }
}
