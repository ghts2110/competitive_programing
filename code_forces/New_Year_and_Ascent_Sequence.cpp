#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    long long cont = 0;
    vector<int> mn, mx;;
    cin >> n;

    for(int j = 0; j != n; j++){
        int l, num;

        cin >> l;
        int array[l];

        cin >> array[0];
        int validate = 0;

        for(int i = 1; i != l; i++){
            cin >> array[i];

            if(array[i] > array[i-1]){
                validate = 1;
            }
        }

        if(validate == 1){
            cont += n + (n-1);
            n--;
            j--;
        }else{
            mx.push_back(array[0]);
            mn.push_back(array[l-1]);
        }
    }

    sort(mx.begin(), mx.end());
    
    for(int j = 0; j != mn.size(); j++){
        cont += mn.size() - (upper_bound (mx.begin(), mx.end(), mn[j]) - mx.begin());    
    }

    cout << cont << endl;

}
