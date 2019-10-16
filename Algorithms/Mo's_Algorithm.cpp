// Source : https://cp-algorithms.com/data_structures/sqrt_decomposition.html
// Mo's algorithm - Offline querying on intervals (i.e. W/O updates)
// Modify the add(), remove() and get_ans() function as per the question

ll a[N];
ll sum = 0;

struct Query{
  int l, r, idx;
  bool operator < (Query o) const{
    if(l / block_size != o.l / block_size)
      return l / block_size < o.l / block_size;
    return ((l / block_size) & 1) ? (r < o.r) : (r > o.r);
  }
};

struct Mo{  // Computes sum of elements in a range [l, r]

  void add(int idx){
    sum += a[idx];
  }

  void remove(int idx){
    sum -= a[idx];
  }

  ll get_ans(){
    return sum;
  }

  vl query(vector<Query> queries){
    int l = 0, r = -1;
    vl ans(sz(queries));
    sum = 0;
    for(auto q : queries){
      while(l > q.l){
        l--; add(l);
      }
      while(r < q.r){
        r++; add(r);
      }
      while(l < q.l){
        remove(l); l++;
      }
      while(r > q.r){
        remove(r); r--;
      }
      ans[q.idx] = get_ans();
    }
    return ans;
  }
}

