using namespace std;

#include<iostream>
#include<fstream>
#include<stdlib.h>


class item
{
int item_code;
char name[40];
int price;
int cost;
public:
item(int itcd,char *dish,int p,int c)
{
int i=0;
item_code = itcd;
while (*dish != '\0')
{
name[i++] = *dish;
dish++;
                }
                name[i] = '\0';
                price = p;
                cost = c;
}
item()
{
}
void set_itemcode(int x)
{
item_code = x;
}
int get_itemcode()
{
return item_code;
}
void set_name(char *n)
{
int i=0;
while (*n != '\0')
{
name[i++] = *n;
n++;
}
name[i] = '\0';
}
char* get_name()
{
return name;
}
void set_price(int p)
{
price = p;
}
int get_price()
{
return price;
}
void set_cost(int c)
{
cost = c;
}
int get_cost()
{
return cost;
}
void item_display()
{
cout<<"\t"<<item_code<<" "<<name<<" "<<price<<" "<<cost<<"\n";
}
};





class menu
{
item it[20];
public:
int get_price(int itCode)
{
for(int i=0; i<20; i++)
if(it[i].get_itemcode() == itCode)
return it[i].get_price();
}
int get_cost(int itCode)
{
for(int i=0; i<10; i++)
if(it[i].get_itemcode() == itCode)
return it[i].get_cost();
}
void loadfile()
{
int i=0,j,k,sp,cp,code=0;
               char *sent, word[50][50];
               ifstream fin;
               fin.open("menu.txt", ios::in);
               char line[50];
               while(!fin.eof())
               {
fin.getline(line,50);
                    sent = line;
                    j=0;
                    do
                    {
                    	k=0;
                       	while ((*sent != ','))
                       	{
                          	word[j][k] = *sent;
                          	k++;
                          	sent++;
                       	}
                    	sent++;
                    	word[j][k] = '\0';
                    	j++;
                    } while (*sent != '\0');
code = atoi(word[0]);
sp = atoi(word[2]);
cp = atoi(word[3]);
it[i++] = item(code, word[1], sp, cp);
}
}
void display()
{
for(int i=0; i<10; i++)
it[i].item_display();
}
};

class swiggyorder
{
int order_no;
int item_code;
char cust_name[40];
char cust_address[80];
int qty;
char mobile[20];
    	public:
swiggyorder(int odno,int itcd,char *cname, char*
  caddr, int q, char *mob)
        	{
int i=0;
order_no = odno;
item_code = itcd;
while (*cname != '\0')
            	{
               	cust_name[i++] = *cname;
                	cname++;
            	}
            	cust_name[i] = '\0';
            	i=0;
            	while (*caddr != '\0')
            	{
                	cust_address[i++] = *caddr;
                	caddr++;
            	}
            	cust_address[i] = '\0';
            	qty = q;
            i=0;
            while (*mob != '\0')
            {
                mobile[i++] = *mob;
                mob++;
            }
            mobile[i] = '\0';
        }
        swiggyorder()
        {

        }

        void set_orderno(int x)
        {
            order_no = x;
        }
        int get_orderno()
        {
            return order_no;
        }
        void set_code(int c)
        {
           item_code = c;
        }
        int get_code()
        {
            return item_code;
        }
        void set_custname(char *cname)
        {
            int i=0;
            while (*cname != '\0')
            {
                cust_name[i++] = *cname;
                cname++;
            }
            cust_name[i] = '\0';
        }
        char* get_custname()
        {
            return cust_name;
        }
        void set_custaddr(char *caddr)
        {
            int i=0;
            while (*caddr != '\0')
            {
                cust_address[i++] = *caddr;
                caddr++;
            }
            cust_address[i] = '\0';
        }
        char* get_custaddr()
        {
            return cust_address;
        }
        void set_quan(int q)
        {
            qty = q;
        }
        int get_quan()
        {
            return qty;
        }
        char* set_mob(char *m)
        {
            int i=0;
            while (*m != '\0')
            {
                mobile[i++] = *m;
                m++;
            }
            mobile[i] = '\0';
            return mobile;
        }
        char* get_mob()
        {
            return mobile;
        }
        void sorder_display()
        {
            cout<<"\t"<<order_no<<" "<<item_code<<" "<<cust_name<<" "<<cust_address<<" "<<qty<<" "<<mobile<<"\n";
        }
    };


