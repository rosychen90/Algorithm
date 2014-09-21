#include <fstream>
#include <iostream>
#include <algorithm>
 
 using namespace std;
 
 int changeCoins(int *T, int n, int v);
 
 int main()
 {
     ifstream in("input.txt");
     ofstream out("output.txt");
 
     int n;
     int v;
 
     in>>n;
     int *T=new int[n];
     for(int i=0;i<n;i++)
     {
         in>>T[i];
     }
 
     in>>v;
 
     int result=changeCoins(T,n,v);
     
     cout<<result<<endl;
 
     out<<result;
 
     in.close();
     out.close();
 
     return 1;
 }
 
 
 int changeCoins(int *T, int n, int v)
 {
     //先对3个硬币按面值进行排序
     sort(T,T+n);
     int **c=new int*[n];
    for(int m=0;m<n;m++){
     c[m]=new int[v+1];
     }
     //初始化第一行,只有一个硬币时的情况
    for(int i=0;i<=v;i++)
         if(i%T[0]==0)
             c[0][i]=i/T[0];
         else
             c[0][i]=INT_MAX;
     //从第二行开始
     for(int j=1;j<n;j++)
         for(int k=0;k<=v;k++)
                   //新加进来的硬币大于要找的钱，用不到这个硬币，所以还是跟上一行的一样
             if(k<T[j])
                 c[j][k]=c[j-1][k];
             else
                 c[j][k]=c[j-1][k]<c[j][k-T[j]]+1?c[j-1][k]:c[j][k-T[j]]+1;
     return c[n-1][v];
 
 
     delete[] c;
 }
