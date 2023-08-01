#include <iostream>
#include <string> 
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;

    int test = 0;
    while(t--){
        if(test != 0){
            cout << endl;
        }
        test++;


        int n;
        cin >> n;
        vector<string> asw(53);
        vector<vector<int>> v(n+1, vector<int>(53));

        int cont = -1;
        string naip;
        for(int i = 2; i <= 53; i++){
            if(i % 13 == 2){
                cont++;
                if(cont == 0){
                    naip = "of Clubs";
                }else if(cont == 1){
                    naip = "of Diamonds";
                }else if(cont == 2){
                    naip = "of Hearts";
                }else{
                    naip = "of Spades";
                }
            }

            int value = i % 13;
            if(value == 11){
                asw[i-1] = "Jack ";
            }else if(value == 12){
                asw[i-1] = "Queen ";
            }else if(value == 0){
                asw[i-1] = "King ";
            }else if(value == 1){
                asw[i-1] = "Ace ";
            }else{
                asw[i-1] = to_string(value) + " ";
            }

            asw[i-1] += naip;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= 52; j++){
                int num; 
                cin >> num;

                v[i][j] = num;
            }
        }

        string s;
        getline(cin, s);
        while(getline(cin, s)){
            if(s.size() == 0){
                break;
            }

            vector<string> nw(53);
            for(int i = 1; i <= 52; i++){
                nw[i] = asw[v[stoi(s)][i]];
            }
            asw = nw;
        }

        for(int i = 1; i <= 52; i++){
            cout << asw[i] << endl;
        }
    }
}

