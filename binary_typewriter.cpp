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
        s = "0" + s;
        ll res = 0, curr = s[0];
        for(int i = 1; i<=n; i++){
            if(s[i] != curr) res++;
            curr = s[i];
        }
        if(res >= 3) cout<<(res - 2 + n)<<endl;
        else if(res == 2) cout<<(res - 1 + n)<<endl;
        else cout<<(res + n)<<endl;
    }
}

// pretty straightforward question, we just have to find the no. of instances where the curr digit was different from what we had in the string.
// if the count was greater than equal to 3, then the res would be (cnt - 2 + n);
// for cnt == 2; we have (cnt - 1 + n);
// else just (cnt + n);
