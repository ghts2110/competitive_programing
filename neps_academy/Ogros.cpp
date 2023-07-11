#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> faixa, premio, forca;

    for(int i = 0; i != n-1; i++){
        int num;
        cin >> num; 
        faixa.push_back(num);
    }

    for(int i = 0; i != n; i++){
        int num; 
        cin >> num;
        premio.push_back(num);
    }

    for(int i = 0; i != m; i++){
        int num;
        cin >> num;

        for(int j = 0; j != faixa.size(); j++){
            if(faixa[j] > num){
                cout << premio[j] << " ";
                break;
            }

            if(j == faixa.size() - 1){
                cout << premio[j+1] << " ";
            }
        }
    }

    cout << endl;
}
