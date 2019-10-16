// For large values of N DON'T USE the code inside struct. Make everything global

const int N = 1e5 + 5;
ll a[N];

struct Segtree{

  vector<ll> T, lazy;

  Segtree(int n = N){
    T.resize(4 * n, 0);
    lazy.resize(4 * n, 0);
  }

  void build(int v,int l,int r){
    if(l == r){
      T[v] = a[l];
      lazy[v] = 0;
      return;
    }
    int m = (l + r) >> 1;
    int n1 = 2*v + 1;
    int n2 = 2*v + 2;
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

  void update(int v,int l,int r,int start,int end,ll val){
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
    int n2 = 2*v + 2;
    update(n1,l,r,start,m,val);
    update(n2,l,r,m + 1,end,val);
    T[v] = T[n1] + T[n2];
    return;
  }

  ll query(int v,int l,int r,int start,int end){
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
    int n2 = 2*v + 2;
    ll p = query(n1,l,r,start,m);
    ll q = query(n2,l,r,m + 1,end);
    return p + q;
  } 
};
