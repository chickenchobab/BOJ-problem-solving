#include <iostream>

using namespace std;

int num;

int main(){

    int m = 0;

    char ch;
    int tmp = 0;

    while (1){
        ch = cin.get();

        if (!isdigit(ch)) {
            m ? num += (tmp * (-1)) : num += tmp; 
            tmp = 0;
        }
        else{
            tmp = tmp * 10 + (ch - '0');
        }

        if (ch == '-') m = 1;
        if (ch == '\n') break;
    }

    cout << num;


}