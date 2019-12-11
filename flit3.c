#include <stdlib.h>
#include <stdio.h>


int size = 0;
int** heap;
void siftUp(int v) 
{
 while (v > 0 && heap[v][1] > heap[(v - 1) / 2][1]) 
 {
	int *t = heap[v];
	heap[v] = heap[(v - 1) / 2];
	heap[(v - 1) / 2] = t;
	v = (v - 1) / 2;
 }
}
void siftDown(int v) 
{
  while (2*v+1 < size) 
  {
   int left = 2*v + 1;
   int right = 2*v + 2;
   int maxCh = left;
   if (right < size && heap[right][1] > heap[left][1])
   maxCh = right;
   if (heap[v][1] >= heap[maxCh][1])
   return;
   int *t = heap[v];
   heap[v] = heap[maxCh];
   heap[maxCh] = t;
   v = maxCh;
}
}
void insert(int* args) 
{
 heap[size++] = args;
 siftUp(size - 1);
}
int* pop() 
{
 if (size == 0) 
	 return NULL;
 int* temp = heap[0];
 heap[0] = heap[--size];
 heap[size] = NULL;
 siftDown(0);
return temp;
}


int main() 
{
 printf("enter ammount of apexes: ");
 int n;
 scanf("%d", &n);
 printf("Enter the adjacency matrix for this graph without loops:\n");
 int **matrix = (int**)malloc(n*sizeof(int*)); //
 for (int i = 0; i < n; i++) // объявление массива под матрицу
 matrix[i] = (int* )malloc(n*sizeof(int)); //
 for (int i = 0; i < n; i++)
 for (int j = 0; j < n; j++) {
 scanf("%d", &matrix[i][j]); // считываем
 matrix[j][i] = matrix[i][j]; //для условия зеркального(неориентированного)
if (i==j) matrix[i][j] = 0; // удаление петель
}
int **vert = (int**)malloc(n*sizeof(int*)); // массив для вершин,где [x][0] - номер вершины, [x][1] - ее степень [x][2] удалена ли она в графе
heap = (int**)malloc(n*sizeof(int*)); //для сортировки
for (int i = 0; i < n; i++)
vert[i] = (int*)malloc(3*sizeof(int));
for (int i = 0; i < n; i++)
for (int j = 0; j < 3; j++)
vert[i][j] = 0;
printf("Set the apex to delete, apexes are numbered from zero: ");
int d1;
scanf("%d", &d1);
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
if (i==d1||j==d1)
matrix[i][j] = 0;
for (int i = 0; i < n; i++) {
vert[i][0] = i;
for (int j = 0; j < n; j++)
if(matrix[i][j]!=0) vert[i][1]++; //считаем степени
}
 vert[d1][2] = -1; // помечаем удаленной
 printf("Final matrix: \n");
for (int i = 0; i < n; i++) 
{
 for (int j = 0; j < n; j++)
 printf("%d ", matrix[i][j]);
 printf("\n");
}
printf("List of apexes and their degrees:\n");
for (int i = 0; i < n; i++)
if (vert[i][2] != -1)
printf("%d. Apex %d degree %d\n", i, vert[i][0], vert[i][1]);
printf("Degree sorting...\n");
for (int i = 0; i < n; i++)
insert(vert[i]);
for (int i = 0; i < n; i++){
int *t = pop();
if (t[2]!=-1)
printf("%d. Apex %d degree %d\n", i, t[0], t[1]);
}
}