// KQUERY on SPOJ

#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:" << __VA_ARGS__, cerr << endl;

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

clock_t time_p = clock();

void ktj(){
    time_p = clock()-time_p;
    cerr << "Time Taken : " << (float)(time_p)/CLOCKS_PER_SEC << "\n";
}
	
const int N = 2e5 + 3e4;

struct node{
	
	int l,r,val,idx;
	bool operator < (const node &n){
		if(val != n.val)return val > n.val;
		return r > n.r;
	}
};

node a[N];

const int M = 3e4 + 100;

int n;

int BIT[M];

void update(int idx,int val){
	for(;idx <= n;idx += (idx & -idx)){
		BIT[idx] += val;
	}
}

int query(int idx){
	int sum = 0;
	for(;idx > 0;idx -= (idx & -idx)){
		sum += BIT[idx];
	}
	return sum;
}

int main(){

	IOS
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i].val;
		a[i].l = i + 1;
		a[i].r = -1;
		a[i].idx = i;
		BIT[i] = 0;
	}
	int m;
	cin >> m;
	int l,r,k;

	for(int i = 0;i < m;i++){
		cin >> a[i + n].l >> a[i + n].r >> a[i + n].val;
		a[i + n].idx = i;
	}

	sort(a,a + m + n);
	int res[m + 5];

	for(int i = 0;i < m + n;i++){
		if(a[i].r == -1){
			update(a[i].l,1);
		}else{
			res[a[i].idx] = query(a[i].r) - query(a[i].l - 1);
		}
	}
	for(int i = 0;i < m;i++){
		cout << res[i] << '\n';
	}

	// ktj();
}