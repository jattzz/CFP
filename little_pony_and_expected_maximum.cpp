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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long double n, k;
    cin>>n>>k;
    long double res = 0;
    for(double i = 1; i<=n; i++){
        res += i*(pow(i/n, k) - pow((i-1)/n, k));
    }
    // long double ans = (1.0*res)/(1.0*power(n, k));
    cout<<fixed<<setprecision(15)<<res<<endl;
}

// 1 -> 1
// 2 -> 3
// 3 -> 5
// 4 -> 7
// 5 -> 9
// 6 -> 11

// really glad that I was able to work up the main logic by myself.
// came up with the eqn: summation(i = 1, i = n) i*(power(i, k) - power(i-1, k))/(power(n, k);
// leads to overflow;
// have no idea how I missed that every term is getting raised to the kth power, so instead of (i^k)/(n^k), we can just use (i/n)^k; (-_-)
// and that's it.
