#include <iostream>
#include <cmath>
#include <vector> 

using namespace std;

int main(){
    int t;
    cin >> t;


    while(t--){
        vector<int> l1(5), l2(5), l3(5), l4(5), l5(5), c1(5), c2(5), c3(5), c4(5), c5(5);
        vector<int> d1(5), d2(5);

        for(int i = 0 ; i != 5; i++){
            for(int j = 0; j != 5; j++){
                if(i == j && j == 2){
                    continue;
                }

                int num;
                cin >> num;

                if(i == 0){
                    l1[j] = num;
                }else if(i == 1){
                    l2[j] = num;
                }else if(i == 2){
                    l3[j] = num;
                }else if(i == 3){
                    l4[j] = num;
                }else if(i == 4){
                    l5[j] = num;
                }

                if(j == 0){
                    c1[i] = num;
                }else if(j == 1){
                    c2[i] = num;
                }else if(j == 2){
                    c3[i] = num;
                }else if(j == 3){
                    c4[i] = num;
                }else if(j == 4){
                    c5[i] = num;
                }

                if(i == j){
                    d1[i] = num; 
                }
                if(i + j == 4){
                    d2[i] = num;
                }
            }
        }

        bool validate = false;
        int value = 0;
        for(int j = 0; j <= 75; j++){
            int num; 
            if(j == 0){
                num = 0;
            }else{
                cin >> num;
            }


            if(validate){
                continue;
            }

            for(int i = 0; i != 5; i++){
                if(l1[i] == num && l1.size() > i){
                    l1.erase(l1.begin()+i);
                }else if(l2[i] == num && l2.size() > i){
                    l2.erase(l2.begin()+i);
                }else if(l3[i] == num && l3.size() > i){
                    l3.erase(l3.begin()+i);
                }else if(l4[i] == num && l4.size() > i){
                    l4.erase(l4.begin()+i);
                }else if(l5[i] == num && l5.size() > i){
                    l5.erase(l5.begin()+i);
                }

                if(c1[i] == num  && c1.size() > i){
                    c1.erase(c1.begin()+i);
                }else if(c2[i] == num  && c2.size() > i){
                    c2.erase(c2.begin()+i);
                }else if(c3[i] == num  && c3.size() > i){
                    c3.erase(c3.begin()+i);
                }else if(c4[i] == num  && c4.size() > i){
                    c4.erase(c4.begin()+i);
                }else if(c5[i] == num  && c5.size() > i){
                    c5.erase(c5.begin()+i);
                }

                if(d1[i] == num && d1.size() > i){
                    d1.erase(d1.begin()+i);
                }
                if(d2[i] == num && d2.size() > i){
                    d2.erase(d2.begin()+i);
                }
            }

            if(l1.empty() || l2.empty() || l3.empty() || l4.empty() || l5.empty() ||
                    c1.empty() || c2.empty() || c3.empty() || c4.empty() || c5.empty() || 
                    d1.empty() || d2.empty()){
                validate = true;
                value = j-1;
            }
        }

        cout << "BINGO after "<<value+1<<" numbers announced" << endl;
    }
}
