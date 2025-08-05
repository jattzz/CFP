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
        ll n, k; cin>>n>>k;
        vll a(n), b(n);
        set<ll> s;
        for(auto &i: a){
            cin>>i;
            s.insert(i);
        }
        for(auto &i: b){
            cin>>i;
            s.insert(i);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        ll res = 0;
        for(auto i: s){
            auto itr1 = lb(a.begin(), a.end(), i) - a.begin();
            auto itr2 = lb(b.begin(), b.end(), i) - b.begin();
            if((n - itr2) <= (n - itr1) + k){
                res = max(res, i*(n-itr2));
            }
        }
        cout<<res<<endl;
    }
}


// great problem, initial appraoch was to binary search from 0 to max_element to find which one will give the best result, going by how many negative reviews does a mid value return, which 
// fails in cases where you have to instead maximise the no. of trees sold, so second naive approach was to use 2 binary searches one for neg reviews and then another for no. of trees sold,
// which also fails in cases where the result is a mixture of both.

// so instead the correct approach is to binary search to check how many positive reviews you can get, and how many negative reviews you can get, and then check whether the solution is feasible if you take 
// only k negative value and then update it accordingly.
// we are essentially checking whether the number of negative reviews we are taking are less than equal to k or not whilst making up for the remaining elements with positive reviews if possible.
