#pragma once
class Student
{
private:
	char name[20];
	float nota_mate, nota_istorie, nota_eng, media;
public:
	void set_name(char* c);
	char* get_name();

	void set_nota_mate(float nota);
	float get_nota_mate();

	void set_nota_istorie(float nota);
	float get_nota_istorie();

	void set_nota_eng(float nota);
	float get_nota_eng();

	float get_media();
    
	//int compara_nume(Student s1, Student s2);
};

