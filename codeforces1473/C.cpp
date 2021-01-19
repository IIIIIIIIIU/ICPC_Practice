#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
int main(){
	int T;
	std::cin>>T;
	while(T--){
		int n,k;
		std::cin>>n>>k;
		for(int i=1;i<k-(n-k);i++)
			std::cout<<i<<' ';
		for(int i=k;i>=k-(n-k);i--)
			std::cout<<i<<' ';
		std::cout<<std::endl;
	}
	return 0;
}
