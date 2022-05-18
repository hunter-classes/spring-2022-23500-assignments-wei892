#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "heap.h"

TEST_CASE("Is sorted?"){
  int arr[] = {5, 7, 6, 9, 8, 10, 12, 2};
  int s = sizeof(arr)/sizeof(arr[0]);
  heapsort(arr, s);
  for (int i = 0; i < s-1; i++){
    CHECK((arr[i] < arr[i+1]) == true);
  }


  int arr2[] = {20, 30, 44, 58, 67, 23, 98, 22};
  s = sizeof(arr2)/sizeof(arr2[0]);
  heapsort(arr2, s);
  for (int i = 0; i < s-1; i++){
    CHECK((arr2[i] < arr2[i+1]) == true);
  }

  
}
