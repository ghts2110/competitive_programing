#include <iostream>
#include <cmath>

using namespace std;

double dist(double x, double y){
    return sqrt(x*x + y*y);
}

int main(){
    int n;
    bool f = true;
    while(cin >> n){
        if(!f){
            cout << endl;
        }
        f = false;
        
        int in=0, out = 8*(n-1) + 4;

        int x = 1, y = 1;
        double r =  n-0.5;
        while(x < n){
            double d1 = dist(x, y);
            double d2 = dist(x-1, y);
            double d3 = dist(x, y-1);
            
            if(d1 <= r && d2 <= r && d3 <= r){ 
                in++;
                y++;
            }else{
                y = 1;
                x++;
            }
        }

        in *= 4;
        cout << "In the case n = "<<n<<", "<<out<<" cells contain segments of the circle." << endl;
        cout << "There are "<<in<<" cells completely contained in the circle." << endl;
    }
}
