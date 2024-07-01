#include <iostream>

using namespace std;

struct Point{
    double x, y;
}; 

int h(Point p1, Point p2, Point p3){
    return (p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y);
}

bool validate(Point p1, Point p2, Point p3){
    bool b1 = false, b2 = false;
    if(p1.x <= p2.x && p1.x >= p3.x){
        b1 = true;
    }
    if(p1.x <= p3.x && p1.x >= p2.x){
        b1 = true;
    }
    if(p1.y <= p2.y && p1.y >= p3.y){
        b2 = true;
    }
    if(p1.y <= p3.y && p1.y >= p2.y){
        b2 = true;
    }

    if(b1 && b2){
        return true;
    }

    if(b1 && (p1.y == p2.y || p1.y == p3.y)){
        return true;
    }

    if(b2 && (p1.x == p2.x || p1.x == p3.x)){
        return true;
    }
    return false;
}

bool l(Point p1, Point p2, Point p3){
    int mxx = max(p1.x, p2.x);
    int mxy = max(p1.y, p2.y);
    int mnx = min(p1.x, p2.x);
    int mny = min(p1.y, p2.y);

    if(mnx <= p3.x && p3.x <= mxx && mny <= p3.y && p3.y <= mxy){
        return true;
    }

    return false;
}

int main(){
    int n;
    cin >> n;

    while(n--){
        Point p1, p2;
        cin >> p1.x >> p1.y >> p2.x >> p2.y;

        double x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        Point a = {x1, y1};
        Point b = {x1, y2};
        Point c = {x2, y1};
        Point d = {x2, y2};
       
        bool val = false;
        
        if(h(p1, p2, a) * h(p1, p2, b) < 0 && h(a, b, p1) * h(a, b, p2) < 0){
            val = true;
        }
        if(h(p1, p2, a) * h(p1, p2, c) < 0 && h(a, c, p1) * h(a, c, p2) < 0){
            val = true;
        }
        if(h(p1, p2, d) * h(p1, p2, b) < 0 && h(d, b, p1) * h(d, b, p2) < 0){
            val = true;
        }
        if(h(p1, p2, d) * h(p1, p2, c) < 0 && h(d, c, p1) * h(d, c, p2) < 0){
            val = true;
        }
        if(validate(p1, a, d) && validate(p2, a, d)){
            val = true;
        }

        if(h(p1, p2, a) == 0 && l(p1, p2, a)){
            val = true;
        }

        if(h(p1, p2, b) == 0 && l(p1, p2, b)){
            val = true;
        }
        if(h(p1, p2, c) == 0 && l(p1, p2, c)){
            val = true;
        }
        if(h(p1, p2, d) == 0 && l(p1, p2, d)){
            val = true;
        }

        if(val){
            cout << "T" << endl;
        }else{
            cout << "F" << endl;
        }

    }
}
