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

ll sumgetter(vll &sum, ll l, ll r){
    if(l == 0) return sum[r];
    return sum[r] - sum[l - 1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k; cin>>n>>k;
    vll v(n), sum(n);
    for(auto &i: v) cin>>i;
    sum[0] = v[0];
    for(int i = 1; i<n; i++){
        sum[i] = sum[i-1] + v[i];
    }
    pair<ll, ll> res = mp(n - 2*k, n - k);
    if(res.first == 0){
        cout<<(res.first + 1)<<" "<<(res.second + 1)<<endl;
        return 0;
    }
    ll resSum = sumgetter(sum, n-2*k, n-k-1) + sumgetter(sum, n-k, n-1);
    pair<ll, ll> maxSuff = mp(n-k, sumgetter(sum, n-k, n-1));
    for(ll i = (n - 2*k - 1); i>=0; i--){
        ll curr = sumgetter(sum, i + k, i + 2*k - 1);
        if(curr >= maxSuff.second){
            maxSuff = mp(i+k, curr);
        }
        curr = sumgetter(sum, i, i+k-1) + maxSuff.second;
        if(curr >= resSum){
            resSum = curr;
            res = mp(i, maxSuff.first);
        }
    }
    cout<<(res.first + 1)<<" "<<(res.second + 1)<<endl;
}


// not intuitive at all; definitely among the harder 1500 problems
// the trick is to initialize the iterator of the for loop from n-2*k-1; by storing the sum of the last k elements in a separate container beforehand.
// why n-2*k-1? because it's the last most index possible for our first k elements (which will happen when the max sum subarrays of k lengths are at the very last indexes
// in a contiguous manner.
