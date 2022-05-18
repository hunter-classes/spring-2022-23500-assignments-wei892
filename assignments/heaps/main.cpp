#include <iostream>
#include "heap.h"

int main(){
  int arr[] = {2, 9, 10, 8, 23, 12, 7, 5, 17, 20};
  int size = sizeof(arr)/sizeof(arr[0]);
  printHeap(arr, size);
  //std::cout << std::to_string(size);
  heapSort(arr, size);
  printHeap(arr, size);
  return 0;
}
