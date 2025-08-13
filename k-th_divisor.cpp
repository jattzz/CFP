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
    vll factors;
    ll temp = sqrt(n);
    int flg = (temp*temp == n);
    int cnt = 0;
    for(int i = 1; i<=temp; i++){
        if(n%i == 0){
            factors.pb(i);
            cnt++;
            if(cnt == k){
                cout<<i<<endl;
                return;
            }
        }
    }
    int sz = factors.size();
    if(k>(2*sz - flg)){
        cout<<(-1)<<endl;
        return;
    }
    k -= (cnt + 1);
    k += flg;
    cout<<(n/factors[cnt-1-k])<<endl;
}

// 64 -> 1, 2, 4, 8

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; t = 1;
    while(t--){
        solve();
    }
}

// more like 1000-1100ish problem.
