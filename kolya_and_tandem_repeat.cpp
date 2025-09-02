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
    string s; cin>>s;
    int n; cin>>n;
    for(int i = 0; i<n; i++) s.pb('?');
    n = s.length();
    int res = 0;
    for(int i = 0; i<=(n-2); i++){
        int temp = 0;
        for(int j = 1; j<=(n-i+1)/2; j++){
            bool flg = true;
            for(int k = i; k<=(i+j-1); k++){
                if(s[k] != s[j+k]){
                    if((s[j+k] != '?') && (s[k] != '?')){
                        flg = false;
                        break;
                    }
                }
                if((j + k) >= n){
                    flg = false;
                    break;
                }
            }
            if(flg){
                temp = max(temp, j);
            }
        }
        res = max(temp, res);
    }
    cout<<(res*2)<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; t = 1;
    while(t--){
        solve();
    }
}
