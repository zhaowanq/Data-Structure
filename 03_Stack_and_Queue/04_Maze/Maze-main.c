/****************************************
 *			                  				      *
 * 文件夹: 03_Stack_and_Queue/04_Maze   *
 * 							                        *
 * 文件名: Maze-main.c                  *
 * 							                        *
 * 内  容: 迷宫相关操作测试             *
 *                                      *
 ****************************************/
 
#include <stdio.h>
#include "Maze.c"

int main(void)
{
	MazeType maze[N][N];
	PosType start, end;
	SElemType_Sq e;
	char Re = 'Y';
	
	while(Re =='Y' || Re =='y')
	{
		InitMaze(maze, &start, &end);		//初始化迷宫，包括出入口 
		ShowMaze(maze);						//显示迷宫的初始状态
		PressEnter;
		MazePath(maze,start,end);			//迷宫寻路
		printf("重置？（Y/N）:");
		scanf("%c",&Re);	
	}
	
	return 0;
}
