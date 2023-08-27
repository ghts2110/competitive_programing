#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;

    for(int test = 1; test <= n; test++){
        cout << test << " $";
        
        double cont = 0;
        for(int i = 0; i != 12; i++){
            double num;
            cin >> num;

            cont += num;
        }
        
        cont /= 12;
        string s = to_string(cont);
        
        int index = 0;
        for(int i = 0; i != s.size(); i++){
            if(s[i] == '.'){
                index = i;
                break;
            }   
        }

        bool val = false;
        for(int i = 0; i < index-1; i++){
            val = true;
            cout << s[i]; 
            if(index%3 == (i%3)+1){
                cout << ",";
            }
        }

        cont = ((int)cont % 10)+(cont-(int)cont);
        
        printf("%.2f\n", cont);
    }
}
