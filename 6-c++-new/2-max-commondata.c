#include <stdio.h>


void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b - tmp;
	
}

int gcd(int n, int k) {
	if (k == 0) return n;
	if (n < k) swap(&n, &k);   // pass none its not useful please instead 
	return gcd(k, n % k);
	
	
}


int main() {

	int n,k;
	scanf("%d %d", &n, &k);
	printf("%d\n", gcd(n,k));
	
	
	
	 return 0;
}



