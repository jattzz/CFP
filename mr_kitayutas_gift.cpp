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

bool isPalindrome(string s){
    int l = 0, r = s.length() - 1;
    while(l <= r){
        if(s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

void solve(){
    string s; cin>>s;
    int n = s.length();
    int cnt = 0;
    int l = 0, r = n - 1;
    if(isPalindrome(s)){
        if(n%2){
            cout<<s.substr(0, (n/2) + 1)<<s.substr((n/2), (n/2) + 1);
        }
        else{
            cout<<s.substr(0, n/2)<<'a'<<s.substr((n/2), (n/2));
        }
        return;
    }
    while(l <= r){
        if(s[l] != s[r]){
            s.insert(s.begin() + r + 1, s[l]);
            if(isPalindrome(s)){
                cout<<s<<endl;
                return;
            }
            else{
                s.erase(s.begin() + r + 1);
                s.insert(s.begin() + l, s[r]);
                if(isPalindrome(s)){
                    cout<<s<<endl;
                }
                else cout<<"NA"<<endl;
                return;
            }
        }
        l++; r--;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; t = 1;
    while(t--){
        solve();
    }
}

// abcddcba
