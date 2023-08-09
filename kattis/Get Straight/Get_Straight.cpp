#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getPrize(vector<int> num) {
    vector<int>  bt(13);

    for (int i = 0; i < 5; i++)
        bt[num[i]]++;

    for(int i = 0; i != 13; i++){
        bool validate = true;
        for(int j = 0; j != 5; j++){
            if(bt[(i+j)%13] == 0){
                validate = false;
                break;
            }
        }

        if(validate){
            return 100;
        }
    }	

    for(int i = 0; i != 13; i++){
        bool validate = true;
        for(int j = 0; j != 4; j++){
            if(bt[(i+j)%13] == 0){
                validate = false;
                break;
            }
        }

        if(validate){
            return 10;
        }
    }

    vector<int> save = bt;
    for(int i = 0; i != 13;i++){
        bool validate = true;

        for(int j = 0; j != 3; j++){
            if(save[(i+j)%13] == 0){
                validate = false;
                break;
            } 

            if(j == 2){
                for(int j = 0; j != 3; j++){
                    save[(i+j)%13]--;
                }

                for(int j = 0; j != 13; j++){
                    validate = true;                    
                    for(int k = 0; k != 2; k++){
                        if(save[(j+k)%13] == 0){
                            validate = false;
                            break;
                        }
                    }

                    if(validate){
                        return 5;
                    }
                }
            }
        }
    }

    for(int i = 0; i != 13; i++){
        bool validate = true;

        for(int j = 0; j != 3; j++){
            if(bt[(i+j)%13] == 0){
                validate = false;
                break;
            }
        }

        if(validate){
            return 3;
        }
    }

    save = bt;
    for(int i = 0; i != 13;i++){
        bool validate = true;

        for(int j = 0; j != 2; j++){
            if(save[(i+j)%13] == 0){
                validate = false;
                break;
            } 

            if(j == 1){
                for(int j = 0; j != 2; j++){
                    save[(i+j)%13]--;
                }

                for(int j = 0; j != 13; j++){
                    validate = true;                    
                    for(int k = 0; k != 2; k++){
                        if(save[(j+k)%13] == 0){
                            validate = false;
                            break;
                        }
                    }

                    if(validate){
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}

int main() {	
    string s;
    while (getline(cin, s)){
        vector<int> num(5);

        if(s == "#") {
            return 0;
        }

        int ndx = 0;
        for(int i = 0; i < 14; i+=3){
            int n = s[i] - '0';
            if(s[i] == 'A'){
                n = 1;
            }else if(s[i] == 'J'){
                n = 11;
            }else if(s[i] == 'Q'){
                n = 12;
            }else if(s[i] == 'K'){
                n = 13;
            }else if(s[i] == 'T'){
                n = 10;
            } 
            num[ndx] = n-1;
            ndx++;
        }

        double value = getPrize(num) * 47.0;
        double maxe = 0;
        ndx = 0;

        vector<int> bt(13);
        for(int i = 0; i != 5; i++){
            bt[num[i]]++;
        }

        for (int i = 0; i < 5; i++) {
            vector<int> save = num; 
            double e = 0;
            for (int j = 0; j < 13; j++) {
                save[i] = j; 
                e += (4 - bt[j]) * getPrize(save);
            } 
            
            e -=  47.0;
            if (e > maxe)
                maxe = e, ndx = i;
        }

        if (value < maxe) {
            cout << "Exchange "; 
            cout << s[ndx*3] << s[ndx*3 +1] << endl;
        } else {
            cout << "Stay" << endl;
        }
    }
    return 0;
}
