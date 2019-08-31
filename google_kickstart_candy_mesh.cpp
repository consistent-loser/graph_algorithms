#include<bits/stdc++.h>
using namespace std;
class Edge{
	public:
	int src,dst,weight;
};
class Graph{
	public:
	int v;
	int e;
	 
	Edge *edge;
};
Graph* createGraph(int v,int e){

	Graph*graph=new Graph;
	graph->v=v;
	graph->e=e;
	graph->edge=new Edge[e];
	return graph;
}
class Subset{
	public:
	int parent,rank;
};
int find(Subset subset[],int u){
	if(subset[u].parent!=u){
		subset[u].parent=find(subset,subset[u].parent);
	}
	return subset[u].parent;
}
void unionn(Subset subset[],int src,int dst){
	int x_set=find(subset,src);
	int y_set=find(subset,dst);
	
	if(subset[x_set].rank<subset[y_set].rank){
		subset[x_set].parent=y_set;
	}
	else if(subset[x_set].rank>subset[y_set].rank){
		subset[y_set].parent=x_set;
	}
	else{
		subset[y_set].parent=x_set;
		subset[x_set].rank++;
	}
}
int mycomp(const void*a,const void*b){
	Edge*a1=(Edge*)a;
	Edge*b1=(Edge*)b;
	return a1->weight>b1->weight;
}
int kruskalsMST(Graph*graph){
	int v=graph->v;
	Edge result[v];
	qsort(graph->edge,graph->e,sizeof(graph->edge[0]),mycomp);
	Subset subset[v];
	for(int i=0;i<v;i++){
		subset[i].parent=i;
		subset[i].rank=0;
	}
	int e=0;
	int i=0;
	while(e<v-1&&i<graph->e){
		Edge next_edge=graph->edge[i++];
		
		int x=find(subset,next_edge.src);
		int y=find(subset,next_edge.dst);
		if(subset[x].parent!=subset[y].parent){
			result[e++]=next_edge;
			unionn(subset,x,y);
		}
	}
	//cout<<"following are the edges int the mst:"<<endl;
	int total=0;
	for(int i=0;i<e;i++){
		total+=result[i].weight;
	}
	return total;
}
int main(){
	int t;
	cin>>t;
	for(int x=0;x<t;x++){
		int v;    // this is for n
		int e; 
		cin>>v>>e;// this is for m
		Graph*graph=createGraph(v,e);
	
		for(int i=0;i<e;i++){
			int c,d;
			cin>>c>>d;
    		graph->edge[i].src = c-1;  
    		graph->edge[i].dst = d-1;  
			graph->edge[i].weight = 1;  
		}
	int ans=kruskalsMST(graph);
	int min_edge_required=v-1;
	int left_ones=min_edge_required-ans;
	//cout<<min_edge_required<<endl;
	//cout<<ans<<endl;
//	cout<<left_ones<<endl;
	cout<<"Case #"<<x+1<<": "<<ans+(left_ones*2)<<endl;
	}
    return 0;  
}
