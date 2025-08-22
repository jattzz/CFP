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
    ll n, k; cin>>n>>k;
    vector<string> v(n);
    ll res = 1, mod = 1e9 + 7;
    for(auto &i: v) cin>>i;
    for(int i = 0; i<k; i++){
        bool visited[26] = {false};
        int cnt = 0;
        for(int j = 0; j<n; j++){
            int temp = v[j][i] - 'A';
            cnt += (!visited[temp]);
            visited[temp] = true;
        }
        res = ((res%mod)*(cnt%mod))%mod;
    }
    cout<<res<<endl;
}

// another fairly easy combinatorics problem.
