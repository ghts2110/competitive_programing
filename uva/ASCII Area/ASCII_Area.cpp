#include <iostream>

using namespace std;

int main(){
    int x, y;
    while(cin >> x >> y){
        double sum = 0;
        for(int i = 0; i != x; i++){
            for(int j = 0; j != y; j++){
                char c;
                cin >> c;

                if(c != '.'){
                    sum += 0.5;
                }else if(sum != (int)sum){
                    sum++;
                }
            }   
        }

        cout << sum << endl;

    }
}
