#include <iostream>
#include <vector>

using namespace std;

int rax;
char edx;
vector<char> st;

int main(){

    rax=0;
    string str1= "maduiersnfotvbylSo you think you can stop the bomb with ctrl-c, do you?";
    string str2= "oilers";
    string rbx= "jdoefg";
    for(rax=0; rax<6; rax++){
        edx=rbx[rax];
    edx=edx & 0xf;
    edx=str1[edx];
    st.push_back(edx);
    }
    for(char ch:st){
        cout<<ch;
    }

    


}