#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adj[], int u,int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void print(vector<int>adj[],int v){
	for(int i=0;i<v;i++){
		for(int x:adj[i]){
			cout<<x<<" ";
		}
		cout<<endl;
	}
}
void dfs(vector<int>adj[],int curr,bool visited[]){
	visited[curr]=true;
	cout<<curr<<" ";
	for(int x:adj[curr]){
		if(visited[x]==false){
			dfs(adj,x,visited);
		}
	}
}
void bfs(vector<int>adj[],int s,int v){
	bool visited[v];
	for(int i=0;i<v;i++){
		visited[i]=false;
	}
	queue<int>q;
	q.push(s);
	visited[s]=true;
	while(q.size()!=0){
		int curr=q.front();
		q.pop();
		cout<<curr<<" ";
	for(int x:adj[curr]){
	if(visited[x]==false){
		visited[x]=true;
		q.push(x);
	}
	}
}
}
int main()
{
    int v=4;
    
    vector<int>adj[v]; //vector of array
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
   // print(adj,v);
    bool visited[v];
    for(int i=0;i<v;i++){
    	visited[i]=false;
    }
    for(int i=0;i<v;i++){
    	if(visited[i]==false){
    		dfs(adj,i,visited);
    	}
    }
  int s=0;
   bfs(adj,s,v);
 
}