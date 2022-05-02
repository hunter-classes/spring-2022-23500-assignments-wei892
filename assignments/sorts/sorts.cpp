#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>
#include <climits>

void print_vector(std::vector<int> a){
  for (auto i : a){
    std::cout << i << ", ";
  }
  std::cout << "\n";
}


int find_min_index(std::vector<int> a,
		   int start_index,
		   int stop_index){
  int min_index = start_index;
  int i;
  for (i = start_index ; i < stop_index; i++){
    if (a[i] < a[min_index]){
      min_index = i;
    }
  }
  return min_index;
}

std::vector<int> ssort(std::vector<int> a){
  int i,min_index,j,tmp;
  int len = a.size();
  // loop through the vector from 0 to end
  for (i=0;i<len; i++){
    // find the smallest value from i to the end
    min_index = find_min_index(a,i,len);
    
    // swap it into position i
    tmp = a[i];
    a[i] = a[min_index];
    a[min_index] = tmp;
    
  }
  return a;
}

/*
  left and right are already sorted
  merged should be a new vector with all the
  elements in left and right, and result
  should be sorted
*/
std::vector<int> merge(std::vector<int> left,
		       std::vector<int> right){
  std::vector<int> merged;

  // your code here
  int l = 0;
  int r = 0;

  while (l < left.size() && r < right.size()){
    if (left[l] < right[r]){
      merged.push_back(left[l]);
      l++;
    }
    else {
      merged.push_back(right[r]);
      r++;
    }
  }

  // add any extra elements in left
  while (l < left.size()){
    merged.push_back(left[l]);
    l++;
  }
  

  // add any extra elements in right
  while (r < right.size()){
    merged.push_back(right[r]);
    r++;
  }
  	 
  return merged;
}

std::vector<int> msort(std::vector<int> list){
  // base case
  // if the list is size 0 or 1 it's sorted
  // so return it
  if (list.size() < 2){
    return list;
  }
    
  // split into two halves (doesn't matter how)
  int mid = list.size() / 2;
  
  std::vector<int> a,b;

  int i;
  for (i = 0; i < mid; i++){
    a.push_back(list[i]);
  }
  
  for (i=mid;i<list.size();i++){
    b.push_back(list[i]);
  }
  
  // recursively msort the two halves
  a = msort(a);
  b = msort(b);
  
  // merge them together
  std::vector<int> sortedList = merge(a,b);
  return sortedList;
}


std::vector<int> qsort(std::vector<int> list){  
  int i, j;
  // base case
  if (list.size() <= 1){
    return list;
  }
  // select a pivot value.
  // for now, just pick list[0]
  int pivot = list[0];
  // make 2 new vectors
  std::vector<int> lower,higher;
  // copy all the values < pivot value to lower
  // copy all the values >= pivot value to higher;
  for (i=1; i < list.size(); i++){
    if (list[i] < pivot){
      lower.push_back(list[i]);
    } else {
      higher.push_back(list[i]);
    }
  }
  lower = qsort(lower);
  higher = qsort(higher);

  // copy everything back into list
  for (i=0 ; i < lower.size(); i++){
    list[i]=lower[i];
  }
  list[i] = pivot;
  i++;
  for (j=0;j<higher.size();j++){
    list[i] = higher[j];
    i++;
  }
  // return the sorted list
  return list; 
}
/*
int findPivot(std::vector<int> list, int low, int high){
  int pivot;
  int mid = list[list.size()/2];
}
*/
/*
void qsort2(std::vector<int> list, int low, int high){
  //std::cout << "low: " << low << " high: " << high << std::endl;
  //base case
  if (list.size() <= 1){
    return;
  }
  

  //std::cout << "finding pivot" << std::endl;
  int mid =  low + ((high-low) / 2);
  int pivot = list[mid];
  //int pivot = findPivot(list, low, high);
  
  
  //std::cout << "pivot found" <<std::endl;
    int i = low;
    int j = high;

    //std::cout << "pivot: " << pivot << std::endl;

    //std::cout << "Loop" << std::endl;
    while (i<=j){
      while (list[i] <  pivot){
	i++;
	//std::cout << "i = " << i << ": " <<list[i] << std::endl;
      }
      while (list[j] >  pivot){
	j--;
	//std::cout << "j= " << j << ": " <<list[j] << std::endl;
      }
      if (i <= j){
	//std::cout << "before switch -> i: " <<list[i] << std::endl;
	//std::cout << "before switch -> j: " << list[j] << std::endl;
	
	int temp = list[i];
	list[i] = list[j];
	list[j] = temp;
	i++;
	j--;

	//std::cout << "after  switch -> i: "<< i << ":"  << list[i] << std::endl;
	//std::cout << "after switch -> j: " << j << ": " << list[j] << std::endl;
      }
    }
    //std::cout << "List: " <<  std::endl;
    print_vector(list);
    if (low < high){
      qsort2(list, low, j);
      qsort2(list, j+1, high);
    }
    
    /*
    int partition = i;
    std::vector<int> lower, higher;
  
    for (int i = 0; i < partition; i++){
      lower.push_back(list[i]);
    }
    for (int i = partition; i < high; i++){
      higher.push_back(list[i]);
    }
  
    qsort2(lower, low, j);
    qsort2(higher, i, high);
    */

