#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int N=1e2+5;

inline void read(int &x){
	x=0;
	char Cget=getchar();
	while(Cget>'9'||Cget<'0')
		Cget=getchar();
	while(Cget>='0'&&Cget<='9'){
		x=x*10+Cget-'0';
		Cget=getchar();
	}
}

int a[N];

int main(){
	int T,n,d;
	read(T);
	while(T--){
		read(n);
		read(d);
		for(int i=1;i<=n;i++)
			read(a[i]);
		std::sort(a+1,a+n+1);
		if(a[n]>d&&a[1]+a[2]>d)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}
