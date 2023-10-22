#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int esi, ecx, eax, edx, ebx;
int ebp, flag, cnt;

int main(){

vector<int> oldrsp{1,2,3,4,5,6};

    do{
        int rsp[100];
        int arr[24]={
        0x020f, 0x01, 
        (int)&arr[4], 0x00, 
        0x0247, 0x02, 
        (int)&arr[8], 0x00, 
        0x0166, 0x03, 
        (int)&arr[12], 0x00, 
        0x01d2, 0x04, 
        (int)&arr[16], 0x00,
        0xf8, 0x05, 
        (int)&arr[20], 0x00,
        0x36, 0x06, 
        0x00, 0x00
        };
        int idx=0;
        for(auto it = oldrsp.begin(); it!=oldrsp.end(); ++it){
            rsp[idx++]=*it;
        }
        for(int i=0;i<6;i++){
            rsp[i]=7-rsp[i];
        }
        // for(int i=0;i<6;i++){
        //     cout<<rsp[i]<<' ';
        // }
        // cout<<"\ncal\n";
        
        do{
            ecx=*(int*)((int)rsp+esi);          //173
            eax=1;
            edx = (int)arr;
            // cout<<*((int*)edx+4)<<'\n';
            // cout<<*(int*)(edx+16)<<'\n';
         
            if(ecx>1){
                do{                            //147
                    edx=*(int*)(edx+8);
                    eax++;
                }while(eax!=ecx);              //156
            }
            *(int*)((int)rsp+2*esi+32)=edx;   //158
            esi+=4;
        }while(esi!=24);  
        //cout<<"1\n";

        ebx=*(int*)((int)rsp+32);   //193

        eax=(int)rsp+32;
        esi=(int)rsp+72;
        ecx=ebx;                    //208
        do{
            edx=*(int*)(eax+8);      //211 
            *(int*)(ecx+8)=edx;
            eax+=8;
            ecx=edx;
        }while(esi!=eax);
        //cout<<"2\n";
            

        *(int*)(edx+8)=0;
        ebp=5;
        do{
            eax=*(int*)(ebx+8);
            eax=*(int*)eax;
            if(*(int*)ebx<eax) {flag=1; break;}
            else{
            ebx=*(int*)(ebx+8);
            ebp--;
            }
        }while(ebp!=1);
        //cout<<"3\n";


        if(flag==0){
            cout<<"suc"<<endl;
            for(int i=0;i<6;i++){
            cout<<7-rsp[i]<<' ';
            }
            cout<<'\n';
        }
        
        esi=ecx=eax=edx=ebx=ebp=flag=0;
        
        
    }while(next_permutation(oldrsp.begin(), oldrsp.end()));
    
}
