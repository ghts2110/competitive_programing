#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v;
    for(int i = 0; i != n; i++){
        int num;
        cin >> num;

        v.push_back(num);
    }

    if(n == 1){
        cout << 1 << " " << 0 << endl;
        return 0;
    }
    int p1 = 0, p2 = n-1, a = 0, b = 0;
    
    for(int i = 0; i != n; i++){
        int mn = min(v[p1], v[p2]);
        v[p1] -= mn;
        v[p2] -= mn;

        if(v[p1] == 0){
            a++;
            if(p1+1 == p2){
                b++;
                break;
            }else{
                p1++;
            }
        }
        if(v[p2] == 0){
            b++;
            if(p2-1 == p1){
                a++;
                break;
            }else{
                p2--;
            }
        }

    }

    cout << a << " " << b << endl;
}
