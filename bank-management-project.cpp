
/************************************==BANK MANAGEMENT SYSTEM==****************************************************************************************
*
*																						   GROUP MEMBERS INTRO.
*																					NAME:SIMRANJEET KAUR, ROLL NO.1913128
*																					NAME:TANNU BANSAL,    ROLL NO.1913150

PURPOSE:
The main AIM of this project to develop software for bank management system.This project is developed using object oriented  in c++ language.
BANK MANAGEMENT SYSTEM is used to Keep the records of clients  in Bank. The system is an application for maintaining a personal
 account in a bank.the system provides the access to the employee of bank  to create an account,delete an account,deposit/withdraw the cash from his 
 account, also to view all the transactions and view reports of all account present.*/

//****HEADER FILE USED IN PROJECT******
#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include<iomanip>
using namespace std;

//****FUNCTION DECLARATION****
void f_write();        //function to write record in binary file
void f_read();         //function to read account details from binary file.
void f_search();       //function to search and show details of an account for a given Account no
void f_delete();       //function to delete record of file .
void f_update();       //function to update record of file.
void f_withdraw();     //function to withdraw amount for given account.
void f_deposit();      //function to deposit amount for given account.
void f_balance();      //function to check balance in account.
void f_transaction();  //function to show details of last transactions

class bank_acc
{
protected:
    char name[30],type;
    long long int acc_no;
    char address[30];
    long long int ph_no;
    int age;
    float amt;
public:
    long long int racc_no();
    float rbalance_();
    void create_();
    void update_();
    void show_();
};

class transaction:public bank_acc
{
private:
    float trans;
    char t_type[15];
public:
    void withdraw_(float);
    void deposit_(float);
    void show_trans();
};

long long int bank_acc::racc_no()// function to return account no of particular record.
{
    return acc_no;
}
float bank_acc::rbalance_()  //function to return balance of a given Account no
{
    return amt;
}
void bank_acc::create_()       //function to get data from user
{
    cout<<"\n\t\t\t\t\t\t\t\t\t*.......REGISTRATION FORM.......*";
    cout<<"\n\n\tPERSONAL INFORMATION-->\n";

    cout<<"\t\tENTER NAME :  ";
    cin.ignore();
    cin.getline(name,30);
    cout<<"\t\tENTER MOBILE NO: ";
    cin>>ph_no;
    cout<<"\t\tENTER AGE: ";
    cin>>age;
    cout<<"\t\tENTER ADDRESS(city,state,country): ";
    cin.ignore();
    cin.getline(address,30);
    cout<<"\n\tBANK ACCOUNT-->\n";
    cout<<"\t\tENTER ACCOUNT NUMBER: ";
    cin>>acc_no;
    cout<<"\t\tENTER ACCOUNT TYPE(C/S): ";       //C-->CURRENT ACCOUNT,S-->SAVING ACCOUNT
    cin>>type;
    type=toupper(type);
    cout<<"\n\tENTER AMOUNT(>=500 for Saving && >=1000 for Current): ";
    cin>>amt;
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t***ACCOUNT CREATED.....*";
}
void bank_acc::update_()                   //function to modify existing data
{
    int i;

    cout<<"\n\t1.PRESS 1 TO UPDATE NAME: ";
    cin>>i;
    if(i==1)
    {
        cout<<"\n\t\t-->ENTER NEW NAME: ";
        cin.ignore();
        cin.getline(name,30);
    }
    cout<<"\n\t2.PRESS 1 TO UPDATE MOBILE NO: ";
    cin>>i;
    if(i==1)
    {
        cout<<"\n\t\t-->ENTER NEW MOBILE NO:";
        cin>>ph_no;
    }
    cout<<"\n\t3.PRESS 1 TO UPDATE AGE: ";
    cin>>i;
    if(i==1)
    {
        cout<<"\n\t\t-->ENTER AGE:";
        cin>>age;
    }
    cout<<"\n\t4.PRESS 1 TO UPDATE ADDRESS:  ";
    cin>>i;
    if(i==1)
    {
        cout<<"\n\t\t-->ENTER ADDRESS(city,state,country):";
        cin.ignore();
        cin.getline(address,30);
    }

    cout<<"\n\t5.PRESS 1 TO UPDATE ACCOUNT TYPE: ";
    cin>>i;
    if(i==1)
    {
        cout<<"\n\t\t-->ENTER ACCOUNT TYPE(C/S):";
        cin>>type;
    }
}
void bank_acc::show_()        //function to show data on output screen
{
    // cout<<"\n\n**DETAILS ABOUT ACCOUNT HOLDER**\n";
    cout<<setw(30)<<"AC_NAME"<<setw(20)<<"AC_TYPE"<<setw(20)<<"ACC_NO"<<setw(40)<<"ADDRESS(city,state,country)"<<setw(15)<<"PH_NO"<<setw(10)<<"AGE"<<setw(20)<<"BALANCE"<<"\n";
    cout<<setw(30)<<name<<setw(20)<<type<<setw(20)<<acc_no<<setw(40)<<address<<setw(15)<<ph_no<<setw(10)<<age<<setw(20)<<amt<<"\n\n";
}

