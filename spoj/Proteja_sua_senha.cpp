#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t, cont = 1;
    while(1){
        cin >> t;
        if(t == 0){
            break;
        }

        vector<vector<int> > num(t);
        vector<vector<int> > letter(t);

        for(int i = 0; i != t; i++){
            int n;
            char c;
            for(int j = 0; j != 10; j++){
                cin >> n;
                num[i].push_back(n);
            }

            for(int j = 0; j != 6; j++){
                cin >> c;
                if(c == 'A'){
                    letter[i].push_back(0);
                }else if(c == 'B'){
                    letter[i].push_back(2);
                }else if(c == 'C'){
                    letter[i].push_back(4);
                }else if(c == 'D'){
                    letter[i].push_back(6);
                }else{
                    letter[i].push_back(8);
                }
            }
        }
        
        printf("Teste %d\n", cont);
        for(int i = 0; i != 6; i++){
            int array[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            for(int j = 0; j != t; j++){
                array[num[j][letter[j][i]]]++;
                array[num[j][letter[j][i]+1]]++;
            }

            int mx = -1, index = -1;
            for(int j = 0; j != 10; j++){
                if(array[j] > mx){
                    mx = array[j];
                    index = j;
                }
            }

            if(i == 5){
                cout << index << endl;
                break;
            }
            cout << index << " ";
        }
        cont++;
        cout << endl;
    }
}
