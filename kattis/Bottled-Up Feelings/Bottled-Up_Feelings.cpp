#include <iostream>

using namespace std;

int main(){
    int s, v1, v2;
    while(cin >> s >> v1 >> v2){
        int div = s/v1;

        bool validate = true;
        while(div != -1){
            if((s - (div * v1))%v2 == 0){
                cout << div  << " " << (s - (div * v1))/v2 << endl;
                validate = false;
                break;
            }
            div--;
        }

        if(validate){
            cout << "Impossible" << endl;
        }
    }
}
