#include <iostream>
#include <fstream>
#include <string>
#include  <iomanip>

using namespace std;

class Sales
{
	string title_;
	string author_;
	string publisher_;
	float price_;
	public:
		int stock_;
		void home();
		void admin();
		void add();
		void edit();
		void rem();
		void search();
		void list();
		void s_person();
};


void Sales::home()
{
	m:
	int choice;
	string username;
	string password;
	
	cout<<"\n\t\t_______________________________________________\n";
	cout<<"\t\t                                               \n";
	cout<<"\t\t                                               \n";
	cout<<"\t\t                  BOOK STORE                   \n";
	cout<<"\t\t                                               \n";
	cout<<"\t\t_______________________________________________\n";
	cout<<"\t\t                                               \n";
	cout<<"\t\t|               1) ADMIN LOGIN                |\n";
	cout<<"\t\t|                                             |\n";
	cout<<"\t\t|               2) Sales Person Login         |\n";
	cout<<"\t\t|                                             |\n";
	cout<<"\t\t|               2) Exit                       |\n";
	cout<<"\t\t|                                             |\n";
	cout<<"\n\n\n\t//To add, modify, delete books you have to login as ADMIN:::\n";
	cout<<"\t//For admin login username is : akash123 \n";
	cout<<"\t//For admin login password is : book123 \n";
	cout<<"\n\n\n\t\tPlease select! ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			cout<<"\n\n\t\tPlease Login ";
			cout<<"\n\n\n\t\tEnter Username : ";
			cin>>username;
			cout<<"\n\t\tEnter Password : ";
			cin>>password;
			if(username=="akash123" && password=="book123")
			{
				admin();
			}
			else{
				cout<<"\n\n\t\tInvalid username/password";
			}
			break;
		case 2:
			{
				s_person();
				break;
			}
			
		case 3:
			{
				exit(0);
			}
		default:
			{
				cout<<"\t Please select from given options";
			}
	}
	goto m;
}


void Sales::admin()
{
	m:
	int choice;
	cout<<"\n\n\n\t|___________Administrator menu__________|";
	cout<<"\n\n\t\t|    1) Add Book       |";
	cout<<"\n\t\t|                      |";
	cout<<"\n\t\t|    2) Modify Book    |";
	cout<<"\n\t\t|                      |";
	cout<<"\n\t\t|    3) Remove Book    |";
	cout<<"\n\t\t|                      |";
	cout<<"\n\t\t|    4) Add Sale       |";
	cout<<"\n\t\t|                      |";
	cout<<"\n\t\t|    5) View Books List|";
	cout<<"\n\t\t|                      |";
	cout<<"\n\t\t|    6) Go Back        |";
	cout<<"\n\t\t|                      |";
	cout<<"\n\n\t\tPlease enter your choice: ";
	cin>>choice;
	switch(choice){
		case 1:
			add();
			break;
		case 2:
			edit();
			break;
		case 3:
			rem();
			break;
		case 4:
			search();
			break;
		case 5:
			list();
			break;
		case 6:
			home();
			break;
		default:
			{
				cout<<"\n\n\t\tInvalid Choice!";
			}
    }
    goto m;
}


void Sales::s_person()
{
	m:
    int choice;
    cout<<"\n\n\n\t|___________Sales Person Menu__________|";
    cout<<"\n\t\t|                      |";
	cout<<"\n\t\t|    1) Add Sale       |";
	cout<<"\n\t\t|                      |";
	cout<<"\n\t\t|    2) View Books List|";
	cout<<"\n\t\t|                      |";
	cout<<"\n\t\t|    3) Go Back        |";
	cout<<"\n\t\t|                      |";
	cout<<"\n\n\tPlease enter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:{
			search();
			break;
		}
		case 2:{
			list();
			break;
		}
		case 3:{
			home();
			break;
		}
		default:{
			cout<<"\n\tInvalid Entry! ";
			break;
		}	
	}
	goto m;
}


