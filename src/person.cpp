#include "person.h"

void :: person :: set_first_name(std::string fname){
  mFirst_Name = fname;
}

void :: person:: set_last_name(std::string lname){
  mLast_Name = lname;
}

void :: person:: set_age(int age){
  mAge = age;
}
void :: person:: set_gender(char gender){
  mGender = gender;
}

std :: string person:: get_first_name(){
  return mFirst_Name;
}

std :: string person:: get_last_name(){
  return mLast_Name;
}

int :: person :: get_age(){
  return mAge;
}
char :: person :: get_gender(){
  return mGender;
}
void :: person ::  set_password(std::string pwd){
  password = pwd;
}
std :: string person :: get_password(){
  return password;
}
person :: person ()
{

mFirst_Name = "";
mLast_Name = "";
int age = 0;
char gender = 'M';
password = "";

}








