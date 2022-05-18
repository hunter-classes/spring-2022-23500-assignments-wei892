#include <iostream>
#include "heap.h"
//referencing geeks for geeks


void heapify(int arr[], int size, int index){
  int max = index; //set i as the current max, it will also be considered the root
  int left = (2*index)+1;
  int right = (2*index)+2;

  //check if left and right are not out of array bounds
  //check if they are greater than the current max value
  //if they are, replace max with them
  if (left < size && arr[left] > arr[max]){
    max = left;
  }
  if (right < size && arr[right] > arr[max]){
    max = right;
  }
  
  //if the largest is not the root, switch
  //call recusively
  if (max != index){
    int temp = arr[index];
    arr[index] = arr[max];
    arr[max] = temp;

    //swap(arr[index], arr[max]);
    //recursive call
    heapify(arr, size, max);
  }
}

void buildHeap(int arr[], int size){

  //find the number at the center of the array
  int start = (size/2)-1;
  
  //tranverse from center to beginning
  for (int i = start; i>=0; i--){
    heapify(arr, size, i);
  }

}

void printHeap(int arr[], int size){
  for (int i = 0; i < size; i++){
    std::cout << std::to_string(arr[i]) + " ";
  }
  std::cout << std::endl;
} 


void heapsort(int arr[], int size){
  buildHeap(arr, size);

  for (int i = 1; i < size; i++){
    int temp = arr[0];
    arr[0] = arr[size-i];
    arr[size-i] = temp;

    heapify(arr, size-i, 0);
  }
}

