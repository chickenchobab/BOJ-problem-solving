#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

int esi, ecx, eax, edx, ebx;
int ebp, flag, cnt;

struct Node {
	int value;
	int index;
	struct Node* next;
};





int main(){
    

vector<int> oldrsp{1,2,3,4,5,6};



    do{

        int A[6];
Node* B[6];
Node* C[6];

    for(auto it=oldrsp.begin(); it!=oldrsp.end(); it++){
        
    }

    for (int i = 0; i < 6; ++i) C[i] = (Node*)malloc(sizeof(Node));
    *C[5] = {0x36, 6, 0};
    *C[4] = {0xf8, 5, C[6]};
    *C[3] = {0x1d2, 4, C[5]};
    *C[2] = {0x166, 3, C[4]};
    *C[1] = {0x247, 2, C[3]};
    *C[0] = {0x20f, 1, C[2]};


        if(flag==0){
            cout<<"suc"<<endl;
            for(int i=0;i<6;i++){
            cout<<7-A[i]<<' ';
            }
            cout<<'\n';
        }
        
        esi=ecx=eax=edx=ebx=ebp=flag=0;
        
        
    }while(next_permutation(oldrsp.begin(), oldrsp.end()));
    
}
