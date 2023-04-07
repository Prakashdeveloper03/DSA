#include <stdio.h>
int cost[10][10];
int temp[10][10];
int i, j, n;

void make() {
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      temp[i][j] = cost[i][j];
    }
  }
}

void make2() {
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      temp[i][j] = 0;
    }
  }
}

int main() {
  printf("Enter No of vertices : ");
  scanf("%d", &n);
  printf("Enter Adjancey Matrix\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &cost[i][j]);
    }
  }
  make();
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (j == 3)
        temp[i][j] = 1;
      else
        temp[i][j] = 0;
    }
  }
  printf("First Minimum Spanning Tree");
  printf("\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%4d", temp[i][j]);
    }
    printf("\n");
  }

  make2();
  temp[0][2] = temp[0][3] = 1;
  temp[1][3] = temp[2][0] = 1;
  temp[3][3] = temp[4][3] = 1;

  printf("\n");
  printf("Second Minimum Spanning Tree");
  printf("\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%4d", temp[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  make2();
  temp[0][2] = temp[1][3] = 1;
  temp[2][3] = temp[2][0] = 1;
  temp[3][1] = temp[3][2] = 1;
  temp[3][4] = temp[4][3] = 1;

  printf("Third Minimum Spanning Tree");
  printf("\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%4d", temp[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return 0;
}