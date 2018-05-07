//*****************************************************************************
//Filename:  Sullivan_Creg_Assignment_8
//Purpose:   To define a class to store the name of classes that a student
//           is enrolled in.
//Author:    Creg C. Sullivan Sr.
//Date:      April 7, 2010
//******************************************************************************

// Headers and other Technical Items

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Student
{
      friend istream & operator>>(istream & m, Student & n);
      //No additional Student &, will not enter cin
      
      friend ostream & operator<<(ostream & m, const Student & n);
      //Const Student &, call by reference, is faster
      
      public:
             Student();
             ~ Student();
             Student & operator =(const Student & n);
             
             void ResetClasses ();
             private:
                     string name;
                     int numClasses;
                     string*classList;
                                  };
  {                                   
 Student:: Student(): name(""), numClasses(0), classList(0);



Student::~Student(){
if(classList!=0)
delete[]classList;
}

istream & operator>>(istream & m, Student &n){
if(n.classList!=0)
delete[] n.classList;
}

{
cout<< "Enter student name:";
m>> n.name;
cout<< "Enter number of classes:";
m>> n.numClasses;
n.classList=new string[n.numClasses];

for(int i=0; i<n.numClasses; i==){
cout<< "Enter name of class"<<i+1<<":";
m>>n.classList[i];
}
return m;
}
ostream & operator <<(ostream & m, const Student & n){
m<<"Name:"<<n.name<<endl;
m<<"Number of classes:"<<n.numClasses<<endl;
for(int i=0; i<n.numClasses; i++)
m<<"class"<<i+1<<":"<<n.classList[i]<<endl;
return m;
}

Student & Student:: operator =(const Student & n){
if (classList!=0)
delete[]classList;
name = n.name;
numClasses = n.numClasses;

classList = new string[numClasses];
for(int i=0; i<numClasses; i++)
classList[i]= n.classList[i];
return*this;
}
void Student:: ResetClasses(){
numClasses=0;
if(classList!=0){
delete[]classList;
classList=0;
}
}
int main(){
Student s1,s2;

cin >> s1;
cout << endl;
cout <<"Student 1's data:"<<endl;
cout <<s1<<endl;

s2=s1;
cout<<"Student 2's data after assignment from student 1:"<<endl;
cout<< s2<<endl;

s1.ResetClasses();
cout<<"Student 1's data after reset:"<< endl;
cout<<s1<<endl;

cout<<"Student 2's data, should have original classes:"<<endl;
cout<<s2<<endl;
system("pause");
}
