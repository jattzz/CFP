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

vi leader(1001, -1), sz(1001, 1);

int findLeader(int x){
    if(leader[x] == -1) return x;
    return leader[x] = findLeader(leader[x]);
}

void Union(int lead1, int lead2){
    if(sz[lead1]>sz[lead2]){
        swap(lead1, lead2);
    }
    sz[lead2] += sz[lead1];
    sz[lead1] = 0;
    leader[lead1] = lead2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin>>n;
    vi x(n+1), y(n+1);
    for(int i = 1; i<=n; i++) cin>>x[i]>>y[i];
    for(int i = 1; i<=n; i++){
        for(int j = i + 1; j<=n; j++){
            if((x[i] == x[j])||(y[i] == y[j])){
                int lead1 = findLeader(i);
                int lead2 = findLeader(j);
                if(lead1 != lead2){
                    Union(lead1, lead2);
                }
            }
        }
    }
    int res = 0;
    for(int i = 1; i<=n; i++){
        if(leader[i] == (-1)) res++;
    }
    cout<<(res-1)<<endl;
}

// basically in the last for loop, we are checking who's the leader of the ith point

// earlier 2 approaches didn't work because:
//     - in the bool vector approach, a point could later turn out   
//       to be connected, leading to WA.
//     - in the other approach, if 2 points were reachable from each 
//       other, but not from any other point, res would still not 
//       update. It was keeping track of isolated points, rather 
//       than isolated grps.
