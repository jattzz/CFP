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
        string s; cin>>s;
        string copy = "";
        unordered_map<char, int> m;
        for(auto i: s) m[i]++;
        priority_queue<pair<int, char>> pq;
        for(auto i: m){
            pq.push({i.second, i.first});
        }
        while(pq.size()>0){
            auto p = pq.top();
            for(int i = 0; i<p.first; i++){
                copy.pb(p.second);
            }
            pq.pop();
        }
        int idx = 0;
        for(int i = 0; i<n; i+=2){
            s[i] = copy[idx];
            idx++;
        }
        for(int i = 1; i<n; i+=2){
            s[i] = copy[idx];
            idx++;
        }
        cout<<s<<endl;
    }
}

// basically we just have to make all the count of identical adjacent pairs as low as possible. So, one approach is to just store the count of all elements, in order to track which element appeared the most times.
// and then fill the string in alterating order (filling the char vector or string in a jumping fashion (ek index chord ke)).
