const int M = 5; //No of letters in the alphabet

int val(char a){
  return (a - 'a');
}

typedef struct node{
  node *c[M];    
  int subtree = 0;
  int self = 0;
  bool isEnd = 0;
}Node;

struct Trie{
  Node *head;
  Trie(){
    head = new Node();
  }
  void insert(string s){
    Node *curr = head;
    for(int i = 0; i < (int)s.size(); i++){
      if(curr -> c[val(s[i])] == NULL){
        curr -> c[val(s[i])] = new Node();
      }
      curr = curr -> c[val(s[i])];
      curr -> self++;
      curr -> subtree++;
    }
    curr -> isEnd = 1;
  }

  Node* isPrefix(string s){ // Checks if a prefix is present in the trie and returns pointer to the last character
    Node *curr = head;
    for(int i = 0; i < (int)s.size(); i++){
      if(curr -> c[val(s[i])] == NULL)
        return NULL;
      curr = curr -> c[val(s[i])];
    }
    return curr;
  }

  string Smin(Node *root){  // Lex. min string with prefix as the given string
    Node* curr = root;
    string s = "";
    while(1){
      if(curr -> isEnd)
        break;
      bool leaf = 0;
      for(int i = 0; i < M; i++){
        if(curr -> c[i] != NULL){
          leaf = 1;
          curr = curr -> c[i];
          s += (char)(i + 'a');
          break;
        }
      }
      if(!leaf)
        break;
    }
    return s;
  }

  string Smax(Node *root){  // Lex. max string with prefix as the given string
    string s = "";
    Node *curr = root;
    while(1){
      bool leaf = 0;
      for(int i = M - 1; i >= 0; i--){
        if(curr -> c[i] != NULL){
          leaf = 1;
          curr = curr -> c[i];
          s += (char)(i + 'a');
          break;
        }
      }
      if(!leaf)
        break;
    }
    return s;
  }
};

