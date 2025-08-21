#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int> 
#define vll vector<long long>
#define pii pair<int, int> 
#define pic pair<int, char> 
#define mii map<int, int> 
#define mll map<long long, long long>
#define pb push_back
#define mp make_pair
#define sortv(v) sort(v.begin(), v.end())
#define sumup(v) accumulate(v.begin(), v.end(), 0)
#define ull unsigned long long int
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define cinv for(auto &i: v) cin>>i
ll power(ll x, ull y){
    if(y==0){
        return 1;
    }
    ll temp = power(x, y/2);
    if(y%2==0){
        return temp*temp;
    }
    else{
        return x*temp*temp;
    }
}
ll n, m; 
vector<vector<char>> v;
vector<vector<bool>> visited;
bool dfs(int curri, int currj, int previ, int prevj){
    visited[curri][currj] = true;
    int di[4] = {1, -1, 0, 0};
    int dj[4] = {0, 0, 1, -1};
    for(int i = 0; i<4; i++) {
        int ni = curri + di[i];
        int nj = currj + dj[i];
        if((ni<0)||(ni>=n)||(nj<0)||(nj>=m)) continue;
        if(v[ni][nj] != v[curri][currj]) continue;
        if(!visited[ni][nj]){
            if(dfs(ni, nj, curri, currj)) return true;
        }
        else if(!((ni == previ) && (nj == prevj))){
            return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    v.resize(n, vector<char>(m));
    for(auto &i: v) for(auto &j: i) cin>>j;
    visited.assign(n, vector<bool>(m, false));
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++) {
            if (!visited[i][j]) {
                if(dfs(i, j, -1, -1)) {
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"No"<<endl;
}

// standard dfs problem, just dfs to check whether there exists a cycle or not. No idea why its rated 1500 when the n and m constraints are just <=50;
