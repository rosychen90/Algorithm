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
     //�ȶ�3��Ӳ�Ұ���ֵ��������
     sort(T,T+n);
     int **c=new int*[n];
    for(int m=0;m<n;m++){
     c[m]=new int[v+1];
     }
     //��ʼ����һ��,ֻ��һ��Ӳ��ʱ�����
    for(int i=0;i<=v;i++)
         if(i%T[0]==0)
             c[0][i]=i/T[0];
         else
             c[0][i]=INT_MAX;
     //�ӵڶ��п�ʼ
     for(int j=1;j<n;j++)
         for(int k=0;k<=v;k++)
                   //�¼ӽ�����Ӳ�Ҵ���Ҫ�ҵ�Ǯ���ò������Ӳ�ң����Ի��Ǹ���һ�е�һ��
             if(k<T[j])
                 c[j][k]=c[j-1][k];
             else
                 c[j][k]=c[j-1][k]<c[j][k-T[j]]+1?c[j-1][k]:c[j][k-T[j]]+1;
     return c[n-1][v];
 
 
     delete[] c;
 }
