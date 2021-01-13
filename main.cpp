#include <iostream>

using namespace std;

int main()
{
  
  int bits_array[32] = {0}; 
  int integer, i = 0, k = 0;
  char strand_array[16];
  string strand;

  cout << "Input your integer" << endl;
  cin >> integer;	// input of integer																				   

  while (integer > 0)	// converting interger to binary
  {
    bits_array[31-i] = integer%2;
    integer = integer/2;
    i++;
  }
  
  cout << endl << "Binary format of integer" << endl;	

  if(i%2!=0){cout<<"0";}

  for(int j=0; j<32; j++)	// printing binary form of integer
  {
    if (bits_array[j]==1) {k++;}
    if (k>0)
    {
      cout << bits_array[j];
    }
  }		
  
  i=0; 
  k=0;

  for(int j=0; j<32; j+=2)	  // storing binary to DNA bases 
  {
         if (bits_array[j] == 0 && bits_array[j+1] == 0) {strand_array[i] = 'A';}	// A = 00
    else if (bits_array[j] == 1 && bits_array[j+1] == 1) {strand_array[i] = 'T';}	// B = 11
    else if (bits_array[j] == 0 && bits_array[j+1] == 1) {strand_array[i] = 'G';}	// G = 01
    else if (bits_array[j] == 1 && bits_array[j+1] == 0) {strand_array[i] = 'C';}	// C = 10
   i++;    
  }
  

  cout << endl << endl << "You want a DNA strand or RNA strand? (Enter the word idiot!)" << endl;
  cin >> strand;	// taking string as a input

  if (strand[0] == 'D' && strand[1] == 'N' && strand[2] == 'A')	   // printing DNA strand 
  {
    for(int j=0; j<16; j++)
    {
      if (strand_array[j] == 'T' || strand_array[j] == 'G' || strand_array[j] == 'C') {k++;}
      if (k>0)
      {
        cout << strand_array[j];	
      }
    }
  }

  else if (strand[0] == 'R' && strand[1] == 'N' && strand[2] == 'A')	// printing RNA strand
  {
    for(int j=0; j<16; j++)
    {
      if (strand_array[j] == 'T' || strand_array[j] == 'G' || strand_array[j] == 'C') {k++;}
      if (k>0)
      { 
        if (strand_array[j] != 'T') {cout << strand_array[j];}	  // converting DNA base to RNA base
        else {cout << "U";} 
      }
    }
  }
  
  else cout << "Please get lost! I won't even loop it for you"  << endl;	// output of false input 
  

    return 0;
}
