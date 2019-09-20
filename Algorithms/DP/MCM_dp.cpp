#include<bits/stdc++.h>
using namespace std;

const int N = 10;
vector<int> m(N);   // Change int to ll if needed
int dp[N + 1][N + 1];
int sol[N + 1][N + 1];

int INF = 1e9;

void print_sol(int i,int j){
  if(i == j){
    cout << "M" << i;
  }else{
    cout << "[";
    print_sol(i,sol[i][j]);
    print_sol(sol[i][j] + 1,j);
    cout << "]";
  }
}

void Matrix_Chain_Multiplication(int n){
  for(int i = 0; i <= n; i++){
    dp[i][i] = 0;
    sol[i][i] = i;
  }
  for(int i = 0; i <= n; i++){
    for(int j = i + 1; j <= n; j++){
      dp[i][j] = INF;
      sol[i][j] = -1;
    }
  }

  for(int l = 2; l <= n; l++){
    for(int i = 1; i <= n - l + 1; i++){
      int j = i + l - 1;
      for(int k = i; k < j; k++){
        int cost = dp[i][k] + dp[k + 1][j] + m[i - 1] * m[k] * m[j];
        if(cost < dp[i][j]){
          dp[i][j] = cost;
          sol[i][j] = k;
        }
      }
    }
  }
  cout << "+++Interative Sol\n";
  cout << "  Min cost : ";
  cout << dp[1][n] << '\n';
  cout << "  Optimal split : ";
  print_sol(1,n);
  cout << '\n';
}

int solve(int i,int j){
  if(i == j){
    return 0;
  }
  int &ans = dp[i][j];
  if(ans != INF){
    return ans;
  }
  for(int k = i; k < j; k++){
    int cost = solve(i,k) + solve(k + 1,j) + m[i - 1] * m[k] * m[j];
    if(cost < ans){
      ans = cost;
      sol[i][j] = k;
    }
  }
  return ans;
}

void Matrix_Chain_Multiplication_rec(int n){
  for(int i = 0; i <= n; i++){
    dp[i][i] = 0;
    sol[i][i] = i;
  }
  for(int i = 0; i <= n; i++){
    for(int j = i + 1; j <= n; j++){
      dp[i][j] = INF;
      sol[i][j] = -1;
    }
  }
  cout << "+++Recursive Sol\n";
  cout << "  Min cost : ";
  cout << solve(1,n) << '\n';
  cout << "  Optimal split : ";
  print_sol(1,n);
  cout << '\n';
}

int main(){

  int n;
  n = 5;
  m.resize(n + 1);
  m = {2,3,3,7,2,5};

  Matrix_Chain_Multiplication(n);

  Matrix_Chain_Multiplication_rec(n);

}