#include<iostream>
#include<fstream>
#include<string>
void line();
using namespace std;
class student						//declaring class student
{
	string fname,lname,course;
	int section;
	public:
		void add();
		void list();
		void modify();
		void delete_records();
};
int main()
{
	student s;
	int ch;
	while(true)							//Drives the code.
	{
		system("cls");
		line();							//To print a header a seperate function is called.
		cout<<"********************STUDENT DBMS********************";
		line();
		cout<<"\n\t\t\t\tEnter:"
    <<"\n\t\t\t\t\t1-Add Records."
		<<"\n\t\t\t\t\t2-List Records."
		<<"\n\t\t\t\t\t3-Modify Records."
		<<"\n\t\t\t\t\t4-Delete Records."
		<<"\n\t\t\t\t\t5-Exit Program."
		<<"\n\t\t\t\t\tYour Choice:-";
		fflush(stdin);
		cin>>ch;
		switch(ch)
		{
			case 1:
				s.add();				//add method is called in order to add data to the file.
				break;
			case 2:
				s.list();				//list method is called in order to print data from the file.
				break;
			case 3:
				s.modify();				//modify method is called in order to modify datas in the file.
				break;
			case 4:
				s.delete_records();		//delete_records method is called in order to delete data from the file.
				break;
			case 5:
				exit(0);				//To terminate the program.
		}
	}
}
void line()								//To print lines for the header.
{
	for(int i=0;i<150;i++)
	{
		cout<<"_";
	}
}
void student::add()						//To add data to the file.
{
	ofstream p;
	string s;
	p.open("students_db.txt",ios::app );	//opening 'students_db.txt' file.
	if(p)									//To check if file is opened.
	{
		while(true)
		{
			system("cls");
			cout<<"\nEnter Student Details:";	//Getting student Data.
			cout<<"\nEnter The First Name:\t";
			cin>>fname;
			cout<<"\nEnter The Last Name:\t";
			cin>>lname;
			cout<<"\nEnter Course:\t";
			cin>>course;
			cout<<"\nEnter Section:\t";
			cin>>section;
			p<<fname<<" "<<lname<<"\n"<<course<<"\n"<<section<<endl;	//Writing the data to the file.
			fflush(stdin);
			int n;
			cout<<"\nEnter 1 to add another record else enter 2:";
			cin>>n;
			if(n!=1)
			{
				break;
			}
		}
	}
	else			//If file did not open else block will be executed.
	{
		system("cls");
		cout<<"\nCould not open file.";
	}
	p.close();		//Closing the file.
}
void student::list()		//To print the file.
{
	system("cls");
	ifstream p;
	string str;
	p.open("students_db.txt");	//Opening the file with ifstream.
	int x=0;					//To check the line number as every students data will be covered in 3 lines.
	while (getline(p,str))		//to print data.
	{
		if (x%3==1)
			cout<<"Course:\t";
		if (x%3==2)
			cout<<"Section:\t";
		cout<<str<<endl;
		x++;
	}
	p.close();				//closing the file.
	system("pause");
}
void student::modify()		//To modify data in file.
{
	string t_name,str;
	while(true)				//LOOP is used to delete more than 1 record if required.
	{
		system("cls");
		int lp=0,c=0;
		cout<<"\nFirst Name of the Student to be modified: \t";
    	cin>>t_name;
	    ifstream x;
    	x.open("students_db.txt");		//Opening file with ifstream to read data from it.
	    ofstream temp;					//temporary file to write required data in it.
    	temp.open("temp.txt");
		x>>str;							//getting a word from students_db.txt file and stores it in str.
		int k=0;
		while (!x.eof())
    	{
       		if (t_name .compare(str)!=0 && lp==0)	//checks each string from the file if it matches with the string entered.
       		{
       			if (k==0)
       			{
    				temp << str<<" ";		//writes first name to the temp file.
    				k++;
    			}
   				else
    			{
    				temp<<str<<endl;		//writes all other data other than first name to the temp file.
    				k++;
    			}
	    		if (k==4)
    				k=0;
    		}
    		else
    		{
    			c=1;			// This is to show that changes are made in the data and that the name is found.
    			if(lp==0)
    			{
					lp=3;
					cout << "\nEnter new First Name :\t";	//Getting data to be modified.
					cin >> fname;
        			cout << "\nEnter new Last Name :\t";
	    		    cin >> lname;
			        cout << "\nEnter new Course    :\t";
        			cin >> course;
    	    		cout << "\nEnter new Section   :\t";
					cin >> section;
					temp<<fname<<" "<<lname<<"\n"<<course<<"\n"<<section<<endl;	//writing in temp file.
				}
				else
   					--lp;
			}
			x>>str;				//Stores the next word in str.
    	}
	    x.close();
    	temp.close();
   		remove("students_db.txt");				//removing students_db.txt file
	    rename("temp.txt", "students_db.txt"); // renaming temp.txt file as students_db.txt
		if (c!=0)
	   		cout<<"\nMODIFIED.";
		else
			cout<<"\nName not found.";
		int choice;
		cout<<"\nEnter 1 to delete another data else enter 2:\t";
		cin>>choice;
		if (choice!=1)
			break;
}

}
void student::delete_records()		//To delete records from the file.
{
	while(true)					//LOOP is used to delete more than 1 record if required.
	{
		system("cls");
		string t_name,str;
		int lp=0,c=0;
		cout<<"\nFirst Name of the Student: ";
	    cin>>t_name;	
    	ifstream x;
    	x.open("students_db.txt");		//Opening file with ifstream to read data from it.
	    ofstream temp;					//temporary file to write required data in it.
	    temp.open("temp.txt");
		x>>str;							//getting a word from students_db.txt file and stores it in str.
		int k=0;
		while (!x.eof())
    	{
       		if (t_name .compare(str)!=0 && lp==0)
       		{
       			if (k==0)
       			{
    				temp << str<<" ";
    				k++;
    			}
   				else
    			{
    				temp<<str<<endl;
    				k++;
    			}
	    		if (k==4)
    				k=0;
    		}
    		else
    		{
    			c=1;
    			if(lp==0)
					lp=3;
				else
   					--lp;
			}
			x>>str;					//Stores the next word in str.
    	}
    	x.close();
    	temp.close();
   		remove("students_db.txt");					//removing students_db.txt file.
	    rename("temp.txt", "students_db.txt");		 // renaming temp.txt file as students_db.txt.
		if (c!=0)
	   		cout<<"\nDELETED\n";
		else
			cout<<"\nName not found\n";
		int choice;
		cout<<"\nEnter 1 to delete another data else enter 2:\t";
		cin>>choice;
		if (choice!=1)
			break;
	}
}
