#include "BinaryTree.h"
#include <fstream>


int main(){
  BinaryTree<char> morse;
  
  std::ifstream fisier("morse.txt");

  if(!fisier.is_open()){
    printf("Error opening the file!\n");
    return 1;
  }
   char code[100];
  char letter;
  for(;fisier >> code && fisier>>letter;){
    morse.insert((const char*)code, letter);
  }

   const char* r = morse.find(".-");
  if (r) printf("%c\n", *r);      // A
  else   printf("negasit\n");

  if (!morse.find("--")) printf("negasit\n");  // nu există
}