#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;
int r,n;
struct frame{
    char ack;
    int data;
}frm[10];
int sender(void);
void revack(void);
void resend_sr(void);
void resend_gb(void);
void goback(void);
void selective(void);

int main()
{
    int c;
    do{
        cout<<"\n\n1. selective repeat\n\n2.goback arq"<<endl;
        cout<<"enter your choice: "<<endl;
        cin>>c;
        switch(c){
            case 1:selective();
               break;
            case 2: goback();
              break;
            case 3: exit(0);
              break;
        }
    }while(c>=4);
    return 0;
}
void goback(void){
    sender();
    revack();
    resend_gb();
    cout<<"All frame sent sucessful"<<endl;
} 
void selective(){
    sender();
    revack();
    resend_sr();
    cout<<"All frame sent sucessful"<<endl;
} 
int sender(){
    int i;
    cout<<"enter the number of frames sent: "<<endl;
    cin>>n;
    for(i=0;i<n;i++){
        cout<<"enter the data for frame"<<i<<":-" ;
        cin>>frm[i ]. data;
        frm[i ].ack='Y';
}
return 0;
    }
void revack(){
    int i;
    rand();
    r=rand()%n;
    
    frm[r].ack='n';
    for(i=1;i<=n;i++){
        if(frm[r].ack=='n'){
            cout<<"The frame number "<<r<<" is not recieved"<<endl;
            break;
        }
    }
}
void resend_sr(){
    cout<<"resending frame"<<r<<endl;
    sleep(2);
    frm[r].ack='Y';
    cout<<"The recieved frame is "<<frm[r].data<<endl;
}
void resend_gb(){
    int i;
    cout<<"resending frame"<<r<<endl;
    for(i=r;i<n;i++){
    sleep(2);
    frm[r].ack='Y';
    cout<<"The recieved frame is "<<i<<frm[i].data<<endl;
    }
}
