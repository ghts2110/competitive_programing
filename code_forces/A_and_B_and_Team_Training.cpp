#include <iostream>

using namespace std;

int main(){
    int n, m, cont = 0, team2NB;
    cin >> n >> m;

    cont = min(n, m/2);
    n -= cont;
    m -= cont*2;

    team2NB = cont + m;

    if(n == 0){
        cout << cont << endl;
        return 0;
    }

    while(n > 0 && team2NB != 0){
        n--;
        m++;
        if(n > 0 && m > 1){
            team2NB--;
            cont++;
            n--;
            m -= 2;
        }
    }

    cout << cont << endl;
}
