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

void solve(){
    ll n, k; cin>>n>>k;
    vll v(n);
    map<ll, ll> m;
    for(auto &i: v){
        cin>>i;
        m[i] = 1;
    }
    sortv(v);
    ll cnt = 0;
    map<ll, bool> inserted;
    for(auto i: v){
        if(i%k){
            cnt++;
            inserted[i] = true;
        }
        else{
            if(inserted[i/k] == false){
                cnt++;
                inserted[i] = true;
            }
        }
    }
    cout<<cnt<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; t = 1;
    while(t--){
        solve();
    }
}


// really easy greedy solution, just check whether the number i is divisible by k or not, if not then simply insert it, else check whether
// i/k is already in the selected set or not, if not then insert it too, if it is then continue.
// make sure to sort the array beforehand.
// actual solution would be to maintain a chain for each i, meaning suppose k = 2, and out array is 
// 1 2 3 4 6 8 12 24 48
// then our chains will be; 
// 1. 1 2 4 8
// 2. 3 6 12 24 48
// for each chain the maximum numbers we can take is floor((length of chain + 1)/2);
