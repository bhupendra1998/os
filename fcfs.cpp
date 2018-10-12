#include<iostream>
using namespace std;
int main()
{

int i,j,n,at[100],bt[100],ct[100],tat[100],wt[100],p[100],t=0,k;


cout<<"enter the no of processes :";
cin>>n;
cout<<"enter the process id :";
for(i=0;i<n;i++)
{
cin>>p[i];
}

cout<<"enter the arrival time :";
for(i=0;i<n;i++)
{
cin>>at[i];
}


cout<<"enter the burst time :";
for(i=0;i<n;i++)
{
cin>>bt[i];
}


for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(at[i]>at[j])
{
t = at[j];at[j]=at[i];at[i] = t;

t = bt[j];bt[j]=bt[i];bt[i] = t;

t = p[j]; p[j]=p[i];p[i] = t;
}
}
}



for(i=0;i<n;i++)
{
cout<<at[i]<<"  ";
}

cout<<endl;

for(i=0;i<n;i++)
{
cout<<bt[i]<<"  ";
}
cout<<endl;

cout<<"the process order is            pr:";
for(i=0;i<n;i++)
{
cout<<p[i]<<"    ";
}
cout<<endl;


cout<<"the complission time is         ct:";
ct[-1] = 0;   
k=0;
    for(i=0;i<n;i++)
    {
        if(ct[i-1]+k>=at[i])
         {
           ct[i] = bt[i] + ct[i-1]+k;
           k=0;
         }
        else
         {
           k++;
           i--;
         }
        
    }

for(i=0;i<n;i++)
{
cout<<ct[i]<<"   ";
}
cout<<endl;

cout<<"the turnarround time is        tat:";
for(i=0;i<n;i++)
{
tat[i] = ct[i] - at[i];
cout<<tat[i]<<"    ";
}
cout<<endl;

cout<<"the waiting time is             wt:";
 for(i=0;i<n;i++)
{
wt[i] = tat[i] - bt[i];
cout<<wt[i]<<"    ";
}
cout<<endl;

float total=0.0,temp=0.0;
for(i=0;i<n;i++)
{
total = total+tat[i];
temp = temp+wt[i];
}
float tAt = total/n;
float Wt = temp/n;
cout<<"the average turn around time is   :"<<tAt<<" "<<endl;
cout<<"the average waiting time is       :"<<Wt<<" "<<endl;

return 0;
}
