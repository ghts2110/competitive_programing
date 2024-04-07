#include <iostream>

using namespace std;

int main(){
    int s, p1, p2, p3;
    while(cin >> s >> p1 >> p2 >> p3){
        
        if(s == p1 && s == p2 && s == p3 && s==0){
            break;
        }

        int asw = 1080;
        if(s > p1){
            asw += (s-p1)*9;
        }else{
            asw += (s + (40-p1))*9;
        }

        if(p1 < p2){
            asw += (p2-p1)*9;
        }else{
            asw += ((40-p1) + p2)*9;
        }

        if(p2 > p3){
            asw += (p2 -p3)*9;
        }else{
            asw += (p2 + (40-p3))*9;
        }
        
        cout << asw << endl;
    }
}

