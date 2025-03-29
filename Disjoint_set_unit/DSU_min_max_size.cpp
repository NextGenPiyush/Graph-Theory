#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &pr, int x){
    // TX:(log*n);
    // This method returns which group/cluster x belongs to
    return pr[x] = (pr[x] == x) ? x : find(pr, pr[x]);
}

void Union(vector<int> &pr, vector<int> &sz, vector<int> &mini, vector<int> &maxi, vector<int> &rk, int a, int b){
    a = find(pr, a);
    b = find(pr, b);
    if(a == b) return;     // both a and b are same set
    if(rk[a] > rk[b]){
        rk[a]++;
        pr[b] = a;
        sz[a] += sz[b];
        maxi[a] = max(maxi[a], maxi[b]);
        mini[a] = min(mini[a], mini[b]);
    } 
    else{
        rk[b]++;
        pr[a] = b;
        sz[b] += sz[a];
        maxi[b] = max(maxi[a], maxi[b]);
        mini[b] = min(mini[a], mini[b]);
    }
}

void file_i_o(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
}

int main() {

    file_i_o();

    int n, m;
    cin>>n>>m;
    // n-> elements, m -> no of queries
    vector<int> pr(n+1);
    vector<int> rk(n+1, 0);
    vector<int> sz(n+1,1);
    vector<int> mini(n+1);
    vector<int> maxi(n+1);
    for(int i = 0; i <= n; i++) pr[i] = mini[i] = maxi[i] = i;

    while(m--){
        string str;
        cin>>str;
        if(str == "union"){
            int x, y;
            cin>>x>>y;
            Union(pr, sz, mini, maxi, rk, x, y);
        } 
        else{
            int x;
            cin>>x;
            x= find(pr, x);
            cout<<mini[x]<<" "<<maxi[x]<<" "<<sz[x]<<"\n";            
        }
    }

    return 0;
}