#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
const int N=1e5+5;
int gcd(int x,int y){
	if(!y)
		return x;
	return gcd(y,x%y);
}
int main(){
	int T;
	std::cin>>T;
	while(T--){
		char a[21],b[21];
		std::cin>>a>>b;
		int la=strlen(a);
		int lb=strlen(b);
		if(la>lb){
			std::swap(la,lb);
			std::swap(a,b);
		}
		int ans=0;
		for(int i=0;i<la;i++)
			if(a[i]!=b[i]){
				ans=-1;
				break;
			}
		if(ans==-1){
			puts("-1");
		}
		else{
			int lcm=la*lb/gcd(la,lb);
			for(int i=0;i<lcm;i++){
				if(a[i%la]!=b[i%lb]){
					ans=-1;
					break;
				}
			}
			if(ans==-1){
				puts("-1");
			}
			else{
				for(int i=0;i<lcm;i++)
					putchar(a[i%la]);
				puts("");
			}
		}
	}
	return 0;
}
