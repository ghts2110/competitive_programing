#include <iostream>
#include <map>

using namespace std;

int n, value = 0;

void dp(map<pair<int, int>, int>& holes, map<int, int>& line, map<int, int>& diaP, map<int, int>& diaS, int q){
    if(n == q){
        value++;
        return;
    }

    for(int i = 0; i != n; i++){
        if(holes[pair<int, int> (i, q)] != 1 && line[i] != 1 && diaP[i - q] != 1 && diaS[i + q] != 1){
            holes[pair<int, int> (i, q)] = 1;
            line[i] = 1;
            diaP[i - q] = 1;
            diaS[i + q] = 1;
            
            dp(holes, line, diaP, diaS, q+1);
            
            holes[pair<int, int> (i, q)] = 0;
            line[i] = 0;
            diaP[i - q] = 0;
            diaS[i + q] = 0;
        }

    }

    return;
}

int main(){
    int m;

    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0){
            break;
        }

        value = 0;
        map<pair<int, int>, int> holes;
        map<int, int> line, diaP,diaS;

        for(int i = 0; i != m; i++){
            int x, y;
            cin >> x >> y;

            holes[pair<int, int> (x, y)] = 1;
        }

        dp(holes, line, diaP, diaS, 0);

        cout << value << endl;
    }
}
