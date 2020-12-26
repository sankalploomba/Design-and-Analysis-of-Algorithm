#include <iostream>
#include <unistd.h>		//use windows.h and change sleep() to Sleep() if on Windows OS
using namespace std;

int i,j, MAX, MIN;
int *a,*b,*c,size;

void csort()
{
	MAX=a[1],MIN=a[1];

	for(i=2;i<size;i+=2)
	{
		if(a[i]>=a[i+1])
		{
			if(a[i]>MAX)
				MAX=a[i];
				
			if(a[i+1]<MIN)
				MIN=a[i+1];
		}
		else if(a[i+1]>a[i])
		{
			if(a[i+1]>MAX)
				MAX=a[i+1];
				
			if(a[i]<MIN)
				MIN=a[i];
		}
		//~ cout<<"i: "<<i<<endl;
		//~ cout<<"MAX: "<<MAX<<endl;
		//~ cout<<"MIN: "<<MIN<<endl;
	}
	
	if(i==size)
	{
		if(a[i]>MAX)
			MAX=a[i];
		
		else if(a[i]<MIN)
			MIN=a[i];
	}
	
	cout<<"MAX: "<<MAX<<endl;
	cout<<"MIN: "<<MIN<<endl;
	
	b=new int[MAX];
	int count;

	for(i=MIN;i<=MAX;i++)
		b[i]=0;
	
	sleep(5);
	
	for(i=MIN;i<=MAX;i++)
	{
		count=0;
		for(j=1;j<=size;j++)
		{
			if(a[j]==i)
				count++;
		}
		b[i]=count;
	}
	
	int sum=0;
	for (i = MIN; i <= MAX; i++)
	{
		sum+=b[i];
		b[i]=sum;
		cout<<"i:"<<i<<" b[i]:"<<b[i]<<"\t";
	}
	
	c=new int[size];
	
	for(i=size;i>0;i--)
	{
		c[b[a[i]]]=a[i];
		b[a[i]]--;
	}
	
}
int main()
{
	cout<<"Enter size: ";
	cin>>size;
	
	a=new int[size];
	
	cout<<"Enter array: ";
	for(i=1;i<=size;i++)
		cin>>a[i];
	
	csort();
	
	cout<<endl<<endl<<"Sorted array: ";
	for(i=1;i<=size;i++)
		cout<<c[i]<<" ";
}
