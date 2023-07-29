#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >>t ;

    int test = 1;
    while(t--){
        cout << "Case "<<test<<": ";
        test++;

        vector<string> v(52);
        for(int i = 0; i != 52; i++){
            cin >> v[i];
        }

        int index = 26, y = 0;
        for(int i = 0; i != 3; i++){
            int x;
            if(v[index][0] >= 'A' && v[index][0] <= 'Z'){
                x = 10;
            }else{
                x = v[index][0] - '0';
            }
            y+=x;
            
            for(int j = 0; j != 10-x+1; j++){
                v.erase(v.begin()+index);
                index--;
            }
        }

        cout << v[y-1] << endl;
    }
}
