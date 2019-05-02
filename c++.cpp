#include <iostream> 
#include <cstring>
using namespace std ; 
 int ctoi ( char *x , int &i )  ;
void main () 
{
 int num1, num2, num3,k, numofplus=0; //For this example: num1 will be 46, num2 will be 23, sign will be + 
 char sign1, sign2 ; //(sign1 is +) (sign2 is <)
 char n=10 ; 
 
char *x = new char [n] ; 
cout << " Enter your equation: " ; 
cin >> x ; 

  num1= ctoi(x,k) ; // Answer is num1=46, k=2 k is the number of digits in function it was i
  x+=k ; //it will move the pointer to the sign (+)
  numofplus+=k;//how much pluses we have till the end of main we need to collect this numbers into numofplus
  sign1=*x ; //save plus symbol (+) into sign varriable 
  x++ ; //will go to next number after (+)
  numofplus++;
  num2= ctoi(x,k) ;//Answer is num2=23, k=2
  x+=k ;// it will move the pointer to (<)
  numofplus+=k;
  sign2=*x;//save plus symbol (<) into sign varriable
  x++;//its on the answer
  //numofplus++; after 2 row we have x-- so we dont need ++
  num3= ctoi(x,k);//Answer is num3=195, k=3
  x--; //go back to the sign2 (<)
 
  int leftpart=0;

   switch ( sign1 )
   {
   case '+' : leftpart=num1+num2  ; 
    break ; 
   case '-' : leftpart=num1-num2  ; 
    break ; 
   case '*' : leftpart=num1*num2  ; 
    break ; 
   case '/' : leftpart=num1/num2  ; 
    break ; 

   default : cout<< " no operation " << endl; 
  
   }



   switch ( sign2 )
   {
   case '<' : if(leftpart<num3)
      cout<<"Congrats Brohhhh!!!!!"<<endl;
     else if(leftpart > num3)
     {
       cout<<"Equation is wrong. "<<endl;
       *x='>';//our *x pointer was on the second sign2 (<) (we want to change this sign)
     }
     
     else {
      cout<<"Equation is wrong. "<<endl;
     *x='=';
     }
 break;
   case '>' :  if(leftpart>num3)
      cout<<"Congrats Brohhhh!!!!!"<<endl;
     else if(leftpart < num3)
     {
       cout<<"Equation is wrong. "<<endl;
       *x='<';
     }
     
     else
      {
       cout<<"Equation is wrong. "<<endl;
     *x='=';
     }
 break;
   case '=' :  if(leftpart==num3)
      cout<<"Congrats Brohhhh!!!!!"<<endl;
     else if(leftpart < num3)
     {
       cout<<"Equation is wrong. "<<endl;
       *x='<';
     }
     
     else {
      cout<<"Equation is wrong. "<<endl;
     *x='>';
     }
 break;

   default : cout<< "Stupid operation broohhhh."<<endl; 
   }
   x-=numofplus;//x-= move the pointer of x into first element of array
   cout<<"x:  "<<x<<endl;
   
  delete []x;
}
 int ctoi ( char *x , int &i )//*x is char array , i will be the number of digits of current number 
                            //i is 2 cz we have 46 (2 numbers)
 {
 int  z=0 ; //Ex: z=46 is the curent number which will be cut from array
   i=0 ; 

 while ( *(x+i) >= 48 && *(x+i) <= 57 ) //while the current element in array is number 
  {
   z=z*10 +((int) *(x+i)-48)  ; 
   //z=converted to int number (it will b the code of this number) Miunes 48 (code of zero '0') 
   
   i++ ;
   //(go to next element of array)
  } 
return z ;  //what ever you cut it will return FE:(46)
 }