#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using ll=long long;
const int N=2e5+5;
int n,m,hd[N],E[N<<1],V[N<<1],W[N<<1],cnt;
ll dis[N][2][2];
bool vis[N][2][2];
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
inline void EA(int x,int y,int w){
	E[++cnt]=hd[x];
	V[cnt]=y;
	W[cnt]=w;
	hd[x]=cnt;
}
std::queue<int>q1,q2,q3;
void Up(int x,int y,int z){
	if(!vis[x][y][z]){
		vis[x][y][z]=true;
		q1.push(x);
		q2.push(y);
		q3.push(z);
	}
}
int main(){
	read(n);
	read(m);
	while(m--){
		int x,y,w;
		read(x);
		read(y);
		read(w);
		EA(x,y,w);
		EA(y,x,w);
	}
	memset(dis,0x3f,sizeof(dis));
	dis[1][0][0]=0;
	q1.push(1);
	q2.push(0);
	q3.push(0);
	while(!q1.empty()){
		int x=q1.front();
		int y=q2.front();
		int z=q3.front();
		q1.pop();
		q2.pop();
		q3.pop();
		ll tmp=dis[x][y][z];
		vis[x][y][z]=false;
		for(int i=hd[x];i!=0;i=E[i]){
			if(tmp+W[i]<dis[V[i]][y][z]){
				dis[V[i]][y][z]=tmp+W[i];
				Up(V[i],y,z);
			}
			if(!y&&!z){
				if(tmp<dis[V[i]][0][1]){
					dis[V[i]][0][1]=tmp;
					Up(V[i],0,1);
				}
				if(tmp+W[i]*2<dis[V[i]][1][0]){
					dis[V[i]][1][0]=tmp+W[i]*2;
					Up(V[i],1,0);
				}
				if(tmp+W[i]<dis[V[i]][1][1]){
					dis[V[i]][1][1]=tmp+W[i];
					Up(V[i],1,1);
				}
			}
			else if(!y&&z){
				if(tmp+W[i]*2<dis[V[i]][1][1]){
					dis[V[i]][1][1]=tmp+W[i]*2;
					Up(V[i],1,1);
				}
			}
			else if(!z&&y){
				if(tmp<dis[V[i]][1][1]){
					dis[V[i]][1][1]=tmp;
					Up(V[i],1,1);
				}
			}
		}
	}
	for(int i=2;i<=n;i++){
		std::cout<<dis[i][1][1]<<' ';
	}
	return 0;
}
