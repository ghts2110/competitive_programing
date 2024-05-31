#include <iostream>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n==0){
            break;
        }

        int sum = 0, mx = 0;
        for(int i = 0; i != n; i++){
            int num;
            cin >> num;

            sum += num;
            mx = max(mx, sum);
            if(sum < 0){
                sum = 0;
            }
        }

        if(mx > 0){
            cout << "The maximum winning streak is "<<mx<<"."<<endl;
        }else{
            cout << "Losing streak." << endl;
        }
    }
}
