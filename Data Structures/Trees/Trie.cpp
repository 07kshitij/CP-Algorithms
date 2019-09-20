// Implementation credits :
// https://github.com/Ashishgup1/Competitive-Coding/blob/master/Trie.cpp

typedef struct Data{
  Data *bit[2];
  int cnt = 0;
}Node;

struct Trie{
  Node *head;

  void init(){
    head = new Node();
  }

  void insert(int x){
    Node *curr = head;
    for(int i = 30; i >= 0; i--){
      int b = (x >> i) & 1;
      if(!curr -> bit[b])
        curr -> bit[b] = new Node();
      curr = curr -> bit[b];
      curr -> cnt++;
    }
  }

  void remove(int x){
    Node *curr = head;
    for(int i = 30; i >= 0; i--){
      int b = (x >> i) & 1;
      curr = curr -> bit[b];
      curr -> cnt--;
    }
  }

  // Implement other queries accordingly as per requirement

  int query_less(int q,int k){ // Subarray with XOR < K
    Node *curr = head;
    int ans = 0;
    for(int i = 30; i >= 0; i--){ // From MSB to LSB
      int b = (q >> i) & 1;
      if((k >> i) & 1){ // Set bit in k found, so can go in each way
        if(b){  // Set bit in q
          if(curr -> bit[1] != NULL) // If ^1 possible, do it and add to ans
            ans += curr -> bit[1] -> cnt;
          if(curr -> bit[0] != NULL) // Go down ^0 way to find more paths
            curr = curr -> bit[0];
          else
            return ans;
        }else{ // Unset bit in k, so go in the direction of 0 bit in tree
          if(curr -> bit[0] != NULL) 
            ans += curr -> bit[0] -> cnt;
          if(curr -> bit[1] != NULL)
            curr = curr -> bit[1];
          else
            return ans;
        }
      }else{
        if(b){
          if(curr -> bit[1] != NULL)
            curr = curr -> bit[1];
          else
            return ans;
        }else{
          if(curr -> bit[0] != NULL)
            curr = curr -> bit[0];
          else
            return ans;
        }
      }
    }
    return ans;
  }

  int query_more_or_greater(int q,int k){ // Subarray with XOR >= K
    Node *curr = head;
    ll ans = 0;
    for(int i = 30; i >= 0; i--){ // From MSB to LSB
      int b = (q >> i) & 1;
      if((k >> i) & 1){
        if(b){  // Set bit in q
          if(curr -> bit[0] != NULL)
            curr = curr -> bit[0];
          else
            return ans;
        }else{
          if(curr -> bit[1] != NULL)
            curr = curr -> bit[1];
          else
            return ans;
        }
      }else{
        if(b){
          if(curr -> bit[0] != NULL)
            ans += curr -> bit[0] -> cnt;
          if(curr -> bit[1] != NULL)
            curr = curr -> bit[1];
          else
            return ans;
        }else{
          if(curr -> bit[1] != NULL)
            ans += curr -> bit[1] -> cnt;
          if(curr -> bit[0] != NULL)
            curr = curr -> bit[0];
          else
            return ans;
        }
      }
    }
    ans += curr -> cnt; // For subarr equal to k
    return ans;
  }

  ll query_maxXOR_discrete(int x){
    Node *curr = head;
    ll ans = 0;
    for(int i = 30; i >= 0; i--){
      int b = (x >> i) & 1;
      int nxt = b ^ 1;
      if(curr -> bit[nxt] != NULL and curr -> bit[nxt] -> cnt > 0){  
        // To take care in case bit[nxt] has been removed but pointer not nullified
        ans += (1ll << i);
        curr = curr -> bit[nxt];
      }else{
        curr = curr -> bit[b];
      }
    }
    return ans;
  }


};
