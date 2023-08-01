#include <iostream>
#include <cmath>
#include <map>
#include <string>
#include <deque>
#include <bitset>
#include <algorithm>

#define pf push_front
#define pb push_back

using namespace std;

bool myfunction (int i,int j) { return (i>j); }

int main(){
    string card;
    while(cin >> card){
        deque<pair<int, int>> v1;
        for(int i = 0; i != 5; i++){
            if(i != 0){
                cin >> card;
            }
            int t, val;
            if(card[1] == 'C'){
                t = 0;
            }else if(card[1] == 'D'){
                t = 1;
            }else if(card[1] == 'H'){
                t = 2;
            }else{
                t = 3;
            }

            if(card[0] == 'A'){
                val = 14;
            }else if(card[0] == 'K'){
                val = 13;
            }else if(card[0] == 'Q'){
                val = 12;
            }else if(card[0] == 'J'){
                val = 11;
            }else if(card[0] == 'T'){
                val = 10;
            }else{
                val = card[0] - '0';
            }

            pair<int, int> p(t, val);
            v1.push_back(p);
        }
        sort(v1.begin(), v1.end());
        
        int cont9 = 1, mx9 = 0, cont8 = 0, mx8 = 0, cont7 = 0, mx7 = 0, cont6 = 1, cont5 = 0, mx5 =0;
        int cont4 = 0, mx4 = 0, cont3=0, mx31 =0, mx32 =0, mx33 =0, cont2 = 0, mx2 = 0;
        map<int, int> mp;
        mp[v1[0].second]++;
        for(int i = 1; i != 5; i++){
            if(v1[i].first == v1[i-1].first && v1[i].second == v1[i-1].second +1){
                cont9 ++;
                if(cont9 == 5){
                    mx9 = v1[i].second;
                    break;
                }
            }   
            
            mp[v1[i].second]++;
            if(mp[v1[i].second] == 4){
                cont8 = 1;
                mx8 = v1[i].second;
            }
            
            
            if(i == 4){
                bool pr = false, tr = false;
                for(int j = 1; j != 15; j++){
                    if(mp[j] == 2){
                        pr = true;
                    }else if(mp[j] == 3){
                        mx7 = j;
                        tr = true;
                    }
                }

                if(pr && tr){
                    cont7 = 1;
                }
            }

            if(v1[i].first == v1[i-1].first){
                cont6++;
            }

            if(i == 4){            
                bitset<15> bt(0);
        
                for(int j = 0; j != 5; j++){
                    bt[v1[j].second] = 1;
                }
               
                int c = 1;
                for(int i = 1; i != 15; i++){
                    if(bt[i] == 1 && bt[i-1] == 1){
                        c++;
                        mx5 = i;
                    }
                }

                if(c == 5){
                    cont5 = 1;
                }
            }

            if(mp[v1[i].second] == 3){
                cont4 = 1;
                mx4 = v1[i].second;
            }

            if(i == 4){
                bool pr1 = false, pr2 = false;
                int vl1, vl2, vl3;
                for(int j = 1; j != 15; j++){
                    if(mp[j] == 2 && !pr1){
                        pr1 = true;
                        vl1 = j;
                    }else if(mp[j] == 2){
                        mx7 = j;
                        pr2 = true;
                        vl2 = j;
                    }

                    if(mp[j] == 1){
                        vl3 = j;
                    }
                }

                if(pr1 && pr2){
                    cont3 = 1;
                    mx31 = vl1;
                    mx32 = vl2;
                    mx33 = vl3;
                }else if(pr1){
                    cont2 = 1;
                    mx2 = vl1;
                }

            }
        }

        int tip1;
        deque<int> val1;
        if(cont9 == 5){
            tip1 = 9;
            val1.pb(mx9);
        }else if(cont8 == 1){
            tip1 = 8;
            val1.pb(mx8);
        }else if(cont7 == 1){
            tip1 = 7;
            val1.pb(mx7);
        }else if(cont6 == 5){
            tip1 = 6;
            for(int i = 0; i != 5; i++){
                val1.pb(v1[i].second);
            }
            sort(val1.begin(), val1.end(), myfunction);
        }else if(cont5 == 1){
            tip1 = 5;
            val1.pb(mx5);
        }else if(cont4 == 1){
            tip1 = 4;
            val1.pb(mx4);
        }else if(cont3 == 1){
            tip1 = 3;
            val1.pb(mx31);
            val1.pb(mx32);
            val1.pb(mx33);
        }else if(cont2 == 1){
            tip1 = 2;
            for(int i = 0; i != 5; i++){
                if(v1[i].second != mx2){
                    val1.pb(v1[i].second);
                }
                sort(val1.begin(), val1.end(), myfunction);
            }
            val1.pf(mx2);
        }else{
            tip1 = 1;
            for(int i = 0; i != 5; i++){
                val1.pb(v1[i].second);
            }
            sort(val1.begin(), val1.end(), myfunction);
        }
       
        deque<pair<int, int>> v2;
        for(int i = 0; i != 5; i++){
            cin >> card;
            
            int t, val;
            if(card[1] == 'C'){
                t = 0;
            }else if(card[1] == 'D'){
                t = 1;
            }else if(card[1] == 'H'){
                t = 2;
            }else{
                t = 3;
            }

            if(card[0] == 'A'){
                val = 14;
            }else if(card[0] == 'K'){
                val = 13;
            }else if(card[0] == 'Q'){
                val = 12;
            }else if(card[0] == 'J'){
                val = 11;
            }else if(card[0] == 'T'){
                val = 10;
            }else{
                val = card[0] - '0';
            }

            pair<int, int> p(t, val);
            v2.push_back(p);
        }
        sort(v2.begin(), v2.end());
        
        cont9 = 1, mx9 = 0, cont8 = 0, mx8 = 0, cont7 = 0, mx7 = 0, cont6 = 1, cont5 = 0, mx5 =0;
        cont4 = 0, mx4 = 0, cont3=0, mx31 = mx32 = mx33 =0, cont2 = 0, mx2 = 0;
        mp.clear();
        mp[v2[0].second]++;
        for(int i = 1; i != 5; i++){
            if(v2[i].first == v2[i-1].first && v2[i].second == v2[i-1].second +1){
                cont9 ++;
                if(cont9 == 5){
                    mx9 = v2[i].second;
                    break;
                }
            }   
            
            mp[v2[i].second]++;
            if(mp[v2[i].second] == 4){
                cont8 = 1;
                mx8 = v2[i].second;
            }
            
            
            if(i == 4){
                bool pr = false, tr = false;
                for(int j = 1; j != 15; j++){
                    if(mp[j] == 2){
                        pr = true;
                    }else if(mp[j] == 3){
                        mx7 = j;
                        tr = true;
                    }
                }

                if(pr && tr){
                    cont7 = 1;
                }
            }

            if(v2[i].first == v2[i-1].first){
                cont6++;
            }

            if(i == 4){            
                bitset<15> bt(0);
        
                for(int j = 0; j != 5; j++){
                    bt[v2[j].second] = 1;
                }
               
                int c = 1;
                for(int i = 1; i != 15; i++){
                    if(bt[i] == 1 && bt[i-1] == 1){
                        c++;
                        mx5 = i;
                    }
                }

                if(c == 5){
                    cont5 = 1;
                }
            }

            if(mp[v2[i].second] == 3){
                cont4 = 1;
                mx4 = v2[i].second;
            }
            
            if(i == 4){
                bool pr1 = false, pr2 = false;
                int vl1, vl2, vl3;
                for(int j = 1; j != 15; j++){
                    if(mp[j] == 2 && !pr1){
                        pr1 = true;
                        vl1 = j;
                    }else if(mp[j] == 2){
                        mx7 = j;
                        pr2 = true;
                        vl2 = j;
                    }

                    if(mp[j] == 1){
                        vl3 = j;
                    }
                }

                if(pr1 && pr2){
                    cont3 = 1;
                    mx31 = vl1;
                    mx32 = vl2;
                    mx33 = vl3;
                }else if(pr1){
                    cont2 = 1;
                    mx2 = vl1;
                }

            }
        }

        int tip2;
        deque<int> val2;
        if(cont9 == 5){
            tip2 = 9;
            val2.pb(mx9);
        }else if(cont8 == 1){
            tip2 = 8;
            val2.pb(mx8);
        }else if(cont7 == 1){
            tip2 = 7;
            val2.pb(mx7);
        }else if(cont6 == 5){
            tip2 = 6;
            for(int i = 0; i != 5; i++){
                val2.pb(v2[i].second);
            }
            sort(val2.begin(), val2.end(), myfunction);
        }else if(cont5 == 1){
            tip2 = 5;
            val2.pb(mx5);
        }else if(cont4 == 1){
            tip2 = 4;
            val2.pb(mx4);
        }else if(cont3 == 1){
            tip2 = 3;
            val2.pb(mx31);
            val2.pb(mx32);
            val2.pb(mx33);
        }else if(cont2 == 1){
            tip2 = 2;
            for(int i = 0; i != 5; i++){
                if(v2[i].second != mx2){
                    val2.pb(v2[i].second);
                }
                sort(val2.begin(), val2.end(), myfunction);
            }
            val2.pf(mx2);
        }else{
            tip2 = 1;
            for(int i = 0; i != 5; i++){
                val2.pb(v2[i].second);
            }
            sort(val2.begin(), val2.end(), myfunction);
        }

        if(tip1 > tip2){
            cout << "Black wins." << endl;
        }else if(tip1 < tip2){
            cout << "White wins." << endl;
        }else{
            if(val1 > val2){
                cout << "Black wins." << endl;
            }else if(val1 < val2){
                cout << "White wins." << endl;
            }else{
                cout << "Tie." << endl;
            }
        }
    }
}
