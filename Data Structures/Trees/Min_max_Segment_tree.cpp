// Code credits : https://www.codechef.com/viewsolution/27331680

const int N = 2e5 + 5; 
ll t[4*N], lazy[4*N]; 

void push(int node, int start, int end){
    t[node] = max(t[node], lazy[node]); 
    if(start != end){
        lazy[2*node] = max(lazy[2*node], lazy[node]); 
        lazy[2*node + 1] = max(lazy[2*node + 1], lazy[node]); 
    }
    lazy[node] = 0; 
}

void update(int node, int start, int end, int l, int r, int val){
    push(node, start,  end); 
    if(start > r || end < l)return ; 
    if(start >= l && end <= r){
        lazy[node] = val;
        push(node, start, end); return ; 
    }
    int mid = (start + end)/2; 
    update(2*node, start, mid, l, r, val); 
    update(2*node + 1, mid + 1, end, l, r, val); 
    t[node] = max(t[2*node], t[2*node + 1]);
}

ll query(int node, int start, int end, int l, int r){
    push(node, start, end); 
    if(start > r || end < l)return 0; 
    if(start >= l && end <= r){
        return t[node]; 
    }
    int mid = (start + end)/2; 
    return max(query(2*node, start, mid, l, r), query(2*node + 1, mid + 1, end, l, r)); 
}
