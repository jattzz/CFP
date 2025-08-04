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
        n *= 2;
        vll v(n);
        for(auto &i: v) cin>>i;
        sort(v.begin(), v.end());
        ll temp = v[n-1];
        temp += v[n-2];
        for(int i = 1; i<n-2; i+=2){
            temp += (v[i]-v[i-1]);
        }
        cout<<v[n-1]<<" "<<temp<<" "<<v[n-2];
        for(int i = 0; i<n-2; i++){
            cout<<" "<<v[i];
        }
        cout<<endl;
    }
}


// so basically we want to rearrange the given elements in a way that, we can determine the missing element with guarantee that it wont be a duplicate.
// we are given 2*n elements; 
// we have a1 = a2 - a3 + a4 - a5 + a6 - a7... + a2n - a2n+1;
// we can rearrenge it to look like; 
// a2n = a1 + (a3 - a2) + (a5 - a4) + (a7 - a6) + ...... + a2n+1;
// now we just have to maximise a2n;
// first we arrange the max two elements to a1 and a2n+1 (since they are getting directly added up), then, we can just have the difference of adjacent elements in 
// our sorted vector added into temp variable that we'll be using to store the sum of a1 and a2n+1;
// its guaranteed to pile up and be greater than any element in the array.
