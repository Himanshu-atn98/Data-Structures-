#include<stdio.h>
void addStudent();
void editStudent();
void deleteStudent();
void searchStudent();
void displayListOfStudents();
struct Student
{ 
int rollNumber;
char name[21];
};
int main()
{
int ch,z;
while(1)
{
printf("1. Add student\n");
printf("2. Edit student\n");
printf("3. Delete student\n");
printf("4. Search student\n");
printf("5. Display list of students\n");
printf("6. Exit\n");
printf("Enter your choice : ");
scanf("%d",&ch);
fflush(stdin);
if(ch==1)
{
 addStudent();
}
if(ch==2)
{
 editStudent();
} 
if(ch==3)
{
deleteStudent();
} 
if(ch==4)
{
searchStudent();
} 
if(ch==5)
{
displayListOfStudents();
} 
if(ch==6)
{
break;
}
}
return 0;
}

//addStudent()
void addStudent()
{
struct Student g,t;
FILE *f;
char m;
printf("Enter roll number : ");
scanf("%d",&g.rollNumber);
fflush(stdin);
if(g.rollNumber<=0)
{
printf("Invalid roll number\n");
return;
}
f=fopen("studstud.dat","rb");
if(f!=NULL)
{
while(1)
{
fread(&t,sizeof(struct Student),1,f);
if(feof(f)) break;
if(g.rollNumber==t.rollNumber)
{
fclose(f);
printf("That roll number alloted to %s\n",t.name);
return;
}}
fclose(f);
}
printf("Enter name : ");
gets(g.name);
fflush(stdin);
printf("Save (Y/N) : ");
scanf("%c",&m);
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("Student not added\n");
return;
}
f=fopen("studstud.dat","ab");
fwrite(&g,sizeof(struct Student),1,f);
fclose(f);
printf("Student added\n");
}

//editStudent()
void editStudent()
{
struct Student g,t;
FILE *f1,*f2;
char m;
int found;
printf("Enter roll number of the student to edit : ");
scanf("%d",&g.rollNumber);
fflush(stdin);
if(g.rollNumber<=0)
{
printf("Invalid roll number\n");
return;
}
f1=fopen("studstud.dat","rb");
if(f1==NULL)
{
printf("Invalid roll number\n");
return;
}
found=0;
while(1)
{
fread(&t,sizeof(struct Student),1,f1);
if(feof(f1)) break;
if(g.rollNumber==t.rollNumber)
{
found=1;
break;
}
}
fclose(f1);
if(found==0)
{
printf("Invalid roll number\n");
return;
}
printf("Name : %s\n",t.name);
printf("Edit (Y/N) : ");
scanf("%c",&m);
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("Student not edited\n");
return;
}
printf("Enter new name : ");
gets(g.name);
fflush(stdin);
printf("Update (Y/N) : ");
scanf("%c",&m);
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("Student not updated\n");
return;
}
f1=fopen("studstud.dat","rb");
f2=fopen("fhaltu.dat","wb"); // blank new file
while(1)
{
fread(&t,sizeof(struct Student),1,f1);
if(feof(f1)) break;
if(g.rollNumber==t.rollNumber)
{
fwrite(&g,sizeof(struct Student),1,f2);
} else
{
fwrite(&t,sizeof(struct Student),1,f2);
}
}
fclose(f1);
fclose(f2);
f1=fopen("studstud.dat","wb"); // blank new file
f2=fopen("fhaltu.dat","rb");
while(1)
{
fread(&t,sizeof(struct Student),1,f2);
if(feof(f2)) break;
fwrite(&t,sizeof(struct Student),1,f1);
}
fclose(f1);
fclose(f2);
f2=fopen("fhaltu.dat","wb"); // blank new file
fclose(f2);
printf("Student updated\n");
}

//deleteStudent()
void deleteStudent()
{
struct Student g,t;
FILE *f1,*f2;
char m;
int found;
printf("Enter roll number of the student to delete : ");
scanf("%d",&g.rollNumber);
fflush(stdin);
if(g.rollNumber<=0)
{
printf("Invalid roll number\n");
return;
}
f1=fopen("studstud.dat","rb");
if(f1==NULL)
{
printf("Invalid roll number\n");
return;
}
found=0;
while(1)
{
fread(&t,sizeof(struct Student),1,f1);
if(feof(f1)) break;
if(g.rollNumber==t.rollNumber)
{
found=1;
break;
}}
fclose(f1);
if(found==0)
{
printf("Invalid roll number\n");
return;
}
printf("Name : %s\n",t.name);
printf("Delete (Y/N) : ");
scanf("%c",&m);
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("Student not deleted\n");
return;
}
f1=fopen("studstud.dat","rb");
f2=fopen("fhaltu.dat","wb"); // blank new file
while(1)
{
fread(&t,sizeof(struct Student),1,f1);
if(feof(f1)) break;
if(g.rollNumber!=t.rollNumber)
{
fwrite(&t,sizeof(struct Student),1,f2);
}
}
fclose(f1);
fclose(f2);
f1=fopen("studstud.dat","wb"); // blank new file
f2=fopen("fhaltu.dat","rb");
while(1)
{
fread(&t,sizeof(struct Student),1,f2);
if(feof(f2)) break;
fwrite(&t,sizeof(struct Student),1,f1);
}
fclose(f1);
fclose(f2);
f2=fopen("fhaltu.dat","wb"); // blank new file
fclose(f2);
printf("Student deleted\n");
}

//searchStudent()
void searchStudent()
{ 
int k;
struct Student t;
FILE *f;
printf("Enter roll number of the student to search : ");
scanf("%d",&k);
if(k<=0)
{
printf("Invalid roll number\n");
return;
}
f=fopen("studstud.dat","rb");
if(f==NULL)
{
printf("Invalid roll number\n");
return;
}
while(1)
{
fread(&t,sizeof(struct Student),1,f);
if(feof(f)) break;
if(k==t.rollNumber)
{
printf("Name : %s\n",t.name);
fclose(f);
return;
}
}
fclose(f);
printf("Invalid roll number\n");
}
//displayListOfStudents()
void displayListOfStudents()
{
FILE *f;
struct Student g;
f=fopen("studstud.dat","rb");
if(f==NULL)
{
printf("No records\n");
return;
}
while(1)
{
fread(&g,sizeof(struct Student),1,f);
if(feof(f)) break;
printf("Roll number %d, Name %s\n",g.rollNumber,g.name);
}
fclose(f);
}