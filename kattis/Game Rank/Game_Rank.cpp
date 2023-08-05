#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    while(cin >> s){


        int p = 0, ex = 0, rank = 25;

        for(int i = 0; i != s.size(); i++){
            if(s[i] == 'W'){
                p++;
                ex++;
                if(rank >= 6 && ex >= 3){
                    p++;
                }

                if(rank >= 21 && p > 2){
                    p -= 2;
                    rank--;
                }else if(rank >= 16 && p > 3){
                    p -= 3;
                    rank--;
                }else if(rank >= 11 && p > 4){
                    p -= 4; 
                    rank--;
                }else if(rank >= 1 && p > 5){
                    p -= 5;
                    rank--;
                }
            }else{
                ex = 0;
                if(rank <= 20 && rank >= 1){
                    p--;
                    if(p == -1){
                        if(rank == 20){
                            p = 0;
                            continue;
                        }

                        rank++;
                        if(rank >= 16){
                            p = 2;
                        }else if(rank >= 11){
                            p = 3;
                        }else{
                            p = 4;
                        }
                    }
                }
            }
        }

        if(rank <= 0){
            cout << "Legend" << endl;
        }else{
            cout << rank << endl;
        }

    }
}