class swiggy
{
swiggyorder so[15];
public:
void loadfile()
{
int i=0,j,k,odno,itcd,qt;
               char *sent, word[100][100], ch;
               ifstream fin;
               fin.open("swiggy.txt", ios::in);
               char line[100];
               while(!fin.eof())
               {
               	fin.getline(line,100);
                    sent = line;
                    j=0;
                    do
                    {
                    	k=0;
                       	while ((*sent != ','))
                       	{
                         	word[j][k] = *sent;
                          	k++;
                          	sent++;
                       	}
sent++;
                    	word[j][k] = '\0';
                    	j++;
                    } while (*sent != '\0');
                    odno = atoi(word[0]);
                    itcd = atoi(word[1]);
                    qt = atoi(word[4]);
                    so[i++] = swiggyorder (odno, itcd, word[2],
             word[3],qt,word[5]);
}
}
          void display()
          {
          	for(int i=0; i<15; i++)
                   	so[i].sorder_display();
}
void sprocessorder(menu m1)
{
int odno,cd,discount=0;
               char *addr,*mob;
               int costprice, sellingprice, totcost, totprice,
    nettot, gst = 5;
               ofstream fout;
               fout.open("sales.txt", ios::out|ios::app);
               for(int i=0; i<15; i++)
               {
odno = so[i].get_orderno();
cd = so[i].get_code();
addr = so[i].get_custaddr();
mob = so[i].get_mob();
sellingprice = m1.get_price
(so[i].get_code());
costprice = m1.get_cost(so[i].get_code());
                  	totcost = costprice*so[i].get_quan();
                  	totprice = sellingprice*so[i].get_quan();
                  	nettot = (totprice + (gst*totprice)/100);
fout<<odno<<","<<addr<<","<<mob<<","<<cd<<","<<totcost<<","<<totprice<<","<<gst<<","<<discount<<","<<nettot<<","<<"\n";
                  	}
                  	fout.close();
              	}
		};

class zomatoorder
{
int order_no;
    	int item_code;
    	char cust_name[40];
    	char cust_address[80];
    	int qty;
    	char mobile[20];
    	int discount;
    	public:
     	zomatoorder(int odno,int itcd,char *cname, char
 *caddr, int q, char *mob,int disc)
        	{
          	int i=0;
            	order_no = odno;
            	item_code = itcd;
            	while (*cname != '\0')
            	{
               	cust_name[i++] = *cname;
                	cname++;
            	}
            	cust_name[i] = '\0';
            	i=0;
            	while (*caddr != '\0')
            	{
               	cust_address[i++] = *caddr;
                	caddr++;
            	}
            	cust_address[i] = '\0';
            	qty = q;
            	i=0;
            	while (*mob != '\0')
            	{
               	mobile[i++] = *mob;
                	mob++;
            	}
            	mobile[i] = '\0';
            	discount = disc;
        	}
        	zomatoorder()
        	{
        	}
        	void set_orderno(int x)
        	{
          	order_no = x;
        	}
        	int get_orderno()
        	{
          	return order_no;
        	}
        	void set_code(int c)
        	{
         		item_code = c;
        	}
        	int get_code()
        	{
          	return item_code;
        	}
        	void set_custname(char *cname)
        	{
          	int i=0;
            	while (*cname != '\0')
            	{
               	cust_name[i++] = *cname;
                	cname++;
            	}
            	cust_name[i] = '\0';
        	}
        	char* get_custname()
        	{
          	return cust_name;
        	}
        	void set_custaddr(char *caddr)
        	{
          	int i=0;
            	while (*caddr != '\0')
            	{
               	cust_address[i++] = *caddr;
                	caddr++;
            	}
            	cust_address[i] = '\0';
        	}
        	char* get_custaddr()
        	{
          	return cust_address;
        	}
        	void set_quan(int q)
        	{
          	qty = q;
        	}
        	int get_quan()
        	{
          	return qty;
        	}
        	char* set_mob(char *m)
        	{
          	int i=0;
            	while (*m != '\0')
            	{
               	mobile[i++] = *m;
                	m++;
            	}
            	mobile[i] = '\0';
        	}
        	char* get_mob()
        	{
          	return mobile;
        	}
        	void set_disc(int d)
        	{
          	discount = d;
        	}
        	int get_disc()
        	{
          	return discount;
        	}
        	void zorder_display()
        	{
          	cout<<"\t"<<order_no<<" "<<item_code<<" "<<cust_name<<" "<<cust_address<<" "<<qty<<" "<<mobile<<" "<<discount<<"\n";
        	}
    };

