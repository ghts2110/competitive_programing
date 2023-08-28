#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string s;
    vector<double> v(5);
    bool validate = true;

    while(cin >> s){
        if(s == "-"){
            if(validate){
                break;
            }
            double sum = 0;
            for(int i = 0; i != 5; i++){
                sum += v[i];
            }
            double asw = (v[0]*100)/sum;
            if((int)(asw*10)%10 >= 5){
                asw++;
            }
            
            cout << int(asw)<<"%" << endl;
            for(int i= 0;i != 5; i++){
                v[i] = 0;
            }

            validate = true;
            continue;
        }   
        validate = false;

        double cont = 0;
        double p = 100;
        vector<pair<double, int>> por;

        if(s[s.size()-1] == 'C'){
            s.erase(s.end()-1);
            int num = stoi(s);
            v[0] += num;
            cont += num;
        }else if(s[s.size()-1] == 'g'){
            s.erase(s.end()-1);
            int num = stoi(s) * 9;
            v[0] += num;
            cont += num;
        }else{
            s.erase(s.end()-1);
            int num = stoi(s);
            p -= num;
            por.push_back(make_pair(num, 0));
        }

        for(int i = 0; i != 4; i++){
            cin >> s;
            if(i == 0){
                if(s[s.size()-1] == 'C'){
                    s.erase(s.end()-1);
                    int num = stoi(s);
                    v[1] += num;
                    cont += num;
                }else if(s[s.size()-1] == 'g'){
                    s.erase(s.end()-1);
                    int num = stoi(s) * 4;
                    v[1] += num;
                    cont += num;
                }else{
                    s.erase(s.end()-1);
                    int num = stoi(s);
                    p -= num;
                    por.push_back(make_pair(num, 1));
                }
            }else if(i == 1){
                if(s[s.size()-1] == 'C'){
                    s.erase(s.end()-1);
                    int num = stoi(s);
                    v[2] += num;
                    cont += num;
                }else if(s[s.size()-1] == 'g'){
                    s.erase(s.end()-1);
                    int num = stoi(s) * 4;
                    v[2] += num;
                    cont += num;
                }else{
                    s.erase(s.end()-1);
                    int num = stoi(s);
                    p -= num;
                    por.push_back(make_pair(num, 2));
                }               
            }else if(i == 2){
                if(s[s.size()-1] == 'C'){
                    s.erase(s.end()-1);
                    int num = stoi(s);
                    v[3] += num;
                    cont += num;
                }else if(s[s.size()-1] == 'g'){
                    s.erase(s.end()-1);
                    int num = stoi(s) * 4;
                    v[3] += num;
                    cont += num;
                }else{
                    s.erase(s.end()-1);
                    int num = stoi(s);
                    p -= num;
                    por.push_back(make_pair(num, 3));
                }              
            }else{
                if(s[s.size()-1] == 'C'){
                    s.erase(s.end()-1);
                    int num = stoi(s);
                    v[4] += num;
                    cont += num;
                }else if(s[s.size()-1] == 'g'){
                    s.erase(s.end()-1);
                    int num = stoi(s) * 7;
                    v[4] += num;
                    cont += num;
                }else{
                    s.erase(s.end()-1);
                    int num = stoi(s);
                    p -= num;
                    por.push_back(make_pair(num, 4));
                }
            }
        }

        for(int i = 0; i != por.size(); i++){
            v[por[i].second] += (cont*por[i].first)/p;
        }
    }

}
