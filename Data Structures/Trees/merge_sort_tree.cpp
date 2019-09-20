/*
*	https://www.spoj.com/problems/MKTHNUM/
*	https://cp-algorithms.com/data_structures/segment_tree.html
*	https://www.geeksforgeeks.org/merge-sort-tree-for-range-order-statistics/
*	Finds number of elements less than / more than a given element in the interval [i..j]
*/


#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(v) v.begin(), v.end()
int const N = 1e5 + 1;

pair<int,int> a[N];
int b[N];
vector<int> T[4 * N];

void build(int v,int l,int r){

	if(l == r){
		T[v].push_back(a[l].ss);
		return;
	}
	int m = (l + r) >> 1;

	build(2*v + 1,l,m);
	build(2*v + 2,m + 1,r);

	merge(all(T[2*v + 1]),all(T[2*v + 2]),back_inserter(T[v]));
}

int query(int v,int l,int r,int start,int end,int k){

	if(start == end){
		return T[v][0];
	}
	int m = (start + end) >> 1;

	int last = upper_bound(all(T[2*v + 1]),r) - T[2*v + 1].begin();
	int first = lower_bound(all(T[2*v + 1]),l) - T[2*v + 1].begin();

	int M = last - first;

	if(M >= k)
		return query(2*v + 1,l,r,start,m,k);
	else
		return query(2*v + 2,l,r,m + 1,end,k - M);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL); 
	int n,m;
	cin >> n >> m;
	int i,j,k,l,r;
	for(i = 0;i < n;i++){
		cin >> a[i].ff;
		b[i] = a[i].ff;
		a[i].ss = i;
	}

	sort(a,a + n);
	build(0,0,n - 1);


	while(m--){
		cin >> l >> r >> k;
		l--;r--;
		cout << b[query(0,l,r,0,n - 1,k)] << '\n';
	}
}