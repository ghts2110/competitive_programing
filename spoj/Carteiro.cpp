#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> casas;
    for(int i = 0; i != n; i++){
        int num;
        scanf("%d", &num);
        casas.push_back(num);
    }

    int index = 0, cont = 0;
    for(int i = 0; i != m; i++){
        int num;
        scanf("%d", &num);

        if(casas[index] == num){
            continue;
        }

        int save = index;
        index = lower_bound(casas.begin(), casas.end(), num) - casas.begin();

        cont += abs(save - index);
    }

    cout << cont << endl;
}
