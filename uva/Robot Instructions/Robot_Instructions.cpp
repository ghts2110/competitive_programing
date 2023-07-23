#include <iostream>
#include <string>
#include <vector>

#define pb push_back

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<string> v; 
        int x = 0;
        for(int i= 0; i != n; i++){
            string s;
            cin >> s;

            if(s == "LEFT"){
                x--;
            }else if(s == "RIGHT"){
                x++;
            }else{
                cin >> s;
                int n;
                cin >> n;
                if(v[n-1] == "LEFT"){
                    x--;
                    v.pb("LEFT");
                }else{
                    x++;
                    v.pb("RIGHT");
                }
                continue;
            }

            v.pb(s);
        }

        cout << x << endl;
    }
}
