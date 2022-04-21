#include<stdio.h> 
#include<string.h>
#include<ctype.h>

int n,m1=0,m2=0,p,i=0,j=0;
char a[10][10],followResult[10], firstResult[10];
void follow(char c);
void first(char c);
char first1(char c);
void addToResult(char);
void addToResult1(char);

int main()
{
 	int choose;
 	int i;
 	char c,ch;
 	printf("Total number of productions: ");
	scanf("%d", &n);
 	printf(" Enter %d productions \n", n);
 	for(i=0;i<n;i++)
 	{
  		scanf("%s%c",a[i],&ch);
  	}
  	
  	while(1){
  	
  	printf("Enter your choice 1 for first 2 for follow :\n");
  	scanf("%d", &choose);
  	
  	if(choose==1){
  	
  	  m1=0;
	  printf("first of which Non Termial -->");
	  scanf(" %c",&c);
	  first(c);
	  printf("FIRST(%c) = { ",c);
	  for(i=0;i<m1;i++)
	  {
	   printf("%c ",firstResult[i]);
	  }
	  printf(" }\n");
  	
  	}
  	else if(choose==2){
  	
  		  m2=0;
		  printf("follow of which Non Termial -->");
		  scanf(" %c",&c);
		  follow(c);
		  printf("FOLLOW(%c) = { ",c);
		  for(i=0;i<m2;i++)
		  {
		   printf("%c ",followResult[i]);
		  }
		  printf(" }\n");
  	
  	}
  	}
}
void follow(char c)
{
    if(a[0][0]==c)
    {
    addToResult1('$');
    }
 for(i=0;i<n;i++)
 {
  for(j=2;j<strlen(a[i]);j++)
  {
   if(a[i][j]==c)
   {
    if(a[i][j+1]!='\0')
    {
    addToResult1(first1(a[i][j+1]));
    }
    if(a[i][j+1]=='\0'&&c!=a[i][0])
    {
     follow(a[i][0]);
     }
   }
  }
 }
}
void first(char c)
{
      		int k;
                 if(!(isupper(c)))
          	{
                     addToResult(c);
                }
                 for(k=0;k<n;k++)
                 {
                 if(a[k][0]==c)
                 {
                 if(a[k][2]=='$') {
                 	follow(a[i][0]);
                 }
                 else if(islower(a[k][2]))
                   {
                     addToResult(a[k][2]);
                   }
                 else 
                 {
                 first(a[k][2]);
                 }
                 }
                 }
}

char first1(char c)
{
      		int k;
                 if(!(isupper(c)))
          	{
                     return c;
                }
                 for(k=0;k<n;k++)
                 {
                 if(a[k][0]==c)
                 {
                 if(a[k][2]=='$') {
                 	follow(a[i][0]);
                 }
                 else if(islower(a[k][2]))
                   {
                     return  a[k][2];
                   }
                 else 
                 {
                 first(a[k][2]);
                 }
                 }
                 }
}

void  addToResult(char c)
{
    int i;
    for( i=0;i<=m1;i++)
        if(firstResult[i]==c)
            return;
   firstResult[m1++]=c;
}

void  addToResult1(char c)
{
    int i;
    for( i=0;i<=m2;i++)
        if(followResult[i]==c)
            return;
   followResult[m2++]=c;
}
