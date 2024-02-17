#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n;

struct Point{
    ll x, y;
};
Point a, b, c;

ll sentido(Point p1, Point p2, Point p3){
    return (p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y);
}

bool validate1(vector<Point> &v){
    if(v.size() < 3){
        return true;
    }

    for(int i = 0; i != v.size(); i++){
        if(sentido(v[0], v[1], v[i]) != 0){
            return false;
        }
    }
    return true;
}

bool validate2(Point no1, Point no2, vector<Point> &v){
    if(v.size() < 3){
        return true;
    }

    vector<Point> save;
    for(int i = 0; i != n; i++){
        if(sentido(no1, no2, v[i]) != 0){
            save.push_back(v[i]);
        }
    }

    if(no2.x == b.x && no2.y == b.y && save.size() != 0){
        c = save[0];
    }

    return validate1(save);
}

int main(){
    cin >> n;

    vector<Point> v(n);
    for(int i = 0; i != n; i++){
        int x, y;
        cin >> x >> y;

        v[i].x = x;
        v[i].y = y;
    }
    a = v[0];
    b = v[1];

    bool val = validate2(a, b, v);
    if(val){
        cout << "YES" << endl;
        return 0;
    }

    val = val||validate2(a, c, v);
    if(val){
        cout << "YES" << endl;
        return 0;
    }   
    
    val = val||validate2(b, c, v);
    if(val){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
