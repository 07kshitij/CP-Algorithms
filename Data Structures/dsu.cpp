// Code credits : https://codeforces.com/contest/1209/submission/60538028

const int N = 1e5 + 5;

class dsu {  
 public:
  vector<int> p, size;
  int n;
 
  dsu(int n = N){
    this -> n = n;
    p.resize(n + 1);
    size.resize(n + 1);
    for(int i = 1; i <= n; i++){
      p[i] = i;
      size[i] = 1;
    }
  }
 
  inline int root(int x) {
    return (x == p[x] ? x : (p[x] = root(p[x])));
  }
 
  inline bool merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) {
      if(size[x] < size[y])
        swap(x, y);
      p[y] = x;
      size[x] += size[y];
      return true;
    }
    return false;
  }
};
