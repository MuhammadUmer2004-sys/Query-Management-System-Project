#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
//#include<stdlib.h>
#include <cstdlib>
#include <cstdio>
//#include<string.h>
#include<time.h>
#include<dos.h>
#include<windows.h>
using namespace std;

void MainMenu();
class info{
	protected:
	char name[20];
	char id[10];
	public:
		info()
		{
			strcpy(name,"");
			strcpy(id,"");
		}
		info(char n[20],char i[10]){
			strcpy(name,i);
			strcpy(id,i);
		}		
//    void set_id(char i){
//		id=i;
//	}
//	void set_name(char* n){
//		name = n;
//	}
};

class student:public info
{	
	char department[20];
	char batch[20];
	char query[100];
	char response[100];
	public:
		student()
		{
			strcpy(name,"");
			strcpy(department,"");
			strcpy(batch,"");
			strcpy(query,"");
			strcpy(id,"");
			strcpy(response,"");
		}
	student(char n[20],char i[20],char dep[20], char b[20], char q[100]){
			strcpy(name,n);
			strcpy(department,dep);
			strcpy(batch,b);
			strcpy(query,q);
			strcpy(id,i);
			strcpy(response,"");
		}
		input()
		{string tempquery;
			cout<<"Enter ID ;:";
			cin>>id;
			cin.ignore();
			cout<<"Enter Name :";
			cin>>name;
			cin.ignore();
			cout<<"Enter Department :";
			cin>>department;
			cin.ignore();			
			cout<<"Enter Batch :";
			cin>>batch;
			cin.ignore();
			cout<<"Enter Query :";
			getline(cin,tempquery);
			
			for(int i=0;i<tempquery.length();i++)
		{
			query[i]=tempquery[i];
		}
		
			
		
			
		return 0;	
		}
//	void set_department(char* dep){
//		department=dep;
//	}	 
//	void set_batch(char* b){
//		batch=b;
//	} 
//	void set_query(char* q){
//		query=q;
//	}
	void display(){
			cout<<"\nName :"<<name<<"\nID :"<<id<<"\nBatch :"<<batch<<"\nDepartment :"<<department<<"\nQuery :"<<query<<"\nResponse:"<<response<<"\n";
		
		}

		int create();
		int login(char *n,char *i);
		void readdata(char *s);
		void readall();
		int deletestudent(char *z);
		void updatequery(char *t);
		void respondquery(char *t);
		void inputquery()
		{ string tempquery;
			cout<<"Enter Your Query :";
			cin.ignore();	
			getline(cin,tempquery);
			
			for(int i=0;i<tempquery.length();i++)
		{
			query[i]=tempquery[i];
		}		
		}
		void inputrespond()
		{
		string temprespond;
			cin.ignore();
			cout<<"Enter Your Respond :";
			getline(cin,temprespond);
			
			for(int i=0;i<temprespond.length();i++)
		{
			response[i]=temprespond[i];
		}		
		}
		
};
class faculty:public info{
	char department[20];
	char designation[20];
	public:
		
	faculty(char n[20]="",char dep[20]="",char i[10]="", char des[20]=""){
			strcpy(name,n);
			strcpy(department,dep);
			strcpy(designation,des);
			strcpy(id,i);
		}
		input()
		{
			cout<<"Enter ID :";
			cin>>id;
			cin.ignore();
			cout<<"Enter Name :";
			cin>>name;
			cin.ignore();
			cout<<"Enter Department :";
			cin>>department;
			cin.ignore();
			cout<<"Enter Designation :";
			cin>>designation;
			cin.ignore();
		return 0;	
		}
		
		int create();
		void readdata(char *s);
		bool login(char *n,char *i);
		void readall();
		int deletefaculty(char *z);
		
		
void display()
{
	cout<<"\nName :"<<name<<"\nID :"<<id<<"\nDesignation :"<<designation<<"\nDepartment :"<<department;	
}
		
		
};



