#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main(){
	int c;
	cout<<"\t\t\t -------------------------\n\n\n";
	cout<<"\t\t\t Welcome to the Login page \n\n\n";
	cout<<"\t\t\t ----------Menu----------- \n\n\n";
	cout<<"                                   \n\n";
	cout<<"\t| Press 1 to LOGIN                      |"<<endl;
	cout<<"\t| Press 2 to REGISTER                   |"<<endl;
    cout<<"\t| Press 3 if you forgot your PASSWORD   |"<<endl;
    cout<<"\t| Press 4 to EXIT                       |"<<endl;
    cout<<"\n\t\t\t Please enter your choice : ";
    cin>>c;
    cout<<endl;
    
    switch(c){
    	case 1:
    		login();
    		break;
    	case 2:
    		registration();
    		break;
    	case 3:
    		forgot();
    		break;
    	case 4:
    		cout<<"\t\t\t THANKYOU! \n\n";
    		break;
    	default:
    		system("cls");
    		cout<<"\t\t\t Please select from the option given above \n"<<endl;
    		main();
	}
    
}
void login(){
	int count;
	string UserId, Password, Id, Pass;
	system("cls");
	cout<<"\t\t\t Please enter the username and password :"<<endl;
	cout<<"\t\t\t USERNAME ";
	cin>>UserId;
	cout<<"\t\t\t PASSWORD ";
	cin>>Password;
	
	ifstream input("records.txt");
	while(input>>Id>>Pass){
		if(Id == UserId && Pass==Password){
			count=1;
			system("cls");
		}
	}
	input.close();
	
	if(count==1){
		cout<<UserId<<"\n Your LOGIN is successfull \n Thanks for Logging in ! \n";
		main();
	}
	else{
		cout<<"\n LOGIN ERROR \n Please check your Username and Password\n";
		main();
		
	}		
}
void registration(){
	string rUserId,rPassword,rId,rPass;
	system("cls");
	cout<<"\t\t\t Enter the username : ";
	cin>>rUserId;
	cout<<"\t\t\t Enter the password : ";
	cin>>rPassword;
	ofstream f1("records.txt",ios::app); //ios->input output stream
	f1<<rUserId<<' '<<rPassword<<endl; //f1->object
	system("cls");
	cout<<"\n\t\t\t Registration is Successfull ! \n";
	main();
	
}
void forgot(){
	int option;
	system("cls");
	cout<<"\t\t\t You forgot the password? No worries \n";
	cout<<"Press 1 to search your id by username "<<endl;
	cout<<"Press 2 to go back to the main menu "<<endl;
	cout<<"\t\t\t Enter you choice : ";
	cin>>option;
	switch(option){
		case 1:
		{
			int count = 0;
			string sUserId,sId,sPass;
			cout<<"\n\t\t\t Enter the username which you remembered :";
			cin>>sUserId;
			
			ifstream f2("records.txt");
			while(f2>>sId>>sPass){
				if(sId==sUserId){
					count+=1;
				}
			}
			f2.close();
			if(count==1){
				cout<<"\n\n Your account is found! \n";
				cout<<"\n\n Your password is : "<<sPass;
				main();
				
			}
			else{
				cout<<"\n\t Sorry! Your account is not found! \n";
				main();
			}
			break;
		}
		case 2:
			{
			    main();	
			}
			default:
				cout<<"\t\t\t Wrong choice ! Please Try Again "<<endl;
			    forgot();
	}
}

