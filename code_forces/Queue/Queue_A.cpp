#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> k;
    vector<vector<int> > f(n);
    vector<int> change_f(5);

    int array[] = {1, 5, 10, 20, 50};

    for(int i = 0; i != n; i++){
        int num;
        cin >> num;

        k.push_back(num);
        for(int j = 0; j != 5; j++){
            cin >> num;
            f[i].push_back(num);
        }
    }

    int validate = 1, change = 0;
    for(int i = 0; i != n; i++){
        int sum = 0;
        for(int j = 0; j != 5; j++){
            sum += f[i][j] * array[j];
            change_f[j] += f[i][j];
        }   
        change = sum - k[i];

        for(int j = 0; j != 5; j++){
            if(change == 0){
                break;
            }

            int notes_f = change / array[j];
        
            change -= min(notes_f, change_f[j]) * array[j];
            change_f[j] -= min(notes_f, change_f[j]);
        }
        
        if(change > 0){
            validate = 0;
        }
    }


    if(validate == 0){
        cout << "no" << endl;
    }else{
        cout << "yes" << endl;
    }
}
