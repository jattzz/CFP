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
    string s; cin>>s;
    int i = 0, j = 1;
    vi v(26);
    for(auto i: s){
        v[i-'a']++;
    }
    for(auto i: v){
        if(i == 1){
            cout<<"NO"<<endl;
            return;
        }
        if((i == s.length() && s.length()>2)){
            cout<<"YES"<<endl;
            cout<<s.substr(0, (s.length()/2) + 1)<<endl;
            return;
        }
    }
    while(j<s.size()){
        if(s[i] == s[j]){
            i++; j++;
        }
        else{
            j = j - i + 1;
            i = 0;
        }
    }
    if(2*i > j){
        cout<<"YES"<<endl;
        cout<<s.substr(0, i)<<endl;
    }
    else cout<<"NO"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; t = 1;
    while(t--){
        solve();
    }
}

// the idea is to have to pointers and keep incrementing them if the chars are identical, else i is reset to 0
// whilst j is set to j = j - i + 1; 
// the algo is very naive in approach and will lead to tle for some peculiar test cases, which is why I had to add the preliminary if cases.
// one for cnt = 1, and then one for cnt == n; still not clear how this logic works, but cant think of anything better.
