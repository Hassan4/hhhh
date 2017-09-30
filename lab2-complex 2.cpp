#include <iostream.h>
#include <conio.h>
class complex{
  	int real;
   int imag;
   static int cnum;
   public:
   complex (int r,int i)
   {
   	real=r;
      imag=i;
      cnum++;
      cout<<"The "<<cnum<<" constructor"<<endl;
   }
   complex ()
   {
   	cnum++;
      cout<<"The "<<cnum<<" constructor"<<endl;
   }
   complex (complex &c)
   {
    	real=c.real;
      imag=c.imag;
      cnum++;
      cout<<"The "<<cnum<<" constructor"<<endl;
   }
   void setreal(int r)
   {
   	real=r;
   }
   void setimag(int i)
   {
   	imag=i;
   }
   int getreal(void)
   {
   	return real;
   }
   int getimag(void)
   {
   	return imag;
   }
   void printcomplex (void)
   {
   	if(imag<0)
   		cout<<"The complex number: "<<real<<" - "<<(imag*-1)<<" i"<<endl;
      else
         cout<<"The complex number: "<<real<<" + "<<(imag)<<" i"<<endl;
   }
   static int getcnum ()
   {
    	return cnum;
   }
   ~complex ()
   {
      cout<<"I`m the destructor"<<endl;
      cnum--;
   }
};
complex add (complex x ,complex y)
{
	complex z;
   z.setreal(x.getreal()+y.getreal());
  	z .setimag(x.getimag()+y.getimag());
  	return z;
}
complex sub (complex x ,complex y)
{
	complex z;
   z.setreal(x.getreal()-y.getreal());
   z.setimag(x.getimag()-y.getimag());
   return z;
}
int complex::cnum = 0;
void main (void)
{
	complex c1(2,2);
   complex c2(3,0);
   complex c3(4,-4);
   complex cadd;
   complex csub;
   c1.printcomplex();
   c2.printcomplex();
   c3.printcomplex();
   cout<<"The number of complex numbers: "<<complex::getcnum()<<endl;
   cadd=add(c1,c2);
   cadd.printcomplex();
   csub=sub(c1,c2);
   csub.printcomplex();
   getch();
}