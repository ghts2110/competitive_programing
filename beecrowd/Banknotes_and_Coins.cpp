#include <iostream>

using namespace std;

int main(){
    double n;
    cin >> n;

    int N = n;

    int notes1 = (int)(N / 100);
    N = N % 100;
    int notes2 = (int)(N / 50);
    N = N % 50;
    int notes3 = (int)(N / 20);
    N = N % 20;
    int notes4 = (int)(N / 10);
    N = N % 10;
    int notes5 = (int)(N / 5);
    N = N % 5;
    int notes6 = (int)(N / 2);
    N = N % 2;


    int coins1 = (int)(N);
    N = int(n*100) % 100;
    int coins2 = (int)(N / 50);
    N = N % 50;
    int coins3 = (int)(N / 25);
    N = N % 25;
    int coins4 = (int)(N / 10);
    N = N % 10;
    int coins5 = (int)(N / 5);
    N = N % 5;
    int coins6 = (int)(N);

    cout << "NOTAS:" << endl;
    cout << notes1 << " nota(s) de R$ 100.00" << endl;
    cout << notes2 << " nota(s) de R$ 50.00" << endl;
    cout << notes3 << " nota(s) de R$ 20.00" << endl;
    cout << notes4 << " nota(s) de R$ 10.00" << endl;
    cout << notes5 << " nota(s) de R$ 5.00" << endl;
    cout << notes6 << " nota(s) de R$ 2.00" << endl;
    cout << "MOEDAS:" << endl;
    cout << coins1 << " moeda(s) de R$ 1.00" << endl;
    cout << coins2 << " moeda(s) de R$ 0.50" << endl;
    cout << coins3 << " moeda(s) de R$ 0.25" << endl;
    cout << coins4 << " moeda(s) de R$ 0.10" << endl;
    cout << coins5 << " moeda(s) de R$ 0.05" << endl;
    cout << coins6 << " moeda(s) de R$ 0.01" << endl;

}
