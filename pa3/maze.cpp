//Josue Campos
//PA3
//Ghyam

#include <iostream>
#include "maze_io.h"
using namespace std;

// Prototype for maze_search
int maze_search(char **, int, int);


int main(int argc, char *argv[])
{
  int rows, cols, result;

  if(argc < 3){
    cerr << "Usage: ./maze in_filename out_filename" << endl;
    return 1;
  }

  char** mymaze = read_maze(argv[1], &rows, &cols);

  // For checkpoint 1, just leave maze_search() unedited
  //  and the program should read in the maze, print it
  //  and write it back to the output file
  result = maze_search(mymaze, rows, cols);

  if( result == 1 ){
    cout << "Path successfully found!" << endl;
    print_maze(mymaze,rows,cols);
    write_maze(argv[2],mymaze,rows,cols);
  }
  else if (result == 0) {
    cout << "No path could be found!" << endl;
  }
  else {
    cout << "Error occurred during search!" << endl;
  }

 	for(int i = 0; i < rows; i++)
 	{
  	delete [] mymaze[i];
  }
	
	delete [] mymaze;
	
  return 0;
}

/**************************************************
 * Attempt to find shortest path and return:
 *  1 if successful
 *  0 if no path exists
 * -1 if an error occurred (no start of finish
 *     cell present in the maze)
 *
 * If path is found fill it in with '*' characters
 *  but don't overwrite the 'S' and 'F' cells
 *************************************************/
int maze_search(char **maze, int rows, int cols)
{
	int queue_size = rows*cols;
	bool start = false;
	bool finish = false;
	int (*bfsq)[2] = new int[queue_size][2];//initialize queue array
	int (*prd) = new int[queue_size];//initilaize predecessor array
	int head = 0;
	int tail = 0;
	int loc_row;
	int loc_col;
	bool solved = false;
	
	//int temp;

	int **visited = new int*[rows];//initialize visited array
	for (int i=0; i<rows; i++)
	{
		visited[i] = new int [cols];
		for(int j=0; j<cols; j++)
		{
			visited[i][j]=0;
		}
	}

	for (int i=0;i<rows;i++) 
	{
		for(int j=0;j<cols;j++)
		{
	   	if (maze[i][j] == 'S')//declare start
	    {
	      bfsq[0][0]=i; 
	      bfsq[0][1]=j;
	      tail++;
	      start = true;//check for start
	      prd[i*cols + j]=-1;
	    }
 	   	if (maze[i][j] == 'F') 
 	   	{
 	   	  finish = true;//check for finish
 	    }
 	  }
	}
	if (finish==false || start==false) //check for start and finish
	{
		return -1; 
	}

	while(solved == false) 
	{
		loc_row= bfsq[head][0]; //update for current location of row
		loc_col= bfsq[head][1]; //update for current location of col
		visited[loc_row][loc_col]=1;
		int current = head;
		head++;
		
		
		if(loc_row-1>=0 && loc_row-1<rows)// check north
		{
			if (visited[loc_row-1][loc_col] != 1)
			{
				if (maze[loc_row-1][loc_col]== '.')
				{
					bfsq[tail][0]=loc_row-1;
					bfsq[tail][1]=loc_col;
					prd[tail]=current;
					tail++;
					visited[loc_row-1][loc_col]=1;
				}
				else if(maze[loc_row-1][loc_col]== 'F')
				{
					bfsq[tail][0]=loc_row-1;
					bfsq[tail][1]=loc_col;
					prd[tail]=current;
					visited[loc_row-1][loc_col]=1;
					solved = true;
					head --;
				}
			}
		}
		
		if(loc_col-1>=0 && loc_col-1<cols) //check west
		{
			if (visited[loc_row][loc_col-1] != 1)
			{
				if (maze[loc_row][loc_col-1]== '.')
				{
					bfsq[tail][0]=loc_row;
					bfsq[tail][1]=loc_col-1;
					prd[tail]=current;
					tail++;
					visited[loc_row][loc_col-1]=1;
				}
				else if(maze[loc_row][loc_col-1]== 'F')
				{
					bfsq[tail][0]=loc_row;
					bfsq[tail][1]=loc_col-1;
					prd[tail]=current;
					visited[loc_row][loc_col-1]=1;
					solved = true;
					head--;
				}
			}
		}
		
		if(loc_row+1>=0 && loc_row+1<rows)//check south
		{
			if (visited[loc_row+1][loc_col] != 1)
			{
				if (maze[loc_row+1][loc_col]== '.')
				{
					bfsq[tail][0]=loc_row+1;
					bfsq[tail][1]=loc_col;
					prd[tail]=current;
					tail++;
					visited[loc_row+1][loc_col]=1;
				}
				else if(maze[loc_row+1][loc_col]== 'F')
				{
					bfsq[tail][0]=loc_row+1;
					bfsq[tail][1]=loc_col;
					prd[tail]=current;
					visited[loc_row+1][loc_col]=1;
					solved = true;
					head--;
				}
			}
		}
		
		if(loc_col+1>=0 && loc_col+1<cols) //check east
		{
			if (visited[loc_row][loc_col+1] != 1)
			{
				if (maze[loc_row][loc_col+1]== '.')
				{
					bfsq[tail][0]=loc_row;
					bfsq[tail][1]=loc_col+1;
					prd[tail]=current;
					tail++;
					visited[loc_row][loc_col+1]=1;
				}
				else if(maze[loc_row][loc_col+1]== 'F')
				{
					bfsq[tail][0]=loc_row;
					bfsq[tail][1]=loc_col+1;
					prd[tail]=current;
					visited[loc_row][loc_col+1]=1;
					solved = true;
					head--;
				}
			}
		}
	
	if(tail==head)
			{
				return 0;
			}

	}
	
	if(solved)
	{
		int pred = prd[tail];
		while(pred!=0)
		{
			int temprow = bfsq[pred][0];
			int tempcol = bfsq[pred][1];
			maze[temprow][tempcol]='*';
			pred = prd[pred];
		}
	
	}



	delete [] prd; //deallocate predecessor
	
	delete[] bfsq;
	
	for(int i=0; i<rows; i++)
	{
		delete [] visited[i]; //first deallocation of visitied
	}
  delete[] visited; //deallocate visited
  
  if (solved)
  	return 1;
  else
  	return 0;
}


