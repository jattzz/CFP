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

long double eps = 1e-7;

bool canMeet(vector<pair<long double, long double>> v, long double mid){
    pair<long double, long double> p;
    p = {(v[0].first - mid*v[0].second), (v[0].first + mid*v[0].second)};
    for(int i = 1; i<v.size(); i++){
        long double temp1 = v[i].first - mid*v[i].second;
        long double temp2 = v[i].first + mid*v[i].second;
        // cout<<"-> ";
        // cout<<p.first<<" "<<p.second<<" "<<temp1<<" "<<temp2<<" ";
        if((((temp2>=p.first)&&(temp2<=p.second))||((temp1<=p.second)&&(temp1>=p.first))||((temp1<=p.first&&temp2>=p.second)))){
            // cout<<"satisfies"<<endl;
            continue;
        }
        // cout<<"doesnt satisfy"<<endl;
        return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin>>n;
    vector<pair<long double, long double>> v(n);
    for(auto &i: v){
        cin>>i.first>>i.second;
    }
    long double mnx = 1e9, mxx = -1e9;
    for(auto i: v){
        mnx = min(i.first, mnx);
        mxx = max(i.first, mxx);
    }
    // cout<<mnx<<" "<<mxx<<endl;
    long double low = 0, high = 1;
    for(int i = 0; i<n; i++){
        high = max(abs(mnx - v[i].first)/v[i].second, abs(mxx - v[i].first)/v[i].second);
    }
    // cout<<low<<" "<<high<<endl;
    while(abs(high - low) >= eps){
        long double mid = (low + high)/2;
        // cout<<mid<<endl;
        if(canMeet(v, mid)){
            high = mid;
        }
        else{
            low = mid;
        }
    }
    cout<<fixed<<setprecision(15)<<high<<endl;
}
