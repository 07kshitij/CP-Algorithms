/*
*	https://www.spoj.com/problems/MIXTURES/
*	Regular MCM DP
*/


#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL); 

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define pu push
#define pp pop_back
#define in insert
#define ld long double
#define endl '\n'
#define debug cout << "Hold right there sparky.....\n";
#define forn(low,high,i) for(i=low;i<high;i++)
#define forrev(high,low,i) for(i = high; i>= low;i--)
#define trace(x) cerr << #x << ": " << x << " " << endl;
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define line cout << __LINE__;
typedef unordered_map<int,int> umi;
typedef unordered_map<ll,ll> uml;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

const ll N = 100 + 5;

ll dp[N][N];
ll color[N][N];

int main()
{
	IOS;
	freopen("input.txt","r",stdin);
	ll n,i,j,k,l;
	while(cin >> n){
		for(i = 0; i < n;i++){
			cin >> color[i][i];
		}
		for(i = 0;i < n;i++){
			for(j = 0;j < n;j++){
				dp[i][j] = 1e9;
			}
		}
		for(i = 0;i < n;i++)
			dp[i][i] = 0;
		ll s;
		for(l = 2;l <= n;l++){
			for(i = 0;i <= n - l;i++){
				j = i + l - 1;
				for(k = i;k < j;k++){
					s = dp[i][k] + dp[k + 1][j] + color[i][k] * color[k + 1][j];
					if(dp[i][j] > s){
						dp[i][j] = s;
						color[i][j] = (color[i][k] + color[k + 1][j]) % 100;
					}
				}
			}
		}
		cout << dp[0][n - 1] << '\n';
	}
}