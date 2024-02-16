#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point{
    int x, y;
};

int dist(Point p1, Point p2){
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}

bool validate1(Point p1, Point p2, Point p3, Point p4){
    int d1 = dist(p1, p2);
    int d2 = dist(p2, p3);
    int d3 = dist(p3, p4);
    int d4 = dist(p4, p1);

    if(d1 == d2 && d2 == d3 && d3 == d4){
      int d5 = dist(p1, p3);
      int d6 = dist(p2, p4);

      return d5 == d6;
    }
    
    return false;
}

bool validate2(Point p1, Point p2, Point p3, Point p4){
    int d1 = dist(p1, p2);
    int d2 = dist(p2, p3);
    int d3 = dist(p3, p4);
    int d4 = dist(p4, p1);

    if(d1 != d3 || d2 != d4){
       return false;
    }

    int d5 = dist(p1, p3);
    int d6 = dist(p2, p4);
    if(d1+d2 != d5 || d2+d3 != d6 || d3+d4 != d5 || d4+d1 != d6){
       return false;
    }

    return true;
}

int main(){
    vector<pair<int, pair<int, int> > > v(8);
    for(int i = 0; i != 8; i++){
        int x, y;
        cin >> x >> y;
        v[i].second.first= x;
        v[i].second.second = y;
        v[i].first = i+1;
    }

    bool val = true;
    do{
        Point p1 = {v[0].second.first, v[0].second.second};
        Point p2 = {v[1].second.first, v[1].second.second};
        Point p3 = {v[2].second.first, v[2].second.second};
        Point p4 = {v[3].second.first, v[3].second.second};
        val = validate1(p1, p2, p3, p4);


        if(val){
            Point p5 = {v[4].second.first, v[4].second.second};
            Point p6 = {v[5].second.first, v[5].second.second};
            Point p7 = {v[6].second.first, v[6].second.second};
            Point p8 = {v[7].second.first, v[7].second.second};
            if(validate1(p5, p6, p7, p8) || validate2(p5, p6, p7, p8)){
                cout << "YES" << endl;
                printf("%d %d %d %d\n", v[0].first, v[1].first, v[2].first, v[3].first);
                printf("%d %d %d %d\n", v[4].first, v[5].first, v[6].first, v[7].first);
                break;
            }

            val = false;
        }
    }while(next_permutation(v.begin(), v.end()));

    if(!val){
        printf("NO\n");
    }
}
