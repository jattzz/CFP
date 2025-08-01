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
    double xa, ya, ra, xb, yb, rb;
    cin>>xa>>ya>>ra>>xb>>yb>>rb;
    double temp;
    double distance = sqrt(((xa-xb)*(xa-xb))+((ya-yb)*(ya-yb)));
    temp = distance-ra-rb;
    if(temp==0){
        temp = 0;
    }
    else if(temp<0){
        temp = max(ra, rb) - distance - min(ra, rb);
    }
    cout<<fixed<<setprecision(15)<<max(temp/2, 0.0)<<endl;
}

// quite easy geometry problem, no idea why its rated 1800
