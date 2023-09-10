#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        map<int, bool> mp;
        vector<int> v(1000005);
        int asw = 0;

        for(int i = 0; i != n; i++){
            int h;
            scanf("%d", &h);

            if(!mp[h+1]){
                asw++;
                v[h]++;
                mp[h] = true;
            }else{
                v[h]++;
                mp[h] = true;

                v[h+1]--;
                if(!v[h+1]){
                    mp[h+1] = false;
                }
            }
        }

        printf("%d\n", asw);
    }
}