#include<iostream.h>
#include<conio.h>

class stack
{
int *stk;
int tos,size;
static int counter;

public:

//copy constructor
stack(stack &olds)
{
tos=olds.tos;
size=olds.size;
stk=new int[size];
for(int i=0;i<tos;i++)
{
stk[i]=olds.stk[i];

}
  counter++;

}

//constructor

stack(int s)

{
tos=0;
size=s;
stk=new int [size];
counter++;
cout<<"constructor \n";

}

~stack()
{
delete[]stk;

cout<<"I am the destructor \n";
counter--;
cout<<stack::getcounter()<<endl;
getch();
}


int IsFull()
{
return (tos==size);
}


int ISEMPTY()
{
return(tos==0);
}
int push(int n)
{
if(!IsFull())

{
stk[tos++]=n;
return 1   ;
}
return 0;
}

int pop()
{
if(!ISEMPTY())

{
return stk[--tos];

 }
return -1000;

}


  //getcounter
static int getcounter()
{
return counter;
}


//reverse
stack Reverse()
{
stack R(size);
for(int i=0;i<tos;i++)
{
R.stk[tos-1-i]=stk[i];
R.tos=tos;

}
     return R;
}

 friend void viewcontent(stack s);

};

int stack::counter=0;

//view content

void viewcontent(stack s)
{
for(int i=0;i<s.tos;i++)

cout<<"content="<<s.stk[i]<<endl;
}

int main ()
{
stack S1(5);
int f;

//cout<<S1.pop()<<endl;

for(int i=0;i<6;i++)
{
	f=S1.push(i*4);
	if(f==0)
		{cout<<"stack is full \n";}

//cout<<"flag="<<f<<endl;
}



/*for(int j=0;j<5;j++)

{
int R=S1.Reverse().pop();
if (R!=-1000)
cout<<R<<endl;
}
    */
   viewcontent(S1);
stack S2(3);

stack S3(4);

       cout<<"reverse"<<(S1.Reverse()).pop();

cout<<"counter= "<<stack::getcounter()<<endl;
}