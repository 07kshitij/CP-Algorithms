/*https://codeforces.com/contest/242/problem/E*/

#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 

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
#define forn(low,high,i) for(i=low;i<high;i++)
#define forrev(high,low,i) for(i = high; i>= low;i--)
#define trace(x) cerr << #x << ": " << x << " " << endl;
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define line cout << __LINE__;
#define prv(a) for(auto x : a) cout << x << ' ';cout << '\n';
#define decimal_digits cout << fixed << setprecision(15);
#define sp cout << " ";
#define dbg2(a,b) cerr << #a << " = " << a << " " << #b << " = " << b << '\n';				

const ll N = 1e5 + 5;
const ll MAX = 1e6;
const ll logN = (ll)ceil(log2(MAX));


ll T[4*N][25], lazy[4*N][25];
ll n;
ll a[N];

void build(ll node,ll l,ll r,ll bit){
	if(l == r){
		if((a[l] >> bit) & 1)
			T[node][bit] = 1;
		return;
	}
	ll m = (l + r) >> 1;
	ll n1 = 2*node + 1;ll n2 = n1 + 1;
	build(n1,l,m,bit);
	build(n2,m + 1,r,bit);

	T[node][bit] = T[n1][bit] + T[n2][bit];
}

void propagate(ll node,ll l,ll r,ll start,ll end,ll bit){

	T[node][bit] = (end - start + 1) - T[node][bit];

	if(start != end){
		lazy[2*node + 1][bit] ^= 1;
		lazy[2*node + 2][bit] ^= 1;
	}
	lazy[node][bit] = 0;
}	

void update(ll node,ll l,ll r,ll start,ll end,ll bit){

	if(lazy[node][bit]){
		propagate(node,l,r,start,end,bit);
	}
	if(start > end || start > r || end < l){
		return;
	}
	if(l <= start and r >= end){
		T[node][bit] = (end - start + 1) - T[node][bit];
		if(start != end){
			lazy[2*node + 1][bit] ^= 1;
			lazy[2*node + 2][bit] ^= 1;
		}return;
	}

	ll m = (start + end) >> 1;
	ll n1 = 2*node + 1;ll n2 = n1 + 1;
	update(n1,l,r,start,m,bit);
	update(n2,l,r,m + 1,end,bit);

	T[node][bit] = T[n1][bit] + T[n2][bit];
	return;
}

ll query(ll node,ll l,ll r,ll start,ll end,ll bit){

	if(lazy[node][bit]){
		propagate(node,l,r,start,end,bit);
	}
	if(start > end || start > r || end < l){
		return 0;
	}
	if(l <= start and r >= end){
		return T[node][bit];
	}

	ll m = (start + end) >> 1;
	ll n1 = 2*node + 1;ll n2 = n1 + 1;

	ll p1 = query(n1,l,r,start,m,bit);
	ll p2 = query(n2,l,r,m + 1,end,bit);

	return p1 + p2;
}

int main(){

	IOS
	cin >> n;
	for(ll i = 0;i < n;i++){
		cin >> a[i];
	}
	for(ll i = 0;i < logN; i++){
		build(0, 0, n - 1, i);
	}

	ll q,type,l,r,x;
	cin >> q;
	while(q--){
		cin >> type;
		if(type == 1){
			cin >> l >> r;
			l--;r--;
			ll sum = 0;
			for(ll i = 0;i < logN; i++){
				sum += (1ll << i) * (query(0,l,r,0,n - 1,i));
			}
			cout << sum << '\n';
		}else{
			cin >> l >> r >> x;
			l--;r--;
			for(ll i = 0;i < logN; i++){
				if((x >> i) & 1){
					update(0,l,r,0,n - 1,i);
				}
			}
		}
	}
}