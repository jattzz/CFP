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

bool possible(vll v, ll x, ll k){
    ll cnt = 1, lastused = v[0];
    for(int i = 1; i<v.size(); i++){
        if((v[i] - lastused) >= x){
            cnt++;
            lastused = v[i];
        }
    }
    return (cnt>=k);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k; cin>>n>>k;
    vll v(n);
    for(auto &i: v) cin>>i;
    ll low = 1, high = v[n-1];
    while(low <= high){
        ll mid = (low + high)/2;
        if(possible(v, mid, k)) low = mid + 1;
        else high = mid - 1;
    }
    cout<<high<<endl;
}

// standard binary search problem, is even there on tuf+ by the name of aggresive cows.
// I forgot that we have to assign cows to a stall, so its quite easy, mistook as something similar to gas stations which is quite complex.
