#include <iostream>
#include <string>

using namespace std;

int main(){
    string n1, n2;
    while(getline(cin, n1)){
        getline(cin, n2);
        int contn1 = 0, contn2= 0;
        
        for(int i = 0; i != n1.size(); i++){    
            if(n1[i] >= 'a' && n1[i] <= 'z'){
                contn1 += n1[i] - 'a' + 1;
            }else if(n1[i] >= 'A' && n1[i] <= 'Z'){
                contn1 += n1[i] - 'A' + 1;
            }
        }
        int save = 0;
        while(contn1 >= 10){
            save += contn1 % 10;
            contn1 /= 10;

            if(contn1 < 10){
                contn1 += save;
                save = 0;
            }
        }

        for(int i= 0; i != n2.size(); i++){
            if(n2[i] >= 'a' && n2[i] <= 'z'){
                contn2 += n2[i] - 'a' + 1;
            }else if(n2[i] >= 'A' && n2[i] <= 'Z'){
                contn2 += n2[i] - 'A' + 1;
            }
        }
        
        save = 0;
        while(contn2 >= 10){
            save += contn2 % 10;
            contn2 /= 10;

            if(contn2 < 10){
                contn2 += save;
                save = 0;
            }
        }
       
        printf("%.2f ", (min(contn1, contn2)*100.0) / max(contn1, contn2));
        cout << "%" << endl;
    }
}
