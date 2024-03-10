#include "Student.h"
#include<string.h>

void Student::set_name(char* c)
{
	strcpy_s(this->name, 20, c);
}

char* Student::get_name()
{
	return this->name;
}

void Student::set_nota_mate(float n)
{
	this->nota_mate = n;
}

void Student::set_nota_istorie(float n)
{
	this->nota_istorie = n;
}
void Student::set_nota_eng(float n)
{
	this->nota_eng = n;
}
float  Student::get_nota_mate()
{
	return this->nota_mate;
}
float  Student::get_nota_istorie()
{
	return this->nota_istorie;
}
float  Student::get_nota_eng()
{
	return this->nota_eng;
}
float  Student::get_media()
{
	this->media = (get_nota_mate () + get_nota_eng() + get_nota_istorie()) / 3;
	return this->media;
}
/*int Student::compara_nume(Student s1, Student s2)
{
	return strcmp(s1.get_name(), s2.get_name());
}*/