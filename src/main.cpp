#include <iostream>
#include "person.h"
int main (int argc, char *argv[]) {
  std :: cout << "Hello";
  person a;
  a.set_first_name("Tadios");
  std :: cout << a.get_first_name();
}
