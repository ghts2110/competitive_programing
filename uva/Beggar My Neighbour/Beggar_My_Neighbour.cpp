#include <iostream>
#include <deque>
#include <string>

#define pb push_back
#define pf push_front

using namespace std;

deque<char> p1, p2;
deque<char> b;
int l, cont;

void disputa(){
    l++;
    cont = 1;
    if(b.back() == 'A'){
        cont = 4;
    }else if(b.back() == 'K'){
        cont = 3;
    }else if(b.back() == 'Q'){
        cont = 2;
    }

    while(cont--){ 
        if(l % 2 == 0){
            if(p2.size() == 0){
                return;
            }

            b.pb(p2.front());
            p2.pop_front();
            if(b.back() != '-'){
                disputa();
                return;
            }
        }else{
            if(p1.size() == 0){
                return ;
            }
            b.pb(p1.front());
            p1.pop_front();
            if(b.back() != '-'){
                disputa();
                return ;
            }
        }
    }

}

int main(){
    string s;
    while(1){
        p1.clear(); 
        p2.clear();
        b.clear();

        for(int i = 0; i != 52; i++){
            cin >> s;
            if(s == "#"){
                return 0;
            }

            if(i % 2 == 0){
                if(s[1] >= 'A' && s[1] <= 'Z' && s[1] != 'T'){
                    p2.pf(s[1]);
                }else{
                    p2.pf('-');
                }
            }else{
                if(s[1] >= 'A' && s[1] <= 'Z' && s[1] != 'T'){
                    p1.pf(s[1]);
                }else{
                    p1.pf('-');
                }

            }
        }

        l = 0;
        while(1){
            if(l % 2 == 0){
                if(p2.size() == 0){
                    break;
                }
                b.pb(p2.front());
                p2.pop_front();
            }else{
                if(p1.size() == 0){
                    break;
                }
                b.pb(p1.front());
                p1.pop_front();
            }

            if(b.back() != '-'){
                disputa();

                if(cont != -1){
                    break;
                }

                while(b.size() != 0){
                    if(l % 2 == 0){
                        p1.pb(b.front());
                        b.pop_front();
                    }else{
                        p2.pb(b.front());
                        b.pop_front();
                    }
                }
            }

            l++;
        }

        if(l % 2 == 0){
            printf("1 %2lu\n", p1.size());
        }else{
            printf("2 %2lu\n", p2.size());
        }
    }    
}
