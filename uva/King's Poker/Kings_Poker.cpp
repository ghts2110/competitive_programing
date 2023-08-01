#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int v[3];
    while(cin >> v[0] >> v[1] >> v[2]){
        if(v[0] == 0){
            break;
        }

        if(v[0] == v[1] && v[0] == v[2]){
            if(v[0] == 13){
                cout << "*" << endl;
                continue;
            }

            cout << v[0] +1 << " " << v[0] + 1 << " " << v[0] + 1 << endl;
            continue;
        }

        if(v[0] != v[1] && v[0] != v[2] && v[1] != v[2]){
            cout << "1 1 2" << endl;
            continue;
        }


        if(v[0] == v[1]){
            if(v[2] != 13){
                v[2] ++;
                if(v[2] == v[1]){
                    v[2]++;
                    if(v[2] == 14){ 
                        v[0] = v[1] = v[2] =1;
                    }

                }
            }else{
                v[0]++, v[1]++, v[2] = 1;
            }
        }else if(v[0] == v[2]){
            if(v[1] != 13){
                v[1] ++;
                if(v[1] == v[0]){
                    v[1]++;
                    if(v[1] == 14){
                        v[0] = v[1] = v[2] =1;
                    }
                }
            }else{
                v[0]++, v[1] = 1, v[2]++;
            }
        }else{
            if(v[0] != 13){
                v[0] ++;
                if(v[0] == v[1]){
                    v[0]++;
                }
                if(v[0] == 14){
                    v[0] = v[1] = v[2] =1;
                }
            }else{
                v[0]=1, v[1]++, v[2]++;
            }
        }

        sort(v, v+3);
        cout << v[0] << " " << v[1] << " " << v[2] << endl;
    }
}
