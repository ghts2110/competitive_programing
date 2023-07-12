#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, cont = 0;
    string sg, sr;
    
    cin >> n >> sg >> sr;

    for(int i = 0; i != n; i++){
        if(sg[i] == sr[i]){
            cont++;
        }
    }

    cout << cont << endl;
}
