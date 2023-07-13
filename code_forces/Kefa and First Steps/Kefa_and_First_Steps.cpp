#include <iostream>

using namespace std;

int main(){
    int t, start, end, cont = 0, mx = 0;
    cin >> t;
    
    cin >> start;
    t--;
    while(t--){
        cin >> end;
        if(start <= end){
            cont++;
        }else{
            mx = max(mx, cont);
            cont = 0;
        }
        start = end;
    }

    mx = max(mx, cont);
    cout << mx + 1 << endl;

}
