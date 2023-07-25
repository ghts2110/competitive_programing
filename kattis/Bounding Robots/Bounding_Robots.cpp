#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int w, l;
    
    while(cin >> w >> l){
        if(w == 0 && l == 0){
            break;
        }

        int n;
        cin >> n;

        pair<int, int> t(0, 0), a(0, 0); 
        for(int i = 0; i != n; i++){
            char c;
            int m;
            cin >> c >> m;
            
            if(c == 'u'){
                t.second += m;
                a.second = min(a.second + m, l-1);
            }else if(c == 'd'){
                t.second -= m;
                a.second = max(a.second-m, 0);
            }else if(c == 'l'){
                t.first -= m;
                a.first = max(a.first-m, 0);
            }else{
                t.first += m;
                a.first = min(a.first+m, w-1);
            }
        }

        cout << "Robot thinks " << t.first << " " << t.second << endl;
        cout << "Actually at " << a.first << " " << a.second << endl;
        cout << endl; 
    }
}