class zomato
          {
              zomatoorder zo[15];
          public:
              void loadfile()
              {
                 int i=0,j,k,odno,itcd,qt,disc;
                 char *sent, word[100][100], ch;
                 ifstream fin;
                 fin.open("zomato.txt", ios::in);
                 char line[100];
                 while(!fin.eof())
                 {
                    fin.getline(line,100);
                    sent = line;
                    j=0;
                    do
                    {
                       k=0;
                       while ((*sent != ','))
                       {
                          word[j][k] = *sent;
                          k++;
                          sent++;
                       }
                    sent++;
                    word[j][k] = '\0';
                    j++;
                    }while (*sent != '\0');
                    odno = atoi(word[0]);
                    itcd = atoi(word[1]);
                    qt = atoi(word[4]);
                    disc = atoi(word[6]);
                    zo[i++] = zomatoorder(odno,itcd,word[2],word[3],qt,word[5],disc);
                }
              }
              void display()
              {
                  for(int i=0; i<15; i++)
                   zo[i].zorder_display();
              }
              void zprocessorder(menu m2)
              {
                  int odno,cd,disc=10;
                  char *addr,*mob;
                  int costprice, sellingprice, totcost, totprice, nettot, gst = 5;
                  ofstream fout;
                  fout.open("sales.txt", ios::out|ios::app);
                  for(int i=0; i<4; i++)
                  {
                  odno = zo[i].get_orderno();
                  cd = zo[i].get_code();
                  addr = zo[i].get_custaddr();
                  mob = zo[i].get_mob();
                  sellingprice = m2.get_price(zo[i].get_code());
                  costprice = m2.get_cost(zo[i].get_code());
                  totcost = costprice*zo[i].get_quan();
                  totprice = sellingprice*zo[i].get_quan();
                  nettot = totprice + (gst*totprice)/100 - disc*totprice/100;
                  fout<<odno<<","<<addr<<","<<mob<<","<<cd<<","<<totcost<<","<<totprice<<","<<gst<<","<<disc<<","<<nettot<<","<<"\n";
                  }
                  fout.close();
              }
          };


class salesitem {
    int orderno,itemno;
    int quantity;
    char dishname[30],address[30];
    char phno[30];
    int GST,totalprice,netprice,totalcost,dis;
    public:
        salesitem(int od,char *adr,char *pho,int id,char *dish,int tc,int tp,int gs,int ds,int np)
        {
            orderno=od;
            int i=0;
            itemno=id;
            totalprice=tp;
            totalcost=tc;
            dis=ds;
            GST=gs;
            netprice=np;
            while(*dish !='\0')
            {
                dishname[i++]=*dish;
                dish++;
            }
            dish[i]='\0';
            cout << dish << endl;
            i=0;
          while(*adr !='\0')
                {
                  address[i++]=*adr;
                  adr++;
                }
                  adr[i]='\0' ;
                   i=0;
         while(*pho!='\0')
                {
                  phno[i++]=*pho;
                  pho++;
                }
                  pho[i]='\0' ;
           }
           salesitem()
           {

           }
            void set_orderno(int x)
            {
                orderno=x;

            }
           int get_orderno()
            {
                return orderno;

            }
            void set_itemno(int y)
            {
                itemno=y;
            }
             int get_itemno()
            {
                return itemno;
            }
             void set_quantity(int m)
             {
                 quantity=m;
             }
             float get_quantity()
             {
                return quantity;
             }
             void set_GST(int b)
             {
                 GST=b;
             }
             int get_GST()
             {
                 return GST;
             }
             int get_totalcost()
             {
                 return totalcost;
             }
             void set_totalcost(int w)
             {
                  totalcost=w;
             }
             int get_totalprice()
             {
                 return totalprice;
             }
             void set_totalprice(int q)
             {
                totalprice=q;
             }
             int get_discount()
             {
                 return dis;
             }
             void set_discount(int e)
             {
                 dis=e;
             }
             int get_netprice()
             {
                 return netprice;
             }
             void set_netprice(int h)
             {
                 netprice=h;
             }
             void display()
             {
                cout<<orderno<<" "<<address<<" "<<phno<<" "<<itemno<<" "<<dishname<<" "<<totalprice<<" "<<GST<<" "<<dis<<" "<<netprice;
             }
          };

