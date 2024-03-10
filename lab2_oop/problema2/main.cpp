#include<iostream>
#include "Student.h"
#include<iomanip>

using namespace std;
int compara_nume(Student s1, Student s2)
{
	return strcmp(s1.get_name(), s2.get_name());
}
int compara_media(Student s1, Student s2)
{
	if (s1.get_media() > s2.get_media())
		return 1;
	else
		if (s1.get_media() == s2.get_media())
			return 0;
		else
			return -1;
}
int main()
{
	Student s1;
	s1.set_name((char*)"Messi");
	s1.set_nota_istorie(7.9);
	s1.set_nota_mate(10);
	s1.set_nota_eng(5);
	cout << s1.get_name() <<": "<< s1.get_media() << '\n';

	Student s2;
	s2.set_name((char*)"Ronaldo");
	s2.set_nota_istorie(10);
	s2.set_nota_mate(8.1);
	s2.set_nota_eng(10);
	cout << s2.get_name() <<": "<< s2.get_media() << '\n';
	cout << compara_nume(s1, s2)<<'\n';
	cout << compara_media(s2,s1);

}