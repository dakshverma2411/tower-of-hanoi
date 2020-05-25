#include<iostream>
#include<stdlib.h>
using namespace std;
class node     //blueprint of a stack
{
    public:
    int top=-1;
    unsigned int capacity;
    int *ptr;
};
node* newstack0(int max)
{
    //cout<<"in newstack0";
    node *temp=new node;
    temp->capacity=max;
    temp->ptr=new int[max]; 
    for(int i=0;i<max;i++)
    {
        temp->ptr[i]=0;
        temp->top=max-1;
    }
     return temp;

}
node* newstackwithdisks(int max)
{
   // cout<<"in newstack0";
    node *temp=new node;
    temp->capacity=max;
    temp->ptr=new int[max];
    for(int i=0;i<max;i++)
    {
        temp->ptr[i]=max-i;
       
    }
     temp->top=max-1;              /////////////
    return temp;
}

void printdisk(int x);
void display(node *a,node *b,node *c)
{
    cout<<"\n-----------------------------------------------------\n";
    a->top=a->capacity-1;
    int x=a->top;
    b->top=b->capacity-1;
    c->top=c->capacity-1;
    for(int i=x;i>=0;i--)
    {
        cout<<"            ";
        printdisk(a->ptr[i]);cout<<"\t";printdisk(b->ptr[i]);cout<<"\t";printdisk(c->ptr[i]);
        cout<<endl;
    }
    cout<<"                A\t            B\t            C\n";
    cout<<"-----------------------------------------------------\n";
}
bool shift(node *t1,node *t2)
{
    if(t1->ptr[0]==0)
    {
        cout<<"invalid move\a";
        return false;
    }
    else 
    {
        
    int helper;
    int position=t1->capacity-1;
    while(t1->ptr[position]==0)
    {//cout<<"in shift first else\n";
        position--;
    }
    
    helper=t1->ptr[position];
   // t1->ptr[position]=0;
    
    
    int position2;

    if(t2->ptr[0]==0)
    {
        t2->ptr[0]=helper;
        t1->ptr[position]=0;
        return true;
    }
    else
    {
      //  cout<<"\ni am here\n";
        position2=t2->capacity-1;
        while(t2->ptr[position2]==0)
        {
            position2--;
        }

        int x=position2++;
        if(t2->ptr[x]>helper)
        {
             t2->ptr[position2]=helper;
             t1->ptr[position]=0;
             return true;
        }
        else
        {
            cout<<"invalid move\a";
            return false;
        }
    }
    }

}
bool win(node *t1,node *t2)
{
    if(t1->ptr[t1->capacity-1]==1)
    return true;
    else if(t2->ptr[t2->capacity-1]==1)
    return true;
    else return false;
}




int main()
{
    int choice;
    cout<<"Choose the difficulty level\n1. Easy\n2. Medium\n3. Hard\n";
    cin>>choice;
    system("CLS");
    if(choice==1)
    {
        node* a=newstackwithdisks(3);
        node *b=newstack0(3);
        node *c=newstack0(3);
        int moves=7;
        display(a,b,c);
        cout<<"----MOVES :"<<moves<<"----\n"<<endl;
        
        
        while(moves--)
        {
            char out,in;
            
            cout<<"choose the tower you want to take the disk out from(a/b/c):";
            cin>>out;
            cout<<"choose the tower you want to put the disk into(a/b/c):";
            cin>>in;
            system("CLS");
            bool x;
            
            {
                node *t1,*t2;
                if(out=='a'||out=='A')
                {
                    t1=a;
                }
                else if(out=='b'||out=='B')
                {
                    t1=b;
                }
                else if(out=='c'||out=='C')
                {
                    t1=c;
                }
                if(in=='a'||in=='A')
                {
                    t2=a;
                }
                else if(in=='b'||in=='B')
                {
                    t2=b;
                }
                else if(in=='c'||in=='C')
                {
                    t2=c;
                }
                x=shift(t1,t2);
                if(!x)moves++;
            }
            if(x){
               
                display(a,b,c);
                 cout<<"----MOVES :"<<moves<<"----\n"<<endl;}
        }
        if(win(b,c))cout<<"\nYOU WIN!\n";
        else cout<<"\nOUT OF MOVES!\n";
    }
    else if(choice==2)
    {
       node* a=newstackwithdisks(4);
        node *b=newstack0(4);
        node *c=newstack0(4);
        int moves=15;
        display(a,b,c);
        cout<<"----MOVES :"<<moves<<"----"<<endl;
        
        
        while(moves--)
        {
            char out,in;
            cout<<"choose the tower you want to take the disk out from(a/b/c):";
            cin>>out;
            cout<<"choose the tower you want to put the disk into(a/b/c):";
            cin>>in;
            bool x;
            
            {
                node *t1,*t2;
                if(out=='a'||out=='A')
                {
                    t1=a;
                }
                else if(out=='b'||out=='B')
                {
                    t1=b;
                }
                else if(out=='c'||out=='C')
                {
                    t1=c;
                }
                if(in=='a'||in=='A')
                {
                    t2=a;
                }
                else if(in=='b'||in=='B')
                {
                    t2=b;
                }
                else if(in=='c'||in=='C')
                {
                    t2=c;
                }
                x=shift(t1,t2);
                if(!x)moves++;
            }
            if(x){display(a,b,c);
                cout<<"----MOVES :"<<moves<<"----"<<endl;
                }
        }
        if(win(b,c))cout<<"\nYOU WIN\n";
        else cout<<"\nOUT OF MOVES\n";
    }
    else if(choice==3)
    {
        node* a=newstackwithdisks(5);
        node *b=newstack0(5);
        node *c=newstack0(5);
        int moves=31;
        display(a,b,c);
        cout<<"----MOVES :"<<moves<<"----"<<endl;
        
        
        while(moves--)
        {
            char out,in;
            cout<<"\nChoose the tower you want to take the disk out from(a/b/c):";
            cin>>out;
            cout<<"\nChoose the tower you want to put the disk into(a/b/c):";
            cin>>in;
            bool x;
            
            {
                node *t1,*t2;
                if(out=='a'||out=='A')
                {
                    t1=a;
                }
                else if(out=='b'||out=='B')
                {
                    t1=b;
                }
                else if(out=='c'||out=='C')
                {
                    t1=c;
                }
                if(in=='a'||in=='A')
                {
                    t2=a;
                }
                else if(in=='b'||in=='B')
                {
                    t2=b;
                }
                else if(in=='c'||in=='C')
                {
                    t2=c;
                }
                x=shift(t1,t2);
                if(!x)moves++;
            }
            if(x){ display(a,b,c);
                cout<<"----MOVES :"<<moves<<"----"<<endl;
               }
        }
        if(win(b,c))cout<<"\nYOU WIN\n";
        else cout<<"\nOUT OF MOVES\n";
    }
   



}
void printdisk(int x)
{
    if(x==0)
    {
        cout<<"         ";
    }
    else if(x==1)
    {
        cout<<"    =    ";
    }
    else if(x==2)
    {
        cout<<"   ===   ";
    }
    else if(x==3)
    {
        cout<<"  =====  ";
    }
    else if(x==4)
    {
        cout<<" ======= ";
    }
    else if(x==5)
    {
        cout<<"=========";
    }
}

