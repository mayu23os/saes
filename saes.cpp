#include<iostream>
#define N 16
using namespace std;
int key[N],pt[N],en[N],de[N];
int key1[N],key2[N]; 
int M[][2]={1,4,
            1,4};
int IM[][2]={9,2,
            2,9};
int w2xor[]={1,0,0,0,0,0,0,0};
int w4xor[]={0,0,1,1,0,0,0,0};
void half(int org[],int* wo,int* w1,int len)//len -- length to be divided in
{ 
    for(int i=0;i<len;i++)
    {
        wo[i]=org[i];
        w1[i]=org[i+len];
    }
}
void sub(int a[N])
{
    if(a[0]==0 && a[1]==0 && a[2]==0 && a[3]==0)
    {
        a[0]=1;
        a[1]=0;
        a[2]=0;
        a[3]=1;
    }
    else if(a[0]==0 && a[1]==0 && a[2]==0 && a[3]==1)
    {
        a[0]=0;
        a[1]=1;
        a[2]=0;
        a[3]=0;
    }
    else if(a[0]==0 && a[1]==0 && a[2]==1 && a[3]==0)
    {
        a[0]=1;
        a[1]=0;
        a[2]=1;
        a[3]=0;
    }
    else if(a[0]==0 && a[1]==0 && a[2]==1 && a[3]==1)
    {
        a[0]=1;
        a[1]=0;
        a[2]=1;
        a[3]=1;
    }
    else if(a[0]==0 && a[1]==1 && a[2]==0 && a[3]==0)
    {
        a[0]=1;
        a[1]=1;
        a[2]=0;
        a[3]=1;
    }
    else if(a[0]==0 && a[1]==1 && a[2]==0 && a[3]==1)
    {
        a[0]=0;
        a[1]=0;
        a[2]=0;
        a[3]=1;
    }
    else if(a[0]==0 && a[1]==1 && a[2]==1 && a[3]==1)
    {
        a[0]=0;
        a[1]=1;
        a[2]=0;
        a[3]=1;
    }
    else if(a[0]==0 && a[1]==1 && a[2]==1 && a[3]==0)
    {
        a[0]=1;
        a[1]=0;
        a[2]=0;
        a[3]=0;
    }
    else if(a[0]==1 && a[1]==0 && a[2]==0 && a[3]==0)
    {
        a[0]=0;
        a[1]=1;
        a[2]=1;
        a[3]=0;
    }
    else if(a[0]==1 && a[1]==0 && a[2]==0 && a[3]==1)
    {
        a[0]=0;
        a[1]=0;
        a[2]=1;
        a[3]=0;
    }
    else if(a[0]==1 && a[1]==0 && a[2]==1 && a[3]==0)
    {
        a[0]=0;
        a[1]=0;
        a[2]=0;
        a[3]=0;
    }
    else if(a[0]==1 && a[1]==0 && a[2]==1 && a[3]==1)
    {
        a[0]=0;
        a[1]=0;
        a[2]=1;
        a[3]=1;
    }
    else if(a[0]==1 && a[1]==1 && a[2]==0 && a[3]==0)
    {
        a[0]=1;
        a[1]=1;
        a[2]=0;
        a[3]=0;
    }
    else if(a[0]==1 && a[1]==1 && a[2]==0 && a[3]==1)
    {
        a[0]=1;
        a[1]=1;
        a[2]=1;
        a[3]=0;
    }
    else if(a[0]==1 && a[1]==1 && a[2]==1 && a[3]==0)
    {
        a[0]=1;
        a[1]=1;
        a[2]=1;
        a[3]=1;
    }
    else if(a[0]==0 && a[1]==1 && a[2]==0 && a[3]==1)
    {
        a[0]=0;
        a[1]=0;
        a[2]=0;
        a[3]=1;
    }
     else if(a[0]==1 && a[1]==1 && a[2]==1 && a[3]==1)
    {
        a[0]=0;
        a[1]=1;
        a[2]=1;
        a[3]=1;
    }
}
void rotate_nib(int *org,int *res)
{
    int temp;
    for(int i=0;i<4;i++)
    {
        res[i]=org[i+4];
        res[i+4]=org[i];
    }
}
void merge(int *a1,int *a2,int *b,int len=8)
{
    for(int i=0;i<len;i++)
    {
        b[i]=a1[i];
        b[i+len]=a2[i];
    }    
}
void subroutine(int *org,int *subb)
{
    int sub1[4],sub2[4],w[N];
    rotate_nib(org,w);
    half(w,sub1,sub2,4);
    sub(sub1);
    sub(sub2);
    merge(sub1,sub2,subb,4);
}
void exor(int *a,int *b,int *res,int len=8)
{
    for(int i=0;i<len;i++)
    {
        res[i]=a[i]^b[i];
    }
}
void printarr(int *a,int len)
{
    for(int i=0;i<len;i++)
    {
       cout<<a[i]<<" ";
    }
}
void genkey()
{
     cout<<"\n==================/ KEY GENERATION /=====================\n";
    int wo[N/2],w1[N/2],w2[N/2],w3[N/2],w4[N/2],w5[N/2];
    int sub1[4],sub2[4],subb[N/2],ex[N/2];
    half(key,wo,w1,8);
    cout<<"\nwo\t";
    printarr(wo,8);
    cout<<"\nw1\t";
    printarr(w1,8);
    subroutine(w1,subb); // subnib(rotnib());
    exor(wo,w2xor,ex);
    exor(ex,subb,w2);
    cout<<"\nw2\t"; //-------------------------w2
    printarr(w2,8);
    exor(w2,w1,w3);
    cout<<"\nw3\t"; //-------------------------w3
    printarr(w3,8);
    subroutine(w3,subb);
    exor(w2,w4xor,ex);
    exor(ex,subb,w4);
    cout<<"\nw4\t";//-----------------------w4
    printarr(w4,8);
    exor(w4,w3,w5);
    cout<<"\nw5\t";//-----------------------w5
    printarr(w5,8);
    merge(w2,w3,key1);
    merge(w4,w5,key2);
    cout<<"\nkey1\t";
    printarr(key1,N);
    cout<<"\nkey2\t";
    printarr(key2,N);
}
void swap(int *a,int *b,int len=4)
{
    int temp;
    for(int i=0;i<len;i++)
    {
        temp=a[i];
        a[i]=b[i];
        b[i]=temp;
    }
}
void multiply_4(int *a,int *res)
{
    if(a[0]==0 && a[1]==0 && a[2]==0 && a[3]==0)//0
    {
        res[0]=0;
        res[1]=0;
        res[2]=0;
        res[3]=0;
    }
    else if(a[0]==0 && a[1]==0 && a[2]==0 && a[3]==1)  // 1
    {
        res[0]=0;
        res[1]=1;
        res[2]=0;
        res[3]=0;
    }
    else if(a[0]==0 && a[1]==0 && a[2]==1 && a[3]==0)  // 2
    {
        res[0]=1;
        res[1]=0;
        res[2]=0;
        res[3]=0;
    }
    else if(a[0]==0 && a[1]==0 && a[2]==1 && a[3]==1)  // 3
    {
        res[0]=1;
        res[1]=1;
        res[2]=0;
        res[3]=0;
    }
    else if(a[0]==0 && a[1]==1 && a[2]==0 && a[3]==0)  // 4
    {
        res[0]=0;
        res[1]=0;
        res[2]=1;
        res[3]=1;
    }
    else if(a[0]==0 && a[1]==1 && a[2]==0 && a[3]==1)  // 5
    {
        res[0]=0;
        res[1]=1;
        res[2]=1;
        res[3]=1;
    }
    else if(a[0]==0 && a[1]==1 && a[2]==1 && a[3]==0)  // 6
    {
        res[0]=1;
        res[1]=0;
        res[2]=1;
        res[3]=1;
    }
    else if(a[0]==0 && a[1]==1 && a[2]==1 && a[3]==1)  // 7
    {
        res[0]=1;
        res[1]=1;
        res[2]=1;
        res[3]=1;
    }
    else if(a[0]==1 && a[1]==0 && a[2]==0 && a[3]==0)  //8--
    {
        res[0]=0;
        res[1]=1;
        res[2]=1;
        res[3]=0;
    }
    else if(a[0]==1 && a[1]==0 && a[2]==0 && a[3]==1)  //9
    {
        res[0]=0;
        res[1]=0;
        res[2]=1;
        res[3]=0;
    }
    else if(a[0]==1 && a[1]==0 && a[2]==1 && a[3]==0)  //10
    {
        res[0]=1;
        res[1]=1;
        res[2]=1;
        res[3]=0;
    }
    else if(a[0]==1 && a[1]==0 && a[2]==1 && a[3]==1)  //11
    {
        res[0]=1;
        res[1]=0;
        res[2]=1;
        res[3]=0;
    }
     else if(a[0]==1 && a[1]==1 && a[2]==0 && a[3]==0)  //12
    {
        res[0]=0;
        res[1]=1;
        res[2]=0;
        res[3]=1;
    }
    else if(a[0]==1 && a[1]==1 && a[2]==0 && a[3]==1)  //13
    {
        res[0]=0;
        res[1]=0;
        res[2]=0;
        res[3]=1;
    }
    else if(a[0]==1 && a[1]==1 && a[2]==1 && a[3]==0)  //14
    {
        res[0]=1;
        res[1]=1;
        res[2]=0;
        res[3]=1;
    }
    else if(a[0]==1 && a[1]==1 && a[2]==1 && a[3]==1)  //15
    {
        res[0]=1;
        res[1]=0;
        res[2]=0;
        res[3]=1;
    }
}
void multiply_9(int *a,int *res)
{
    if(a[0]==0 && a[1]==0 && a[2]==0 && a[3]==0)//0
    {
        res[0]=0;
        res[1]=0;
        res[2]=0;
        res[3]=0;
    }
    else if(a[0]==0 && a[1]==0 && a[2]==0 && a[3]==1)  // 1
    {
        res[0]=1;
        res[1]=0;
        res[2]=0;
        res[3]=1;
    }
    else if(a[0]==0 && a[1]==0 && a[2]==1 && a[3]==0)  // 2
    {
        res[0]=0;
        res[1]=0;
        res[2]=0;
        res[3]=1;
    }
    else if(a[0]==0 && a[1]==0 && a[2]==1 && a[3]==1)  // 3
    {
        res[0]=1;
        res[1]=0;
        res[2]=0;
        res[3]=0;
    }
    else if(a[0]==0 && a[1]==1 && a[2]==0 && a[3]==0)  // 4
    {
        res[0]=0;
        res[1]=0;
        res[2]=1;
        res[3]=0;
    }
     else if(a[0]==0 && a[1]==1 && a[2]==0 && a[3]==1)  // 5
    {
        res[0]=1;
        res[1]=0;
        res[2]=1;
        res[3]=1;
    }
    else if(a[0]==0 && a[1]==1 && a[2]==1 && a[3]==0)  // 6
    {
        res[0]=0;
        res[1]=0;
        res[2]=1;
        res[3]=1;
    }
    else if(a[0]==0 && a[1]==1 && a[2]==1 && a[3]==1)  // 7
    {
        res[0]=1;
        res[1]=0;
        res[2]=1;
        res[3]=0;
    }
    else if(a[0]==1 && a[1]==0 && a[2]==0 && a[3]==0)  //8
    {
        res[0]=0;
        res[1]=1;
        res[2]=0;
        res[3]=0;
    }
    else if(a[0]==1 && a[1]==0 && a[2]==0 && a[3]==1)  //9----
    {
        res[0]=1;
        res[1]=1;
        res[2]=1;
        res[3]=0;
    }
    else if(a[0]==1 && a[1]==0 && a[2]==1 && a[3]==0)  //10
    {
        res[0]=0;
        res[1]=1;
        res[2]=0;
        res[3]=1;
    }
    else if(a[0]==1 && a[1]==0 && a[2]==1 && a[3]==1)  //11----
    {
        res[0]=1;
        res[1]=0;
        res[2]=0;
        res[3]=1;
    }
     else if(a[0]==1 && a[1]==1 && a[2]==0 && a[3]==0)  //12
    {
        res[0]=0;
        res[1]=1;
        res[2]=1;
        res[3]=0;
    }
    else if(a[0]==1 && a[1]==1 && a[2]==0 && a[3]==1)  //13----
    {
        res[0]=1;
        res[1]=1;
        res[2]=0;
        res[3]=0;
    }
    else if(a[0]==1 && a[1]==1 && a[2]==1 && a[3]==0)  //14
    {
        res[0]=0;
        res[1]=1;
        res[2]=1;
        res[3]=1;
    }
    else if(a[0]==1 && a[1]==1 && a[2]==1 && a[3]==1)  // F
    {
        res[0]=1;
        res[1]=1;
        res[2]=1;
        res[3]=0;
    }
     
}
void multiply_2(int *a,int *res)
{
    if(a[0]==0 && a[1]==0 && a[2]==0 && a[3]==0)//0
    {
        res[0]=0;
        res[1]=0;
        res[2]=0;
        res[3]=0;
    }
    else if(a[0]==0 && a[1]==0 && a[2]==0 && a[3]==1)  // 1
    {
        res[0]=0;
        res[1]=0;
        res[2]=1;
        res[3]=0;
    }
     else if(a[0]==0 && a[1]==0 && a[2]==1 && a[3]==0)  // 2
    {
        res[0]=0;
        res[1]=1;
        res[2]=0;
        res[3]=0;
    }
    else if(a[0]==0 && a[1]==0 && a[2]==1 && a[3]==1)  // 3
    {
        res[0]=0;
        res[1]=1;
        res[2]=1;
        res[3]=0;
    }
    else if(a[0]==0 && a[1]==1 && a[2]==0 && a[3]==0)  // 4---
    {
        res[0]=1;
        res[1]=0;
        res[2]=0;
        res[3]=0;
    }
    else if(a[0]==0 && a[1]==1 && a[2]==0 && a[3]==1)  // 5
    {
        res[0]=1;
        res[1]=0;
        res[2]=1;
        res[3]=0;
    }
    else if(a[0]==0 && a[1]==1 && a[2]==1 && a[3]==0)  // 6
    {
        res[0]=1;
        res[1]=1;
        res[2]=0;
        res[3]=0;
    }
    else if(a[0]==0 && a[1]==1 && a[2]==1 && a[3]==1)  // 7
    {
        res[0]=1;
        res[1]=1;
        res[2]=1;
        res[3]=0;
    }
    else if(a[0]==1 && a[1]==0 && a[2]==0 && a[3]==0)  //8--
    {
        res[0]=0;
        res[1]=0;
        res[2]=1;
        res[3]=1;
    }
    else if(a[0]==1 && a[1]==0 && a[2]==0 && a[3]==1)  //9
    {
        res[0]=0;
        res[1]=0;
        res[2]=0;
        res[3]=1;
    }
    else if(a[0]==1 && a[1]==0 && a[2]==1 && a[3]==0)  //10
    {
        res[0]=0;
        res[1]=1;
        res[2]=1;
        res[3]=1;
    }
    else if(a[0]==1 && a[1]==0 && a[2]==1 && a[3]==1)  //11
    {
        res[0]=0;
        res[1]=1;
        res[2]=0;
        res[3]=1;
    }
     else if(a[0]==1 && a[1]==1 && a[2]==0 && a[3]==0)  //12
    {
        res[0]=1;
        res[1]=0;
        res[2]=1;
        res[3]=1;
    }
    else if(a[0]==1 && a[1]==1 && a[2]==0 && a[3]==1)  //13
    {
        res[0]=1;
        res[1]=0;
        res[2]=0;
        res[3]=1;
    }
    else if(a[0]==1 && a[1]==1 && a[2]==1 && a[3]==0)  //14
    {
        res[0]=1;
        res[1]=1;
        res[2]=1;
        res[3]=1;
    }
    else if(a[0]==1 && a[1]==1 && a[2]==1 && a[3]==1)  // F
    {
        res[0]=1;
        res[1]=1;
        res[2]=0;
        res[3]=1;
    }
}
void encrypt(int en[N])
{
    cout<<"\n\n\n====================/ ENCRYPTION /=======================\n";
    int ro[N],r1[N],rf[N];
    int s00[4],s01[4],s10[4],s11[4];
    int ex1[N/2],ex2[N/2];
    int nib1[4],nib2[4],nib3[4],nib4[4];
    cout<<"\n----------------Initial Round------------\n";
    exor(pt,key,ro,16);
    cout<<"\nRound0\t";
    printarr(ro,16);
    cout<<"\n\n----------------Round 1------------------\n";
    half(ro,ex1,ex2,8);
    half(ex1,nib1,nib2,4);
    half(ex2,nib3,nib4,4);
    sub(nib1);
    sub(nib2);
    sub(nib3);
    sub(nib4);
    swap(nib2,nib4);
    cout<<"\nSubstitution Nibbles\t";
    printarr(nib1,4);
    printarr(nib2,4);
    printarr(nib3,4);
    printarr(nib4,4);
    multiply_4(nib3,ex1);  //-----------------------s00
    exor(nib1,ex1,s00,4);
    cout<<"\ns00\t";
    printarr(s00,4);
    multiply_4(nib4,ex1); //----------------------s01
    exor(nib2,ex1,s01,4);
    cout<<"\ns01\t";
    printarr(s01,4);
    multiply_4(nib1,ex1); //----------------------s10
    exor(nib4,ex1,s10,4);
    cout<<"\ns10\t";
    printarr(s10,4);
    multiply_4(nib2,ex1); //----------------------s11
    exor(nib4,ex1,s11,4);
    cout<<"\ns11\t";
    printarr(s11,4);
    merge(s00,s10,ex1,4);
    merge(s01,s11,ex2,4);
    merge(ex1,ex2,r1,8);
    exor(key1,r1,r1,16);
    cout<<"\nRound1\t";
    printarr(r1,16);//-------------------round 1 
    cout<<"\n\n---------------Final Round---------------\n";
    half(r1,ex1,ex2,8);
    half(ex1,nib1,nib2,4);
    half(ex2,nib3,nib4,4);
    sub(nib1);
    sub(nib2);
    sub(nib3);
    sub(nib4);
    swap(nib2,nib4);
    cout<<"\nSubstitution Nibbles\t";
    printarr(nib1,4);
    printarr(nib2,4);
    printarr(nib3,4);
    printarr(nib4,4);
    merge(nib1,nib2,ex1,4);
    merge(nib3,nib4,ex2,4);
    merge(ex1,ex2,rf,8);
    exor(key2,rf,en,16);
    cout<<"\n\nCIPHERTEXT\t";
    printarr(en,16);    
}
void invsub(int a[N])
{
     if(a[0]==0 && a[1]==0 && a[2]==0 && a[3]==0)
    {
        a[0]=1;
        a[1]=0;
        a[2]=1;
        a[3]=0;
    }
    else if(a[0]==0 && a[1]==0 && a[2]==0 && a[3]==1)
    {
        a[0]=0;
        a[1]=1;
        a[2]=0;
        a[3]=1;
    }
    else if(a[0]==0 && a[1]==0 && a[2]==1 && a[3]==0)
    {
        a[0]=1;
        a[1]=0;
        a[2]=0;
        a[3]=1;
    }
    else if(a[0]==0 && a[1]==0 && a[2]==1 && a[3]==1)
    {
        a[0]=1;
        a[1]=0;
        a[2]=1;
        a[3]=1;
    }
    else if(a[0]==0 && a[1]==1 && a[2]==0 && a[3]==0)
    {
        a[0]=0;
        a[1]=0;
        a[2]=0;
        a[3]=1;
    }
    else if(a[0]==0 && a[1]==1 && a[2]==0 && a[3]==1)
    {
        a[0]=0;
        a[1]=1;
        a[2]=1;
        a[3]=1;
    }
    else if(a[0]==0 && a[1]==1 && a[2]==1 && a[3]==1)
    {
        a[0]=1;
        a[1]=1;
        a[2]=1;
        a[3]=1;
    }
    else if(a[0]==0 && a[1]==1 && a[2]==1 && a[3]==0)
    {
        a[0]=1;
        a[1]=0;
        a[2]=0;
        a[3]=0;
    }
    else if(a[0]==1 && a[1]==0 && a[2]==0 && a[3]==0)
    {
        a[0]=0;
        a[1]=1;
        a[2]=1;
        a[3]=0;
    }
    else if(a[0]==1 && a[1]==0 && a[2]==0 && a[3]==1)
    {
        a[0]=0;
        a[1]=0;
        a[2]=0;
        a[3]=0;
    }
    else if(a[0]==1 && a[1]==0 && a[2]==1 && a[3]==0)
    {
        a[0]=0;
        a[1]=0;
        a[2]=1;
        a[3]=0;
    }
    else if(a[0]==1 && a[1]==0 && a[2]==1 && a[3]==1)
    {
        a[0]=0;
        a[1]=0;
        a[2]=1;
        a[3]=1;
    }
    else if(a[0]==1 && a[1]==1 && a[2]==0 && a[3]==0)
    {
        a[0]=1;
        a[1]=1;
        a[2]=0;
        a[3]=0;
    }
    else if(a[0]==1 && a[1]==1 && a[2]==0 && a[3]==1)
    {
        a[0]=0;
        a[1]=1;
        a[2]=0;
        a[3]=0;
    }
    else if(a[0]==1 && a[1]==1 && a[2]==1 && a[3]==0)
    {
        a[0]=1;
        a[1]=1;
        a[2]=0;
        a[3]=1;
    }
    else if(a[0]==0 && a[1]==1 && a[2]==0 && a[3]==1)
    {
        a[0]=0;
        a[1]=1;
        a[2]=1;
        a[3]=1;
    }
     else if(a[0]==1 && a[1]==1 && a[2]==1 && a[3]==1)
    {
        a[0]=1;
        a[1]=1;
        a[2]=1;
        a[3]=0;
    }
}
void decrypt(int en[N])
{
    cout<<"\n\n\n=====================/ DECRYPTION /======================\n";
    int ro[N],r1[N],rf[N],ext[N];
    int s00[4],s01[4],s10[4],s11[4];
    int ex1[N/2],ex2[N/2];
    int nib1[4],nib2[4],nib3[4],nib4[4];
    exor(en,key2,rf,16);
    half(rf,ex1,ex2,8);
    half(ex1,nib1,nib2,4);
    half(ex2,nib3,nib4,4);
    swap(nib2,nib4);
    invsub(nib1);
    invsub(nib2);
    invsub(nib3);
    invsub(nib4);
    cout<<"\nInvSubstitution Nibbles\t";
    merge(nib1,nib2,ex1,4);
    merge(nib3,nib4,ex2,4);
    merge(ex1,ex2,ext,8);
    printarr(ext,16);
    exor(ext,key1,r1,16);
    half(r1,ex1,ex2,8);
    half(ex1,nib1,nib2,4);
    half(ex2,nib3,nib4,4);
    swap(nib3,nib2);//---------------------es
    multiply_9(nib1,ex1);//------------------s00
    multiply_2(nib3,ex2);
    exor(ex1,ex2,s00,4);
    cout<<"\ns00\t";
    printarr(s00,4);
    multiply_9(nib2,ex1);//------------------s01
    multiply_2(nib4,ex2);
    exor(ex1,ex2,s01,4);
    cout<<"\ns01\t";
    printarr(s01,4);
    multiply_9(nib3,ex1);//------------------s10
    multiply_2(nib1,ex2);
    exor(ex1,ex2,s10,4);
    cout<<"\ns10\t";
    printarr(s10,4);
    multiply_9(nib4,ex1);//------------------s11
    multiply_2(nib2,ex2);
    exor(ex1,ex2,s11,4);
    cout<<"\ns11\t";
    printarr(s11,4);
    invsub(s00);
    invsub(s11);
    invsub(s01);
    invsub(s10);
    merge(s00,s11,ex1,4);
    merge(s01,s10,ex2,4);
    merge(ex1,ex2,ro,8);
    exor(ro,key,de,16);
    cout<<"\n\nDECIPHERED TEXT\t";
    printarr(de,16);
    cout<<"\nPLAIN  TEXT\t";
    printarr(pt,16);

}
int main()
{
    cout<<"Enter the 16 bit Plain text ";
    for(int i=0;i<N;i++)
    cin>>pt[i];
    cout<<"Enter the 16 bit Key ";
    for(int i=0;i<N;i++)
    cin>>key[i];
    genkey();
    encrypt(en);
    decrypt(en);
}

/*------------
Plain text - 1 1 0 1 0 1 1 1 0 0 1 0 1 0 0 0 
key - 0 1 0 0 1 0 1 0 1 1 1 1 0 1 0 1
--------------*/