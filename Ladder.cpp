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
    ll n, q; cin>>n>>q;
    vll v(n);
    for(auto &i: v) cin>>i;
    vll toil(n), toir(n);
    toil[0] = 0; toir[n-1] = n-1;
    for(int i = 1; i<n; i++){
        if(v[i]<=v[i-1]) toil[i] = toil[i-1];
        else toil[i] = i;
    }
    for(int i = n-2; i>=0; i--){
        if(v[i]<=v[i+1]) toir[i] = toir[i+1];
        else toir[i] = i;
    }
    // for(auto i: toil) cout<<i<<" ";
    // cout<<endl;
    // for(auto i: toir) cout<<i<<" ";
    // cout<<endl;
    while(q--){
        int l, r; cin>>l>>r;
        if(toir[l-1] >= toil[r-1]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
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

// Learned about iota(); basically it assigns a range of increasing numbers in the vector.
// iota(v.begin(), v.end(), 0); // will start from 0, 

// had to look at the editorial for this, and found the most genius solution that works in linear time frame.
// we keep track of the 
