#include <iostream>

using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0){
            break;
        }

        int tic = -1, prz;
        double mn = 1e9;
        for(int i = 0; i != n; i++){
            double a, b;
            cin >> a >> b;

            if(a <= m && ((mn > b/a) || (mn == b/a && a > tic))){
                mn = b/a;
                tic = a;
                prz = b;
            }
        }

        if(tic == -1){
            cout << "No suitable tickets offered" << endl;
        }else{
            cout << "Buy "<<tic<<" tickets for $"<<prz << endl;
        }
    }
}
