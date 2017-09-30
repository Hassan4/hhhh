  #include <iostream.h>
  #include <conio.h>

class Complex
{
private :
    int real;
    int img;
    static int onum;

public :
    Complex()
    {
        real=img=0;
        cout<<"Default Constructor"<<Getreal()<<"+"<<Getimg()<<endl;
        onum++;
    }
    Complex(int p,int q)
    {

        real=p;
        img=q;
        cout<<"First Constructor : "<<Getreal()<<"+"<<Getimg()<<endl;
        onum++;
    }
    Complex(int x)
    {

        real=x;
        img=x;
        cout<<"Second Constructor : "<<Getreal()<<"+"<<Getimg()<<endl;
        onum++;
    }
    ~ Complex()
    {
        cout<<"I AM THE DESTRUCTOR"<<endl;
        onum--;
    }
    Getreal()
    {
        return real;
    }
    Getimg()
    {
        return img;
    }
    static int Getonum()
    {
        return onum;
    }
    void Setimg(int i)
    {
        img = i;
    }
     void Setreal(int r)
    {
        real = r;
    }
    Complex printcomplex(Complex g)
    {
        cout<<g.Getreal()<<"+"<<g.Getimg()<<"i"<<endl;
    }
    Complex addcl(Complex c)
    {
        Complex o;
        o.real=real+c.real;
        o.img=img+c.img;
        return o;
    }
};
int Complex::onum = 0;

Complex subc(Complex e,Complex f)
{
    Complex z;
    z.Setreal(e.Getreal()-f.Getreal());
    z.Setimg(e.Getimg()-f.Getimg());
    cout<<z.Getreal()<<"-"<<z.Getimg()<<"i"<<endl;
}

Complex addc(Complex x,Complex y)
{
    Complex c;
    c.Setreal(x.Getreal()+y.Getreal());
    c.Setimg(x.Getimg()+y.Getimg());
    cout<<c.Getreal()<<"+"<<c.Getimg()<<"i"<<endl;

}

int main()
{
    Complex c0,c1,c3,c4;
    c1.Setreal(5);
    c1.Setimg(7);
    Complex c5;
    Complex c6(5,10);
    Complex c2(8);
    c3=c1.addcl(c2);
    c3=addc(c1,c2);
    c4=subc(c1,c2);
    cout<<"c1=";
    c0.printcomplex(c1);
    cout<<"c2=";
    c0.printcomplex(c2);
    cout<<"c3=";
    c0.printcomplex(c3);
    cout<<"c4=";
    c0.printcomplex(c4);
    cout<<Complex::Getonum();
    getch();
}

