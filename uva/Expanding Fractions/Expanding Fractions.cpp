#include <iostream>
#include <bitset>

using namespace std;

int main(){
    int isf = 0;

    while(1){
        int n, cont = 0, max, min = 1234;
        char s = 'n';

        cin >> n;

        if(n == 0){
            break;
        }

        if(isf == 0){
            isf = 1;
        }else{
            cout << endl;
        }

        while(min < 87654){
            int div = 10000, cont = 0, num = min;
            bitset<10> bs(0);

            if(num / div == 0){
                bs[0] = 1;
                cont++;

                div /= 10;
            }

            while(div != 0){        
                if(bs[num/div] == 0){
                    bs[num/div] = 1;
                    cont++;
                }

                num %= div;
                div /= 10; 
            }


            if(min*n > 98765){
                break;
            }

            if(cont == 5){
                num = max = min * n;
                div = 10000;

                while(div != 0){
                    if(bs[num/div] == 0){
                        bs[num/div] = 1;
                        cont++;
                    }

                    num %= div;
                    div /= 10;
                }
                
                if(cont == 10){
                    s = 'y';
                    cout << max << " / ";
                    if(min/10000 == 0){
                        cout << "0" << min << " = " << n << endl;
                    }else{
                        cout << min << " = " << n << endl;
                    }
                }
            }

            min++;
        }

        if(s == 'n'){
            cout << "There are no solutions for " << n << "." << endl;
        }
    }
}
