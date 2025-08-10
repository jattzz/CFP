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

bool canMeet(vector<pair<long double, long double>> v, long double mid){
    long double minr = INT_MAX, maxl = INT_MIN;
    for(int i = 0; i<v.size(); i++){
        long double left = v[i].first - mid*v[i].second;
        long double right = v[i].first + mid*v[i].second;
        minr = min(minr, right);
        maxl = max(maxl, left);
    }
    return ((minr - maxl)>=0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin>>n;
    vector<pair<long double, long double>> v(n);
    for(auto &i: v){
        cin>>i.first>>i.second;
    }
    long double low = 0, high = 2*1e9;
    while((high - low)>=(1e-7)){
        long double mid = (low + high)/2;
        if(canMeet(v, mid)){
            high = mid;
        }
        else{
            low = mid;
        }
    }
    cout<<fixed<<setprecision(15)<<high<<endl;
}


// the binary search logic is simple, just searching for the optimal 't' value, (mid is t), the main logic part is in the boolean function;
// so the way it works is, after a certain time t, each x will have a leftmost possible position and a rightmost posible position;
// which are; (x-v.t) and (x+v.t) respectively;
// what we'll do is we'll keep track of the minimum right value and the maximum left value;
// if (minr - maxl) >= 0, (it will be possible for the correct time, since all segments will overlap), then it is possible for that certain 't'.
