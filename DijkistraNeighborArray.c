#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>

int n, i, j;

int minDistance(int dist[], bool Setter[])
{ // Calculating distance

  int minimum = INT_MAX, min_index, i;
  for (i = 0; i < n; i++)
  {
    if (Setter[i] == false && dist[i] <= minimum)
    {
      minimum = dist[i], min_index = i;
    }
  }
  return min_index;
}

void printPath(int parent[], int j)
{ // Displaying the path
  if (parent[j] == (-1))
  {
    return;
  }
  printPath(parent, parent[j]);
  printf("%d ", j);
}

int printSolution(int dist[], int src, int parent[], int rad, int l)
{ // Displaying the final result
  int i;
  printf("\nVertex\t\tDistance from Source\tUsed Path\n");
  for (i = 0; i < n; i++)
  {
    if (dist[i] <= rad)
    { // Checking if the vertex position is in the rad
      printf("\n%d -> %d\t\t%d\t\t\t%d ", src, (i + 1), dist[i], src);
      printPath(parent, i);
    }
    else
    {
      printf("\n%d is unreachable %d", (i + 1), dist[i]);
    }
  }
}
void fastpath(int a[n][n], int src, int rad, int l)
{ // Finding the quickest path
  int i, j, dist[n], parent[n];
  bool Setter[n];
  for (i = 0; i < n; i++)
  {
    parent[i] = -1;
    dist[i] = INT_MAX;
    Setter[i] = false;
  }
  dist[src - 1] = 0;
  for (i = 0; i < n; i++)
  {
    int u = minDistance(dist, Setter);
    Setter[u] = true;
    for (j = 0; j < n; j++)
    {
      if (!Setter[j] && a[u][j] && dist[u] + a[u][j] < dist[j])
      {
        parent[j] = u;
        dist[j] = dist[u] + a[u][j];
      }
    }
  }
  printSolution(dist, src, parent, rad, l);
}

int main(int argc, char const *argv[])
{
  int l, rad, source;
  printf("Input size of Square\n");
  scanf("%d", &l);
  printf("Size of Square = %d x %d\n", l, l);
  printf("Enter the number of vertices:");
  scanf("%d", &n);
  int a[n][n];
  srand(time(NULL));
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (i == j)
      {
        a[i][j] = 0;
      }
      else
      {
        a[i][j] = rand() % l;
      }
    }
  }
  printf("Input Radius\n");
  scanf("%d", &rad);
  printf("Input starting vertex\n");
  scanf("%d", &source);
  clock_t start = clock();
  fastpath(a, source, rad, l);
  clock_t end = clock();
  ; // Finishing Clock
  double mseconds = (double)(end - start) / CLOCKS_PER_SEC;
  printf("\nTime Elapsed: %lf (milliseconds)", mseconds * 1000); // Displaying time in milliseconds

  return 0;
}
