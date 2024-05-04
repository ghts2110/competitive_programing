#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        cout << "TERM "<<n<<" IS ";
        int l = 1, r = 1;
        while(n != 1){
            if(l == 1){
                r++;
                n--;
                while(r != 1 && n != 1){
                    r--;
                    l++;
                    n--;
                }
            }else{
                l++;
                n--;
                while(l != 1 & n != 1){
                    l--;
                    r++;
                    n--;
                }
            }
        }

        cout << l << "/" << r << endl;
    }
}
