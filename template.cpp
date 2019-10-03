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
#define dbg  cerr << __LINE__ << " Hmm\n";

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

#define min_heap_ll priority_queue<ll,vl,greater<ll>>
#define min_heap_int priority_queue<int,vi,greater<int>>
#define min_heap_pii priority_queue<pii,vpii,greater<pii>>
#define min_heap_pll priority_queue<pll,vpll,greater<pll>>

// rng -> Use this, not rand()
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 


#define MAX (int)1e6
const ll mod = 1e9 + 7;
const double pi = 2*acos(0.0);

ll gcd(ll a,ll b){
	if(b == 0)return a;
	return gcd(b,a % b);
}

ll lcm(ll a,ll b){
	return (a * (b / gcd(a,b)));
}

inline ll add(ll a,ll b){
	return (a % mod + b % mod) % mod;
}

inline ll sub(ll a,ll b){
	return (a % mod - b % mod + mod) % mod;
}

inline ll mul(ll a,ll b){
	return(a % mod * b % mod) % mod;
}

inline ll modexpo(ll a,ll b){
	ll res = 1;
	while(b > 0){
		if(b & 1)
			res = ((res % mod) * (a % mod)) % mod;
		a = ((a % mod) * (a % mod)) % mod;
		b >>= 1;
	}return res;
}

inline ll modinv_Fermat(ll a){
	return modexpo(a,mod - 2);
}

inline ll divide(ll a,ll b){
	return(a%mod * modexpo(b,mod - 2)%mod)%mod;
}

// For Euler - phi related problems (a ^ b) % mod where b is itself calculated % mod
// Equals (a ^ (b % (mod - 1))) % mod
inline ll add2(ll a,ll b){
	ll MOD = mod - 1;
	return (a % MOD + b % MOD) % MOD;
}

inline ll sub2(ll a,ll b){
	ll MOD = mod - 1;
	return (a % MOD - b % MOD + MOD) % MOD;
}

inline ll mul2(ll a,ll b){
	ll MOD = mod - 1;
	return(a % MOD * b % MOD) % MOD;
}


