#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
int main(){
	fstream f;
	f.open("H.txt",ios::in |ios::out |ios::app );
	char id[5];
	char name[20];
	char num[20];
	char visa[20];

	int choice;
	cout<<"Enter 1 to write  , 2 to Read  , 3 to search , 4 to delete , 5 to update \n";
	cin>>choice;
	cin.ignore();

	// ************************ Write ( Insert ) ************************
	if(choice==1){

		int request=1;
	while(request==1){
	cout<<"Enter id \n";
	cin.getline(id,5);
	cout<<"Enter NAme \n";
	cin.getline(name,20);
	cout<<"Enter num \n";
	cin.getline(num,20);
	cout<<"Enter Visa \n";
 	cin.getline(visa,20);

	f<<id<<"$"<<num<<"$"<<name<<"$"<<visa<<endl;
	cout<<"Press 1 to write again 2 to close ";
	cin>>request;
	cin.ignore();
}

	}

	// ************************ Read ( Display ) ************************


	else if(choice==2){

		while (!f.eof()){
	f.getline(id,5,'$');
	f.getline(name,20,'$');
	f.getline(num,20,'$');
	f.getline(visa,20);

	cout<<"id : "<<id<<" Name : "<<name<<" Num : "<<num<<" Visa : "<<visa<<"\n";
}



	}

	// ************************ Search ************************


	else if (choice==3){
		int flage=0;
		char s[20];
		cout<<"Enter name to search on \n ";
		cin.getline(s,20);

			while (!f.eof()){
	f.getline(id,5,'$');
	f.getline(num,20,'$');
	f.getline(name,20,'$');
	f.getline(visa,20);

	if (strcmp(s,name)==0){
		flage=1;
		cout<<"Found \n";
		cout<<"id : "<<id<<" Name : "<<name<<" Num : "<<num<<" Visa : "<<visa<<"\n";

	}

}
if(flage==0){
	cout<<"Not found \n";
}
	}

	// ************************ Search ************************


	else if(choice==4){
		fstream f2;
		f2.open("H2.txt",ios::in |ios::out |ios::app );
		char d[20];
		cout<<"Enter name to delete \n";
		cin.getline(d,20);
		while (!f.eof()){
	f.getline(id,5,'$');
	f.getline(num,20,'$');
	f.getline(name,20,'$');
	f.getline(visa,20);

	if (strcmp(d,name)==0){
		cout<<"Found and deleted \n";
		continue;
	}
	else{
			f2<<id<<"$"<<num<<"$"<<name<<"$"<<visa<<endl;
	}
	}
	f.close();
	f2.close();
	remove("H.txt");
	rename("H2.txt","H.txt");

}

// ************************ Search ************************

else if(choice==5){

	fstream f2;
		f2.open("H2.txt",ios::in |ios::out |ios::app );
		char u[20];
		cout<<"Enter name to update \n";
		cin.getline(u,20);
		while (!f.eof()){
	f.getline(id,5,'$');
	f.getline(num,20,'$');
	f.getline(name,20,'$');
	f.getline(visa,20);

	if (strcmp(u,name)==0){

		cout<<"Enter id \n";
	cin.getline(id,5);
	cout<<"Enter NAme \n";
	cin.getline(name,20);
	cout<<"Enter num \n";
	cin.getline(num,20);
	cout<<"Enter Visa \n";
	cin.getline(visa,20);

	f2<<id<<"$"<<num<<"$"<<name<<"$"<<visa<<endl;
	}
	else
	    {
			f2<<id<<"$"<<num<<"$"<<name<<"$"<<visa<<endl;
	    }
}
	f.close();
	f2.close();
	remove("H.txt");
	rename("H2.txt","H.txt");

}
}

