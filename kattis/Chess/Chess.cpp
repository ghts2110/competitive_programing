#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int main(){
    int t;
    cin >> t;

    map<int, char> mp;
    mp[1] = 'A';
    mp[2] = 'B';
    mp[3] = 'C';
    mp[4] = 'D';
    mp[5] = 'E';
    mp[6] = 'F';
    mp[7] = 'G';
    mp[8] = 'H';

    while(t--){
        int l, a;
        char c, b;

        cin >> c >> l >> b >> a;
        if(((c-'A'+1)+l)%2 != ((b-'A'+1)+a)%2){
            cout << "Impossible" << endl;
            continue;
        }

        if(c == b && l == a){
            cout << 0 << " " << c << " " << l << endl;
        }else if((c-'A'+1)-l == (b-'A'+1)-a || abs(l-a) == abs((c-'A'+1)-(b-'A'+1))){
            cout << 1 << " " << c << " " << l << " " << b << " " << a << endl;
        }else{
            cout << 2 << " " << c << " " << l << " ";
            
            int x = 1, y = 1;
            while(1){
                if((x-y==(b-'A'+1)-a || abs(x-(b-'A'+1))==abs(y-a)) && (x-y==(c-'A'+1)-l || abs(y-l)==abs(x-(c-'A'+1)))){
                       cout << mp[x] << " " << y << " ";
                       break;
                }
                x++;
                if(x == 9){
                    x = 1;
                    y++;
                }
            }

            cout << b << " " << a << endl;
        }
    }
}
