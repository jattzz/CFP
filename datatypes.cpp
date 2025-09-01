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
    int n; cin>>n;
    vll v(n);
    cinv(v);
    sortv(v);
    for(int i = 1; i<n; i++){
        if(v[i] == v[i - 1]) continue;
        if((v[i] < 2*v[i-1])){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; t = 1;
    while(t--){
        solve();
    }
}
