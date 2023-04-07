#include <stdio.h>
#include <stdlib.h>
int m[50][50], s[50][50];

void print(int i, int j) {
  if (i == j)
    printf("%c", i + 64);
  else {
    printf("(");
    print(i, s[i][j]);
    print((s[i][j] + 1), j);
    printf(")");
  }
}

void main() {
  int i, n, j, l, k, q, r, u, t, v;
  printf("\nEnter the Number of Matrix: ");
  scanf("%d", &n);
  int p[n];
  for (i = 0; i <= n; i++) {
    printf("p[%d]: ", i);
    scanf("%d", &p[i]);
  }
  for (i = 1; i <= n; i++) {
    m[i][i] = 0;
  }
  for (l = 2; l <= n; l++) {
    for (i = 1; i <= n - l + 1; i++) {
      j = i + l - 1;
      m[i][j] = 999;
      for (k = i; k <= j - 1; k++) {
        q = m[i][k] + m[k + 1][j] + (p[i - 1] * p[j] * p[k]);
        printf("\nFor k= %d, m[%d][%d] = %d\n", k, i, j, q);
        if (q < m[i][j]) {
          m[i][j] = q;
          s[i][j] = k;
        }
      }
      printf("\n%d is Minimum and the value of k is %d\n", m[i][j], s[i][j]);
      printf("\nCost Matrix\n");
      for (r = 1; r <= n; r++) {
        for (u = 1; u <= n; u++) {
          printf("%d\t", m[r][u]);
        }
        printf("\n");
      }
      printf("\nSequence Matrix\n");
      for (t = 1; t <= n; t++) {
        for (v = 1; v <= n; v++) {
          printf("%d\t", s[t][v]);
        }
        printf("\n");
      }
    }
  }
  print(1, n);
  printf("\nThe Cost of the Matrix is: %d", m[1][n]);
}
