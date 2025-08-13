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

int n = 0;
bool visited[101];
vi start(101, 0), endd(101, 0);

void dfs(int l){
    visited[l] = true;
    for(int i = 1; i<=n; i++){
        if(visited[i]) continue;
        if(start[l]>start[i] && start[l]<endd[i]){
            dfs(i);
        }
        else if(endd[l]>start[i] && endd[l]<endd[i]){
            dfs(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin>>q;
    while(q--){
        int l, r, k;
        cin>>k;
        if(k == 1){
            n++;
            cin>>start[n];
            cin>>endd[n];
        }
        else{
            cin>>l>>r;
            memset(visited, false, sizeof(visited));
            dfs(l);
            if(visited[r]) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}

// very straightforward problem, only implementation is a bit tricky.
// we store all the intervals' starting and ending points in the start and endd vector respectively, where their index is basically their number/position.
// then we just dfs search to see whether it is possible to reach from a certain segment to another.
// just make sure to memset false the visited set before trying on another 2nd type of query.
