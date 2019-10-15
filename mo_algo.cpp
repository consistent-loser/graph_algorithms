// Mo's algorithm

#include<bits/stdc++.h>
using namespace std;
int block;
struct Query{
	int l,r;
};

bool compare(Query r1,Query r2){
	if(r1.l/block!=r2.l/block)
	return (r1.l/block<r2.l/block);
	
	
	return (r1.r<r2.r);
}


void query_result(int a[],int n,Query q[],int m){
	block=(int)sqrt(n);
	
	sort(q,q+m,compare);
	
	int currL=0,currR=0;
	int currSum=0;
	
	for(int i=0;i<m;i++){
		int l=q[i].l;
		int r=q[i].r;
		
		// step 1
		// remove the left elements not required
		
		while(currL<l){
			currSum-=a[currL];
			currL++;
		}
		
		//step 2
		// add elements of the current rannge
		
		while(currL>l){
			currSum+=a[currL];
			currL--;
		}
		
		//step 3
		//add element to the right
		
		while(currR<=r){
			currSum+=a[currR];
			currR++;
		}
		
		//step 4
		//rempve previous elements out of the rnage
		
		while(currR>r+1){
			currSum-=a[currR];
			currR--;
		}
		
		cout<<"sum of "<<l<<" "<<r<<" : "<<currSum<<endl;
	}
	
	
}



int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	int m;
	cin>>m;
	Query q[m];
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		q[i].l=a;
		q[i].r=b;
		
	}
	
	query_result(a,n,q,m);
	return 0;
}
