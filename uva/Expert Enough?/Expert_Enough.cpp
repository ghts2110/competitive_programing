#include <iostream>
#include <string>
#include <vector>

#define pb push_back

using namespace std;

int main(){
    int t;
    cin >> t;

    int test = 1;
    while(t--){
        if(test != 1){
            cout << endl;
        }
        test++;
        
        int n;
        cin >> n;

        vector<string> name;
        vector<pair<int, int>> v;
        for(int i = 0;i != n; i++){
            string m;
            int l, h;
            cin >> m >> l >> h;
        
            name.pb(m);
            pair<int, int> p(l, h);

            v.pb(p);
        }

        int h;
        cin >> h;
        for(int i = 0; i != h; i++){
            int num;
            cin >> num;

            int cont = 0;
            string s;
            for(int j = 0; j != n; j++){
                if(num >= v[j].first && num <= v[j].second){
                    cont++;
                    s = name[j];
                }
            }

            if(cont == 1){
                cout << s << endl;
            }else{
                cout << "UNDETERMINED" << endl;
            }
        }
    }
}