void transaction::show_trans()   //function to show last transaction record from transaction binary file.
{
    cout<<setw(30)<<"AC_NAME"<<setw(9)<<"AC_TYPE"<<setw(15)<<"ACC_NO"<<setw(15)<<"TRANS. TYPE"<<setw(10)<<"TR_AMOUNT"<<setw(9)<<"BALANCE"<<"\n";
    cout<<setw(30)<<name<<setw(9)<<type<<setw(15)<<acc_no<<setw(15)<<t_type<<setw(10)<<trans<<setw(9)<<amt<<"\n";
}

void transaction::withdraw_(float with)// function to withdraw money from a particular account
{
    if(with>amt)
        cout<<"\nINSUFFICIENT BALANCE!!\n";
    else
    {
        fstream obj;
        trans=with;
        strcpy(t_type,"WITHDRAW");
        obj.open("trans.dat",ios::binary|ios::out|ios::app);
        amt=amt-with;
        obj.write((char*)this,sizeof(*this));
        cout<<"\nUPDATED BALANCE IS: "<<amt;
        obj.close();

    }
}
void transaction::deposit_(float dep)//function to withdraw money into a particular account
{
    if(dep+amt>1000000)
        cout<<"\nLIMIT EXCEED!!\n";
    else
    {
        fstream obj;
        trans=dep;
        strcpy(t_type,"DEPOSIT");
        obj.open("trans.dat",ios::binary|ios::out|ios::app);

        amt=amt+dep;
        obj.write((char*)this,sizeof(*this));
        cout<<"\nUPDATED BALANCE IS: "<<amt;
        obj.close();
    }
}
bool passwords()				//Checks for correct password
{
	int i=0;
	char ch,st[21],ch1[21]={"0000"};
	cout<<"\n\n\t\tEnter Password : ";
	while(1)
    {
    	ch=getch();
    	if(ch==13)
    	{
        	st[i]='\0';
        	break;
    	}
    	else if(ch==8&&i>0)
    	{
        	i--;
        	cout<<"\b \b";
    	}
    	else
    	{
    		cout<<"*";
    		st[i]=ch;
    		i++;
    	}
    }
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    	return 1;
    else
    	return 0;
}
//********************MAIN FUNCTION OF PROGRAM************************
int main()
{
	
    int choice;
    while(1)
    {
		cout<<"\n***************************************************************************************************************************************************************************";
        cout<<"\n\t\t\t\t\t\t\t\t\t BANK MANAGEMENT SYSTEM\n";
        cout<<"**************************************************************************************************************************************************************************";
        bool a=passwords();
        if(!a)
        {
        	for(int i=0;i<2;i++)
		{
			cout<<"\nWrong password";
			cout<<"\nYou have "<<2-i<<"attempts left";
			if(passwords())
			break;
			if(i==1)
			{
				cout<<"\n\n\n\t\t\t All attempts failed........";
				cout<<"\n\n\t\t\t Sorry, but you can't login";
				exit(0);
			}
		}
		}
		system("cls");
        cout<<"\n***************************************************************************************************************************************************************************";
        cout<<"\n\t\t\t\t\t\t\t\t\t BANK MANAGEMENT SYSTEM\n";
        cout<<"**************************************************************************************************************************************************************************";
        cout<<"\n\n\t\t\t\t\t\t\t\t\t------MAIN MENU------\n\n";
        cout<<"\t1.CREATE ACCOUNT\n ";
        cout<<"\t2.SHOW DETAILS\n";
        cout<<"\t3.SEARCH ACCOUNT\n";
        cout<<"\t4.DELETE ACCOUNT\n";
        cout<<"\t5.UPDATE ACCOUNT\n";
        cout<<"\t6.WITHDRAW AMOUNT\n";
        cout<<"\t7.DEPOSITE AMOUNT\n";
        cout<<"\t8.CHECK BALANCE\n";
        cout<<"\t9.SHOW  TRANSACTIONS\n";
        cout<<"\t10.EXIT\n";
        cout<<"\nSELECT AN OPTION : ";
        cin>>choice;
        // clrscr();
        system("cls");
        switch(choice)
        {
        case 1:
            f_write();
            break;
        case 2:
            f_read();
            break;
        case 3:
            f_search();
            break;
        case 4:
            f_delete();
            break;
        case 5:
            f_update();
            break;
        case 6:
            f_withdraw();
            break;
        case 7:
            f_deposit();
            break;
        case 8:
            f_balance();
            break;
        case 9:
            f_transaction();
            break;

        case 10:
        {
            cout<<"\n(.)THANK YOU (.)\n";
            exit(0);
        }
        default:
            cout<<"\n==WRONG CHOICE==\n";
        }
        cout<<"\nPRESS ANY KEY TO BACK:\n";
        char key;
        cin>>key;
        //clrscr();
        system("cls");
    }

    return 0;
}
//****FUNCTION TO WRITE IN FILE****
void f_write()
{
    transaction a;
    fstream obj;
    obj.open("bank.dat",ios::binary|ios::out|ios::app);
    cout<<"\n\n\t\t\t\t\t\t\t\t\t------CREATING ACCOUNT------\n\n";
    a.create_();
    obj.write((char*)&a,sizeof(a));
    obj.close();
}
//****FUNCTION TO READ RECORD FROM FILE****
void f_read()
{
    transaction a;
    fstream obj;
    obj.open("bank.dat",ios::binary|ios::in);
    obj.seekg(ios::beg);
    cout<<"\n\n\t\t\t\t\t\t\t\t\t------ACCOUNT HOLDER'S DETAILS------\n\n";
    while(obj.read((char*)&a,sizeof(a)))
    {
        a.show_();
    }
    obj.close();
}
//****FUNCTION TO SEARCH RECORD FROM FILE****
void f_search()
{
    transaction a;
    fstream obj;
    int flag=0;
    long long int ano;
    cout<<"\n\n\t\t\t\t\t\t\t\t\t------SEARCHING ACCOUNT------\n\n";
    cout<<"\nENTER THE ACCOUNT NO: ";
    cin>>ano;
    obj.open("bank.dat",ios::binary|ios::in);
    obj.seekg(ios::beg);

    while(obj.read((char*)&a,sizeof(a)))
    {
        if(a.racc_no()==ano)
        {
            cout<<"\n==USER FOUND==\n";
            a.show_();
            flag=1;
        }
    }
    obj.close();
    if(flag==0)
        cout<<"\n==USER NOT FOUND==\n";
}
//****FUNCTION TO DELETE RECORD OF FILE****
void f_delete()
{
    transaction a;
    fstream obj,obj2;
    int flag=0;
    long long int ano;
    cout<<"\n\n\t\t\t\t\t\t\t\t\t------DELETING ACCOUNT------\n\n";
    cout<<"\nENTER THE ACCOUNT NO: ";
    cin>>ano;
    obj.open("bank.dat",ios::binary|ios::in);
    obj2.open("new.dat",ios::binary|ios::out);
    obj.seekg(0,ios::beg);

    obj2.seekp(0,ios::beg);

    while(obj.read((char*)&a,sizeof(a)))
    {
        if(a.racc_no()!=ano)
            obj2.write((char*)&a,sizeof(a));
        else
        {
            printf("\n==ACCOUNT DELETED==\n");
            flag=1;
        }
    }
    obj.close();
    obj2.close();
    remove("bank.dat");
    rename("new.dat","bank.dat");
    if(flag==0)
        cout<<"\n==USER NOT FOUND==\n";
}
//****FUNCTION TO MODIFY RECORD OF FILE****
void f_update()
{
    transaction a;
    fstream obj,obj2;
    int flag=0;
    long long int ano;
    cout<<"\n\n\t\t\t\t\t\t\t\t\t------UPDATING DETAILS------\n\n";
    cout<<"\nENTER THE ACCOUNT NO: ";
    cin>>ano;
    obj.open("bank.dat",ios::binary|ios::in);
    obj2.open("new.dat",ios::binary|ios::out);
    obj.seekg(ios::beg);
    obj2.seekp(ios::beg);

    while(obj.read((char*)&a,sizeof(a)))
    {
        if(a.racc_no()==ano)
        {
            flag=1;
            a.update_();
            cout<<"\n==ACCOUNT UPDATED==\n";
        }
        obj2.write((char*)&a,sizeof(a));

    }
    obj.close();
    obj2.close();
    remove("bank.dat");
    rename("new.dat","bank.dat");
    if(flag==0)
        cout<<"\n==USER NOT FOUND==\n";
}
//****FUNCTION TO WITHDRAW AMOUNT****
void f_withdraw()
{
    transaction a;
    fstream obj,obj2;
    int flag=0;
    long long int ano;
    cout<<"\n\n\t\t\t\t\t\t\t\t\t------WITHDRAWING MONEY------\n\n";
    cout<<"\nENTER THE ACCOUNT NO: ";
    cin>>ano;
    obj.open("bank.dat",ios::binary|ios::in);
    obj2.open("new.dat",ios::binary|ios::out);
    obj.seekg(ios::beg);
    obj2.seekp(ios::beg);

    while(obj.read((char*)&a,sizeof(a)))
    {
        if(a.racc_no()==ano)
        {
            float with;
            cout<<"\nENTER THE AMOUNT TO WITHDRAW: ";
            cin>>with;
            a.withdraw_(with);

            flag=1;
        }
        obj2.write((char*)&a,sizeof(a));

    }

    obj.close();
    obj2.close();
    remove("bank.dat");
    rename("new.dat","bank.dat");
    if(flag==0)
        cout<<"\n==USER NOT FOUND==\n";
}
//****FUNCTION TO DEPOSIT AMOUNT****
void f_deposit()
{
    transaction a;
    fstream obj,obj2;
    int flag=0;
    long long int ano;
    cout<<"\n\n\t\t\t\t\t\t\t\t\t------DEPOSITING MONEY------\n\n";
    cout<<"\nENTER THE ACCOUNT NO: ";
    cin>>ano;
    obj.open("bank.dat",ios::binary|ios::in);
    obj2.open("new.dat",ios::binary|ios::out);
    obj.seekg(ios::beg);
    obj2.seekp(ios::beg);

    while(obj.read((char*)&a,sizeof(a)))
    {
        if(a.racc_no()==ano)
        {
            float dep;
            cout<<"\nENTER THE AMOUNT TO DEPOSIT: ";
            cin>>dep;
            a.deposit_(dep);

            flag=1;
        }
        obj2.write((char*)&a,sizeof(a));
    }

    obj.close();
    obj2.close();
    remove("bank.dat");
    rename("new.dat","bank.dat");
    if(flag==0)
        cout<<"\n==USER NOT FOUND==\n";
}

//****FUNCTION TO CHECK BALANCE****
void f_balance()
{
    transaction a;
    fstream obj,obj2;
    int flag=0;
    long long int ano;
    cout<<"\n\n\t\t\t\t\t\t\t\t\t------CHECKING BALANCE------\n\n";
    cout<<"\nENTER THE ACCOUNT NO: ";
    cin>>ano;
    obj.open("bank.dat",ios::in|ios::out);

    while(obj.read((char*)&a,sizeof(a)))
    {
        if(a.racc_no()==ano)
        {
            cout<<"\nBALANCE IS: "<<a.rbalance_();
            flag=1;
        }
    }
    obj.close();
    if(flag==0)
        cout<<"\n==USER NOT FOUND==\n";
}
//****FUNCTION TO SHOW LAST TRANSACTIONs ****
void f_transaction()
{
    transaction a;
    fstream obj,obj2;
    obj.open("trans.dat",ios::binary|ios::in|ios::out);
    obj.seekg(ios::beg);
    cout<<"\n\n\t\t\t\t\t\t\t\t\t------LAST TRANSACTIONS LIST------\n\n";
    while(obj.read((char*)&a,sizeof(a)))
    {
        a.show_trans();
    }
    obj.close();
}
