#include <iostream>

using namespace std;

int main(){
    int b;
    double p;
    int t;
    cin >> t;

    while(t--){
        cin >> b >> p;

        double bpm = (60*b)/p;
        double ABPMmax = bpm+(60/p), ABPMmin = bpm-(60/p);
        printf("%.4f %.4f %.4f\n", ABPMmin, bpm, ABPMmax);
    }
}
