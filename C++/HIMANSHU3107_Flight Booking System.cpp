#include <iostream>

using namespace std;

void setRoute(char *path[], float *fare, float *tfare){
	int i=0;
	for(i=0;i<5;i++){
		cout<<"Enter flight route:"<<endl;
		cout<<"Route ["<<i+1<<"] : ";
		path[i]=new char[100];
	    cin.ignore(1);
		cin.getline(path[i],100);
		cout<<"Enter fare: ";
		cin>>fare[i];
		tfare[i]=fare[i]+(fare[i]*19/100);
	}
}

void displayPath(char *path[],float *fare, float *tfare){
	int i=0;
	cout<<"Available flight routes are:"<<endl;
	for(i=0;i<5;i++){
		cout<<"Route ["<<i+1<<"] : "<<path[i]
		<<" - Fare: "<<fare[i]<<",Total Fare: "<<tfare[i]<<endl;
	}
}


int main(){
	//variable to store flight route
	char *route[5];
	float fare[5],totalFare[5];
	char name[30],path[100];
	int d,m,y;
	int routeId;

	setRoute(route,fare,totalFare);

	cout<<endl<<endl;
	cout<<"Enter name: ";
	cin.ignore(1);
	cin.getline(name,30);

	cout<<"Enter date of travel (d m y): ";
	cin>>d>>m>>y;

	displayPath(route,fare,totalFare);
	cout<<"Choose flight route (1 to 5): ";
	cin>>routeId;

	if(routeId<1 || routeId>5){
		cout<<"Invalid flight route!!!"<<endl;
		return 0;
	}

	cout<<endl<<endl;
	cout<<"Congratulations... "<<name<<" your ticket has been booked."<<endl;
	cout<<"Travel date is: "<<d<<"/"<<m<<"/"<<y<<endl;
	cout<<"Flight route: "<<route[routeId-1]<<endl;
	cout<<"Total fare is: "<<totalFare[routeId-1]<<endl;

	return 0;
}

