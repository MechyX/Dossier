#include<stdio.h>
void main()
{
  int n,no;
  printf("Enter The Index :\n\n\n");
  scanf("%d",&n);
  int ms[n][n];
  memset(ms,0,sizeof(ms));
  int i=n/2;
  int j=n-1;
  
  for(no=1;no<=n*n;)
  {
    
    if(i==-1 && j==n)
    {   
        i=0;
        j=n-2;
    }
    
    else
    {
      
      if(j==n)
        j=0;
      
      if(i<0)
        i=n-1;

    }
    
    if(ms[i][j])
    {
          j-=2;
          i++;
          continue;
    }
     
    else
      ms[i][j]=no++;
    
    i--;
    j++;
  }
      

for(i=0;i<n;i++)
{    
  for(j=0;j<n;j++)
    {
        printf("%d ",ms[i][j]);
    } 
  printf("\n");
}     
      
}  
      
      
      
      
      
      
      
      
      