class Sales
{
    salesitem si[5];

    public:
        void loadfile()
        {
            int i=0,j=0,k,od1,id1,gs1,tp1,tc1,ds1,np1;
            float pr1;
            char *sent,word[100][100];
            ifstream fin;
            fin.open("sales.txt", ios::in);
            char line[100];
            while(!fin.eof())
            {
                fin.getline(line,100);
                sent = line;
                j=0;
                cout<<line<<"\n";
                do
                {
                    k=0;
                    while ((*sent != ','))
                    {
                        word[j][k] = *sent;
                        k++;
                        sent++;
                    }
                    sent++;
                    word[j][k] = '\0';
                    j++;
                }while (*sent != '\0');
                    od1 = atoi(word[0]);
                    id1 = atoi(word[3]);
                    gs1 = atoi(word[7]);
                    tc1 = atoi(word[5]);
                    tp1 = atoi(word[6]);
                    np1 = atoi(word[9]);
                    ds1 = atoi(word[8]);
                    si[i++]=salesitem(od1,word[1],word[2],id1,word[4],tc1,tp1,gs1,ds1,np1);
                }
        }

             void displaydata()
               {
                 for(int i=0;i<5;i++)
                   si[i].display();
               }

             float daily_profit(int sp, int cp,int GST,int dis)
             {  int totalcost,totalprice,totalprofit;
                for(int i=0;i<4;i++)
                {totalcost=si[i].get_totalcost();
                totalprice=si[i].get_totalprice();
                GST=si[i].get_GST();
                dis=si[i].get_discount();
               }
               totalprofit=totalprice+((GST*totalprice)/100)-totalcost;
             }
       };


int main()
{
  menu m;
  swiggy s;
  zomato z;
  Sales sal;
  m.loadfile();
  int choice;
  char ch;
  cout<<"\t\t\t\t\t\tSSS RESTAURANT\n\n";
  cout<<"\t\t\t\t\tNo. 7, 5th cross street, Arekere\n\t\t\t\t\t       Bangalore, 560077\n\n\n\n";
  do
  {
   cout<<"\t\tSelect from the following:-\n\n";
   cout<<"\t\t1. Display menu\n\t\t2. Swiggy orders\n\t\t3. Zomato orders\n\t\t4. Sales\n\t\t5. Profit\n\t\t6. Exit\n\n";


   cout<<"Login  \n\n";
   cout<<"Enter Email address:  ";
   cin>>uemail;
   if(uemail != email){
    cout<<" \n \n Invalid Email, Try again   ";
    getchar();
    return 0;
   }
    cout<<"\n Enter Password:  ";
   cin>>upassword;

   if(upassword != password){
    cout<<" \n \n Invalid password, Try again   ";
    return 0;
    getchar();
   }

   cout<<"\t\tEnter your choice:-  ";
   cin>>choice;
   switch(choice)
   {
      case 1: m.display();
              break;
      case 2: s.loadfile();
              s.sprocessorder(m);
              s.display();
              break;
      case 3: z.loadfile();
              z.zprocessorder(m);
              z.display();
              break;
      case 4: sal.loadfile();
              sal.displaydata();
              break;
      //case 5: sal.daily_profit();
             // break;
      case 6: exit(0);
              break;
      default: cout<<"WRONG OPTION!!";
   }
   cout<<"\nDo you want to continue?  ";
   cin>>ch;
   }while((ch=='y')||(ch=='Y'));
   return 0;
}
