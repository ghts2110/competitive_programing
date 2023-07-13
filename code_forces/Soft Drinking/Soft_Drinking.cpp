#include <iostream>

using namespace std;

int main(){
    int pessoas, garafas, litros, limas, fatias, sal, litrosN, salN;
    cin >> pessoas >> garafas >> litros >> limas >> fatias >> sal >> litrosN >> salN;

    int lt = garafas * litros, rl = limas * fatias;
    int cont = min(lt/(litrosN * pessoas), rl/pessoas);
    cont = min(cont, sal/(salN*pessoas));

    cout << cont << endl;
    
}
