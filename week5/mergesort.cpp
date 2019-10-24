#include<iostream>
using namespace std;

int help[2000000];
 
void merge(int a[],int i1,int j1,int i2,int j2){
	int i,j,k;
	i=i1;	
	j=i2;	
	k=0;
	while(i<=j1 && j<=j2)	
	{
		if(a[i]<a[j]){
			help[k]=a[i];
			k++;
			i++;
			
		}
			
		else{
			help[k]=a[j];
			k++;
			j++;
			
		}		
	}
	
	while(i<=j1){
		help[k]=a[i];
		k++;
		i++;
	}	
		
		
	while(j<=j2){
		help[k]=a[j];
		k++;
		j++;
	}	
		
	for(i=i1,j=0;i<=j2;i++,j++)
		a[i]=help[j];
}


void mergesort(int a[],int i, int j){
	int mid;
	if(i<j){
		mid=(i+j)/2;
		mergesort(a,i,mid);		
		mergesort(a,mid+1,j);	
		merge(a,i,mid,mid+1,j);	
	}
}


 
int main()
{
	int a[2000000],n,i;
	ios::sync_with_stdio(false);
	while(cin>>n){
		if(n==0)
			break;

		for(i=0;i<n;i++)
			cin>>a[i];

		mergesort(a,0,n-1);
		for(i=0;i<n;i++)
			cout<<help[i]<<" ";
		cout<<endl;	
	}
	return 0;	
}
 
