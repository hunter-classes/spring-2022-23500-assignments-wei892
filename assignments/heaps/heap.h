#pragma once

void heapify(int arr[], int size, int index);
void buildHeap(int arr[], int size);
void printHeap(int arr[], int size);
void heapSort(int arr[], int size);
//void heapsort(int arr[], int size)

//a container for objects that have keys
//example: opject is employment records and key is id

//2 opperations
//insert -  add a new object to heap
//extract min - remove an object in heap with a minimum key value
//heap sort
//running time Ologn

//heapify - initialize a heap in linear time

//use a heap if u notice prgram is doing repeated minimal applications (common use)

//heap sort
//insert all elements into an array
//extract the minimun one by one
