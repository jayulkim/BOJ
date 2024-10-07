#include <stdio.h> 
#include <math.h> 
int main(void){int n,i,Prev,num;while(scanf("%d",&n)!= EOF){bool visited[3000]={};int count=0;for(i=0;i<n;i++){scanf("%d",&num);if(i==0){Prev=num;}else{visited[abs(num-Prev)]=true;Prev= num;}}for(i=1;i<n;i++){if(visited[i]){count++;}}if(count!=n-1){printf("Not jolly\n");}else{printf("Jolly\n");}}}