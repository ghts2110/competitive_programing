#include <iostream>
#include <random>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;

    int test = 1;
    while(t--){
        if(test != 1){
            cout << endl;
        }
        test++;


        string p1, p2;
        cin >> p1 >> p2;

        int cont = 0;
        string b1 = "", b2 = "";
        while(1){
            cont++;
            b1 = p1[0] + b1;
            b2 = p2[0] + b2;

            p1.erase(p1.begin());
            p2.erase(p2.begin());

            if(b1[0] == b2[0]){
                if(random()/141%2 == 0){
                    b1 = b2 + b1; 

                    b2 = "";
                    cout << "Snap! for Jane: " << b1 << endl;
                }else{
                    b2 = b1 + b2;

                    b1 = "";
                    cout << "Snap! for John: " << b2 << endl;
                }
            }

            if(p1.size() == 0){
                for(int i = 1; i <= b1.size(); i++){
                    p1 += b1[b1.size()-i];
                }
                b1 = "";
            }

            if(p2.size() == 0){
                for(int i = 1; i <= b2.size(); i++){
                    p2 += b2[b2.size()-i];
                }
                b2 = "";
            }

            if(p1.size() == 0 || p2.size() == 0 || cont == 1001){
                break;
            }
        }
        if(p1.size() == 0){
            cout << "John wins." << endl;
        }else if(p2.size() == 0){
            cout << "Jane wins." << endl;
        }else{
            cout << "Keeps going and going ..." << endl;
        }

    }
}
