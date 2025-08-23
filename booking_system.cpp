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
    ll n, k; cin>>n;
    vector<vector<int>> v(n, vector<int>(3));
    for(int i = 0; i<n; i++){
        cin>>v[i][1]>>v[i][0];
        v[i][2] = i + 1;
    }
    cin>>k;
    multiset<pair<int, int>> tables;
    for(int i = 0; i<k; i++){
        int z;
        cin>>z;
        tables.insert({z, i + 1});
    }
    int cnt = 0, sum = 0;
    sort(v.begin(), v.end(), [](const vector<int> &a, const vector<int> &b){return a[0] > b[0];});
    vector<pair<int, int>> res;
    for(int i = 0; i<n; i++){
        int temp = v[i][1];
        auto itr = tables.lb({temp, 0});
        if(itr != tables.end()){
            cnt++;
            sum += v[i][0];
            res.pb({v[i][2], itr->second});
            tables.erase(itr);
        }
    }
    cout<<cnt<<" "<<sum<<endl;
    for(auto i: res) cout<<i.first<<" "<<i.second<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}

// solved using greedy; first we sort the customers according to their budget, then we maintain a multiset for tables, and apply lower_bound for each customers' grp.
// overall time complxity => O(max(n*logn, n*logk)
