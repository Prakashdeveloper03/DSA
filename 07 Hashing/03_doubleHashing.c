#include <stdio.h>
#include <stdlib.h>
#define n 10
int h[n];
int returnfold(int key) {
  int sum;
  while (key > 0) {
    sum = sum + key % 10;
    key = key / 10;
  }
  return sum;
}

int insert() {
  int key, value, i;
  printf("\nEnter value : ");
  scanf("%d", &value);
  for (i = 0; i < n; i++) {
    key = returnfold(key) % 7 + returnfold(key) % 7 + i;
    if (h[key] == -1) {
      h[key] = value;
      break;
    }
  }
  if (i > 0) printf("\nCollision has happened\n");
}

int display() {
  for (int i = 0; i < n; i++) printf("%d  ", h[i]);
  printf("\n");
}

int main() {
  int num;
  printf("Enter the no of elements : ");
  scanf("%d", &num);
  for (int i = 0; i < n; i++) h[i] = -1;

  for (int i = 0; i < num; i++) {
    insert();
    display();
  }
}
