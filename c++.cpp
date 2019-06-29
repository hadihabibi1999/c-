#include <iostream> 
#include <ctime>
using namespace std ; 
 struct student 
{
char fname[15] ;
char lname[15] ; 
int age ; 
double mark ; 
}; 
 void input(student group[], int n);
 void output(student group[], int n);
 void findname(student group[], int n);
 void findage(student group[], int n);
 void sort(student group[], int n);
 void main () 
 {

 const int n=3;
 student group[n] ; 
 
 char z,f;
 bool t=true;

 while (t==true)
{
 cout<<"press 'I'nput,'O'utput,'F'ind,'S'ort,'E'xit:  "<<endl;
 cin>>z;
 switch (z)
 {
 case 'I': 
 case 'i':
  input (group, n);
  break;
 case 'O':
 case 'o':
  output(group, n);
  break;


 case 'F':
 case 'f':
  cout<<"Search 'N'ame,'A'ge: ";
  cin>>f;
 if(f=='A'||f=='a')
   findage(group,n);
 else
  if(f=='N'||f=='n') 
   findname(group,n);
 else
   cout<<"Try again!!";
  break;
 case 'S':
 case 's':
 sort(group,n);
  break;
 case 'E':
 case 'e':
  t=false;
  cout<<"GOODBYE!!!"<<endl;
  break;
 default:"No opertaion";
  break;
 }
} 
 }
  void input(student group[], int n)
{
 srand (time(0));

    for ( int i=0 ; i<n ; i++ )

  {
 cout << " first name : "  ; 
 cin>>group[i].fname ; 
 cout << " last name : "  ; 
 cin >> group[i].lname ; 
  
   group[i].age=rand()%60-10 ; 
   cout << " age is : "<< group[i].age  << endl ; 
   group[i].mark=rand()%100-10 ; 
   cout<<" mark is : " << group[i].mark << endl ; 
  }
}
   void output(student group[], int n)
{
 for (int i=0;i<n;i++)
 
   cout << group[i].fname << '\t'<<  group[i].lname << '\t'<< group[i].age << '\t' << group[i].mark <<endl;
  
}
 void findname(student group[], int n)
 {
  char fn[15];
  bool f=false;
  cout<<"Enter Name to search:";
  cin>>fn;
   for ( int i=0 ; i<n ; i++ )
    if( strcmp(group[i].fname ,fn)==0)
 {
  cout << group[i].fname << '\t'<<  group[i].lname << '\t'<< group[i].age << '\t' << group[i].mark <<endl;
  f=true;
 }
 if(f==false)
  cout<<"No matches found!! "<<endl;
}
 void findage(student group[], int n)
 {
  int fa;
  bool f=false;
  cout<<"Enter Age to search:";
  cin>>fa;
   for ( int i=0 ; i<n ; i++ )
    if(fa==group[i].age)
    {
  cout<<"Sytsem found: ";
  cout << group[i].fname << '\t'<<  group[i].lname << '\t'<< group[i].age << '\t' << group[i].mark <<endl;
   f=true;
    }
   if (f==false)
    cout<<"No matches found!! "<<endl;
 }
 void sort(student group[], int n)
 {
  bool t=true;
  student temp;
  while (t==true)
  {
   t=false;
   for(int i=0;i<n-1;i++)
    if (group[i].mark<group[i+1].mark)
    {
     temp=group[i+1];
     group[i+1]=group[i];
     group[i]=temp;
     t=true;
    }
  
  }
  
  cout<<"Sorted succesfully"<<endl;
 }