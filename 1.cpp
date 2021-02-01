#include<bits/stdc++.h>
using namespace std;
stack<int>st;
void addedge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
}

void dfsrectopo(vector<int>adj[],int s,bool visited[]){
    
    visited[s]=true;
    for(int x:adj[s]){
        if(visited[x]==false){
            dfsrectopo(adj,x,visited);
        }
    }
    st.push(s);
    return;
}
void dfstopo(vector<int>adj[],int v){
    bool visited[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
   
    for(int i=0;i<v;i++){
    if(visited[i]==false){
        dfsrectopo(adj,i,visited);
    }
        
    }
    cout<<st.size();
    while(st.size()!=0){
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main(){
    int v=6;
    vector<int>adj[v];
    addedge(adj,0,2);
    addedge(adj,0,3);
    addedge(adj,3,1);
    addedge(adj,4,1);
    addedge(adj,4,2);
    addedge(adj,5,0);
    addedge(adj,5,2);
    print(adj,v);
    if(dfscycle(adj, v)){
        cout<<"cyclic graph we cannot find toppological sort ";
    }
    else {
dfstopo(adj,v);    
    }
}
