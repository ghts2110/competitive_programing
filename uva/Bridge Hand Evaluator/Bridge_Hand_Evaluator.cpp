#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string l;
    while(cin >> l){
        int s=0, h=0, d=0, c=0, cont = 0;
        bool vs = false, vh = false, vd = false, vc = false;
        bool ks = false, kh = false, kd = false, kc = false;
        bool qs = false, qh = false, qd = false, qc = false;
        bool js = false, jh = false, jd = false, jc = false;

        for(int i = 0; i != 13; i++){
            if(i != 0){
                cin >> l;
            }

            if(l[0] == 'K'){
                cont+=3;
                if(l[1] == 'S'){
                    ks = true;
                }else if(l[1] == 'H'){
                    kh = true;
                }else if(l[1] == 'D'){
                    kd = true;
                }else{
                    kc = true;;
                }

            }else if(l[0] == 'Q'){
                cont+=2;
                if(l[1] == 'S'){
                    qs = true;
                }else if(l[1] == 'H'){
                    qh = true;
                }else if(l[1] == 'D'){
                    qd = true;
                }else{
                    qc = true;
                }

            }else if(l[0] == 'J'){
                cont++;
                if(l[1] == 'S'){
                    js = true;
                }else if(l[1] == 'H'){
                    jh = true;
                }else if(l[1] == 'D'){
                    jd = true;
                }else{
                    jc = true;
                }

            }else if(l[0] == 'A'){
                cont+=4;
                if(l[1] == 'S'){
                    vs = true;
                }else if(l[1] == 'H'){
                    vh = true;
                }else if(l[1] == 'D'){
                    vd = true;
                }else{
                    vc = true;
                }

            }

            if(l[1] == 'S'){
                s++;
            }else if(l[1] == 'H'){
                h++;
            }else if(l[1] == 'D'){
                d++;
            }else{
                c++;
            }

        }

        if(ks && s-1 == 0){
            cont--;
        }else if(ks){
            vs = true;
        }
        if(kh && h-1 == 0){
            cont--;
        }else if(kh){
            vh = true;
        }
        if(kd && d-1 == 0){
            cont--;
        }else if(kd){
            vd = true;
        }
        if(kc && c-1 == 0){
            cont--;
        }else if(kc){
            vc = true;
        }

        if(qs && s-1 <= 1){
            cont--;
        }else if(qs){
            vs = true;
        }
        if(qh && h-1 <= 1){
            cont--;
        }else if(qh){
            vh = true;
        }
        if(qd && d-1 <= 1){
            cont--;
        }else if(qd){
            vd = true;
        }
        if(qc && c-1 <= 1){
            cont--;
        }else if(qc){
            vc = true;
        }

        if(js && s-1 <= 2){
            cont--;
        }
        if(jh && h-1 <= 2){
            cont--;
        }
        if(jd && d-1 <= 2){
            cont--;
        }
        if(jc && c-1 <= 2){
            cont--;
        }

        if(cont >= 16 && vs && vh && vd && vc){
            cout << "BID NO-TRUMP" << endl;
            continue;
        }

        if(s == 2){
            cont++;
        }else if(s < 2){
            cont += 2;
        }
        if(h == 2){
            cont++;
        }else if(h < 2){
            cont += 2;
        }
        if(d == 2){
            cont++;
        }else if(d < 2){
            cont += 2;
        }
        if(c == 2){
            cont++;
        }else if(c < 2){
            cont += 2;
        }

        if(cont < 14){
            cout << "PASS" << endl;
            continue;
        }

        if(s >= h && s >= d && s >= c){
            cout << "BID S" << endl;
        }else if(h >= s && h >= d && h >= c){
            cout << "BID H" << endl;
        }else if(d >= s && d >= h && d >= c){
            cout << "BID D" << endl;
        }else{
            cout << "BID C" << endl;
        }
    }
}
