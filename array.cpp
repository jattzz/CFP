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

void solve(){
    ll n, k; cin>>n>>k;
    vll v(n);
    for(auto &i: v) cin>>i;
    if(k == 1){
        cout<<1<<" "<<1<<endl;
        return;
    }
    unordered_map<int, int> um;
    int cnt = 0, startIdx = 0;
    for(int i = 0; i<n; i++){
        if(i>0){
            if(v[i]<v[i-1]){
                um.clear();
                cnt = 1;
                um[v[i]]++;
                startIdx = i;
            }
        }
        if(um[v[i]] == 0){
            cnt++;
            um[v[i]]++;
        }
        if(cnt == k){
            cout<<(startIdx + 1)<<" "<<(i + 1)<<endl;
            return;
        }
    }
    cout<<(-1)<<" "<<(-1)<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
