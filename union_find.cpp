#include<bits/stdc++.h>
using namespace std;
int find(int u,int parent[]){
	if(parent[u]==-1){
		return u;
	}
	return find(parent[u],parent);
}
void unionn(int src,int dst,int parent[]){
	int x_set=find(src,parent);
	int y_set=find(dst,parent);
	parent[x_set]=y_set;
}
int find_cycle(vector<pair<int,int>>v,int parent[],int n){
	for(int i=0;i<v.size();i++){
		int src=v[i].first;
		int dst=v[i].second;
		//cout<<src<<" "<<dst;
		if(find(src,parent)==find(dst,parent)){
			return 1;
		}
		unionn(src,dst,parent);
	}
	return 0;
}
int main(){
	int n,e;
	cin>>n;
	int parent[n];
	for(int i=0;i<n;i++){
		parent[i]=-1;
	}
	cin>>e;
	vector<pair<int,int>>v;
	for(int i=0;i<e;i++){
		int src,dst;
		cin>>src>>dst;
		v.push_back(make_pair(src,dst));
	}

	if(find_cycle(v,parent,n)){
		cout<<"cycle found";
	}
	else{
		cout<<"cycle not found";
	}
	
}
