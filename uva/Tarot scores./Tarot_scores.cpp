#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;

    int test = 1;
    while(t--){
        int n;
        cin >> n;
    
        string s;
        getline(cin, s);
        
        int oudlers = 0;
        double value = 0;
        for(int i = 0;i != n; i++){
            getline(cin, s);
            
            if(s == "fool" || s == "twenty-one of trumps" || s == "one of trumps"){
                oudlers++;
                value += 4.5;
            }else if(s[0] == 'k' && s[1] == 'i'){
                value += 4.5;
            }else if(s[0] == 'q'){
                value += 3.5; 
            }else if(s[0] == 'k'){
                value += 2.5;
            }else if(s[0] == 'j'){
                value += 1.5;
            }else{
                value += 0.5;
            }
        }

        int point;
        if(oudlers == 3){
            point = 36;
        }else if(oudlers == 2){
            point = 41;
        }else if(oudlers == 1){
            point = 51;
        }else{
            point = 56;
        }

        if(test != 1){
            cout << endl;
        }
        cout << "Hand #" << test << endl;
        test++;

        if(value < point){
            cout << "Game lost by "<<point-value<<" point(s)." << endl;
        }else{
            cout << "Game won by "<<value-point<<" point(s)." << endl;
        }
    }
}
