#include <iostream>

using namespace std;

int main(){
    long long n, cont = 0, start, end;
    cin >> n;
   
    cin >> start;
    n--;

    while(n--){
        cin >> end;
        
        if(end - start > 10){
            cont += 10;
        }else{
            cont += end - start;
        }
        start = end;
    }

    cont += 10;

    cout << cont << endl;
}
