#include <iostream>
#include <deque>
using namespace std;
int main(){
    long long test;
    cin >> test;
    while(test--){
        long long l,m;
        cin >> l >> m;

        deque<long long>lef;
        deque<long long>rig;
        for(long long i = 0; i < m; i++){
            long long num;
            cin >> num;
            string s;
            cin >> s;
            if(s == "left"){
                lef.push_back(num);
            }else{
                rig.push_back(num);
            }
        }

        long long cont = 0;
        char pos = 'E';
        long long comp = 100 * l;
        while(!lef.empty() || !rig.empty()){
            long long sum = 0;
            if(pos == 'E'){
                while(true){
                    if(!lef.empty() && sum + lef[0] <= comp){
                        sum += lef[0];
                        lef.pop_front();
                    }else{
                        break;
                    }
                }
                pos = 'D';
                cont++;
            }else{
                while(true){
                    if(!rig.empty() && sum + rig[0] <= comp){
                        sum += rig[0];
                        rig.pop_front();
                    }else{
                        break;
                    }
                }
                pos = 'E';
                cont++;
            }
        }

        cout << cont << endl;
    }
}