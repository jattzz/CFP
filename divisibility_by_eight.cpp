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
    string s; cin>>s;
    // unordered_map<int, bool> m;
    bool possible[10010];
    memset(possible, false, sizeof(possible));
    for(auto d: s){
        int dig = d - '0';
        if((dig == 8)||(dig == 0)){
            cout<<"YES"<<endl;
            cout<<dig<<endl;
            return;
        }
        else if(dig%2){
            for(int i = 1; i<10; i+=2){
                if(possible[i]){
                    possible[((i*10) + dig)] = true;
                }
            }
            possible[dig] = true;
        }
        else{
            for(int i = 1; i<1001; i++){
                if(possible[i]){
                    if(((i*10)+dig)%8 == 0){
                        cout<<"YES"<<endl;
                        cout<<((i*10)+dig)<<endl;
                        return;
                    }
                }
            }
            for(int i = 1; i<1001; i+=2){
                if(possible[i]){
                    possible[(i*10)+dig] = true;
                }
            }
            possible[dig] = true;
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}

// no idea how to do it using dp, instead solved it purely using logic
// if 8 or 0 exists in the string then directly return it
// if theres an odd digit 'x', then for all the previously encountered odd digit 'y', add 'yx' into the possible no. as well
// if we see encounter an even digit 'x', then for all possible numbers, we check whether adding x to their last place change their divisibility, else we add all x to the end of all possible odd numbers.
