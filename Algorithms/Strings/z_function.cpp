
/*
*	Computes the z-array that is for each 0 <= i <= n - 1, 
*	z[i] is the length of longest substring starting at i which is also a prefix of s[0,n - 1] 
*   (Prefix may even overlap and contain the index i, so a prefix strictly before i can be computed by the same algo on the reversed string)
*/

vector<int> z_function(string s){

	int n = s.size();
	vector<int> z(n,0);
	for(int i = 1,l = 0,r  = 0;	i < n; i++){
		if(i <= r){
			z[i] = min(r - i + 1,z[i - l]);
		}
		while(i + z[i] < n && s[z[i]] == s[i + z[i]])
			z[i]++;
		if(i + z[i] - 1 > r){
			l = i;r = i + z[i] - 1;
		}
	}
	return z;
}