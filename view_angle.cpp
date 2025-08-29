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

#define M_PI 3.14159265358979323846

void solve(){
    ll n; cin>>n;
    vector<pair<double, double>> coordinates(n);
    set<double> angles;
    for(auto &i: coordinates){
        cin>>i.first>>i.second;
        double deg = (atan2(i.second, i.first))*(180.0/(M_PI));
        if((deg + 360)<360) angles.insert(deg + 360);
        else angles.insert(deg);
    }
    double res = 0, mxangle = 0, mnangle = 361.0;
    if(angles.size() == 1){
        cout<<fixed<<setprecision(8)<<res<<endl;
        return;
    }
    double temp = 361;
    for(auto i: angles){
        temp = min(360.0 - (i - mxangle), temp);
        mxangle = max(mxangle, i);
        mnangle = min(mnangle, i);
    } 
    cout<<fixed<<setprecision(8)<<min(temp, (mxangle - mnangle))<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; t = 1;
    while(t--){
        solve();
    }
}

// we can just store all the different angle in a set (so that they are sorted), and then we just have to check each pair of adjacent angles
// 0, 90, 115, 235, 359;
// s,  1,   2,   3,   e;
// the answer will always be min of (e - s) and (360 - max(v[i] - v[i-1])) for i = 1 to n-2 (0 based indexing).