int faculty::create()
{
	ofstream fout;
	fout.open("Faculty.dat",ios::app|ios::binary);
	fout.write((char*)this,(sizeof(*this)));
	cout<<"Account Registered";	
	fout.close();
return 0;
}
void faculty::readdata(char *s)
{
	ifstream fin;
	fin.open("Faculty.dat");
	fin.read((char*)this,(sizeof(*this)));
	while(!fin.eof())
	{
		if(!strcmp(s,name)||!strcmp(s,id))
		{
		display();
			
		fin.read((char*)this,(sizeof(*this)));
		}
		fin.read((char*)this,(sizeof(*this)));
	}
	
	fin.close();
}
int student::create()
{
	ofstream fout;
	fout.open("AccountData.dat",ios::app|ios::binary);
	fout.write((char*)this,(sizeof(*this)));
	cout<<"Account Registered";	
	fout.close();
	return 0;
}
void student::readdata(char *s){
	ifstream fin;
	fin.open("AccountData.dat");
	fin.read((char*)this,(sizeof(*this)));
	while(!fin.eof())
	{
		if(!strcmp(s,name)||!strcmp(s,id))
		{
		display();
			
		fin.read((char*)this,(sizeof(*this)));
		}
		fin.read((char*)this,(sizeof(*this)));
	}
	
	fin.close();
}
void student::readall()
{
	ifstream fin;
	fin.open("AccountData.dat");
	fin.read((char*)this,(sizeof(*this)));
	while(!fin.eof())
	{
		
		display();
		fin.read((char*)this,(sizeof(*this)));
	}
		
	
	
	fin.close();
}
void faculty::readall()
{
	ifstream fin;
	fin.open("Faculty.dat");
	fin.read((char*)this,(sizeof(*this)));
	while(!fin.eof())
	{
		
		display();
		fin.read((char*)this,(sizeof(*this)));
	}
		
	
	
	fin.close();
}
bool faculty::login(char *n,char *i)
{
	
		
		
	
	ifstream fin;
	fin.open("Faculty.dat");
	int x=0;
	fin.read((char*)this,(sizeof(*this)));
	while(!fin.eof())
	{
		if(!strcmp(n,name)&&!strcmp(i,id))
		{
			display();x=1;
			fin.read((char*)this,(sizeof(*this)));
		}
		 fin.read((char*)this,(sizeof(*this)));
		
	}
	if(x==0)
	{
		cout<<"Wrong Name/ID";
		return false;
	}
	else return true;
	fin.close();
return 0;	
}
int student::login(char *n,char *i)
{
	
		
		
	
	ifstream fin;
	fin.open("AccountData.dat");
	int x=0;
	fin.read((char*)this,(sizeof(*this)));
	while(!fin.eof())
	{
		if(!strcmp(n,name)&&!strcmp(i,id))
		{
			display();x=1;
			fin.read((char*)this,(sizeof(*this)));
		}
		 fin.read((char*)this,(sizeof(*this)));
		
	}
	if(x==0)
	{
		cout<<"Wrong Name/ID";
		return false;
	}
	else return true;
	fin.close();
	
	
}
void student::updatequery(char *t)
{
	fstream file;
	file.open("AccountData.dat",ios::in|ios::out|ios::ate|ios::binary);
	file.seekg(0);
	file.read((char*)this,sizeof(*this));
	while(!file.eof())
	{
		if(!strcmp(t,name))
		{
			inputquery();
			strcpy(response,"");			
			file.seekp(file.tellp()-sizeof(*this));
			file.write((char*)this,sizeof(*this));
		}
		file.read((char*)this,sizeof(*this));
	}
	file.close();
	cout<<"\n\nQuery Updated";
}

