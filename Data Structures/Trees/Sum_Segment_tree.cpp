//	Computes sum a[i...j] in O(lgN) time along with range updates

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int T[4*N], lazy[4*N];

int a[N];

void build(int v,int l,int r){
	if(l == r){
		T[v] = a[l];
		return;
	}
	int m = (l + r) >> 1;
	int n1 = 2*v + 1;
	int n2 = n1 + 1;
	build(n1,l,m);
	build(n2,m + 1,r);

	T[v] = T[n1] + T[n2];
	return;
}

void propagate(int v,int start,int end){

	T[v] += (end - start + 1) * lazy[v];
	if(start != end){
		lazy[2*v + 1] += lazy[v];
		lazy[2*v + 2] += lazy[v];
	}
	lazy[v] = 0;
	return;
}

void update(int v,int l,int r,int start,int end,int val){
	if(start > end || start > r || end < l){
		return;
	}
	if(lazy[v]){
		propagate(v,start,end);
	}
	if(l <= start and end <= r){
		T[v] += (end - start + 1) * val;
		if(start != end){
			lazy[2*v + 1] += val;
			lazy[2*v + 2] += val;
		}
		return;
	}
	int m = (start + end) >> 1;
	int n1 = 2*v + 1;
	int n2 = n1 + 1;
	update(n1,l,r,start,m,val);
	update(n2,l,r,m + 1,end,val);
	T[v] = T[n1] + T[n2];
	return;
}

int query(int v,int l,int r,int start,int end){
	if(start > end || start > r || end < l){
		return 0;
	}
	if(lazy[v]){
		propagate(v,start,end);
	}
	if(l <= start and end <= r){
		return T[v];
	}
	int m = (start + end) >> 1;
	int n1 = 2*v + 1;
	int n2 = n1 + 1;
	int p = query(n1,l,r,start,m);
	int q = query(n2,l,r,m + 1,end);
	return p + q;
}

int main(){

	/*
		---Sample I/O for testing---

			int n = 5;	

			for(int i = 0;i < 5;i++)
				a[i] = i + 1;

			build(0,0,n - 1);
			cerr << query(0,1,3,0,n - 1) << '\n';
			update(0,0,2,0,n - 1,4);
			cerr << query(0,1,3,0,n - 1) << '\n';
	*/

	return 0;	
}