#include <stdio.h>

void Merge(int L[], int start, int end, int mid);
void MergeSort(int L[], int start, int end);
void printList(int L[], int size);

int main(void){
  int L[] = { 5, 3, 8, 1, 6, 10, 7, 2, 4, 9 };
  int L_size = sizeof(L) / sizeof(L[0]);

    Merge(L, 0, 9, 4);

  printf("Given list \n");
  printList(L, L_size);

  MergeSort(L, 0, L_size - 1);

  printf("The sorted list \n");
  printList(L, L_size);
  return 0;
}

void Merge(int L[], int start, int end, int mid){
    int L1_size = mid - start + 1;
    int L1[L1_size];
    int L2_size = end - mid;
    int L2[L2_size];

    for (int i = 0; i < mid - start + 1; ++i) {
        L1[i] = L[i + start];
    }

    for (int i = 0; i < end - mid; ++i) {
        L2[i] = L[i + mid + 1];
    }

    int i = 0;
    int j = 0;

    while (i < L1_size && j < L2_size){
        if (L1[i] <= L2[j]){
            L[start + i + j] = L1[i];
            i++;
        }else{
            L[start + i + j] = L2[j];
            j++;
        }
    }

    if (i == L1_size){
        for (int k = j; k <= end - mid - 1; ++k) {
            L[start + i + k] = L2[k];
        }
    }else{
        for (int k = i; k <= mid - start; ++k) {
            L[start + j + k] = L1[k];
        }
    }
}

void MergeSort(int L[], int start, int end){
    if (start < end){
        // Rounds towards 0.
        int mid = (start + end) / 2;
        MergeSort(L, start, mid);
        MergeSort(L, mid + 1, end);
        Merge(L, start, end, mid);
    }
}

void printList(int L[], int size){
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", L[i]);
  printf("\n");
}
