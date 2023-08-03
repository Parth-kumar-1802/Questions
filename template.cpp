#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define mod1 999983
#define pi 3.14159265352718281828459045
#define gMax(a) *max_element(a.begin(),a.end())
#define gMin(a) *min_element(a.begin(),a.end())
#define gSum(a) accumulate(a.begin(),a.end(),0LL)
#define sortF(a) sort(a.begin(),a.end())
#define sortR(a) sort(a.rbegin(),a.rend())
#define pb(a) push_back(a)
 
using namespace std;
 
int bepower(int x,int n)  
{
    if(n==0) return 1;
    int res=1;
    while( n > 0){
        if(n%2==1){
            res = (res*x)%mod;
        }
        x=(x*x)%mod;
        n/=2;
    }
    return res; 
}
 
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);   
}
 
bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to square root of n
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}//time complexity:- O(sqrt(n))
 
int isComposite(int n){
    if(n<=1) return false;
    for(int i=2;i*i<n;i++){
        if(n%i==0) return i;
    }
    return -1;
} //returns the divisor as well, the first divisor, not all divisors doesnt seem to work for n=4????
 
 
void merge(vector<int>& v, int s, int m, int e) {
	
    // temp is used to temporary store the vector obtained by merging
    // elements from [s to m] and [m+1 to e] in v
	vector<int> temp;
	int i, j;
	i = s;
	j = m + 1;
	while (i <= m && j <= e) {
		if (v[i] <= v[j]) {
			temp.push_back(v[i]);
			++i;
		}else{
			temp.push_back(v[j]);
			++j;
		}
	}
	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}
	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}

	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];

}
 
void mergeSort(vector<int>& v, int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		mergeSort(v, s, m);
		mergeSort(v, m + 1, e);
		merge(v, s, m, e);
	}
}

 
int32_t main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
   
	
}