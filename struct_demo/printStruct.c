#include <stdio.h>
#include <stdlib.h>

/* Macro*/
#define GET_FIELD_OFFSET(struct_name, fld_name) (int)(&((struct_name *)0)->fld_name)
#define GET_FIELD_SIZE(struct_name, fld_name) (int)sizeof(((struct_name *)0)->fld_name)
// makes compiler avoid adding padding bytes in structure
#pragma pack(push, 1)
typedef struct emp_
{
    char emp_name[30];
    unsigned int emp_id;
    unsigned int age;
    struct emp_ *mgr;
    float salary;
} emp_t;
#pragma pack(pop)

typedef struct _student
{
    char stud_name[32];
    int rollno;
    int age;
} student_t;

student_t students[] = {{"Gus", 1, 21}, {"Tommy", 2, 20}, {"Mitch", 3, 22}};

// Null structure is a C structure whose starting address is 0.
// ((emp_t*)0) null pinter of type emp_t
// &(((emp_t*)0)->emp_id) will give you the offset of the field emp_id

int main(int argc, char *argv[])
{
    printf("emp_t->emp_name:     %d\n size:       %d\n", GET_FIELD_OFFSET(emp_t, emp_name), GET_FIELD_SIZE(emp_t, emp_name));
    printf("emp_t->emp_id:       %d\n size:       %d\n", GET_FIELD_OFFSET(emp_t, emp_id), GET_FIELD_SIZE(emp_t, emp_id));
    printf("emp_t->age:          %d\n size:       %d\n", GET_FIELD_OFFSET(emp_t, age), GET_FIELD_SIZE(emp_t, age));
    printf("emp_t->mgr:          %d\n size:       %d\n", GET_FIELD_OFFSET(emp_t, mgr), GET_FIELD_SIZE(emp_t, mgr));
    printf("emp_t->emp_name:     %d\n size:       %d\n", GET_FIELD_OFFSET(emp_t, salary), GET_FIELD_SIZE(emp_t, salary));

    return 0;
}