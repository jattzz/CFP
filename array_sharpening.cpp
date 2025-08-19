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
    bool flg = true;
    int mid = v[n/2];
    if(n%2==0){
        if((v[n/2] == (n/2)-1) && (v[n/2 - 1] == (n/2)-1)){
            cout<<"No"<<endl;
            return;
        }
    }
    for(int i = 0; i<n; i++){
        if((v[i]>=i)||v[i]>=(n-1-i)) continue;
        else{
            flg = false;
            break;
        }
    }
    if(flg) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return;
}

// 0 1 2 3 2 1 0
// 0 1 2 3 4 5 6 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin>>t;
    while(t--){
        solve();
    }
}


// from the comment part, its pretty obvious that if the element is greater than or equal to the minimum number that can be on that index, then it can be sharpenend
// the minimum no. being min(i, n - 1 - i);
// only edge case for even no. of elements is when both the mid values are eactly the minimum possible to bypass the constraint, if they are different then it is possible, else no.
