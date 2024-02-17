#include <iostream>
#include <vector>

using namespace std;

struct Point{
    int x, y;
};

int validate(Point p1, Point p2, Point p3){
   return (p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y);     
}

int main(){
    vector<Point> q(4), l(4);
    for(int i = 0; i != 4; i++){
        int x, y;
        cin >> x >> y;
        q[i].x = x;
        q[i].y = y;
    }

    for(int i = 0; i != 4; i++){
        int x, y;
        cin >> x >> y;

        l[i].x = x;
        l[i].y = y;
    }

    bool val = false;
    for(int i = 0; i!= 4; i++){
        int v1 = validate(q[i], l[0], l[1]);
        int v2 = validate(q[i], l[1], l[2]);
        int v3 = validate(q[i], l[2], l[3]);
        int v4 = validate(q[i], l[3], l[0]);

        if((v1 <= 0 && v2 <= 0 && v3 <= 0 && v4 <= 0) || (v1 >= 0 && v2 >= 0 && v3 >= 0 && v4 >= 0)){
            val = true;
            break;
        }
    }
    
    for(int i = 0; i!= 4; i++){
        int v1 = validate(l[i], q[0], q[1]);
        int v2 = validate(l[i], q[1], q[2]);
        int v3 = validate(l[i], q[2], q[3]);
        int v4 = validate(l[i], q[3], q[0]);

        if((v1 <= 0 && v2 <= 0 && v3 <= 0 && v4 <= 0) || (v1 >= 0 && v2 >= 0 && v3 >= 0 && v4 >= 0)){
            val = true;
            break;
        }
    }

    if(validate(q[0], q[2], l[0]) * validate(q[0], q[2], l[2]) < 0 &&
            validate(l[0], l[2], q[0]) * validate(l[0], l[2], q[2]) < 0){
        val = true;
    }

    if(val){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
}
