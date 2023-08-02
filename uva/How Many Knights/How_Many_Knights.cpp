#include <iostream>

using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0){
            break;
        }

        int value;
        if(n == 0 || m == 0){
            value = 0;
        }else if(n == 1){
            value = m;
        }else if(m == 1){
            value = n;
        }else if(n == 2 || m == 2){
            value = (n*m)/8; 
            value *= 4;
            if((n*m)%8 >= 4){
                value += 4;
            }else if((n*m)%8 == 2){
                value += 2;
            }
        }else{
            value = (n*m)/2;
            if((n*m)%2 == 1){
                value++;
            }
        }

        cout << value <<" knights may be placed on a "<<n<<" row "<<m<<" column board." << endl;
    }
}
