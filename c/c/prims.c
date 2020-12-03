


#include<iostream.h>
#include<conio.h>
#define MAX 20
struct Edges
{
	int v1,v2,wt;
};
class Prims
{
   private:
	Edges E[MAX];
	int G[MAX][MAX],S[MAX][MAX],n,noe,Visited[MAX],TV[MAX],vt1,vt2;
	void printEdges(Edges [], int);
	void sortEdges();
	int search(int [], int, int);
   public:
	Prims();
	void acceptData();
	void matToEdges();
	void findSpanning();
};

Prims :: Prims()
{
	for(int i=0;i<MAX;i++)
	for(int j=0;j<MAX;j++)
		G[i][j]=S[i][j]=0;
	for(i=0;i<MAX;i++)
		Visited[i] = 0;
	noe = 0;
}

void Prims :: acceptData()
{
	cout << "Enter No.of Vertices: ";
	cin >> n;
	for(int i=0;i<n;i++)
	{
	  for(int j=i+1; j<n; j++)
	   {
	 cout << "Enter wt of (V" << i << ", V" << j << ") edge (0-if edge doesnt exits): ";
	    cin >> G[i][j];
	    G[j][i] = G[i][j];
	    }
	}
}

void Prims :: matToEdges()
{
	for(int i=0;i<n;i++)
		for(int j=i+1; j<n; j++)
			if(G[i][j]!=0)
			{
			E[noe].v1 = i;
			E[noe].v2 = j;
			E[noe].wt = G[i][j];
			noe++;
			}
	sortEdges();
	printEdges(E,noe);
}

void Prims :: printEdges(Edges e[], int n)
{
	for(int i=0;i<n;i++)
	cout << "(V" << e[i].v1 << ",V" << e[i].v2 << ")-" << e[i].wt << endl;
}

void Prims :: sortEdges()
{
	Edges t;
	for(int i=0;i<noe;i++)
		for(int j=i+1;j<noe;j++)
			if(E[i].wt > E[j].wt)
			{
			t = E[i];
			E[i] = E[j];
			E[j] = t;
			}
}

int Prims :: search(int tv[], int v, int n)
{
	for(int i=0;i<n;i++)
		if(tv[i]==v)
			return 1;
	return 0;
}



void Prims :: findSpanning()
{
	int k=0;
	TV[k++] = 0;
	
for(int i=0;i<noe;i++)
	{
		for(int j=0;j<noe;j++)
		{
			if(!Visited[j])
			{
			vt1 = E[j].v1;
			vt2 = E[j].v2;
			if(search(TV,vt1,k) && !search(TV,vt2,k))
			{
			S[vt1][vt2] = E[j].wt;
			S[vt2][vt1] = E[j].wt;
			TV[k++] = vt2;
			Visited[j]=1;
			break;
			}
			else if(search(TV,vt2,k) && !search(TV,vt1,k))
			{
			S[vt1][vt2] = E[j].wt;
			S[vt2][vt1] = E[j].wt;
			TV[k++] = vt1;
			Visited[j]=1;
			break;
			}
			}
		}
	}
	cout << "The Spanning Tree By Prim's Algorithm..." << endl;
	for(i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(S[i][j]!=0)
		cout << "(V" << i << ",V" << j << ")-" << S[i][j] << endl;
}

void main()
{
	Prims ob;
	clrscr();
	ob.acceptData();
	ob.matToEdges();
	ob.findSpanning();
}



-------------output----------------

Enter No.of Vertices: 6

Enter wt of (V0, V1) edge (0-if edge doesnt exits): 10

Enter wt of (V0, V2) edge (0-if edge doesnt exits): 20

Enter wt of (V0, V3) edge (0-if edge doesnt exits): 0

Enter wt of (V0, V4) edge (0-if edge doesnt exits): 0

Enter wt of (V0, V5) edge (0-if edge doesnt exits): 0

Enter wt of (V1, V2) edge (0-if edge doesnt exits): 0

Enter wt of (V1, V3) edge (0-if edge doesnt exits): 5

Enter wt of (V1, V4) edge (0-if edge doesnt exits): 15

Enter wt of (V1, V5) edge (0-if edge doesnt exits): 0

Enter wt of (V2, V3) edge (0-if edge doesnt exits): 6

Enter wt of (V2, V4) edge (0-if edge doesnt exits): 20

Enter wt of (V2, V5) edge (0-if edge doesnt exits): 0

Enter wt of (V3, V4) edge (0-if edge doesnt exits): 0

Enter wt of (V3, V5) edge (0-if edge doesnt exits): 15

Enter wt of (V4, V5) edge (0-if edge doesnt exits): 20

(V1,V3)- 5
(V2,V3)- 6
(V0,V1)- 10
(V1,V4)- 15
(V3,V5)- 15
(V2,V4)- 20
(V0,V2)- 20
(V4,V5)- 20

The Spanning Tree By Prim's Algorithm...

(V0,V1)- 10
(V1,V3)- 5
(V1,V4)- 15
(V2,V3)- 6
(V3,V5)- 15