void Sales::add()
{
	m:
	fstream data;
	string title;
	int token=0;
	string author;
	string publisher;
	float price;
	int stock;
	
	cout<<"\n\n\t\tAdd new Book ";
	cout<<"\n\n\t\tEnter Name of book: ";
	cin>>title_;
	cout<<"\n\n\t\tEnter Author Name: ";
	cin>>author_;
	cout<<"\n\n\t\tEnter Publisher Name: ";
	cin>>publisher_;
	cout<<"\n\n\t\tEnter Book Price: ";
	cin>>price_;
	cout<<"\n\n\t\tEnter Stock: ";
	cin>>stock_;
	
	data.open("database.txt",ios::in);
	if(!data)
	{
		data.open("database.txt",ios::app|ios::out);
		data<<" "<<title_<<" "<<author_<<" "<<publisher_<<" "<<price_<<" "<<stock_<<"\n";
		data.close();
	}
	else
	{
		data>>title>>author>>publisher>>price>>stock;
		while(!data.eof()){
			if(title==title_ && author==author_){
				token++;
			}
			data>>title>>author>>publisher>>price>>stock;
	    	}
		    data.close();
	    if(token==1){
	    	cout<<"\n\n\t\tBook with this Title/author already exists! Add book with different title/author";
		    goto m;
	    }
	    else{
		    data.open("database.txt",ios::app|ios::out);
		    data<<" "<<title_<<" "<<author_<<" "<<publisher_<<" "<<price_<<" "<<stock_<<"\n";
		    data.close();
	    }
    }
	cout<<"\n\n\t\tRecord Inserted !";
}


void Sales::edit()
{
	fstream data,data1;
	string title;
	string n_title;
	string n_author;
	string author;
	int token=0;
	string publisher;
	float price;
	int stock;
	cout<<"\n\n\t\tModify the product";
	cout<<"\n\n\t\tBook Title: ";
	cin>>title;
	cout<<"\n\t\tAuthor Name: ";
	cin>>author;
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\n\t\tFile doesn't exist! ";
	}
	else{
		data1.open("database1.txt",ios::app|ios::out);
		data>>title_>>author_>>publisher_>>price_>>stock_;
		while(!data.eof())
		{
			if(title==title_ && author==author_)
			{
				cout<<"\n\n\t\tNew Book Title :";
				cin>>n_title;
				cout<<"\n\t\tNew Author Name :";
				cin>>n_author;
				cout<<"\n\t\tNew Publisher Name :";
				cin>>publisher;
				cout<<"\n\t\tNew Price :";
				cin>>price;
				cout<<"\n\t\tNew Stock :";
				cin>>stock;
				data1<<" "<<n_title<<" "<<n_author<<" "<<publisher<<" "<<price<<" "<<stock<<"\n";
				cout<<"\n\n\t\tData Modified ";
				token++;
			}
			else
			{
				data1<<" "<<title_<<" "<<author_<<" "<<publisher_<<" "<<price_<<" "<<stock_<<"\n";
			}
			data>>title_>>author_>>publisher_>>price_>>stock_;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		if(token==0){
			cout<<"\n\n\t\tRecord not found sorry!";
		}
	}
}


