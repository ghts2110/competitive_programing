#include <iostream>

using namespace std;

int main(){
    int n, test = 1;
    while(1){
        int areaX, areaY, areaU, areaV, r = 1;
        cin >> n;
        if(n == 0){
            break;
        }

        cin >> areaX >> areaY >> areaU >> areaV; 
        n--;

        while(n--){
            int x, y, u, v;
            cin >> x >> y >> u >> v;
                
            if(u < areaX || x > areaU || y < areaV || v > areaY){
                r = 0;
            }

            areaX = max(areaX, x);
            areaY = min(areaY, y);
            areaU = min(areaU, u);
            areaV = max(areaV, v);
        }

        cout << "Teste " << test << endl;

        if(r == 1){
            cout << areaX << " " << areaY << " " << areaU << " " << areaV << endl << endl;
        }else{
            cout << "nenhum" << endl << endl;
        }

        test++;
    }
}
