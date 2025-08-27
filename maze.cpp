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
#define sortr(v) sort(v.begin(), v.end(), greater<>())
#define sumup(v) accumulate(v.begin(), v.end(), 0ll)
#define cinv(v) for(auto &i: v) cin>>i
#define coutv(v) for(auto &i: v) cout<<i<<" "; cout<<"\n";
#define ull unsigned long long int
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
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

bool visited[501][501] = {false};
ll n, m, k, len = 0; 

void dfs(vector<vector<char>> &v, int i, int j){
    if(len == 0) return;
    if((i<0)||(i>=n)||(j<0)||j>=m) return;
    if(visited[i][j]) return;
    if(v[i][j] == '#') return;
    len--;
    visited[i][j] = true;
    dfs(v, i + 1, j);
    dfs(v, i - 1, j);
    dfs(v, i, j + 1);
    dfs(v, i, j - 1);
}

void solve(){
    cin>>n>>m>>k;
    vector<vector<char>> v(n, vector<char>(m));
    int cnt = 0;
    for(auto &i: v) for(auto &j: i){
        cin>>j;
        if(j == '.') cnt++;
    }
    len = cnt - k;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(v[i][j] == '.'){
                dfs(v, i, j);
                break;
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if((v[i][j] == '.')&&(!visited[i][j])) cout<<'X';
            else cout<<v[i][j];
        }
        cout<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; t = 1;
    while(t--){
        solve();
    }
}

// pretty standard dfs question, we can just iterate over the given 2d vector to find a connected segment of length k and then 
// just convert the remaining '.'s to 'X'.
// k = cnt - (no. of wall pieces we have to insert)
