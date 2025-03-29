#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &parent, int x); // this method returns which group x belong to

void Union(vector<int> &parent, vector<int> &size, int a, int b);

int main(){
    
    int n,m;
    cout<<"enter no of elements: ";   cin>>n;
    vector<int> parent(n+1);
    for(int i=0; i<=n; i++) parent[i] = i;
    vector<int> size(n+1,0);
    
    cout<<"Enter queries: ";   cin>>m;
    while(m--){
        string str;
        cin>>str;
        if(str == "UNION"){
            int x,y;
            cin>>x>>y;
            Union(parent,size,x,y);
        }
        else{
            int x;
            cin>>x;
            cout<<find(parent,x)<<endl;
        }
    }
    
    
    return 0;
}

int find(vector<int> &parent, int x){
    return (parent[x] == x) ? x : find(parent,parent[x]); 
}

void Union(vector<int> &parent, vector<int> &size, int a, int b){
    a = find(parent,a);
    b = find(parent,b);
    if(a == b) return;
    if(size[a] >= size[b]){
        size[a] += size[b];
        parent[b] = a;
    }
    else{
        size[b] += size[a];
        parent[a] = b;
    }
}