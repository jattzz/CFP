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

ll rubles;
ll nb, ns, nc;
ll prb, prs, prc;   
ll nbr = 0, nsr = 0, ncr = 0;

bool canMake(ll mid){
    ll cost = ((max(0ll, mid*nbr-nb))*prb + (max(0ll, mid*nsr - ns))*prs + (max(0ll, mid*ncr - nc))*prc);
    return cost <= rubles;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string recipe; cin>>recipe;
    cin>>nb>>ns>>nc;
    cin>>prb>>prs>>prc;
    cin>>rubles;
    ll res = 0;
    for(auto i: recipe){
        if(i == 'B') nbr++;
        else if(i == 'S') nsr++;
        else ncr++;
    }
    while((nb>=nbr)&&(ns>=nsr)&&(nc>=ncr)){
        res++;
        nb -= nbr;
        ns -= nsr;
        nc -= ncr;
    }
    ll low = 0, high = 1e12;
    while(low <= high){
        ll mid = (low + high)/2;
        if(canMake(mid)) low = mid + 1;
        else high = mid - 1;
    }
    cout<<(res + high)<<endl;
}

// intial approach was to not make the hamburgers from the available ingredients right away, and that leads to wrong answer on some edge cases;
// but also it's more logical to first use the initial ingredients;
// and only then apply binary search to determine wheter 'mid' no. of hamburgers can be made or not.
