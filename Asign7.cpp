#include<iostream>
using namespace std;
int key[30],c[30],n ,m;
int i;
class Music
{
    public:
    int tc;
    string name,singer,composer;
    float p;
    void declare();
    void htable();
    void accept();
    void search();
    void Delete();
    void update();
}h[100];
void Music :: declare()
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
        h[i].tc=-1;
        c[i]=0;
    }
}
void Music :: htable()
{
    cout<<"\ntrac_id\tname\tsinger\tcomposer\tChain";
    for(i=0;i<10;i++)
    {
    cout<<"\n"<<h[i].tc<<"\t"<<h[i].name<<"\t"<<h[i].singer<<"\t"<<h[i].composer<<"\t\t
    "<<c[i];
    }
}
void Music :: accept()
{
    int no,pos;
    for(i=0;i<n;i++)
    {
        no=key[i]%10;
        pos=no;
        do{
            if(h[no].tc==-1)
            {
                h[no].tc=key[i];
                cout<<"Name : ";
                cin>>h[no].name;
                cout<<"Singer : ";
                cin>>h[no].singer;
                cout<<"Composer : ";
                cin>>h[no].composer;
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
void Music :: search()
{
    int no,pos,id,found=0;
    cout<<"Enter trac_id to search : ";
    cin>>id;
    for(i=0;i<n;i++)
    {
        no=id%10;
        pos=no;
        do{
            if(h[no].tc==id)
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
        cout<<"\ntrac_id\tname\tsinger\tcomposer\tChain";
        cout<<"\n"<<h[no].tc<<"\t"<<h[no].name<<"\t"<<h[no].singer<<"\t"<<h[no].composer<<"\t"<<c[no];
    }
    else
    {
        cout<<"\nRecord not found";
    }
}
void Music :: update()
{
    int no,pos,id,found=0;
    cout<<"Enter music_id to update : ";
    cin>>id;
    for(i=0;i<n;i++)
    {
        no=id%10;
        pos=no;
        do{
            if(h[no].tc==id)
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
                
                cout<<"Trac_id : ";
                cin>>h[no].tc;
                cout<<"Name : ";
                cin>>h[no].name;
                cout<<"Singer : ";
                cin>>h[no].singer;
                cout<<"Composer : ";
                cin>>h[no].composer;
    }
    else
    {
        cout<<"\nRecord not found";
    }
}
void Music::Delete() {
    int no, pos, id, found = 0, it = -1;
    int m=10;
    cout << "Enter trac_id to delete: ";
    cin >> id;

    for (int i = 0; i < n; i++) {
        no = id % 10;
        pos = no;
        
        do {
            if (h[no].tc == id) {
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
   h[no].tc=-1;
          h[no].name="";
          h[no].singer="";
          h[no].composer="";
}
    if (found == 0) {
      
        cout << "Record not found." << endl;
    }
}

int main()
{
    int ch;
    Music s;
     
    do
    {
        cout<<"\n..........MUSIC MANAGEMENT SYSTEM..........";
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