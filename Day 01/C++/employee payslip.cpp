#include<iostream>
using namespace std;
class Employee
{
    public:
    int id;
    string name,gender,designation;
    float basicsalary;
    public:
    void getinfo()
    {
        cout<<"enter the Employee id";
        cin>>id;
        cout<<" enter the Employee name";
        cin>>name;
        cout<<"enter gender and designation of the Employee";
        cin>>gender>>designation;
        cout<<"enter the basic salary of the Employee";
        cin>>basicsalary;
    }
};
class Payslip:public Employee
{
    public:
    int HRA,DA,grosspay,netpay;
   void gethada()
   {
	
	
    if(basicsalary<=20000)
    {
    	cout<<"if block\n";
        HRA= 20*0.01*basicsalary;
        DA=80*0.01*basicsalary;
    }
    else if((basicsalary>=20001 )&& (basicsalary<=40000))
    {
    	cout<<"elseif block\n";
        HRA=25*0.01*basicsalary;
        DA=90*0.01*basicsalary;
    }
    else
    {
    	cout<<"else block\n";
       HRA=30*0.01*basicsalary;
       DA=95*0.01*basicsalary;
    }
    grosspay= basicsalary+HRA+DA;
    int pf=10*0.01*basicsalary;
    netpay=grosspay-pf;
  }
  void printinfo()
  {
  	cout<<"employe name is: "<<name<<endl;
  	cout<<"emplye id is : "<<id<<endl;
  	cout<<"gender of the employee is : "<<gender<<endl;
  	cout<<"designation of the employye is :"<<designation<<endl;
  	cout<<"netpay= "<<netpay<<endl;
  }
    
};
int main()
{
    Payslip emp;
    emp.getinfo();
    emp.gethada();
    emp.printinfo();
}
