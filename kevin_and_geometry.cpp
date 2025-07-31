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
    vll res;
    map<ll, ll> freq, remaining;
    for(auto i: v) freq[i]++;
    ll cnt = 0;
    for(auto i: freq){
        if(i.second >= 4){
            for(int j = 0; j<4; j++){
                cout<<i.first<<" ";
            }
            cout<<endl;
            return;
        }
        else if(i.second == 1){
            remaining[i.first] = i.second;
        }
        else{
            cnt++;
            res.pb(i.first);
            res.pb(i.first);
            remaining[i.first] = (i.second - 2);
            if(cnt == 2){
                for(auto x: res) cout<<x<<" ";
                cout<<endl; 
                return;
            }
        }
    }
    if(cnt == 0){
        cout<<"-1"<<endl;
        return;
    }
    vll temp;
    for(auto i: remaining){
        if(i.second > 0){
            temp.pb(i.first);
        }
    }
    sort(temp.begin(), temp.end());
    // for(auto i: res) cout<<i<<" ";
    // cout<<endl;
    // for(auto i: temp) cout<<i<<" ";
    // cout<<endl;
    for(int i = 1; i<temp.size(); i++){
        if((temp[i] - temp[i-1])<(2*res[0])){
            // cout<<"->"<<temp[i] - temp[i-1]<<" "<<2*res[0]<<endl;
            res.pb(temp[i-1]);
            res.pb(temp[i]);
            for(auto i: res) cout<<i<<" ";
            cout<<endl;
            return;
        }
    }
    cout<<"-1"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin>>t;
    while(t--){
        solve();
    }
}

// had first hand experience of unordered_map returning a value in O(n) time (worst case TC, when there are multiple hash collisions among keys). The same code leads to TLE if we use unordered_map. 
// in order to use unordered_map, we will have to use a custom hash function. 
// std::map on the other hand, takes logarithmic time for all sorts of operations, searching, inserting, deleting etc.
