#include<iostream>
#include<stack>
#define max 20
using namespace std;

class FT
{
	public:
	int age;
	string name,gen,ger;
	FT *lc,*rc;
    int	cnt=0,cnt1=0,cnt2=0;
	void create();
	void insert(FT *root,FT *next);
	void display(FT *root);
	void leaf(FT *root);
	void height();
		
}*root,*temp,*next;

void FT::create()
{
	int ch;
	FT *next;
	root=new FT;
	cout<<"ENTER the INFORMATION"<<endl;
	cout<<"\nEnter NAME: ";
	cin>>root->name;
	cout<<"Enter generation: ";
	cin>>root->ger;
	cout<<"Enter GENDER: ";
	cin>>root->gen;
	cout<<"Enter AGE: ";
	cin>>root->age;
	cnt=cnt1=cnt2=1;
	root->lc=root->rc=NULL;
	
	do{
		cout<<"Do you want to add new Node:(0/1)no/yes";
		cin>>ch;
		if(ch==1)
		{
			next=new FT;
			cout<<"Enter the data for new node:";
			
			cout<<"\nEnter NAME: ";
			cin>>next->name;
			cout<<"Enter GER: ";
			cin>>next->ger;
			cout<<"Enter GENDER: ";
			cin>>next->gen;
			cout<<"Enter AGE: ";
			cin>>next->age;
			
			next->lc=next->rc=NULL;
			insert(root,next);
		}
		
	}while(ch==1);
	
}
void FT::insert(FT *root,FT *next)
{
	 char chr;
	 FT *temp;
	 cout<<"Whether you want to insert either Left(l) OR Right(r): ";
	 cin>>chr;
	 if(chr=='l'||chr=='L')
	 {
	 	if(root->lc==NULL)
	 	{
	 		root->lc=next;
	 		cnt1++;
	 		
	 	}
	 	else
	 	{
	 		insert(root->lc,next);
	 	}
	 	
	 }
	 if(chr=='r'||chr=='R')
	 {
	 	if(root->rc==NULL)
	 	{
	 		root->rc=next;
	 		
	 	}
	 	else
	 	{
	 		insert(root->rc,next);
	 		cnt2++;
	 	}
	 }
}	 



void FT::display(FT *root)
{
    FT *stack[max];
int top=-1;
FT*temp;
temp=root;
if(root!=NULL)
{
do
{
while(temp!=NULL)
{
top++;
stack[top]=temp;
temp=temp->lc;
}
if(top!=-1)
{
temp=stack[top];
cout<<temp->name<<"\t"<<temp->gen<<"\t"<<temp->age<<"\t"<<temp->ger<<"\t"<<endl;
temp=temp->rc;
}
top--;
}while(temp!=NULL || top!=-1);
}

}
void FT::leaf(FT *root)
{
    FT *stack[max];
    int top=-1;
    temp=root;
    if(root!=NULL)
    {
        do
        {
            while(temp!=NULL)
            {
            top++;
            stack[top]=temp;
            temp=temp->lc;
            }
    if(top!=-1)
    {
        temp=stack[top];
        if(temp->lc==NULL&&temp->rc==NULL)
        {
        cout<<" "<<temp->name<<endl;
        }
        temp=temp->rc;
        top--;
        }
    
   }while(top!=-1||temp!=NULL);
  }
}


void FT::height()
{
    if(cnt1>=cnt2)
    {
    cout<<"Height of tree is :"<<cnt1;
    }
    else
    {
    cout<<"Height of tree is :"<<cnt2;
    }
    
}

int main()
{
	int ch;
	FT t;
	
	do{
	    cout<<"\nMENU";
		cout<<"\n1.Create";
		cout<<"\n2.Display";
		cout<<"\n3.Height";
		cout<<"\n4.Leaf Node";
		cout<<"\n5.Exit";
		cout<<"\nEnter your Choice:";
		cin>>ch;
		
		switch (ch) 
		{
			case 1:
			t.create();
			break;
			case 2:
			cout<<"Name\tGender\tAge\tGenereation"<<endl;
			t.display(root);
			break;
			case 3:
			t.height();
			break;
			case 4:
			t.leaf(root);
			break;
			case 5:
			exit(5);
			default:
			cout<<"Invalid Choice!!";
			break;
		}
		}while(ch!=5);
		return 0;
}
