#include <iostream>
#include <fstream>
 using namespace std;
 
 int findMedian(int*, int*, int);
 
 int main()
  {
     ifstream in("input.txt");
     ofstream out("output.txt");
 
     int n;
     int *x,*y;
 
     in>>n;
     x=new int[n];
     y=new int[n];
 
     for(int i=0;i<n;i++)
         in>>x[i];
     for(i=0;i<n;i++)
         in>>y[i];
 
     int median=findMedian(x, y, n);
 
     cout<<median<<endl;
 
     out<<median;
 
     in.close();
     out.close();
 
     return 1;
 }
 
 int findMedian(int* x, int* y, int n)
  {
     if(n==1)
         return *x <= *y? *x:*y;
     
     int m=(n-1)/2;    //中位数位置
     int p=m+1;    //中位数小者子数字起始位置
 
     if(n%2!=0)    //n为奇数
         p--;
 
     if(*(x+m)==*(y+m))
         return *(x+m);
     else if(*(x+m)<*(y+m))
         return findMedian(x+p,y,m+1);
     else
         return findMedian(x,y+p,m+1);
 }
