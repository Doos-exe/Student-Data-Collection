#include <iostream>
#include <string>
#include <cstring>
#include <ctype.h>
using namespace std;

const int MAX = 100;
int num = 0;

struct Student
{
int StudentID;
char firstName[50];
char lastName[50];
float GPA;
};

void addStudent(Student students[100], int &numStudents);
void displayStudents(const Student students[100], int numStudents);
float calculateAverageGPA(const Student students[100], int numStudents);
void findStudentsByLastName(const Student students[100], int numStudents, const char lastName[50]);

int main(){
	int opt;
	float AveGPA;
	char Name[50];
	
	Student students[MAX];
	
	cout<<"Welcome to Student Database"<<endl;
	cout<<"This program will add or find the students' GPA!"<<endl;
	cout<<"Please choose an option\n"<<endl;
	
	while(true){
		cout<<"-----------------MAIN MENU-----------------"<<endl;	
		cout<<"[1] Add Student\n[2] Display All Students\n[3] Calculate Average GPA\n[4] Find Students by Last Name\n[5] Exit"<<endl<<"Choose a number: ";
		cin>>opt;
	
		switch (opt){
			case 1:
				addStudent(students, num);
				system("cls");
				break;
			case 2:
				displayStudents(students,num);
				system("cls");
				break;
			case 3:
				AveGPA = calculateAverageGPA(students, num);
				cout<<"\nThe Average GPA is "<<AveGPA<<"!";
				cin.ignore();
				cout<<"\nPress enter to continue...";
				cin.get();
				system("cls");
				break;
			case 4:
				cout<<"\nEnter the student's last name: ";
				cin.ignore();
				cin.getline(Name, 50);
				findStudentsByLastName(students, num, Name);
				system("cls");
				break;
			case 5:
				cout<<"Thank you for using!"<<endl;
				return 0;
			default:
				cout<<"That was not an option..."<<endl;
				cout<<"Please try again"<<endl;
				cin.ignore();
				cout<<"\nPress enter to continue...";
				cin.get();
				system("cls");
		}
	}

}

void addStudent(Student students[100], int &numStudents){
	char opt1, upopt1;
	char opt2, upopt2;
	
	Add:
	for (int x = numStudents; x <= 100; x++){
		cout<<"\n-----------------------------------------------"<<endl;
		cout<<"Enter First Name: ";
		cin.ignore();
		cin.getline(students[x].firstName, 50);
		cout<<"Enter Last Name: ";
		cin.getline(students[x].lastName, 50);
		cout<<"Enter the Student ID [9 Digit]: ";
		cin>>students[x].StudentID;
		cout<<"Enter the GPA: ";
		cin>>students[x].GPA;
		
		Opt1:
		cout<<"Are you sure about the information you inputted (Y/N)? ";
		cin>>opt1;
		upopt1 = toupper(opt1);
		switch (upopt1){
			case 'Y':
				break;
			case 'N':
				cout<<"Please re-enter the information needed";
				goto Add;
			default:
				cout<<"That was not an option..."<<endl;
				cout<<"Please try again"<<endl;
				goto Opt1;
			}
			
		numStudents++;
		
		Opt2:
			cout<<"Would you like to add another (Y/N)? ";
			cin>>opt2;
			upopt2 = toupper(opt2);
			switch (upopt2){
				case 'Y':
					break;
				case 'N':
					return;
				default:
					cout<<"That was not an option..."<<endl;
					cout<<"Please try again"<<endl;
					goto Opt2;
			}
		}
}

void displayStudents(const Student students[100], int numStudents){
	cout<<"\n-----------------------------------------------"<<endl;
	cout<<"\nThere are "<<numStudents<<" students!";
	
	if (numStudents == 0){
		cout<<"\nPlease add students in the database for us to display something!";
		cin.ignore();
		cout<<"\nPress enter to continue...";
		cin.get();
		return;
	}
	
	cout<<"\nHere is the list:"<<endl;
	for (int x = 0; x < numStudents; x++){
		cout<<students[x].StudentID<<"     "<<students[x].lastName<<", "<<students[x].firstName<<endl;
	}
	cin.ignore();
	cout<<"\nPress enter to continue...";
	cin.get();
}

float calculateAverageGPA(const Student students[100], int numStudents){
	float GPA = 0; 
	float Ave;
	
	cout<<"\n-----------------------------------------------"<<endl;
	for (int x = 0; x < numStudents; x++){
		GPA += students[x].GPA;
	}
	
	Ave = GPA / float(numStudents);
	return Ave;
}

void findStudentsByLastName(const Student students[100], int numStudents, const char lastName[50]){
	cout<<"\n-----------------------------------------------"<<endl;
				
	for (int x = 0; x < numStudents; x++){
		if (strcmp(students[x].lastName, lastName) == 0){
			cout<<students[x].StudentID<<"     "<<students[x].lastName<<", "<<students[x].firstName<<endl;
			cout<<"GPA: "<<students[x].GPA<<endl;
			cout<<"\nPress enter to continue...";
			cin.get();
			return;
			}
	}
	
	cout<<"\nIt looks like the last name you entered is not on the list or mispelled!";
	cout<<"\nPress enter to continue...";
	cin.get();
	return;
}
