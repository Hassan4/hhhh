#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
# include <iostream.h>

#pragma comment (lib,"openbgi.lib")



class Point
{
  int x,y;

public:
    Point()
           {
            x=y=0;
           }

    Point(int A, int B)
    {
     x=A;
     y=B;
    }

    ~Point()
    {
     cout<<"Point Destructor";
    }

    Point(Point &t)
    {
     x=t.x;
     y=t.y;
    }

    void setx(int A)
    {
     x=A;
    }

    void sety(int B)
    {
     y=B;
    }

    int getx()
    {
     return x;
    }

    int gety()
    {
     return y;
    }

    void print()
    {
     cout<<"("<<x<<","<<y<<")"<<endl;
    }
};


class tri
{
 Point i;
 Point j;
 Point k;
 int co;

 public:
    tri()
   {
    co=0;
   }

   tri(int x,int y,int x1,int y1,int x2,int y2,int c)
   :i(x,y),j(x1,y1),k(x2,y2)
   {
    co=c;
   }

   tri(Point s,Point z,Point e,int o)
   :i(s),j(z),k(e)
   {
    co=o;
   }

     ~tri()
     {
      cout<<"Triangle Destructor"<<endl;
     }

     void Draw()
     {
      setcolor(co);
      line(i.getx(),i.gety(),j.getx(),j.gety());
      line(i.getx(),i.gety(),k.getx(),k.gety());
      line(j.getx(),j.gety(),k.getx(),k.gety());
     }

     /*void Draw1()
     {
      setcolor(co);
      line(j.getx(),j.gety(),k.getx(),k.gety());
     }

     void Draw2()
     {
      setcolor(co);
      line(i.getx(),i.gety(),k.getx(),k.gety());
     }*/



};


class cir
{
 Point d;
 int R,colur;


public:
   cir()
   {
    R=0;
    colur=0;
   }

   cir(int x,int y,int ra,int c1)
   :d(x,y)
   {
    R=ra;
    colur=c1;
   }

   cir(Point s,int a,int c2)
   :d(s)
   {
    R=a;
    colur=c2;
   }

     ~cir()
     {
      cout<<"Circle Destructor"<<endl;
     }
     void Draw()
     {
      setcolor(colur);
      circle(d.getx(),d.gety(),R);
     }

};





class rect
{
 Point ul;
 Point lr;
 int color;

 public :
     rect()
     {
      color=0;
     }

     rect(int x1,int y1,int x2,int y2,int c )
     :ul(x1,y1),lr(x2,y2)
     {
      color=c;
     }

     rect(Point p,Point q,int c)
     :ul(p),lr(q)
     {
      color=c;
     }
     ~rect()
     {
      cout<<"Rectangle Destructor"<<endl;
     }
     void Draw()
     {
      setcolor(color);
      rectangle(ul.getx(),ul.gety(),lr.getx(),lr.gety());
     }
};


int main()
{
int gdriver = DETECT, gmode, errorCode;

initgraph(&gdriver, &gmode, "c:\\bc5\\bgi");

errorCode = graphresult();
if (errorCode != grOk)
{
cout<<"Can not initialize graphics"<<endl ;
}

 Point f(10,10);
 Point g(100,100);

 Point p3(f);
 p3.print();

 rect r;

 rect r2(10,10,100,100,7);

 rect r3(f,g,7);
 r3.Draw();

 //circle
 Point w(25,25);
 cir c;
 cir c0(20,20,15,7);

 cir c1(w,15,7);
 c1.Draw();

 //triangle
 Point u(250,135);
 Point z(100,200);
 Point v(90,70);

 tri t;

 tri t0(150,150,200,200,250,250,7);

 tri t1(u,z,v,7);

 t1.Draw();
 //t1.Draw1();
 //t1.Draw2();

 getch();

}

