#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    int ph=0, pa=0, th = 0, ta = 0;
    int lastT=-1, lastP=0;
    for(int i = 0; i != t; i++){
        char t, c;
        int p, m, s;
        cin >> t >> p >> m >> c >> s;

        if(t == 'H'){
            ph += p;
        }else{
            pa += p;
        }

        if(i != 0){
            if(lastP == 1){
                th += (m*60+s)-lastT;
            }else if(lastP == 2){
                ta += (m*60+s)-lastT;
            }
        }
        lastT = m*60+s;

        if(ph > pa){
            lastP = 1;
        }else if(pa > ph){
            lastP = 2;
        }else{
            lastP = 0;
        }
    }

    if(lastP == 1){
        th += (32*60)-lastT;
    }else if(lastP == 2){
        ta += (32*60)-lastT;
    }

    if(ph > pa){
        cout << 'H';
    }else{
        cout << 'A';
    }

    cout << " " << th/60 << ":";
    
    if(th%60 < 10){
        cout << '0' << th%60 << " " << ta/60 << ":";
    }else{
        cout << th%60 << " " << ta/60 << ":";
    }

    if(ta%60 < 10){
        cout << "0" << ta%60 << endl;
    }else{
        cout << ta%60 << endl;
    }
}
