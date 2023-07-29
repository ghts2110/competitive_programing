#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

int main(){
    while(1){
        vector<int> p1(3), p2(2);
        cin >> p1[0] >> p1[1] >> p1[2] >> p2[0] >> p2[1];
        if(p1[0] == 0){
            break;
        }
        
        bitset<53> bt(0);
        for(int i = 0; i != p1.size(); i++){
            bt[p1[i]] = 1;
        }
        for(int i = 0; i != p2.size(); i++){
            bt[p2[i]] = 1;
        }

        sort(p1.begin(), p1.end());
        sort(p2.begin(), p2.end());
        
        int cont = 0;
        for(int i = 0; i != p1.size(); i++){
            if(p2[1] < p1[i]){
                p2.erase(p2.begin()+1);
                p1.erase(p1.begin() + i);
                cont++;
                break;
            }
        }
        
        if(p2.size() != 1){
            p2.erase(p2.begin()+1);
            p1.erase(p1.begin());
        }

        for(int i = 0; i != p1.size(); i++){
            if(p2[0] < p1[i]){
                p2.erase(p2.begin());
                p1.erase(p1.begin() + i);
                cont++;
                break;
            }   
        }

        if(p2.size() != 0){
            p2.erase(p2.begin());
            p1.erase(p1.begin());
        }

        if(cont == 2){
            cout << -1 << endl;
        }else if(cont == 0){
            int asw = 1;
            while(bt[asw] == 1){
                asw++;
            }

            if(asw > 52){
                asw = -1;
            }

            cout << asw << endl;
        }else{
            int asw = p1[0] +1;
            while(bt[asw] == 1){
                asw++;
            }
            
            if(asw > 52){
                asw = -1;
            }
            
            cout << asw << endl;
        }
    }
}
