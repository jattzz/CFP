// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define vi vector<int> 
// #define vll vector<long long>
// #define pii pair<int, int> 
// #define pic pair<int, char> 
// #define mii map<int, int> 
// #define mll map<long long, long long>
// #define pb push_back
// #define mp make_pair
// #define sortv(v) sort(v.begin(), v.end())
// #define sumup(v) accumulate(v.begin(), v.end(), 0)
// #define ull unsigned long long int
// #define bs binary_search
// #define lb lower_bound
// #define ub upper_bound
// #define cinv for(auto &i: v) cin>>i
// ll power(ll x, ull y){
//     if(y==0){
//         return 1;
//     }
//     ll temp = power(x, y/2);
//     if(y%2==0){
//         return temp*temp;
//     }
//     else{
//         return x*temp*temp;
//     }
// }

// void solve(){
//     ll n, k; cin>>n>>k;
//     vll v(n);
//     for(auto &i: v) cin>>i;
//     if(k == 1){
//         cout<<1<<" "<<1<<endl;
//         return;
//     }
//     unordered_map<int, int> um;
//     int cnt = 0, startIdx = 0;
//     for(int i = 0; i<n; i++){
//         if(i>0){
//             if(v[i]<v[i-1]){
//                 um.clear();
//                 cnt = 1;
//                 um[v[i]]++;
//                 startIdx = i;
//             }
//         }
//         if(um[v[i]] == 0){
//             cnt++;
//             um[v[i]]++;
//         }
//         if(cnt == k){
//             cout<<(startIdx + 1)<<" "<<(i + 1)<<endl;
//             return;
//         }
//     }
//     cout<<(-1)<<" "<<(-1)<<endl;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     solve();
// }

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

void solve(){
    ll n, k; cin>>n>>k;
    vll v(n);
    int arr[100001] = {0};
    int cnt = 0;
    for(auto &i: v){
        cin>>i;
        if(arr[i] == 0) cnt++;
        arr[i]++;
    }
    if(k == 1){
        cout<<1<<" "<<1<<endl;
        return;
    }
    if(cnt<k){
        cout<<(-1)<<" "<<(-1)<<endl;
        return;
    }
    int startIdx = 0, endIdx = n-1;
    for(int i = n-1; i>=0; i--){
        if((cnt>=k)){
            if(cnt == k){
                if(arr[v[i]]>1){
                    endIdx--;
                    arr[v[i]]--;
                    continue;
                }
                break;
            }
            endIdx--;
            cnt -= (arr[v[i]] == 1);
            arr[v[i]]--;
            continue;
        }
        break;
    }
    for(int i = 0; i<n; i++){
        if(cnt>=k){
            if(cnt == k){
                if(arr[v[i]]>1){
                    startIdx++;
                    arr[v[i]]--;
                    continue;
                }
                break;
            }
            startIdx++;
            cnt -= (arr[v[i]] == 1);
            arr[v[i]]--;
            continue;
        }
        break;
    }
    cout<<(startIdx + 1)<<" "<<(endIdx + 1)<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}

// The trick is to consider l = 1, and r = n, initially, and then iterate from back of the array to check whether the current element can be removed.
// Then we check from the front
// decent problem but should be 1300, not 1500.
