// ------	2D Lazy Segment Tree : Supports range updates and range / point queries (Min and max both over an interval) -------
// T[0][node] gives the max value covered by the node [i..j]
// T[1][node] gives the min value covered by the node [i..j]

const int N = 1e5 + 5;
const int inf = INT_MAX;
int T[2][4 * N];
int lazy[2][4 * N];
int a[N];

void build(int node,int l,int r){

	if(l == r){
		T[0][node] = a[l];
		T[1][node] = a[l];
		return;
	}
	int m = (l + r) >> 1;

	build(2*node + 1,l,m);
	build(2*node + 2,m + 1,r);

	T[0][node] = max(T[0][2*node + 1],T[0][2*node + 2]);
	T[1][node] = min(T[1][2*node + 1],T[1][2*node + 2]);
}

void update(int node,int start,int end,int l,int r,int val){

	if(lazy[0][node]){

		T[0][node] += lazy[0][node];
		if(start != end){
			lazy[0][2*node + 1] += lazy[0][node];
			lazy[0][2*node + 2] += lazy[0][node];
		}
		lazy[0][node] = 0;
	}
	if(lazy[1][node]){

		T[1][node] += lazy[1][node];
		if(start != end){
			lazy[1][2*node + 1] += lazy[1][node];
			lazy[1][2*node + 2] += lazy[1][node];
		}
		lazy[1][node] = 0;
	}
	if(start > end or start > r or end < l)
		return;

	if(l <= start and end <= r){

		T[0][node] += val;
		if(start != end){
			lazy[0][2*node + 1] += val;
			lazy[0][2*node + 2] += val;
		}

		T[1][node] += val;
		if(start != end){
			lazy[1][2*node + 1] += val;
			lazy[1][2*node + 2] += val;
		}
		return; 
	}
	int m = (start + end) >> 1;

	update(2*node + 1,start,m,l,r,val);
	update(2*node + 2,m + 1,end,l,r,val);

	T[0][node] = max(T[0][2*node + 1],T[0][2*node + 2]);
	T[1][node] = min(T[1][2*node + 1],T[1][2*node + 2]);
	return;
}

int query(int node,int start,int end,int l,int r,int type){
	if(start > end or start > r or end < l)
		return (type == 0 ? -inf : inf);

	if(lazy[type][node]){

		T[type][node] += lazy[type][node];
		if(start != end){
			lazy[type][2*node + 1] += lazy[type][node];
			lazy[type][2*node + 2] += lazy[type][node];
		}
		lazy[type][node] = 0;
	}

	if(l <= start and end <= r){
		return T[type][node]; 
	}
	int m = (start + end) >> 1;

	int p = query(2*node + 1,start,m,l,r,type);
	int q = query(2*node + 2,m + 1,end,l,r,type);

	if(type == 0)
		return max(p,q);
	else
		return min(p,q);
}
