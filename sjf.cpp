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
ct[-1] = 0;
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

for(int i=0;i<n;i++)
{
for(int j=i+1;j<n;j++)
{
if(bt[i]>bt[j]&&at[i]==at[j])
{
t=bt[i];bt[i]=bt[j];bt[j]=t;
t=p[i];p[i]=p[j];p[j]=t;
}
}
}

int kl=0;
int y=0;
for(int k=0;k<n;k++)
{
int r=0;
if((ct[k-1]+kl)>=at[k])
{
ct[k]=ct[k-1]+bt[k]+kl;
kl=0;
y=ct[k];
r=1;
}
else
{
kl++;
k--;
r=0;
}
if(r==1){
for(int i=k+1;i<n;i++)
{
for(int j=i+1;j<n;j++)
{
if(bt[i]>bt[j]&&at[j]<=y)
{
t=bt[i];bt[i]=bt[j];bt[j]=t;
t=p[i];p[i]=p[j];p[j]=t;
t=at[i];at[i]=at[j];at[j]=t;
}
}
}
}
}
cout<<"the process order is            pr:";
for(i=0;i<n;i++)
{
cout<<p[i]<<"    ";
}
cout<<endl;


cout<< "the complition time is 	       ct:";
for(i=0;i<n;i++)
{
cout<<ct[i]<<"     ";
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

