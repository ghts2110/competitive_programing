#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double base, num;

    while(cin >> base >> num){
        printf("%.0lf\n", pow(num, 1.0/base));
    }
}
