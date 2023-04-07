#include <stdio.h>
#include <stdlib.h>
#define n 11
int h[n];
int insert() {
  int i, key, c1 = 0, c2 = 2;
  float value, tempkey;
  printf("\nEnter value : ");
  scanf("%f", &value);
  tempkey = ((value * 0.681033));
  key = (int)tempkey;
  key = key / 10;
  for (i = 0; i < n; i++) {
    key = key + c1 * i + c2 * i * i;
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
