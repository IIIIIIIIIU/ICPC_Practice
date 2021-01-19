#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
const int N=1e5+5;
const int INF=1e8+5;
inline void read(int &x){
	x=0;
	int it=1;
	char Cget=getchar();
	while(!isdigit(Cget)){
		if(Cget=='-')
			it=-1;
		Cget=getchar();
	}
	while(isdigit(Cget)){
		x=x*10+Cget-'0';
		Cget=getchar();
	}
	x*=it;
}
int n,a[N],b[N],hd[N],V[N],E[N],F[N];
int S,T,cnt,que[N],deep[N];
bool vis[105];
inline void EA(int u,int v,int f){
	E[++cnt]=hd[u];
	V[cnt]=v;
	F[cnt]=f;
	hd[u]=cnt;
	E[++cnt]=hd[v];
	V[cnt]=u;
	F[cnt]=0;
	hd[v]=cnt;
}
inline bool bfs()
{
	int h=0,tail=1,now;
	for(int i=S;i<=T;i++) deep[i]=-1;
	que[0]=S,deep[S]=0;
	while(h<tail)
	{
		now=que[h++];
		for(int i=hd[now];i;i=E[i])
		{
			if(F[i]&&deep[V[i]]<0)
			{
				deep[V[i]]=deep[now]+1;
				if(V[i]==T) return true;
				que[tail++]=V[i];
			}
		}
	}
	return false;
}
inline int flowing(int now,int flow)
{
	if(now==T) return flow;
	int oldflow=0,pos;
	for(int i=hd[now];i;i=E[i])
	{
		if(F[i]&&deep[V[i]]==deep[now]+1)
		{
			pos=flowing(V[i],flow<F[i]?flow:F[i]);
			F[i]-=pos,F[i^1]+=pos,flow-=pos,oldflow+=pos;
			if(!flow) return oldflow;
		}
	}
	if(!oldflow) deep[now]=-1;
	return oldflow;
}
int main(){
	cnt=1;
	read(n);
	T=n+1;
	int s=0;
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	for(int i=1;i<=n;i++){
		read(b[i]);
		if(b[i]>0){
			s+=b[i];
			EA(S,i,b[i]);
		}
		else{
			EA(i,T,-b[i]);
		}
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int v=i-1;v>0;v--){
			if(!vis[a[v]]&&a[i]%a[v]==0){
				EA(i,v,INF);
				vis[a[v]]=true;
			}
		}
	}
	int ans=0;
	while(bfs()){
		ans+=flowing(S,INF);
	}
	std::cout<<s-ans<<std::endl;
	return 0;
}
