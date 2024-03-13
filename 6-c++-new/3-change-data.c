#include<stdio.h>
#include<stdarg.h>

int max_int(int num, ...) {
	int ans =0, tmp;
	va_list arg;
	va_start(arg, num);
	while(num--) {
		tmp = va_arg(arg, int);
		if(tmp > ans) ans = tmp;
	}
	va_end(arg);
	
	
	
	return ans;
}


int main() {
	
	printf("%d\n", max_int(5,1,2,3,5,7));
	printf("%d\n", max_int(6,1,2,3,5,7,8));
	
	
	return 0;
}
