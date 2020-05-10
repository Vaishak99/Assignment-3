#include <iostream>
# include<fstream>

using namespace std;
//FIND THE MINIMUM VERTEX
int findMinVertex(int* distance,bool* visited,int n)
{
	int minVertex = -1;
	for(int i = 0; i<n; i++)
	{
		if((!visited[i]) && (minVertex==-1 || (distance[i] < distance[minVertex])))
		{
			minVertex = i;
		}
	}
	return minVertex;
}
//MAIN PROGRAM TO PERFORM DIJKSTRA
void dijkstra(int** edges, int n)
{
	int* distance = new int[n];
	bool* visited = new bool[n];

	for(int i = 0; i<n; i++)
	{
	        distance[i] = INT8_MAX;
	        visited[i] = false;
	}

	distance[0] = 0;

	for(int i = 0; i<n-1; i++)
	{
		int minVertex = findMinVertex(distance,visited,n);
		visited[minVertex] = true;
		for(int j=0;j<n;j++)
		{
			if(edges[minVertex][j] != 0 && (!visited[j]))
			{
				int dist = distance[minVertex] + edges[minVertex][j];
				if(dist < distance[j])
				{
					distance[j] = dist;
				}
		        }
		}
	}
	cout<<"Distances are\n";
	for(int i= 0; i<n; i++)
	{
        	cout<<i<<"\t"<< distance[i]<< endl;
	}
	delete []visited;
	delete []distance;
}
//DRIVER PROGRAM
int main(int argc,char* argv[]) 
{
	if(argc != 2)
	{
		cout<<"Press enter valid file name\n";
		exit(0);
	}
       	int n,e,x,i = 0,count = 0,j,arr[100];
      	ifstream inFile;
   	inFile.open(argv[1]); //OPENING THE FILE
	// CHECKING THE FILE IS EMPTY
	if(!inFile)		
	{
		cout<<"File is empty\n";
		exit(0);
	}
	//SCANNING THE DATA FROM THE FILE
	while (inFile >> x)	
	{
		if (i == 0)
			n = x;
		else if(i ==1)
			e = x;
		else
		{
			j = i-2;
			count++;
			arr[j] = x;
		}
		i++;
       	}
	inFile.close();			//CLOSING THE FILE
   	int** edges = new int*[n];
       	for (int i = 0; i<n; i++)
	{
               	edges[i] = new int[n];
	       	for (int j = 0; j < n; j++)
           		edges[i][j] = 0;
	}
	cout<<"Info from file\n";
	cout<<"NodeA\tNodeB\tWeight\n";
	for(i = 0;i < count;i += 3)
		cout<<arr[i]<<"\t"<<arr[i+1]<<"\t"<<arr[i+2]<<"\n";
	int f,s,weight;
	for(j = 0;j < count;j +=3 )
	{
		f = arr[j];
		s = arr[j+1];
		weight = arr[j+2];
		edges[f][s] = weight;
		edges[s][f] = weight;
	}
	cout<< endl;
	// CALLING TO PERFORM DIJKSTRA
	dijkstra(edges,n);	
	for (int i = 0; i<n; i++)
       		delete [] edges[i];
	delete [] edges;
}
