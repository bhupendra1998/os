#include<iostream>
using namespace std;
int main()
{
	int n,i,v[10]={0},j,temp=0,k,xb[10],xa[10],a[10],b[10],t,count=0,pid[10],c;
	int ct[10],wt[10],tat[10];
	float tat_av=0,ct_av=0,wt_av=0;
	cout<<"Enter the number of process"<<"\n";
	cin>>n;
	cout<<"Enter the arrival time "<<"\n";
	for(i=0;i<n;i++)
	{
			
		pid[i]=i;
		cin>>a[i];
	}
	cout<<"enter the burst time "<<"\n";
	for(i=0;i<n;i++)
		cin>>b[i];
	for(i=0;i<n;i++)
	{
		xb[i]=b[i];
		xa[i]=a[i];

	}
	for(i=0;i<n;i++)
	{
	for(j=i+1;j<n;j++)
	{
		if(a[i]>a[j])
		{
		t=a[i];a[i]=a[j];a[j]=t;

		t=xa[i];xa[i]=xa[j];xa[j]=t;
		

		t=pid[i];pid[i]=pid[j];pid[j]=t;
		
		t=b[i];b[i]=b[j];b[j]=t;

		t=xb[i];xb[i]=xb[j];xb[j]=t;
		}
        }
        
	}
cout<<"The order of process is as follows:"<<"\n";

cout<<"Process :" ;
for(j=0;j<n;j++)
{
cout<<pid[j]<<" ";
}
cout<<endl;
cout<<"arrival time:";
for(j=0;j<n;j++)
{
cout<<a[j]<<" ";
}
cout<<endl;
cout<<"burst time:";
for(j=0;j<n;j++)
{
cout<<b[j]<<" ";
}
cout<<endl;
count=0;
c=0;

for(t=0;;t++)
{
for(j=0;j<n;j++)
 {
   if((t>=a[j])&&(xb[count]<xb[j])&&(v[j]!=1))
     {
	count=j;
     }
     else if((t>=a[j])&&(xb[count]==xb[j])&&(v[j]!=1))
     {
	if(a[j]<a[count])
	{					
	count=j;
	
	}
     }
  }
xb[count]=xb[count]-1;

cout<<"\n"<<"process ::"<<pid[count]<<"::slot:"<<t<<"--"<<t+1<<endl;
for(k=0;k<n;k++)
{
if((xb[k]==0)&&(v[k]!=1))
{
c++;
v[k]=1;
xb[k]=0;
ct[k]=t+1;

for(j=0;j<n;j++)
{
if((xb[count]<xb[j])&&(a[j]<t))
count=j;
}
	
}
}
if(c==n)
break;
	
}

for(k=0;k<n;k++)
{
tat[k]=ct[k]-a[k];
wt[k]=tat[k]-b[k];	
}

for(k=0;k<n;k++)
{
tat_av=tat_av+tat[k];
wt_av=wt_av+wt[k];	
}

cout<<"Average turnaround time  is"<<tat_av/n<<endl; 
cout<<"Average waiting  time  is"<<wt_av/n<<endl; 
        	
}