int student::deletestudent(char *z)
{

	ifstream fin;
	ofstream fout;
	fin.open("AccountData.dat",ios::in|ios::binary);
	fout.open("tempfile.dat",ios::out|ios::binary);
	_getch();
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(strcmp(z,name))
		{
		fout.write((char*)this,sizeof(*this));			
		}
		fin.read((char*)this,sizeof(*this));
		
		
		
	}
	fin.close();
	fout.close();
	_getch();
	remove("AccountData.dat");
	_getch();
	rename("tempfile.dat","AccountData.dat");
	_getch();
	cout<<"\nRecord Deleted Successfully!";
return 0;
}
int faculty::deletefaculty(char *z)
{
	ifstream fin;
	ofstream fout;
	fin.open("Faculty.dat",ios::in|ios::binary);
	fout.open("tempfile.dat",ios::out|ios::binary);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(strcmp(z,name))
		{
		fout.write((char*)this,sizeof(*this));			
		}
		fin.read((char*)this,sizeof(*this));
		
		
		
	}
	fin.close();
	fout.close();
	remove("Faculty.dat");
	rename("tempfile.dat","Faculty.dat");
	cout<<"\nRecord Deleted Successfully!";
}
void student::respondquery(char *t)
{
	fstream f;
	f.open("AccountData.dat",ios::in|ios::out|ios::ate|ios::binary);
	f.seekg(0);
	f.read((char*)this,sizeof(*this));
	while(!f.eof())
	{
		if(!strcmp(t,name))
		{
			inputrespond();
			f.seekp(f.tellp()-sizeof(*this));
			f.write((char*)this,sizeof(*this));
		}
		f.read((char*)this,sizeof(*this));
	}
	f.close();
	cout<<"\nResponse Updated";
}
void MainMenu();
int main(){
	
MainMenu();
return 0;
}
void MainMenu(){
	int choice;
	k:
		system("cls");
		system("pause");
		for(int i=0;i<111;i++)
		cout<<"\x2";
	cout<< "\n\n\n\t\t\t\t\tFast University Query System\n\n"<<endl;
	for(int i=0;i<111;i++)
	cout<<"\x2";
	Sleep(1000);
	//cout<<"\t\t\t\t\t\x2\x2\x2\x2\x2\x2\x2\x2\x2\x2\x2\x2\x2\x2\x2\x2\x2\x2\x2\x2\x2\x2\x2\x2\x2";
	cout<<"\n\n\n\t\t\t\t\t(1) Admin\n\n\t\t\t\t\t";	Sleep(1000);
	cout<<"(2)Faculty\n\n\t\t\t\t\t";	Sleep(1000);	
	cout<<"(3)Student\t ";	Sleep(1000);	
	cout<<"\nSelect Your Choice :";
	cin>>choice;
	system("cls");
	switch(choice)
	{	
		case 1:
			
			{q:
			string user,pass;
			cout<<"\nEnter Username :";
			cin.ignore();
			getline(cin,user);
			cout<<"\nEnter Password :";
		
			getline(cin,pass);
			if(user=="admin"&&pass=="1234")
			{system("cls");
				
			
			a:
				for(int i=0;i<111;i++)
	
		cout<<"\x2";
	cout<< "\n\n\n\t\t\t\t\tFast University Query System\n\n"<<endl;
	for(int i=0;i<111;i++)
	cout<<"\x2";
			system("Color 80");
			
			
			int c1;
			cout<<"\n\n\n\n(1)Register Student\t\t(2)Register Faculty\t\t\n\n\n(3)Display Students\t\t(4)Display Faculty\t\t\n\n\n(5)Delete Student\t\t(6)Delete Faculty\n\n\t\t\t(7)Main Menu:";
			
			cin>>c1;
			if(c1==1)
			{
				
			student s1;
			s1.input();	
			s1.create();
			getch();		
			}
			if(c1==2)
			{
				faculty f1;
				f1.input();
				f1.create();
			}
			if(c1==3)
			{char str[10];
			student s1;
			s1.readall();
			cout<<endl;
				cout<<"Search By Name/ID :";
				cin>>str;
				s1.readdata(str);
			}
			if(c1==4)
			{
			char str[10];
			faculty f1;
			f1.readall();
				cout<<"\nSearch By Name/ID :";
				cin>>str;
				f1.readdata(str);	
			}
			if(c1==5)
			{student s1;char name[100];char ch;
				cout<<"\nEnter Name or Id of the Student To Delete ";
				cin>>name;
				cout<<name;

				s1.readdata(name);
				cout<<"Are U Sure U Want To Delete This Record (y/n):";
				cin>>ch;
				cin.ignore();
				if(ch=='y')
				{
				s1.deletestudent(name);					
				}
				else cout<<"\nDeletion Stopped!";
				
				s1.readall();
			}
			
			if(c1==6)
			{
				faculty f1;char name[100];char ch;
				cout<<"\nEnter Name or Id of the Faculty To Delete ";
				cin>>name;
				cin.ignore();
				cout<<name;
				f1.readdata(name);
				cout<<"Are U Sure U Want To Delete This Record (y/n):";
				cin>>ch;
				cin.ignore();
				if(ch=='y')
				{
				f1.deletefaculty(name);					
				}
				else cout<<"\nDeletion Stopped!";
				f1.readall();
				
			}
			if(c1==7)
			goto k;
			
			system("pause");
			system("cls");			
			goto a;
	
		}
		else 
		{
			cout<<"\nWrong Entry!";goto q;
		}
	}
		break;
	 case 2:
			{
				for(int i=0;i<111;i++)
	
		cout<<"\x2";
	cout<< "\n\n\n\t\t\t\t\tFast University Query System\n\n"<<endl;
	for(int i=0;i<111;i++)
	cout<<"\x2";
			system("Color A0");
			char name[100],id[100];
			faculty f1;
		cout<<"Enter Your Name:" ;
		cin>>name;
		cin.ignore();
		cout<<"\nEnter ID :";
		cin>>id;
		cin.ignore();
		
		if(f1.login(name,id))
		{
		
	
		cout<<"Welcome!";
		
		system("pause");
		b:
		system("cls");
		cout<<"\n(1)Search Student\t(2)DisplayAll Students\t(3)Main-Menu\n:";
		int ch;
		cin>>ch;	
		if(ch==1)
		{char x;
			student s1;
			cout<<"\nEnter Student Name or ID :";
			cin>>name;
			cin.ignore();
			s1.readdata(name);
			cout<<"\nRespond?(y/n) :";
			cin>>x;
			if(x=='y');
			s1.respondquery(name);
			system("pause");
			goto b;
			}
			if(ch==2)
			{
				student s1;
				s1.readall();
				system("pause");
			goto b;
			}
			if(ch==3)
			{
				goto k;
				}	
		}
		
			
			}	break;	
			
		
		case 3:
			{
				for(int i=0;i<111;i++)
	
		cout<<"\x2";
	cout<< "\n\n\n\t\t\t\t\tFast University Query System\n\n"<<endl;
	for(int i=0;i<111;i++)
	cout<<"\x2";
	system("Color 17");	
		char name[100],id[100];
		char cc;	
		student s1;
		cout<<"\nEnter Your Name :";
		cin.ignore();
		cin.get(name,19);
		cout<<"\nEnter Your ID :";	
		cin>>id;
		cin.ignore();
		if(s1.login(name,id))
		{
			cout<<"\nDo U Want To Update Query :";
		cin>>cc;
	
		if(cc=='y')
		{
		cout<<"\n"<<name;
		s1.updatequery(name);
		}
		}
				
		
	}break;
	default:
		cout<<"\nEntered Wrong! Try Again\n";
		goto k;
 }
	char e;
	cout<<"\n\nEXIT? :";
	cin>>e;
	if(e!='y')
	goto k;



	
	
	
}