void Sales::search()
{
	fstream data,data1;
	string title;
	int token=0;
	string author;
	int quan;
	cout<<"\n\n\t\tEnter Title: ";
	cin>>title;
	cout<<"\n\t\tEnter Author: ";
	cin>>author;
	data.open("database.txt",ios::in);
	if(!data){
		cout<<"\n\n\t\tFile doesn't exist ";
	}
	else
	{
		data>>title_>>author_>>publisher_>>price_>>stock_;
		while(!data.eof())
		{
			if(title==title_ && author==author_)
			{
				cout<<"\n\n\t\tBook is Available: ";
				cout<<"\n\n\n\n"<<"  "<<"\t"<<left<<setw(11)<<"TITLE"<<"\t\t"<<left<<setw(11)<<"AUTHOR"<<"\t\t"<<left<<setw(11)<<"PUBLISHER"<<"\t\t"<<left<<setw(11)<<"PRICE"<<"\t\t"<<left<<setw(11)<<"STOCK"<<"\n\n";
				cout<<">>"<<"\t"<<left<<setw(11)<<title_<<"\t\t"<<left<<setw(11)<<author_<<"\t\t"<<left<<setw(11)<<publisher_<<"\t\t"<<left<<setw(11)<<price_<<"\t\t"<<left<<setw(11)<<stock_;
				cout<<"\n\n\tEnter Quantity: ";
				cin>>quan;
				token++;
				if(quan<=stock_)
				{
					cout<<"\n\n\n\t\t\t\t---------------------------------";
					cout<<"\n\t\t\t\tTotal Bill Amount is Rs : "<<(quan*price_);
					cout<<"\n\t\t\t\t---------------------------------";
					break;
				}
				else
				{
					cout<<"\n\n\n\t\t\t---------------------------------";
					cout<<"\n\t\t\t\tInsufficient Stock!";
					cout<<"\n\t\t\t---------------------------------";
					break;
				}
			}
			data>>title_>>author_>>publisher_>>price_>>stock_;
		}
		if(token==0)
		{
			cout<<"\n\n\n\t\t\t---------------------------------";
			cout<<"\n\t\t\t\tBook Not Found!";
			cout<<"\n\t\t\t---------------------------------";
		}
	}
	data.close();
}


void Sales::list()
{
	fstream data;
	int a=1;
	data.open("database.txt",ios::in);
	if(!data){
		cout<<"\n\n\t\tFile doesn't exist ";
	}
	else
	{
		data>>title_>>author_>>publisher_>>price_>>stock_;
		cout<<"\n\n"<<"  "<<"\t"<<left<<setw(11)<<"TITLE"<<"\t\t"<<left<<setw(11)<<"AUTHOR"<<"\t\t"<<left<<setw(11)<<"PUBLISHER"<<"\t\t"<<left<<setw(11)<<"PRICE"<<"\t\t"<<left<<setw(11)<<"STOCK"<<endl;
		while(!data.eof())
		{
			cout<<"\n"<<a<<")"<<"\t"<<left<<setw(11)<<title_<<"\t\t"<<left<<setw(11)<<author_<<"\t\t"<<left<<setw(11)<<publisher_<<"\t\t"<<left<<setw(11)<<price_<<"\t\t"<<left<<setw(11)<<stock_;
			a++;
			data>>title_>>author_>>publisher_>>price_>>stock_;
		}
	}
	data.close();
}


void Sales::rem()
{
	fstream data,data1;
	string n_title;
	string n_author;
	int token=0;
	cout<<"\n\n\n\t\tEnter Details of Book ";
	cout<<"\n\n\t\tTitle : ";
	cin>>n_title;
	cout<<"\n\t\tAuthor : ";
	cin>>n_author;
	data.open("database.txt",ios::in);
	if(!data){
		cout<<"\n\n\t\tFile doesn't exist";
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		data>>title_>>author_>>publisher_>>price_>>stock_;
		while(!data.eof())
		{
			if(title_==n_title && author_==n_author)
			{
				cout<<"\n\n\n\t\t\t-----------------------------------------";
				cout<<"\n\t\t\t\tRecord Deleted Succesfully!!!";
				cout<<"\n\t\t\t-----------------------------------------";
				token++;
			}
			else
			{
				data1<<" "<<title_<<" "<<author_<<" "<<publisher_<<" "<<price_<<" "<<stock_<<"\n";
			}
			data>>title_>>author_>>publisher_>>price_>>stock_;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		if(token==0){
			cout<<"\n\n\n\t\t\t---------------------------------";
			cout<<"\n\t\t\t\tSorry, Book Not Found! ";
			cout<<"\n\t\t\t---------------------------------";
		}
	}
	
}


int main(){
	Sales j;
	j.home();
	return 0;
}


