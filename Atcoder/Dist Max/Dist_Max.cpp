#include <iostream>

using namespace std;
typedef long long ll;

struct Point{
    ll x, y;
};

ll dist(Point p1, Point p2){
    return abs(p1.x-p2.x) + abs(p1.y-p2.y);
}

int main(){
    int n;
    cin >> n;

    Point p1 = {1000000000, 1000000000}, p2 = {1000000000, 0};
    Point p3 = {0, 0}, p4 = {0, 1000000000};

    for(int i = 0; i != n; i++){
        ll x, y;
        cin >> x >> y;

        if(dist(p1, Point{0, 0}) > dist(Point{x, y}, Point{0, 0})){
            p1 = {x, y};
        }

        if(dist(p2, Point{0, 1000000000}) > dist(Point{x, y}, Point{0, 1000000000})){
            p2 = {x, y};
        }

        if(dist(p3, Point{1000000000, 1000000000}) > 
                dist(Point{x, y}, Point{1000000000, 1000000000})){
            p3 = {x, y};
        }

        if(dist(p4, Point{1000000000, 0}) > dist(Point{x, y}, Point{1000000000, 0})){
            p4 = {x, y};
        }
    }

    ll asw = max(dist(p1, p2), max(dist(p1, p3), dist(p1, p4)));
    asw = max(asw, max(dist(p2, p3), dist(p2, p4)));
    asw = max(asw, dist(p3, p4));

    cout << asw << endl;
}
