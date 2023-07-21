#include <iostream>

using namespace std;

int main(){
    int n, y;
    cin >> n >> y;

    int k = -1;
    for(int i = 0; i != n; i++){
        int num;
        cin >> num;

        if(num <= y && k == -1){
            k = i;
        }
    }

    if(k == -1){
        cout << "It had never snowed this early!" << endl;
    }else{
        cout << "It hadn't snowed this early in "<<k<<" years!" << endl;
    }
}
