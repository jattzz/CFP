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

vector<vector<char>> v;
vector<pair<int, int>> pos;

bool canReachPoint(int i, int j, int x, int y){ 
    bool flg = false;
    if(i == x){
        flg = true;
        int tempmin = min(j, y), tempmax = max(j, y);
        for(int k = tempmin; k<=tempmax; k++){
            if(v[i][k] == 'B') continue;
            else return false;
        }
        return flg;
    }
    else if(j == y){
        flg = true;
        int tempmin = min(i, x), tempmax = max(i, x);
        for(int k = tempmin; k<=tempmax; k++){
            if(v[k][j] == 'B') continue;
            else return false;
        }
        return flg;
    }
    else if(v[i][y] == 'B'){
        flg = true;
        for(int k = min(j, y); k <= max(j, y); k++){
            if(v[i][k] == 'B') continue;
            else{
                flg = false;
                break;
            }
        }
        if(flg){
            for(int k = x; k<=i; k++){
                if(v[k][y] == 'B') continue;
                else{
                    flg = false;
                    break;
                }
            }
        }
    }
    if(v[x][j] == 'B'){
        flg = true;
        for(int k = x; k<=i; k++){
            if(v[k][j] == 'B') continue;
            else{
                flg = false;
                break;
            }
        }
        if(flg){
            for(int k = min(j, y); k <= max(j, y); k++){
                if(v[x][k] == 'B') continue;
                else{
                    flg = false;
                    break;
                }
            }
        }
    }
    return flg;
}

bool canReach(int i, int j){
    if(pos.size() == 0) return true;
    for(auto t: pos){
        if(canReachPoint(i, j, t.first, t.second)) continue;
        else return false;
    }
    return true;
}

void solve(){
    int n, m; cin>>n>>m;
    v.resize(n, vector<char>(m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>v[i][j];
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(v[i][j] == 'B'){
                if(canReach(i, j)){
                    pos.pb({i, j});
                }
                else{
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"YES"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; t = 1;
    while(t--){
        solve();
    }
}

// contraints were too small (max(50)), hence we can just brute force through (n^2)*(m^2) pairs, and each time it will take n*m iterations
// to decide whether it can be reached or not;
// brute appraoch is accepted, but we can still optimize it a little;
// like maintaing a pos vector to store the indexes of previous black cell, and checking for each new black cell whether the previous 
// ones can be reached from it or not, hence we half our brute operations by only checking each pair once.
