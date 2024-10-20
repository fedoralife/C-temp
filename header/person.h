#include <iostream>
class person {
public:
  person();
  person(person &&) = default;
  person(const person &) = default;
  person &operator=(person &&) = default;
  person &operator=(const person &) = default;
  
  void set_first_name(std::string fname);
  void set_age(int age);
  void set_last_name(std::string lname);
  void set_gender(char gender);
  std::string get_first_name();
  
  std::string get_last_name();
  int get_age();
  char get_gender();

  void set_password(std :: string password);
  std :: string get_password();
private:
    int mAge;
    std :: string mFirst_Name;
    std :: string mLast_Name;
    char mGender;
    std :: string password;
    std :: string position;
};






