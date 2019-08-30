#include<bits/stdc++.h>
using namespace std;

int find(int u,pair<int,int>parent_rank[]){
	if(parent_rank[u].first!=u){
		parent_rank[u].first=find(parent_rank[u].first,parent_rank);
	}
	
	return parent_rank[u].first;
}
void unionn(int src,int dst,pair<int,int> parent_rank[]){
	int x_set=find(src,parent_rank);
	int y_set=find(dst,parent_rank);
	
	if(parent_rank[x_set].second<parent_rank[y_set].second){
	parent_rank[x_set].first=y_set;

	}
	else
		if(parent_rank[x_set].second>parent_rank[y_set].second){
			parent_rank[y_set].first=x_set;
			
		}
	
	else{
		parent_rank[y_set].first=x_set;
		parent_rank[x_set].second=parent_rank[x_set].second+1;

	}
	
}
int find_cycle(vector<pair<int,int>>v,int n){
pair<int,int> parent_rank[n];	//first parent and second rank
	for(int i=0;i<n;i++){
		parent_rank[i].first=i;
		parent_rank[i].second=0;
	}

	for(int i=0;i<v.size();i++){
		int src=v[i].first;
		int dst=v[i].second;
	
		if(find(src,parent_rank)==find(dst,parent_rank)){
			return 1;
		}
		unionn(src,dst,parent_rank);
		
	}
	
	return 0;
}

int main(){
	int n,e;
	cin>>n;
	cin>>e;
	vector<pair<int,int>>v;
	for(int i=0;i<e;i++){
		int src,dst;
		cin>>src>>dst;
		v.push_back(make_pair(src,dst));
	}

	if(find_cycle(v,n)){
		cout<<"cycle found";
	}
	else{
		cout<<"cycle not found";
	}
	

}
