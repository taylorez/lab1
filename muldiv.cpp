#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int check(int n);
struct muldiv_entry** generate_tables(int n);
void print_tables(struct muldiv_entry** tables, int n);
void free_tables(struct muldiv_entry** tables, int n);

struct muldiv_entry {
   int mul;
   float div;
};

int main(int argc, char *argv[]){
   int n = atoi(argv[1]);
   check(n);
   muldiv_entry** t = generate_tables(n);
   print_tables(t,n);

}

int check(int n){
   if(n >= 0)
      return 1;
   else
      return 0;
}

struct muldiv_entry** generate_tables(int n){
   muldiv_entry** array = new muldiv_entry* [n];
   for(int i=0;i<n;i++)
      array[i] = new muldiv_entry[n];
   for(int y = 0;y<n;y++){
      for(int t = 0;t<n;t++){
	 array[y][t].mul = ((y+1) * t+1);
	 array[y][t].div = ((float(y)+1) / (float(t)+1));
      }
   }
   return array;
}

void print_tables(struct muldiv_entry** tables, int n){
   for(int i = 0;i < n;i++){
      cout << "" << endl;
      for(int g = 0;g < n;g++){
	 cout << tables[i][g].mul << " " ;
      
      }
   }
   for(int p = 0;p<n;p++){
      cout << "" << endl;
      for(int f = 0;f < n;f++){
	 cout << tables[p][f].div << " " ;

      }
   }
}

void free_tables(struct muldiv_entry** tables, int n){
   for(int g = 0; g < n;g++){
      delete[] tables[g];
   }
   delete[] tables;
}

