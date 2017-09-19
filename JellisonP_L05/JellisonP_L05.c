#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
	char name[20];
	int age;

	union {
		struct {
			char school[40];
		} child;
		struct {
			char college[40];
			float gpa;
		} student;
		struct {
			char company[40];
			int salary;
		} adult;
	} kind;		//end of union

	enum {childK, studentK, adultK} kindOfPerson;
};	//end of person struct
void Display();

void main()
{
	//Create non-dynamic stuct for Bob
	struct person person1;
	strcpy_s(person1.name, sizeof(person1.name), "Bob");
	person1.age = 20;
	strcpy_s(person1.kind.student.college, sizeof(person1.kind.student.college), "K-State");
	person1.kind.student.gpa = 3.5;
	person1.kindOfPerson = studentK;

	//Create dynamica struct for Allison - USE LAB 04
	struct person* personPtr;
	personPtr = malloc(sizeof(struct person));
	strcpy_s((*personPtr).name, sizeof((*personPtr).name), "Alison");
	(*personPtr).age = 10;
	strcpy_s((*personPtr).kind.child.school, sizeof((*personPtr).kind.child.school), "Amanda Arnold Elementary");
	(*personPtr).kindOfPerson = childK;

	//Display Structures
	Display(person1);
	Display(*personPtr);

	free(personPtr);
}

void Display(struct person p)
{
	printf("The name is %s\n", p.name);
	printf("The age is %d\n", p.age);

	if (p.kindOfPerson == studentK)
	{
		printf("The college of the student is %s\n", p.kind.student.college);
		printf("The gpa of the student is %.1f\n", p.kind.student.gpa);
	}
	else if (p.kindOfPerson == childK)
	{
		printf("The school of the kid is %s\n", p.kind.child.school);
	}
	else if(p.kindOfPerson == adultK)
	{
		printf("The company of the adult is %s\n", p.kind.adult.company);
		printf("The salary of the adult is %d\n", p.kind.adult.salary);
	}
	printf("\n");
}