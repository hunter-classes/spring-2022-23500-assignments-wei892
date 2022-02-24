#include <iostream>

int ways(int steps){

  // base case - we have no steps left
  if (steps == 0)
    return 1;

  // recursive reduction
  // how many ways can we do n-1 steps, n-2 steps and n-3 steps
  // and add them up
  int w = 0;
  for (int i = 3; i >= 1; i--){
    int r = steps - i;
    if (r >= 0)
      //std::cout << "there are :" << w << "ways" << std::endl;
      w = w + ways(r);
  }
  return w;
}

int waysTable[10000];

int ways_dyn(int steps){
  if (steps < 2){
    return 1;
  }
  else if (steps == 2){
    return 2;
  }
  else if (waysTable[steps] != 0){
    return waysTable[steps];
  }
  else{
    int temp = ways_dyn(steps-1) + ways_dyn(steps-2) + ways_dyn(steps-3);
    waysTable[steps] = temp;
    return temp;
  }

}


int main()
{
  int n;

  for (int i = 0; i < 10000; i++){
    waysTable[i] = 0;
  }
  /*
  for (n=1 ; n < 10 ; n++) {
    std::cout << n << " : " << ways(n) << "\n";
  }
  */
  
  for (n = 1; n < 40; n++){
    std::cout << n << " : " << ways_dyn(n) << std::endl;
  }
  
  return 0;
}
