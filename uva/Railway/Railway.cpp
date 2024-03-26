#include <iostream>
#include <vector>

using namespace std;
struct Point{
    double x, y;
};

Point sub(Point p1, Point p2){
    p2.x -= p1.x;
    p2.y -= p1.y;

    return p2;
}

double mult(Point p1, Point p2){
    return p1.x*p2.x + p1.y*p2.y;
}

double proj(Point v, Point u){
    return mult(v, u)/mult(v, v);
}

double dist(Point p1, Point p2){
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

double sentido(Point p1, Point p2, Point p3){
    return (p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y);
}

bool entre(Point p1, Point p2, Point p3){
    double mxX = max(p2.x, p3.x);
    double mnX = min(p2.x, p3.x);
    double mxY = max(p2.y, p3.y);
    double mnY = min(p2.y, p3.y);

    if(mnX <= p1.x && p1.x <= mxX && mnY <= p1.y && p1.y <= mxY){
        return false;
    }

    return true;
}

int main(){
    double xm, ym;
    while(cin >> xm >> ym){
        int n;
        cin >> n;
        Point last;
    
        vector<Point> save;
        for(int i = 0; i <= n; i++){
            Point p;
            cin >> p.x >> p.y;
            save.push_back(p);

            if(i == 0){
                last = p;
                continue;
            }

            if(sentido({xm, ym}, last, p) == 0 && entre({xm, ym}, last, p)){
                continue;
            }
           
            Point v = sub(last, p);    
            Point u = sub(last, {xm, ym});

            double k = proj(v, u);
            Point val = {v.x*k + last.x, v.y*k + last.y};
            if(!entre(val, last, p)){
                save.push_back(val);
            }
            last = p;
        }


        pair<Point, double> p = {{0,0}, 1e18};
        for(auto it : save){
            double d = dist({xm, ym}, it);
            if(p.second > d){
                p.second = d;
                p.first = it;
            }

        }

        printf("%.4f\n%.4f\n", p.first.x, p.first.y);

    }
}
