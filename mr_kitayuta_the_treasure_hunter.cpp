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

const int m = 30001;
int dp[m][501];
bool used[m][501] = {false};
int gems[m] = {0};
int d;

int solve(int curr, int lastJump){
    int nextPossible = lastJump - (d - 250);
    if(curr >= m) return 0;
    if(used[curr][nextPossible]) return dp[curr][nextPossible];
    used[curr][nextPossible] = true;
    int res;
    if(lastJump == 1){
        res = gems[curr] + max(solve(curr + lastJump, lastJump), solve(curr + lastJump + 1, lastJump + 1));
    }
    else{
        res = gems[curr] + max(solve(curr + lastJump - 1, lastJump - 1), max(solve(curr + lastJump, lastJump), solve(curr + lastJump + 1, lastJump + 1)));
    }
    dp[curr][nextPossible] = res;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; t = 1;
    while(t--){
        int n; cin>>n>>d;
        for(int i = 0; i<n; i++){
            int temp; cin>>temp;
            gems[temp]++;
        }
        cout<<solve(d, d)<<endl;
    }
}
