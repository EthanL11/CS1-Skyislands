#include <stdio.h>
#include <stdlib.h>

//depth first search
void dfs(int** map, int* visit, int islands, int here){
	visit[here]=1;
	for(int i=0;i<islands;i++){
		if(visit[i]!=1&&map[here][i]==1){
			dfs(map, visit, islands, i);
		}
	}
}

int main(void){
	int islands, bridges, x, y;
	scanf("%d %d",&islands,&bridges);

	//allocate mem to 2d array
	int** map=calloc(islands,sizeof(int*));
	for(int i=0;i<islands;i++){
		map[i]=calloc(islands,sizeof(int));
	}

	//fill islands into map
	for(int i=0;i<islands;i++){
		for(int j=0;j<islands;j++){
			if(i==j){
				map[i][j]=1;
			}
		}
	}

	//insert bridges into map
	for(int i=0;i<bridges;i++){
		scanf("%d %d",&x,&y);
		map[x-1][y-1]=1;
		map[y-1][x-1]=1;
	}
	
	//alocate mem to a visit list
	int* visit=calloc(islands,sizeof(int));
	dfs(map, visit, islands, 0);

	//checks if visit reached the last island
	int connected=1;
	for(int i=0;i<islands;i++){
		if(visit[i]!=1){
			connected=0;
			break;
		}
	}

	//prints if islands are connected
	if(connected){
		printf("YES");
	}
	else{
		printf("NO");
	}

	//free mem
	for(int i=0;i<islands;i++){
		free(map[i]);
	}
	free(map);
	free(visit);

	return (0);
}