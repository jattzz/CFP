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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vll v(n);
        for(auto &i: v) cin>>i;
        unordered_map<ll, ll> freq;
        for(auto i: v) freq[i]++;
        vll res;
        ll cnt = 0;
        for(auto i: freq){
            if(i.second>1){
                res.pb(i.first);
                res.pb(i.first);
                i.second -= 2;
                cnt++;
                if(cnt == 2) break;
            }
        }
        if(cnt == 2){
            for(auto i: res) cout<<i<<" ";
            cout<<endl;
        }
        else if(cnt == 0) cout<<-1<<endl;
        else{
            vll temp;
            for(auto i: freq){
                if(i.second > 0){
                    temp.pb(i.first);
                }
            }
            sort(temp.begin(), temp.end());
            for(int i = 0; i<n-1; i++){
                if((v[i+1]-v[i]) < 2*res[0]){
                    res.pb(v[i+1]);
                    res.pb(v[i]);
                    break;
                }
            }
            if(res.size()<4) cout<<-1<<endl;
            else{
                for(auto i: res) cout<<i<<" ";
                cout<<endl;
            }
        }
    }
}
