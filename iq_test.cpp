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
    ll n; cin>>n;
    vll v(n);
    for(auto &i: v) cin>>i;
    int oddidx, evidx, nodds = 0, neves = 0;
    for(int i = 0; i<n; i++){
        if(v[i]%2){
            nodds++;
            oddidx = i + 1;
        }
        else{
            neves++;
            evidx = i + 1;
        }
    }
    if(nodds>neves){
        cout<<evidx<<endl;
        return;
    }
    else{
        cout<<oddidx<<endl;
        return;
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

// no idea why its rated 1300, was hoping for some insightful edge cases, L problem 
