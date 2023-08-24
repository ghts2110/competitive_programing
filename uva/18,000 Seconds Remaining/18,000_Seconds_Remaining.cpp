#include <iostream>

using namespace std;

int main(){
    int t, test = 1;
    while(cin >> t){
        if(t==0){
            break;
        }
        
        cout << "Output for data set "<<test<<", "<<t<<" bytes:" << endl;
        test++;

        int last5 = 0;
        int time = 0;
        while(t){
            time++;
            int n;
            cin >> n;
            t -= n;
            last5 += n;

            if(last5 == 0 && time % 5 == 0){
                cout << "   Time remaining: stalled" << endl;
            }else if(time % 5 == 0){
                int r = (t*5)/last5;
                if((t*5)%last5 != 0){
                    r++;
                }
                last5 = 0;
                cout << "   Time remaining: "<<r<<" seconds" << endl;
            }
        }

        cout << "Total time: "<<time<<" seconds" << endl;
        cout << endl;
    }
}
