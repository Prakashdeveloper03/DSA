#include <stdio.h>
int heap[50], gap = 1;
int swap(int *x, int *y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

int heapify(int n, int i) {
  int largest = i, left = (2 * i) + 1, right = (2 * i) + 2;
  if (left < n && heap[left] < heap[largest]) largest = left;
  if (right < n && heap[right] < heap[largest]) largest = right;
  if (largest != i) {
    swap(&heap[i], &heap[largest]);
    heapify(n, largest);
  }
}

int insert(int n) {
  int value, j;
  printf("\nEnter the value = ");
  scanf("%d", &value);
  heap[n] = value;
  n++;
  for (j = n / 2 - 1; j >= 0; j--) heapify(n, j);
  return n;
}

int display(int n, int i, int space) {
  int left, right, j;
  if (i < n) {
    space = space + gap;
    left = (2 * i) + 1;
    right = (2 * i) + 2;
    display(n, right, space);
    printf("\n");
    for (j = space; j > 0; j--) printf("\t");
    printf("%d\n", heap[i]);
    display(n, left, space);
  }
}

int main() {
  int n = 0, num;
  printf("Enter the number of elements to be inserted : ");
  scanf("%d", &num);
  printf("Min Heap");
  for (int i = 0; i < num; i++) {
    n = insert(n);
    display(n, 0, 0);
  }
}