int partition(std::vector<int> list, int low, int high){
  int pivot = list[low];
  int i = low;
  int j = high;

  while (i < j){
    do{
      i++;
    }while (list[i] <= pivot);
    
    do{
      j--;
    }while (list[j] > pivot);
    
    if (i<j){
      int temp = list[i];
      list[i] = list[j];
      list[j] = temp;
    }
  }
  int temp = list[i];
  list[i] = list[j];
  list[j] = temp;
  return j;
}

void qsort2(std::vector<int> list, int low, int high){
  if (low < high){
    int j = partition(list, low, high);
    qsort2(list, low, j);
    qsort2(list, j+1, high);
  }
}


void print_help(char *command_name){
  std::cout << "Usage: "<< command_name;
  std::cout << " [-h|-p|-m N|-s N|-a algorithm]\n\n";
  std::cout << " -m MAX_ELEMENT_SIZE\n";
  std::cout << " -s DATA_SET_SIZE\n";
  std::cout << " -a[s|m]: s - selection, m - merge\n";
}

extern char *optarg;
/*
int main(int argc, char *argv[])
  {
    int size = 20; // default vector size
    int max_val = 100; // default max value for entries

    char algorithm = 's' ; //default to selection sort
    bool print = true; // do we print before and after sorting?
    char c;


    while ( ( c = getopt(argc, argv, "phs:m:a:")) != -1){
      
      switch (c) {
      case 'h' :
	print_help(argv[0]);
	exit(0);
	break;
      case 'p' :
	print = true;
	break;
      case 's' :
	size = std::stoi(optarg);
	break;
      case 'm' :
	max_val = std::stoi(optarg);
	break;
      case 'a':
	algorithm = optarg[0]; // or *optarg
      }
    }
    
    srand(time(nullptr));
    std::vector<int> a(size);
    int i;
    for (i=0;i<size; i++){
      a[i] = rand()%max_val;
    }
  
  
    if (print) {
      print_vector(a);
      std::cout << "\n";
    }

    std::cout << "Starting the sort!\n";
    struct timeval tp;
    
    gettimeofday(&tp,NULL);
    long start_time = tp.tv_sec *1000 + tp.tv_usec / 1000;

    if (algorithm == 's'){
      a = ssort(a);
    } else if (algorithm == 'm'){

      a = msort(a);
    } else if (algorithm == 'q'){
      a = qsort(a);
    }


    gettimeofday(&tp,NULL);
    long current_time = tp.tv_sec *1000 + tp.tv_usec / 1000;

    long elapsed = current_time - start_time;
  
    if (print) {
      print_vector(a); 
    }
    std::cout << "Algorithm: " << algorithm << "\n";
    std::cout << "Time: " << elapsed << "\n";
  

  
    return 0;
  }
*/

void timedResult(std::string sortType, bool print, std::vector<int> list){
  struct timeval tp;
  gettimeofday(&tp, NULL);
  long start_time = tp.tv_sec *1000 + tp.tv_usec/1000;

  if (sortType == "msort"){
    list = msort(list);
  }
  else if (sortType == "qsort"){
    list = qsort(list);
  }
  else if (sortType == "qsort2"){
    qsort2(list, 0, list.size()-1);
  }

  if (print)
    print_vector(list);

  gettimeofday(&tp, NULL);
  long current_time = tp.tv_sec *1000 + tp.tv_usec / 1000;
  long elapsed = current_time - start_time;
  std::cout << "Time: " << elapsed << "\n";
}


int main(){
  int max_val = 100;
  int size = 10;
  int i;

  std::cout << "Testing data:" << std::endl;
  srand(time(nullptr));

  //small data size
  std::cout << "Data set size 10" << std::endl;
  std::vector<int> a(size);

  for (int i = 0; i< size; i++){
    a[i] = rand() % max_val;
  }
  print_vector(a);
  qsort2(a, 0, 9);
  std::cout << "quick sort 2:";
  print_vector(a);
  /*
  std::cout << "vector a before q sort" << std::endl;
  print_vector(a);
  std::vector<int> a2 = a;
  std::cout << "sorting with msort" << std::endl;
  timedResult("msort", true, a2);
  std::vector<int> a3 = a;
  std::vector<int> a4 = a;
  std::cout << "sorting with qsort" <<std::endl;
  timedResult("qsort", true, a3);
  std::cout << "sorting with qsort2" << std::endl;
  timedResult("qsort2", true, a4);
  */
  
  return 0;
}
