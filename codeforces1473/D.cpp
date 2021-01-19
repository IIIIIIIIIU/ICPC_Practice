#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
const int N=2e5+5,M=N<<2;
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
using std::max;
using std::min;
struct Val {
	int i,a,s;
	Val(int i_=0,int a_=0,int s_=0){
		i=i_;
		a=a_;
		s=s_;
	}
	Val operator+(const Val &p)const{
		return Val(min(i,s+p.i),max(a,s+p.a),s+p.s);
	}
}val[M];
char oper[N];
int n,m,L[M],R[M],md[M],sq[N];
void B(int x,int l,int r){
	L[x]=l;
	R[x]=r;
	if(l==r){
		val[x]=Val(min(sq[l],0),max(sq[l],0),sq[l]);
		return;
	}
	md[x]=l+r>>1;
	B(x<<1,l,md[x]);
	B(x<<1|1,md[x]+1,r);
	val[x]=val[x<<1]+val[x<<1|1];
}
Val Q(int x,int l,int r){
	if(L[x]>=l&&R[x]<=r)
		return val[x];
	if(r<=md[x])
		return Q(x<<1,l,r);
	else if(l>md[x])
		return Q(x<<1|1,l,r);
	else
		return Q(x<<1,l,r)+Q(x<<1|1,l,r);
}
int main(){
	int T;
	read(T);
	while(T--){
		read(n);
		read(m);
		std::cin>>oper;
		for(int i=1;i<=n;i++)
			if(oper[i-1]=='-')
				sq[i]=-1;
			else
				sq[i]=1;
		B(1,1,n);
		while(m--){
			int l,r;
			read(l);
			read(r);
			if(l==1&&r==n){
				puts("1");
			}
			else{
				Val res;
				if(l==1){
					res=Q(1,r+1,n);
				}
				else if(r==n)
					res=Q(1,1,l-1);
				else res=Q(1,1,l-1)+Q(1,r+1,n);
				std::cout<<res.a-res.i+1<<'\n';
			}
		}
	}
	return 0;
}
