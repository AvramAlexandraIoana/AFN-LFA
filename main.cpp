#include <fstream>
#include <cstring>

using namespace std;

ifstream f("C:\\Users\\Oana\\Desktop\\LFA\\AFN\\date.in");
ofstream g("C:\\Users\\Oana\\Desktop\\LFA\\AFN\\date.out");

int x,y,z,a[101][101][101],final[101],nr,n,ok;
char t,cuv[101],st[101],cuv1;
void afn(int start,char cuv[101],int k)
{
     char x=cuv[0];
    if(final[start] && strlen(cuv)==0)
     {
              ok=1;
              g<<"ACCEPTAT";
              return;
     }
     if(strlen(cuv)!=0 && ok==0)
      for(int i=0;i<n;i++)
       if(a[start][i][x-'a'])
      {
              st[k]=x;
              strcpy(cuv,cuv+1);
              afn(i,cuv,k+1);
              for(int j=strlen(cuv);j>=1;j--)
                  cuv[j]=cuv[j-1];
            cuv[0]=st[k];

      }
}
int main()
{
     f>>x>>n;
   for(int i=0;i<x;i++)
   {
       f>>y>>z>>t;
       a[y][z][t-'a']=1;

   }
   f>>nr;
   for(int i=0;i<nr;i++)
    {
        f>>y;
        final[y]=1;
    }
   f>>cuv;
   afn(0,cuv,0);
   if(ok==0)g<<"NEACCEPTAT";
    return 0;
}
