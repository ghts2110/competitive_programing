#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin >> t;
    int cont = 0;
    while(t--){
        string s;
        getline(cin,s);
        if(cont == 0){
            getline(cin,s);
            cont = 1;
        }
        bool b = true;
        string s1, s2;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                b = false;
                continue;
            }
            if(b){
                s1 += s[i];
            }else{
                s2 += s[i];
            }
        }

        double n1 = stod(s1);
        double n2;
        if(s2 != ""){
            n2 = stod(s2);
        }

        double pi = 2 * acos(0);
        if(s2 == ""){
            double quad = ((n1/2.0) * (n1/2.0));
            double areat = pi * quad;
            areat = areat /2.0;
            printf("%.4f\n",areat);
        }else{
            double areacirc1 = pi * pow(n1,2);
            double areacirc2 = pi * pow(n2,2);
            if(n1 == n2){
                double areagrande = pi * pow(2 * n1, 2);
                double areat = areagrande - areacirc1 - areacirc2;
                printf("%.4f\n",areat);
            }else{
                double raiogrande = ((2 * n1) + (2 * n2))/2;
                double areagrande = pi * pow(raiogrande,2);
                double areat = areagrande - areacirc1 - areacirc2;
                printf("%.4f\n",areat);
            }
        }
    }
}