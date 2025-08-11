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

bool grpNeeded(vll v, ll mid, ll k){
    ll cnt = 1, sum = 0;
    for(int i = 0; i<v.size(); i++){
        sum += v[i];
        if(sum > mid){
            cnt++;
            sum = v[i];
        }
    }
    return (cnt<=k);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k; cin>>n>>k;
    vll v(n);
    for(auto &i: v) cin>>i;
    ll low = *max_element(v.begin(), v.end());
    ll high = accumulate(v.begin(), v.end(), 0ll);
    while(low <= high){
        ll mid = (low + high)/2;
        if(grpNeeded(v, mid, k)) high = mid - 1;
        else low = mid + 1;
    }
    cout<<low<<endl;
}

// another standard binary search question, we just have to split the array into k segments and we have to minimize the max sum possible for any segment.
// very straightforward so no explanation.
