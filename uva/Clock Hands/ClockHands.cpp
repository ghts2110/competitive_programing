#include <iostream>

using namespace std;

int main(){
    double h, m;
    while(scanf("%lf:%lf", &h, &m) == 2){
        if(!h && !m){
            break;
        }
        double g1 = (h*30)+(m/2);
        double g2 = m*6;

        double asw = abs(g1-g2);
        if(asw > 180){
            asw = 360 - asw;
        }

        printf("%.3f\n", asw);
    }
}