ll expo(ll a,ll b){

	ll res = 1;
	while(b > 0){
		if(b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}


const ll N = 1e6;

typedef struct DSU{

	ll p[N],size[N];

	void init(ll n){
		for(ll i = 1;i <= n;i++){
			p[i] = i;size[i] = 1;
		}
	}

	ll root(ll v){
		if(v == p[v])
			return v;
		return p[v] = root(p[v]);
	}

	void merge(ll u,ll v){
		ll x = root(u);
		ll y = root(v);

		if(x != y){
			if(size[x] < size[y])
				swap(x,y);
			p[y] = x;
			size[x] += size[y]; 
		}
		return;
	}	
}dsu;

typedef struct BIT{

	vector<ll> B;
	ll n;

	void init(){
		B.resize(n + 5,0);	// Fix n before calling this function
	}

	void update(ll i,ll val){
		for(;i <= n;i += (i & -i))
			B[i] += val;
	}

	ll query(ll i){
		ll sum = 0;
		for(;i;i -= (i & -i))
			sum += B[i];
		return sum;
	}
}bit;

// Addition of 2 numbers in form of strings

string add(string a,string b){

	reverse(all(a));
	reverse(all(b));

	int n,m,i,j,k,carry;
	n = sz(a), m = sz(b);

	int x,y,z;

	carry = 0;

	string s = "";

	forn(0,min(n,m),i){
		x = a[i] - '0';	y = b[i] - '0';
		z = (x + y + carry);
		carry = z / 10;
		z %= 10;
		s += ('0' + z);
	}
	if(carry){
		if(i < n){
			while(i < n and carry){
				x = a[i] - '0';
				x += carry;
				carry = x / 10;
				x %= 10;
				s += ('0' + x);
				i++;
			}
		}else if(i < m){
			while(i < m and carry){
				x = b[i] - '0';
				x += carry;
				carry = x / 10;
				x %= 10;
				s += ('0' + x);
				i++;
			}
		}
		if(carry){
			s += ('0' + carry);
		}
	}
	if(i < n)
		while(i < n){
			s += a[i++];
		}
	if(i < m)
		while(i < m){
			s += b[i++];
		}

	reverse(all(s));
	return s;

}

string comp(string a,string b){

	if(sz(a) < sz(b))return a;
	if(sz(b) < sz(a))return b;
	if(a < b)return a;
	return b;
}


// Min steps to go from one 2D cell to other when all 8 directions are allowed to travel

ll min_steps(pair<ll,ll> a,pair<ll,ll> b){
    
    ll steps = 0;
    
    if(a.first > b.first){
        swap(a,b);
    }
    if(a.second <= b.second){
        ll go_up = b.second - a.second;
        ll go_right = b.first - a.first;
        ll move_diagonal = min(go_up, go_right);
        ll x = a.first + move_diagonal;
        ll y = a.second + move_diagonal;
        steps = move_diagonal + abs(b.first - x) + abs(b.second - y);
    }else{
        ll go_up = a.second - b.second;
        ll go_right = b.first - a.first;
        ll move_diagonal = min(go_up, go_right);
        ll x = a.first + move_diagonal;
        ll y = a.second - move_diagonal;
        steps = move_diagonal + abs(b.first - x) + abs(b.second - y);
    }
    
    return steps;
}

void ternary_search(){ // Define a cost function int F(int) above

  ll l,r,g,h,p,q;
  l = 0,r = 1e9;
  ll ans = 1e18;
  while(l <= r){
    g = l + (r - l) / 3;
    h = r - (r - l) / 3;
    p = F(g); q = F(h);
    if(p < q){
      ans = p;
      r = h - 1;
    }else{
      ans = q;
      l = g + 1;
    }
  }

}

ll dx[] = {1,-1,0,0};
ll dy[] = {0,0,1,-1};

bool check(pll x){
	if(x.ff >= 0 && x.ff < m && x.ss >= 0 && x.ss < n)return 1;
	return 0;
}

vector<bool> prime(MAX,true);
void sieve(){
	prime[0] = prime[1] = false;
	ll i,j;
	for(i = 2;i < MAX;i++){
		if(prime[i]){
			for(j = 2*i;j < MAX;j += i){
				prime[j] = false;
			}
		}
	}
}

void topological_sort(){

	memset(vis,0,sizeof vis);
	for(int i = 0;i < n;i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	reverse(all(topo));
}

ll C(ll n, ll r){
	if(n < r) return 0;
	if(n == r)return dp[n][r] = 1;
	if(r==0)return dp[n][r] = 1;
	if(dp[n][r])return dp[n][r]%(mod);
	else dp[n][r] = (C(n-1,r)%(mod) + C(n-1,r-1)%(mod))%(mod);
	return dp[n][r]%(mod);
}


ll Euler_totient_phi(ll n){
    if(n == 1)
        return 1;
    ll result = n;
    for(ll i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}


string dec_to_bin(ll n){
	string ans = "";
	while(n)
	{
		ans += ('0' + (n%2));
		n/=2;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
const ll N = 1e5 + 5;

class Factorial{
  ll f[N];
  public:

    Factorial(int n = N){
      f[0] = 1;
      for(int i = 1; i < n; i++){
        f[i] = mul(i, f[i - 1]);
      }
    }

    ll getVal(int n){
      return f[n];
    }

    ll nCr(int n, int r){
      if(r > n)return 0;
      ll ans = f[n];
      ans = divide(ans, f[n - r]);
      ans = divide(ans, f[r]);
      return ans;
    }

    ll nPr(int n, int r){
      if(r > n)return 0;
      ll ans = f[n];
      ans = divide(ans, f[n - r]);
      return ans;     
    }
};


int main()
{
	
	return 0;
}