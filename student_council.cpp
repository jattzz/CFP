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

ll k, n; 

bool canMake(vll v, ll mid){
    ll sum = 0;
    for(int i = 0; i<n; i++){
        sum += min(mid, v[i]);
    }
    return (sum/mid)>=k;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>k>>n;
    vll v(n);
    for(auto &i: v) cin>>i;
    ll low = 0, high = LLONG_MAX;
    while(low<=high){
        ll mid = (low + high)/2;
        if(canMake(v, mid)) low = mid + 1;
        else high = mid - 1;
    }
    cout<<high<<endl;
}

// another standard question; we just have to apply binary search on how many councils can be made;
// in the bool function we have, a sum variable which we use to add all the values that can be used to make councils, we will take at most 'mid' students from a grp.
// Once we have to total sum, we then divide it by mid value; we'll be left with 'how many students will be in a council after that, if it is greater than k, we return true and false otherwise.

// imp note, we take at most 'mid' students from a grp to avoid getting students from the same group in a council.
