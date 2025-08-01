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

bool query(string s){
    cout<<"? "<<s<<endl;
    ll response; cin>>response;
    if(response == -1) exit(0);
    return response;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        string res = "";
        while(res.size()<n){
            if(query(res + "0")){
                res.pb('0');
                continue;
            }
            if(query(res + "1")){
                res.pb('1');
                continue;
            }
            break;
        }
        while(res.size()<n){
            if(query("0" + res)){
                res = "0" + res;
                continue;
            }
            else{
                res = "1" + res;
                continue;
            }
            break;
        }
        cout<<"! "<<res<<endl;
    }
}

// standard interactive problem
