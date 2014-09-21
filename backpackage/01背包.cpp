#include<iostream>
#include<fstream>
using namespace std;


 

 

 

class Knap

{

friend int Knapsack(int p[],int w[],int c,int n );

 

public:

       void print()

       {

        for(int m=1;m<=n;m++)

   {

    cout<<bestx[m]<<" ";
   }

   cout<<endl;

       };

 

private:

  int Bound(int i);

  void Backtrack(int i);

 

  int c;//背包容量

  int n; //物品数

  int *w;//物品重量数组

  int *p;//物品价值数组

  int cw;//当前重量

  int cp;//当前价值

  int bestp;//当前最优值

  int *bestx;//当前最优解

  int *x;//当前解

 

};

 

 

int Knap::Bound(int i)

{

 //计算上界

       int cleft=c-cw;//剩余容量

       int b=cp;

       //以物品单位重量价值递减序装入物品

       while(i<=n&&w[i]<=cleft)

       {

         cleft-=w[i];

         b+=p[i];

         i++;

       }

       //装满背包

       if(i<=n)

              b+=p[i]/w[i]*cleft;

       return b;

}

 

 

void Knap::Backtrack(int i)

{

  if(i>n)

  {

    if(bestp<cp)

       {

           for(int j=1;j<=n;j++)

                   bestx[j]=x[j];

           bestp=cp;

       }

       return;

  }

  if(cw+w[i]<=c) //搜索左子树

  {             

      x[i]=1;

         cw+=w[i];

         cp+=p[i];

         Backtrack(i+1);

         cw-=w[i];

         cp-=p[i];

  }

         if(Bound(i+1)>bestp)//搜索右子树

         {

             x[i]=0;

                Backtrack(i+1);

         }

  

}

 

 

class Object

{

 friend int Knapsack(int p[],int w[],int c,int n);

public:

       int operator<=(Object a)const

       {

        return (d>=a.d);

       }

private:

       int ID;

       float d;

};

 

 

int Knapsack(int p[],int w[],int c,int n)

{

 //为Knap::Backtrack初始化

       int W=0;

       int P=0;

       int i=1;

       Object *Q=new Object[n];

       for(i=1;i<=n;i++)

       {

        Q[i-1].ID=i;

        Q[i-1].d=1.0*p[i]/w[i];

        P+=p[i];

        W+=w[i];

       }

       if(W<=c)

              return P;//装入所有物品

       //依物品单位重量排序

       float f;

       for( i=0;i<n;i++)

        for(int j=i;j<n;j++)

        {

         if(Q[i].d<Q[j].d)

         {

           f=Q[i].d;

              Q[i].d=Q[j].d;

              Q[j].d=f;

         }

 

 

        }

       

       Knap  K;

       K.p = new int[n+1];

    K.w = new int[n+1];

       K.x = new int[n+1];

       K.bestx = new int[n+1];

       K.x[0]=0;

       K.bestx[0]=0;

       for( i=1;i<=n;i++)

       {

        K.p[i]=p[Q[i-1].ID];

        K.w[i]=w[Q[i-1].ID];

       }

       K.cp=0;

       K.cw=0;

       K.c=c;

       K.n=n;

       K.bestp=0;

       //回溯搜索

       K.Backtrack(1);

    K.print();
	    ofstream out("output.txt");	
		        for(int m=1;m<=n;m++)

   {

    out<<K.bestx[m]<<" ";
   }

    delete [] Q;

       delete [] K.w;

       delete [] K.p;

       return K.bestp;

}

 

void main()

{
	ifstream in("input.txt");
       
	int *p;

    int *w;

    int c=0;

    int n=0;

    int i=0;

		in>>n;
		in>>c;

       p=new int[n+1];

       w=new int[n+1];

       p[0]=0;
       w[0]=0;

       for(i=1;i<=n;i++)
			in>>w[i];
       for(i=1;i<=n;i++)
            in>>p[i];
	   cout<<Knapsack(p,w,c,n)<<endl;
}
