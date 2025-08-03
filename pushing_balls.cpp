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
        ll n, m; cin>>n>>m;
        vector<vector<char>> v(n, vector<char>(m));
        for(auto &i: v){
            for(auto &j: i){
                cin>>j;
            }
        }
        bool res = true;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                bool r = true, c = true;
                if(v[i][j] == '1'){
                    for(int k = 0; k<j; k++){
                        if(v[i][k] == '0') r = false;
                    }
                    for(int k = 0; k<i; k++){
                        if(v[k][j] == '0') c = false;
                    }
                    res = (((r == c) && (r == false))?false:res);
                }
            }
        }
        if(res) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

// simple problem, just check for each index that has 1, whether it has a single 0 in row or column or not, if it has in both then false, else true.
