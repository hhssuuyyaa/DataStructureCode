#include<iostream>
using namespace std;

bool ratInMaze(char maze[10][10],int soln[10][10],int i,int j,int m,int n,int count){
	if(i==m && j==n){
		soln[m][n]=1;
		//Print the path
		if(count==0){
		for(int i=0;i<=m;i++){
			for(int j=0;j<=n;j++){
				cout<<soln[i][j]<<" ";
			}
			cout<<endl;
		}
		}
		count=count+1;
		cout<<endl;
		return true;
	}
	
	//Rat Should be in maze
	if(i>m || j>n){
		return false;
	}
	
	if(maze[i][j]=='X'){
		return false;
	}
	
	//Assume solution exists through current cell
	soln[i][j]=1;
	bool rightSuccess = ratInMaze(maze,soln,i,j+1,m,n,count);
	bool downSuccess = ratInMaze(maze,soln,i+1,j,m,n,count);
	
	//Backtracking
	soln[i][j]=0;
	
	if(rightSuccess||downSuccess){
		return true;
	}
	return false;
}

int main(){
	char maze[10][10] = {
						"0000",
						"00X0",
						"000X",
						"0X00",
	};
	int soln[10][10] = {0};
	int m=4;
	int n=4;
	bool ans = ratInMaze(maze,soln,0,0,m-1,n-1,0);
	if(ans==false){
		cout<<"Path don't exist";
	}
	
	return 0;
}
