#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n;
    cin >> n;
    while(n--){
        int t;
        cin >> t;
        
        vector<int>vagoes(t);
        for(int i = 0; i < t; i++){
            cin >> vagoes[i];
        }
        
        int cont = 0;
        for(int i = 0; i < t; i++){
            for(int j = i + 1; j < t; j++){
                if(vagoes[i] > vagoes[j]){
                    cont++;
                    int temp = vagoes[i];
                    vagoes[i] = vagoes[j];
                    vagoes[j] = temp;
                }
            }
        }
        
        printf("Optimal train swapping takes %d swaps.\n", cont);
    }
}

