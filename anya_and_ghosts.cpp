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
    ll m, t, r; cin>>m>>t>>r;
    vll v(m);
    cinv(v);
    if(r>t){
        cout<<-1<<endl;
        return;
    }
    vi candles;
    int res = 0;
    for(auto i: v){
        vi goodCandles;
        for(auto j: candles){
            if(j >= i){
                goodCandles.pb(j);
            }
        }
        int sz = goodCandles.size();
        if(goodCandles.size() < r){
            for(int k = 0; k < (r - sz); k++){
                goodCandles.pb(i + t - k - 1);
                res++;
            }
        }
        candles = goodCandles;
    }
    cout<<res<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; t = 1;
    while(t--){
        solve();
    }
}

// first; the only scenario where -1 result would be returned is when r > t.
// now, for each time 't', we can just iterate the array and keep track of all the previously placed candles that are still good enough;
// we will keep them in a vector and instead of storing their starting time, we will store the last second at which they will still be burning.
// we will count the number of already placed good candles and then insert more to meet the value of 'r'. And we can just get rid of previously placed candles that are no longer good, since they wont be good for next ghosts too.
