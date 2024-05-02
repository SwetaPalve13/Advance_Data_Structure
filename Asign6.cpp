#include<iostream>
using namespace std;
int key[30],c[30],n ,m;
int i;
class Medical
{
    public:
    int mno,price;
    string mname,man;
    float p;
    void declare();
    void htable();
    void accept();
    void search();
    void Delete();
    void update();
}h[100];
void Medical :: declare()
{   
    cout<<"Enter total number of key : ";
    cin>>n;
    cout<<"Enter Keys :  ";
    for(i=0;i<n;i++)
    {
        cin>>key[i];
    }
    for(i=0;i<10;i++)
    {
        h[i].mno=-1;
        c[i]=0;
    }
}
void Medical :: htable()
{
    cout<<"\nmno\tmname\tprice\tman\tchain";
    for(i=0;i<10;i++)
    {
    cout<<"\n"<<h[i].mno<<"\t"<<h[i].mname<<"\t"<<h[i].price<<"\t"<<h[i].man<<"\t"<<c[i];
    }
}
void Medical :: accept()
{
    int no,pos;
    for(i=0;i<n;i++)
    {
        no=key[i]%10;
        pos=no;
        do{
            if(h[no].mno==-1)
            {
                h[no].mno=key[i];
                cout<<"mname : ";
                cin>>h[no].mname;
                cout<<"price : ";
                cin>>h[no].price;
                cout<<"man : ";
                cin>>h[no].man;
                break;
            }
            else 
            {
                no++;
                c[pos]=no;
                
            }
        }while(no<10);
    }

}
void Medical :: search()
{
    int no,pos,id,found=0;
    cout<<"Enter medicineno to search : ";
    cin>>id;
    for(i=0;i<n;i++)
    {
        no=id%10;
        pos=no;
        do{
            if(h[no].mno==id)
            {
             
                found=1;
                     break;
            }
            else 
            {
                no++;
                c[pos]=no;
                
                
            }
        }while(no<10);
    }
    if(found==1)
    {
        cout<<"\nmedicineno\tmname\tprice\tman\tchain";
        cout<<"\n"<<h[no].mno<<"\t"<<h[no].mname<<"\t"<<h[no].price<<"\t"<<h[no].man<<"\t"<<c[no];
    }
    else
    {
        cout<<"\nRecord not found";
    }
}
void Medical :: update()
{
    int no,pos,id,found=0;
    cout<<"Enter Medical_id to update : ";
    cin>>id;
    for(i=0;i<n;i++)
    {
        no=id%10;
        pos=no;
        do{
            if(h[no].mno==id)
            {
                
                found=1;
                     break;
            }
            else 
            {
                no++;
                c[pos]=no;
                if(no>10)
                {
                    no=0;
                }
                
            }
        }while(no<10);
    }
    if(found==1)
    {
                
                cout<<"medicineno : ";
                cin>>h[no].mno;
                cout<<"mname : ";
                cin>>h[no].mname;
                cout<<"price : ";
                cin>>h[no].price;
                cout<<"man : ";
                cin>>h[no].man;
    }
    else
    {
        cout<<"\nRecord not found";
    }
}
void Medical::Delete() {
    int no, pos, id, found = 0, it = -1;
    int m=10;
    cout << "Enter medicineno to delete: ";
    cin >> id;

    for (int i = 0; i < n; i++) {
        no = id % 10;
        pos = no;
        
        do {
            if (h[no].mno == id) {
                found = 1;
       
                
                break;

            } 
            else {
                no++;
            
                c[pos] = no;
            }
        } while (no <10);
    }
    
if(found==1)
{
   h[no].mno=-1;
          h[no].mname="";
          h[no].price=0;
          h[no].man="";
}
    if (found == 0) {
      
        cout << "Record not found." << endl;
    }
}

int main()
{
    int ch;
    Medical s;
     
    do
    {
        cout<<"\n..........Medical MANAGEMENT SYSTEM..........";
        cout<<"\n1.declare\n2.ADD RECORD\n3.DISPLAY RECORD\n4.search\n5.delete\n6.update\n7.exit";

        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
         
            case 1:
            s.declare();
            break;
            case 2:
            s.accept();
            break;
            case 3:
            s.htable();
            break;
            case 4:
            s.search();
            break;
            case 5:
            s.Delete();
            break;
            case 6:
            s.update();
            break;
            case 7:
            cout<<"Exit......!!";
            break;
            default:
            cout<<"Wrong choice";
        }
    } while (ch!=7);
    return 0;
}