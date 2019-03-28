
//copy the elements from x to y which are into [a;b] range
#include <iostream>
#include <ctime>
using namespace std;

void input (int **matrix,int n , int m);
void output (int **matrix,int n , int m);
int calc (int **matrix,int n , int m,int k,int a,int b);
void copy (int **matrix,int n , int m,int k,int a,int b,int *y);
void outarray (int *y,int k);


int main(){
    srand(time(0));
    
     char x;
    while(true){
        
    
    int n,m;
    cout<<"Row:";
    cin>>n;
    cout<<"Column:";
    cin>>m;
    
    int a; cout<<"a?";  cin>>a;
    int b; cout<<"b?";  cin>>b;
    
        cout<<"fo getting started calculation press number zero "<<endl;
        cin>>x;
        
    switch(x){
        case '0':{
            int ** matrix = new int *[n];
            for (int i=0 ; i<n ;i++)
                matrix [i]= new int [m];
            
            cout<<endl;
            
            input(matrix,n,m);
            output(matrix,m,n);
            cout<<endl;
            int k = calc(matrix,m,n,k,a,b);
            int *y = new int [k];
            copy(matrix,n,m,k,a,b,y);
            outarray(y,k);
            break;
        }
        
        default:
            cout<<"error"<<endl;;
        }
        
  
    }
    
}




void input (int **matrix,int n , int m){
    for (int i=0; i<n;i++)
        for (int j=0; j<m;j++)
            *(*(matrix + i)+j)=rand()%9+1;
    
}

void output (int **matrix,int n , int m){
    for (int i=0; i<n;i++){
        for (int j=0; j<m;j++)
            cout<< *(*(matrix + i)+j)<<" ";
        cout<<endl;
    }
}


int calc (int **matrix ,int n , int m ,int k,int a,int b) {
    k=0;
    for (int i=0; i<n;i++)
        for (int j=0; j<m;j++)
            if (*(*(matrix + i)+j) > a && *(*(matrix + i)+j) < b )
                k++;
    return k;
}


void copy (int **matrix,int n , int m,int k,int a,int b,int *y){
    int l=0;
    for (int i=0; i<n;i++)
        for (int j=0; j<m ;j++)
            if ( (*(*(matrix + i)+j) > a) && (*(*(matrix + i)+j) < b )){
                *(y+l)=*(*(matrix+i)+j);
                l++;
            }
}

void outarray (int *y,int k){
    for(int i=0;i<k;i++)
        cout<<*(y+i)<<" ";
    cout<<endl;
}
