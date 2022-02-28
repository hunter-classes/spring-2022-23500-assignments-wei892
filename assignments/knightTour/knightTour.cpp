#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <iomanip>

//list of chars to use

char knight = 'K';
char wall = '.';
char path = '#';
char visited = '_';
int count = 0;
int temp[5][5];

int loadBoard(std::string filename, std::string *board){
  std::ifstream infile(filename);
  int i = 0;
  while(std::getline(infile, board[i])){
    i++;
  }
  return i;
}

void print_Board(std::string board[], int lines){
  std::cout << "[0;0H\n";
  for (int i = 0; i < lines; i++){
    std::cout << board[i] << "\n";
  }
}


void solve(std::string board[], int lines, int row, int col, bool &solved){
  if (count == 26){
    solved = true;
    return;
  }
  
  if (board[row][col] == wall ||
      board[row][col] == knight ||
      board[row][col] == visited) {
    return;
  }

  board[row][col] = knight;
  usleep(80000);
  print_Board(board, lines);
  
  count++;
  temp[row-2][col-2] = count;

  //1st way 
  if (!solved) solve(board,lines,row+2,col+1,solved);
  //2nd 
  if (!solved) solve(board,lines,row+2,col-1,solved);
  //3rd
  if (!solved) solve(board,lines,row+1,col+2,solved);
  //4th
  if (!solved) solve(board,lines,row+1,col-2,solved);
  //5th 
  if (!solved) solve(board,lines,row-2,col-1,solved);
  //6th
  if (!solved) solve(board,lines,row-2,col+1,solved);
  //7th
  if (!solved) solve(board,lines,row-1,col-2,solved);
  //8th
  if (!solved) solve(board,lines,row-1,col+2,solved);
  
  if (!solved){
    board[row][col] = visited;
  }
}

int main(){
  std::string board[9];
  int lines;  
  lines = loadBoard("knightTour.dat", board);
  //print_Board(board, lines);
  bool solved = false;  
  solve(board, lines, 3, 3, solved);
  std::cout << std::endl;
  
  for (int i = 0; i<5; i++){
    for (int j = 0; j<5; j++){
      std:: cout << std::setw(2) << temp[i][j] << ";"; 
    }
    std::cout << std::endl;
  }
}
