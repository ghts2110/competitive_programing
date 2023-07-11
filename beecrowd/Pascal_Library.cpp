#include <iostream>
#include <vector>

using namespace std;

int main(){
    int x, y;
    while(1){
        cin >> x >> y;
        vector<int> v(x);
        if(x == 0 && y == 0){
            break;
        }

        for(int i = 0; i != y; i++){
            for(int j = 0; j != x; j++){
                int num;
                cin >> num;
                v[j] += num;
            }
        }

        for(int i = 0; i != x; i++){
            if(v[i] == y){
                cout << "yes" << endl;
                break;
            }else if(i == x-1){
                cout << "no" << endl;
            }
        }
    }
}
