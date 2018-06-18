#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h> 
#define YEAR 2015
#define MON 9
#define DAY 25
#define HOUR 23
#define MIN 59
#define SEC 59
int student_checkin();/*ѧ����¼����ԭ��*/ 
void classelectf(int);/*ѧ��ѡ�κ���ԭ��*/
void classSearchClassinf();/*���γ�����ѯ�γ���Ϣ����ԭ��*/
void schoolsearchinf();/*������ѧԺ��ѯ�γ���Ϣ����ԭ��*/
void class_reorder();/*�γ�������ԭ��*/
void stuclass_check(int);/*ѧ����ѡ�γ̲�ѯ����ԭ��*/
void stuclass_delete(int );/*ѧ���γ�ɾ������ԭ��*/
void persclassinf(int);/*��ʦ��ѯ���˿�����Ϣ����ԭ��*/
int teacher_checkin();/*��ʦ��¼����*/ 
void nameSearchStuinf();/*��ѧ��������ѯѧ����Ϣ����ԭ��*/
void orderclassinf(int);/*ͳ��ѡ����Ϣ����ԭ��*/
void classSearchStuinf();/*���γ�����ѯѧ����Ϣ����ԭ��*/
void addClass(int);/*�γ���Ӻ���ԭ��*/
void modiclassinf(int);/*�޸Ŀγ���Ϣ����ԭ��*/
void deleteclass(int);/*��ʦɾ�κ���ԭ��*/
void teacher_information(int);/*��ʦ��Ϣ�޸ĺ���*/ 
void autodelete();/*�Զ�ɾ����������γ̺���ԭ��*/
void student_information(int);/*ѧ���޸ĸ�����Ϣ����ԭ��*/



int main()
{
  int loginCode, funCode, clacheckCode, checkcode, manageCode, code, code1, code2;
  int year,mon,day,hour,min,sec, test; 
  int ID;
  tm mytime;
  FILE *infile;
  struct Classinf {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };

  printf("��ӭʹ��ѡ��ϵͳ\n");
  printf("\n�������Ӧ����ѡ�����ĵ�¼��ʽ��1-ѧ����¼��2-��ʦ��¼, ��������-�˳�����\n");
  scanf("%d", &loginCode);
  switch(loginCode)
{
case 1:  /*ѧ��ģ��*/
  ID=student_checkin();
  mainpage1:
  {
  printf("\n�������Ӧ����ѡ����Ӧ��飺1-ѡ��ģ�飬2-��ѯ�γ�ģ�飬3-ѧ��������Ϣ����ģ��, ��������-�˳�����\n");
  scanf("%d", &funCode);
  switch (funCode) 
  {
   case 1:/*����ѡ�ι���ģ��*/
   printf("\n����������ڵ����пγ���Ϣ\n\n");
   
   printf("\n���   ����         ѧ�� ѧʱ ����  ��ʦ   ʱ��  �ص�  ��������  �̲�  ��ѡ����\n");
   infile = fopen("�γ���Ϣ.txt", "r");
   struct Classinf classinf;
   while (fscanf(infile, "%d %s %d %d %s %s %s %d %s %d %s %s %d",&classinf.classid, classinf.classname, &classinf.credit, &classinf.totaltime, classinf.type, classinf.teacher, classinf.term, &classinf.time, classinf.place, &classinf.limnum, classinf.briefinf, classinf.book, &classinf.numalready)!=EOF)
   printf("%d %-12s %d    %d   %s  %-6s %d   %s %-3d %-18s %d\n", classinf.classid, classinf.classname, classinf.credit, classinf.totaltime, classinf.type, classinf.teacher, classinf.time, classinf.place, classinf.limnum, classinf.book, classinf.numalready);
   fclose (infile);
   
   _getsystime(&mytime);/*��ȡϵͳʱ��*/      
   year=mytime.tm_year+1900;  
   mon=mytime.tm_mon+1;     
   day=mytime.tm_mday;   
   hour=mytime.tm_hour;  
   min=mytime.tm_min;   
   sec=mytime.tm_sec; 
   
   if (year<YEAR)
 test = 1;
 else
 {
  if (year>YEAR)
  {
  	test = 0;
  }
  else 
  {
   if (mon<MON)
   {
   	test = 1;
   }
   else
   {
   	if (mon>MON)
   	{
   		test = 0;
	   }
	   else
	   {
	   	if (day<DAY)
	   	{
	   		test = 1;
		   }
		   else
		   {
		   	if (day>DAY)
		   	{
		   		test = 0;
			   }
			   else
			   {
			   	if (hour<HOUR)
			   	{
			   		test = 1;
				   }
				   else 
				   {
				   	if (min<MIN)
				   	{
				   		test = 1;
					   }
					   else 
					   {
					   	if (sec<SEC)
					   	{
					   		test = 1;
						   }
						   else
						   test = 0;
					   }
				   }
			   }
		   }
	   }
   }
  }
 }
   if(test==1)
   {
   classelectf(ID);/*����ѡ�κ���*/ 
   printf("\n���ڽ����ص�½�ɹ�����\n");
   goto mainpage1;/*���breakֱ�ӷ��ع���ѡ�����*/
   }
   else
   {
   	printf("\n������ֹʱ�䣬���ڷ��سɹ���¼����\n\n");
   	goto mainpage1;
   }
   
   
   case 2:/*�����ѯ�γ�ģ��*/
   printf("\n�������Ӧ����ѡ����Ӧ���: 1-���γ�����ѯ, 2-������ѧԺ��ѯ, 3-����������ѡ�������������пγ�\n");
   scanf("%d", &clacheckCode);
   switch (clacheckCode)
{
   	case 1:
     classSearchClassinf();/*���ð��γ�����ѯ�γ���Ϣ����*/ 
     printf("\n�������Ӧ����ѡ����Ӧѡ��: 1-����γ̱��ѡ��, 2-���ع���ѡ�����\n");
     scanf("%d", &checkcode);
     switch(checkcode)
     {
     	case 1:
     	classelectf(ID);/*����ѡ�κ���*/ 
     	printf("\n���ڽ����ص�½�ɹ�����\n\n");
     	goto mainpage1;
     	
     	case 2:
        goto mainpage1;
	 }
   	case 2:
   	   schoolsearchinf();/*���ð�����ѧԺ��ѯ�γ���Ϣ����*/ 
   	   printf("\n�������Ӧ����ѡ����Ӧѡ��: 1-����γ̱��ѡ��, 2-���ع���ѡ�����\n");
   	   scanf("%d", &checkcode);
       switch(checkcode)
       {
     	case 1:
     	classelectf(ID);/*����ѡ�κ���*/
     	printf("\n���ڽ����ص�½�ɹ�����\n\n");
     	goto mainpage1;
     	
     	case 2:
        goto mainpage1;
	   }
	case 3:
	  class_reorder();/*���ÿγ�������*/
	  printf("\n\n�������Ӧ����ѡ����Ӧѡ��: 1-����γ̱��ѡ��, 2-���ع���ѡ�����\n");
	  scanf("%d", &checkcode);
       switch(checkcode)
       {
     	case 1:
     	classelectf(ID);/*����ѡ�κ���*/
     	printf("\n���ڽ����ص�½�ɹ�����\n\n");
     	goto mainpage1;
     	
     	case 2:
        goto mainpage1;
	   }

}
	   
	   
	   
    case 3:/*����ѧ��������Ϣ����ģ��*/
	printf("\n�������Ӧ����ѡ����Ӧ���: 1-��ѯ��ѡ�γ�, 2-ɾ����ѡ�γ�, 3-������Ϣ����\n");
    scanf("%d", &manageCode);
    switch (manageCode)
    {
     case 1:
     stuclass_check(ID);/*����ѧ����ѯ��ѡ�γ̺���*/
     printf("\n���ڷ��سɹ���½����\n\n");
     goto mainpage1;
     
     case 2:
      stuclass_delete(ID);/*����ɾ����ѡ�γ̺���*/
      printf("\n���ڷ��سɹ���½����\n\n");
      goto mainpage1;
      
     case 3:
      student_information(ID);/*���ø�����Ϣ������*/
      
      printf("\n���ڽ����ص�½�ɹ�����\n\n");
      goto mainpage1;
	  
	}
     default:/*�˳�����*/ 
    printf("\n��лʹ�ã��ټ���\n");
    exit(1);
  }
  }
 
 
  case 2:/*��ʦģ��*/
  ID=teacher_checkin();
  mainpage2:
{
  printf("\n�ɹ���¼���������Ӧ����ѡ����Ӧ��飺1-ѡ�ι���ģ�飬2-�γ̹���ģ�飬3-��ʦ������Ϣ����ģ��, ��������-�˳�����\n");
  scanf("%d", &funCode);
  switch (funCode)
  {
   case 1:/*����ѡ�ι���ģ��*/
   autodelete();/*�����Զ�ɾ�����ſγ̺���*/
   printf("\n�������Ӧ����ѡ����Ӧ���ܣ� 1-��ѯѡ�����, 2-ͳ��ѡ����Ϣ");
   scanf("%d", &manageCode);
   switch (manageCode)
   {
   	case 1:/*��ʼ��ѯѡ�����*/
   	 printf("\n�������Ӧ����ʵ����ع��ܣ�1-��ʾ��������Ŀγ���Ϣ, 2-��ѯѧ����Ϣ");
   	 scanf("%d", &code);
   	 switch (code)
   	 {
	  case 1:/*��ʾID�����γ�*/
	  persclassinf(ID);
	  printf("\n���ڽ����سɹ���¼����\n\n");
	  goto mainpage2; 
	  
	  case 2:/*��ʼ��ѯѧ����Ϣ*/
	  printf("\n��ѡ���ѯ��ʽ��1-��ѧ��������ѯ, 2-���γ����Ʋ�ѯѡ��ѧ����Ϣ");
	  scanf("%d", &code1);
	  switch (code1)
	  {
	  	case 1:
	  	nameSearchStuinf();/*���ð�ѧ��������ѯ����*/
	  	printf("\n���ڽ����ص�¼�ɹ�����\n\n");
		goto mainpage2; 
		
		case 2:
		classSearchStuinf();/*���ð��γ�����ѯѧ����Ϣ����*/
		printf("\n���ڽ����ص�¼�ɹ�����\n\n");
		goto mainpage2; 
	  }
	 }
	 case 2:/*ͳ��ѡ����Ϣ*/
	  orderclassinf(ID);/*����ͳ��ѡ����Ϣ����*/
	  printf("\n\n���ڽ����ص�¼�ɹ�����\n\n");
		goto mainpage2; 
	  
   }
   case 2:/*�γ̹���ģ��*/
   printf("\n�������Ӧ����ѡ���Ӧѡ�1-���γ�����ѯ�γ���Ϣ, 2-����ҵĿγ�, 3-�޸Ŀγ���������, 4-ȡ���ҵĿγ�");
   scanf("%d", &code2);
   switch(code2)
   {
   	case 1:
   	 classSearchClassinf();/*���ÿγ�����ѯ�γ���Ϣ����*/
   	 printf("\n���ڽ����ص�¼�ɹ�����\n\n");
	  goto mainpage2; 
	  
	case 2:
	addClass(ID);/*���ÿγ���Ӻ���*/
	printf("\n���ڽ����ص�¼�ɹ�����\n\n");
	  goto mainpage2; 
	  
    case 3:
    modiclassinf(ID);/*�������������޸ĺ���*/
    printf("\n���ڽ����ص�¼�ɹ�����\n\n");
	  goto mainpage2; 
	  
	case 4:
	deleteclass(ID);/*���ø��˿γ�ɾ������*/
	printf("\n���ڽ����ص�¼�ɹ�����\n\n");
	  goto mainpage2; 
	
    }
    case 3:/*��ʦ������Ϣ����ģ��*/
    teacher_information(ID);/*���ý�ʦ������Ϣ������*/
    printf("\n���ڽ����ص�¼�ɹ�����\n\n");
	  goto mainpage2; 
	  
	default:
    printf("\n��лʹ�ã��ټ���\n");
	exit(1);
  }
  }
  
  
  
  default:/*�˳�����*/ 
  printf("\n��лʹ�ã��ټ���\n");
  exit(1);
}
return 0;
}/*����������*/



int student_checkin()/*ѧ����¼�����ײ���*/ 
{struct Information_stu 
 {int id_file;char college[15];char major[20];char name[10];char sex[3];int Tel;char password_file[20];char mail[30]; };
 int id,i;
 char password[20];
 FILE *student_file;
 struct Information_stu student[40];
 if((student_file=fopen("ѧ����Ϣ.txt","r"))==NULL)
 {printf("�ļ��޷���\n"); 
  }
 for(i=0;i<40;i++)     /*��ȡѧ����Ϣ*/
 {fscanf(student_file,"%d %s %s %s %s %d %s %s",&student[i].id_file,student[i].college,student[i].major,student[i].name,student[i].sex,&student[i].Tel,student[i].password_file,student[i].mail);
 }
 while(i==40)
 {printf("\n������ѧ�ţ�"); 
  scanf("%d",&id); 
  printf("\n���������룺");
  scanf("%s",password);
  fclose(student_file);
  for(i=0;i<40;i++)
  {if(id==student[i].id_file)    /*�ȶ�ѧ��ѧ�ż�����*/ 
   {if(strcmp(password,student[i].password_file)==0)
    {printf("\n��¼�ɹ���");}
    else
    {printf("\n�����������������"); 
    i=40;
	}
    break;
   }
   if(i==39)
   printf("\n�ʺŲ����ڣ�����������");
  } 
 }
 return(id);  /*�������򷵻�ѧ��ѧ��*/ 
}


void classelectf(int id)    /*ѧ��ѡ�κ����ײ���*/ 
{
FILE *classfile, *student_classfile,  *studentfile;

struct Classinf {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };
struct Classpicked {int studentid; char studentname[10]; int classid;};
struct Studentinf {int studentid; char school[20]; char major[20]; char name[10]; char gender[5]; char phone[15]; char password[10]; char mailaddr[20];};
int cid, count1 =0, count2 =0;
printf("������γ̱��ʵ��ѡ�Σ�\n");
scanf("%d", &cid);
classfile = fopen("�γ���Ϣ.txt", "r");

int s1,s3,s4,s8,s10,s13;
char s2[81], s5[81], s6[81], s7[81], s9[81], s11[81], s12[81];/*s[i]ϵ�еı���ֻ����ʱ����*/
while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d",&s1, s2, &s3, &s4, s5, s6, s7, &s8, s9, &s10, s11, s12, &s13) != EOF)/*��ȡ�γ��ļ���ȷ���ж������γ���Ϣ*/
count1 ++;
fclose (classfile);

classfile = fopen("�γ���Ϣ.txt", "r");
struct Classinf classinf[count1];
int j=0;
while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d", &classinf[j].classid, classinf[j].classname, &classinf[j].credit, &classinf[j].totaltime, classinf[j].type, classinf[j].teacher, classinf[j].term, &classinf[j].time, classinf[j].place, &classinf[j].limnum, classinf[j].briefinf, classinf[j].book, &classinf[j].numalready) != EOF)
{
j++;
}
fclose(classfile);

int i, search;
for (i = 0, search = 1; i < count1 && search; i++)/*�����Ƿ��иÿγ�*/ 
{
 if (cid == classinf[i].classid)
 search = 0;
}
if (search)
printf("\n����γ̱������\n");
else
{
student_classfile = fopen("ѧ��ѡ�α�.txt","r");/*ȷ��ѧ��ѡ�α���Ϣ����*/
int a1, a3;
char a2[81];/*a[i]ϵ�б���ֻ����ʱ����*/
while (fscanf(student_classfile, "%d %s %d", &a1, a2, &a3)!= EOF)
count2++;
fclose (student_classfile);

student_classfile = fopen("ѧ��ѡ�α�.txt","r");
struct Classpicked classpicked[count2];
int k =0, count3 =0;
while (fscanf(student_classfile, "%d %s %d", &classpicked[k].studentid, classpicked[k].studentname, &classpicked[k].classid)!= EOF)
{
if (classpicked[k].studentid == id)/*ȷ�ϸ�ѧ����ѡ�γ���Ŀ*/
count3++;
k++;
}

if (count3 == 3)
printf("\n����ѡ����������\n");
else/*ȷ�ϸÿγ��Ƿ��Ѿ���Ա*/
{
 for (j=0; j<count1; j++)
 {
  if (cid == classinf[j].classid) 
  break;
  } 
  if (classinf[j].numalready == classinf[j].limnum)
  printf("\n�ÿγ�����Ա��\n");
  
  else
  {
	if (count3 == 0)/*û�пγ�ֱ�����*/
	{
	  fclose(student_classfile);
	  student_classfile= fopen("ѧ��ѡ�α�.txt", "a");
	  studentfile= fopen("ѧ����Ϣ.txt", "r");
	  int count6=0;
	  int b1;
	  char b2[81], b3[81], b4[81], b5[81], b6[81], b7[81], b8[81];
	  while(fscanf(studentfile, "%d %s %s %s %s %s %s %s", &b1, b2, b3, b4, b5, b6, b7, b8)!=EOF)/*��count6ȷ��ѧ����Ϣ��Ŀ��*/
	  {
	  	count6++;
	  }
	  fclose(studentfile);
	  struct Studentinf studentinf[count6];
	  studentfile= fopen("ѧ����Ϣ.txt", "r");
	  i = 0;
	  while(fscanf(studentfile, "%d %s %s %s %s %s %s %s", &studentinf[i].studentid, studentinf[i].school, studentinf[i].major, studentinf[i].name, studentinf[i].gender, studentinf[i].phone, studentinf[i].password, studentinf[i].mailaddr)!=EOF)
	  {
	  	i++;
      }  
	  char stuname[10];/*��ȡѧ������*/
	  for (i=0; i<count6; i++)
	  {
	  	if (id == studentinf[i].studentid)
	  	{
	  	 strcpy(stuname, studentinf[i].name);
	  	 break;
		  }
	  }
	  fprintf(student_classfile, "\n");
	  fprintf(student_classfile, "%-16d%-12s%-d", id, stuname, cid);
	  fclose(student_classfile);/*���ѧ��ѡ�α������*/
	  
	  fclose(classfile);
	  classfile= fopen("�γ���Ϣ.txt", "w");
	  for(i=0; i<count1; i++)/*��ɿγ���Ϣ����ѡ�������޸�*/
	  {
	  	if (cid == classinf[i].classid)
	  	{
	  		classinf[i].numalready++;
	  		break;
	  		
		  }
	  }
	  for(i=0; i<count1; i++)/*��ɿγ���Ϣ�ļ�����¼*/
	{
	   fprintf(classfile, "%-d %-s %-d %-d %-s %-s %-s %-d %-s %-d %-s %-s %-d\n", classinf[i].classid, classinf[i].classname, classinf[i].credit, classinf[i].totaltime, classinf[i].type, classinf[i].teacher, classinf[i].term, classinf[i].time, classinf[i].place, classinf[i].limnum, classinf[i].briefinf, classinf[i].book, classinf[i].numalready);
	 } 
	 
	 
	 fclose(classfile);
	  
	  
	  printf("\nѡ�γɹ���\n");
     }
	else/*���пγ̺˶��Ƿ�ʱ���ͻ*/ 
	{
	 int time[count3], classs[count3];
	 for (i=0, j=0; i<count2; i++)/*���γ̵ı�����¸�ֵ��һ���������*/
	 {
	  if (id == classpicked[i].studentid)
	  {
	  	classs[j] = classpicked[i].classid;
	  	j++;
	  }
	 }

	 for (j=0, k=0; j<count3; j++)/*�����������γ���Ϣ����ջ�ö�Ӧ��ʱ������*/
	 {
	  for (i=0; i<count1; i++)
	  {
	  	if (classs[j]== classinf[i].classid)
	  	{
	  	  time[k]= classinf[i].time;
	  	  k++;
		  break; 	 
		  }
	  }
	 }/*������֤����Ŀγ�ʱ���Ƿ���ʱ���������ʱ���ظ�*/

	 int classtime;
	 for (i=0; i<count1; i++)/*ȡ�øÿγ̵�ʱ��*/
	 {
	   if (cid == classinf[i].classid)
	   {
	   	classtime = classinf[i].time;
	   	break;
	   }
	 }
	  int test;
	  for (i=0, test=0; i < count3; i++)/*��ʱ������Ƚ�*/
	  {
	  	if (classtime == time[i])
	  	{
	  	  test = 1;
	  	  break;
		  }
	  }

	 if (test)
	 printf("\nʱ���ͻ\n");
	 else/*����ѡ�ÿ�*/
	 {
	  fclose(student_classfile);
	  student_classfile= fopen("ѧ��ѡ�α�.txt", "a");
	  studentfile= fopen("ѧ����Ϣ.txt", "r");
	  int count6=0;
	  int b1;
	  char b2[81], b3[81], b4[81], b5[81], b6[81], b7[81], b8[81];
	  while(fscanf(studentfile, "%d %s %s %s %s %s %s %s", &b1, b2, b3, b4, b5, b6, b7, b8)!=EOF)/*��count6ȷ��ѧ����Ϣ��Ŀ��*/
	  {
	  	count6++;
	  }
	  fclose(studentfile);
	  struct Studentinf studentinf[count6];
	  studentfile= fopen("ѧ����Ϣ.txt", "r");
	  i = 0;
	  while(fscanf(studentfile, "%d %s %s %s %s %s %s %s", &studentinf[i].studentid, studentinf[i].school, studentinf[i].major, studentinf[i].name, studentinf[i].gender, studentinf[i].phone, studentinf[i].password, studentinf[i].mailaddr)!=EOF)
	  {
	  	i++;
      }  
	  char stuname[10];/*��ȡѧ������*/
	  for (i=0; i<count6; i++)
	  {
	  	if (id == studentinf[i].studentid)
	  	{
	  	 strcpy(stuname, studentinf[i].name);
	  	 break;
		  }
	  }
	  fprintf(student_classfile, "\n");
	  fprintf(student_classfile, "%-16d%-12s%-d", id, stuname, cid);
	  fclose(student_classfile);/*���ѧ��ѡ�α������*/
	  
	  fclose(classfile);
	  classfile= fopen("�γ���Ϣ.txt", "w");
	  for(i=0; i<count1; i++)/*��ɿγ���Ϣ����ѡ�������޸�*/
	  {
	  	if (cid == classinf[i].classid)
	  	{
	  		classinf[i].numalready++;
	  		break;
	  		
		  }
	  }
	  for(i=0; i<count1; i++)/*��ɿγ���Ϣ�ļ�����¼*/
	{
	   fprintf(classfile, "%-d %-s %-d %-d %-s %-s %-s %-d %-s %-d %-s %-s %-d\n", classinf[i].classid, classinf[i].classname, classinf[i].credit, classinf[i].totaltime, classinf[i].type, classinf[i].teacher, classinf[i].term, classinf[i].time, classinf[i].place, classinf[i].limnum, classinf[i].briefinf, classinf[i].book, classinf[i].numalready);
	 } 
	 
	 
	 fclose(classfile);
	  
	  printf("\nѡ�γɹ���\n");
	  
	  }
	  } 
	}
	}
}
}


void classSearchClassinf()/*���γ�����ѯ�γ���Ϣ�����ײ���*/
{
 FILE *classfile;
 struct Classinf {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };
 char name[81];
 printf("\n������γ������ṩ�ÿγ���Ϣ: ");
 scanf("%s", name);
 
classfile = fopen("�γ���Ϣ.txt", "r");
int s1,s3,s4,s8,s10,s13, count1=0;
char s2[81], s5[81], s6[81], s7[81], s9[81], s11[81], s12[81];/*s[i]ϵ�еı���ֻ����ʱ����*/
while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d",&s1, s2, &s3, &s4, s5, s6, s7, &s8, s9, &s10, s11, s12, &s13) != EOF)/*��ȡ�γ��ļ���ȷ���ж������γ���Ϣ*/
count1 ++;
fclose (classfile);

classfile = fopen("�γ���Ϣ.txt", "r");
struct Classinf classinf[count1];
int j=0;
while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d", &classinf[j].classid, classinf[j].classname, &classinf[j].credit, &classinf[j].totaltime, classinf[j].type, classinf[j].teacher, classinf[j].term, &classinf[j].time, classinf[j].place, &classinf[j].limnum, classinf[j].briefinf, classinf[j].book, &classinf[j].numalready) != EOF)
{
j++;
}
fclose(classfile);

printf("\n���   ����         ѧ�� ѧʱ ����  ��ʦ   ʱ��  �ص�  ��������  �̲�  ��ѡ����\n");
int i, search,cid;
for (i = 0, search = 1; i < count1 && search; i++)/*�����Ƿ��иÿγ�*/ 
{
 if (strcmp(name, classinf[i].classname)== 0)
 {
 	printf("%d %s   %d  %d   %s %s   %d    %s %d     %s %d\n", classinf[i].classid, classinf[i].classname, classinf[i].credit, classinf[i].totaltime, classinf[i].type, classinf[i].teacher, classinf[i].time, classinf[i].place, classinf[i].limnum, classinf[i].book, classinf[i].numalready); 
 	search = 0;
 	break;
 }
}
if (search)
printf("\n����γ�������\n");

}



void schoolsearchinf()/*������ѧԺ��ѯ�γ���Ϣ����*/
{
 FILE *classfile, *teacherfile;
 struct Classinf {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };
 struct Teacherinf {int teacherid; char school[30]; char teachername[20]; char mailaddr[30];  char password[10]; };
 
 char school[81];
 printf("\n������ѧԺ�����ṩ��ѧԺ������Ϣ: ");
 scanf("%s", school);
 
 classfile = fopen("�γ���Ϣ.txt", "r");
 int s1,s3,s4,s8,s10,s13, count1=0;
 char s2[81], s5[81], s6[81], s7[81], s9[81], s11[81], s12[81];/*s[i]ϵ�еı���ֻ����ʱ����*/
 while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d",&s1, s2, &s3, &s4, s5, s6, s7, &s8, s9, &s10, s11, s12, &s13) != EOF)/*��ȡ�γ��ļ���ȷ���ж������γ���Ϣ*/
 count1 ++;
 fclose (classfile);

 classfile = fopen("�γ���Ϣ.txt", "r");
 struct Classinf classinf[count1];
 int j=0;
 while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d", &classinf[j].classid, classinf[j].classname, &classinf[j].credit, &classinf[j].totaltime, classinf[j].type, classinf[j].teacher, classinf[j].term, &classinf[j].time, classinf[j].place, &classinf[j].limnum, classinf[j].briefinf, classinf[j].book, &classinf[j].numalready) != EOF)
 {
 j++;
 }
 fclose(classfile);
 
 teacherfile = fopen("��ʦ��Ϣ.txt", "r");
 int count2=0, a1;
 char a2[81], a3[81], a4[81], a5[81];/*aϵ�к���ֻ����ʱ����*/
 while(fscanf(teacherfile, "%d %s %s %s %s", &a1, a2, a3, a4, a5)!= EOF)/*��һ�ζ�ȡ�ļ���ȷ����Ϣ��Ŀ��*/
 {
 count2++;
 }
 fclose(teacherfile);
 
 teacherfile = fopen("��ʦ��Ϣ.txt", "r");
 struct Teacherinf teacherinf[count2];
 int i=0;
 while (fscanf(teacherfile, "%d %s %s %s %s", &teacherinf[i].teacherid, teacherinf[i].school, teacherinf[i].teachername, teacherinf[i].mailaddr, teacherinf[i].password)!= EOF)
 {
 i++;
 }
 printf("\n���   ����         ѧ�� ѧʱ ����  ��ʦ   ʱ��  �ص�  ��������  �̲�  ��ѡ����\n");
 int search, count3=0;
 for (i = 0; i < count1; i++)
 {
  for (j = 0, search=1; j<count2; j++)
  {
   if (strcmp(classinf[i].teacher, teacherinf[j].teachername)==0)
   {
    search = 0;
    break;
   }
  }
   if (strcmp(school, teacherinf[j].school)==0 && search == 0)
   {
   	printf("%d %s   %d  %d   %s %s   %d    %s %d     %s %d\n", classinf[i].classid, classinf[i].classname, classinf[i].credit, classinf[i].totaltime, classinf[i].type, classinf[i].teacher, classinf[i].time, classinf[i].place, classinf[i].limnum, classinf[i].book, classinf[i].numalready);
   	count3++;
   }
 }
  if (count3 == 0)
  {
  	printf("\nû�и�ѧԺ�Ŀ�����Ϣ��\n");
  }
 }
 
 
 void class_reorder()/*�γ��������ײ���*/
{FILE *classfile;
 struct Classinf {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };
 int choose; 
classfile = fopen("�γ���Ϣ.txt", "r");
int s1,s3,s4,s8,s10,s13, count1=0;
char s2[81], s5[81], s6[81], s7[81], s9[81], s11[81], s12[81];/*s[i]ϵ�еı���ֻ����ʱ����*/
while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d",&s1, s2, &s3, &s4, s5, s6, s7, &s8, s9, &s10, s11, s12, &s13) != EOF)/*��ȡ�γ��ļ���ȷ���ж������γ���Ϣ*/
count1 ++;
fclose (classfile);
classfile = fopen("�γ���Ϣ.txt", "r");
struct Classinf classinf[count1];
int j=0;
while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d", &classinf[j].classid, classinf[j].classname,&classinf[j].credit,&classinf[j].totaltime, classinf[j].type, classinf[j].teacher,classinf[j].term, &classinf[j].time,classinf[j].place, &classinf[j].limnum, classinf[j].briefinf, classinf[j].book, &classinf[j].numalready) != EOF)
{
j++;                                                /*���ļ���Ϣ����ṹ*/ 
}
fclose(classfile);
struct Classinf temp;
int rest[count1],i,temp1;
for(i=0;i<count1;i++)
{rest[i]=classinf[i].limnum-classinf[i].numalready;
}
printf("\n������������������1����ѡ����������������2:");
scanf("%d",&choose);
if(choose==1)
{for(i=0;i<count1;i++)              /*�Ա�����*/ 
 {for(j=0;j<(count1-1);j++)
  {if (rest[j]>rest[j+1])
   {temp=classinf[j];             
    classinf[j]=classinf[j+1];             
    classinf[j+1]=temp;
    temp1=rest[j];
    rest[j]=rest[j+1];
    rest[j+1]=temp1;
   }
  }
 }
 printf("\n���   ����         ѧ�� ѧʱ ����  ��ʦ   ʱ��  �ص�  ��������  �̲�  ������\n");
 for (i=(count1-1);i>-1;i--)        /*��ӡ�γ̱�*/ 
 {printf("\n%d %-12s %d %d   %s  %-6s %d   %s %-3d %-18s %d", classinf[i].classid, classinf[i].classname, classinf[i].credit, classinf[i].totaltime, classinf[i].type, classinf[i].teacher, classinf[i].time, classinf[i].place, classinf[i].limnum, classinf[i].book,rest[i]); 
 }
}
else if(choose==2)               
{for(i=0;i<count1;i++)                /*�Ա�����*/ 
 {for(j=0;j<(count1-1);j++)
  {if(classinf[j].numalready>classinf[j+1].numalready)
   {temp=classinf[j];             
    classinf[j]=classinf[j+1];             
    classinf[j+1]=temp;
   }
  }
 }
 printf("\n���   ����         ѧ�� ѧʱ ����  ��ʦ   ʱ��  �ص�  ��������  �̲�  ��ѡ����\n");
 for (i=(count1-1);i>-1;i--)        /*��ӡ�γ̱�*/ 
 {printf("\n%d %-12s %d    %d   %s  %-6s %d   %s %-3d %-18s %d", classinf[i].classid, classinf[i].classname, classinf[i].credit, classinf[i].totaltime, classinf[i].type, classinf[i].teacher, classinf[i].time, classinf[i].place, classinf[i].limnum, classinf[i].book, classinf[i].numalready); 
 }
}
}


void stuclass_check(int id)/*ѧ����ѯ��ѡ�γ̺����ײ���*/ 
{struct Information_stuclass
 {int id_file;char name[10];int clas;};
 struct Information_Class
 {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };
 struct Information_stuclass student[120];
 struct Information_Class classinf[100];
 int i=0,j=0,count,mark,choose,markid[3],markname[3],k=0,classid,choose1,mark1,mark2,year,mon,day,hour,min,sec; 
 FILE *studentclass_file,*class_file;
 if((class_file=fopen("�γ���Ϣ.txt","r"))==NULL)
 {printf("�ļ��޷���\n"); 
  }
 while(fscanf(class_file,"%d %s %d %d %s %s %s %d %s %d %s %s %d",&classinf[j].classid, classinf[j].classname, &classinf[j].credit, &classinf[j].totaltime, classinf[j].type, classinf[j].teacher, classinf[j].term, &classinf[j].time, classinf[j].place, &classinf[j].limnum, classinf[j].briefinf, classinf[j].book, &classinf[j].numalready) != EOF)  
 {j++;
 }                           /*��ȡ�γ���Ϣ������ṹ*/ 
 count=j;                       /*��¼�γ�����*/ 
 if((studentclass_file=fopen("ѧ��ѡ�α�.txt","r"))==NULL)
 {printf("�ļ��޷���\n"); 
  }
 printf("\n�γ̱��        �γ�����");
 while(fscanf(studentclass_file,"%d %s %d",&student[i].id_file,student[i].name,&student[i].clas)!=EOF)   /*��ȡѧ����ѡ�γ���Ϣ������ṹ*/ 
 {if(id==student[i].id_file)
  {for(j=count;j>-1;j--)
   {if(classinf[j].classid==student[i].clas)
    {printf("\n%-10d      %-20s",student[i].clas,classinf[j].classname);                              
     markid[k]=i;                /*��¼��ѡ�γ̴洢λ��*/ 
     markname[k]=j;
     k++;
	}
   }
   mark=1;                        /*�ж��Ƿ�ѡ��γ�*/ 
  }
  i++;
 }
 if(mark!=1)
 printf("\n\nû��ѡ���κογ�");
 fclose(studentclass_file);
 fclose(class_file);
}


void stuclass_delete(int id)/*ѧ���γ�ɾ�������ײ���*/
{struct Information_stuclass
 {int id_file;char name[10];int clas;};
 struct Information_Class
 {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };
 struct Information_stuclass student[120];
 struct Information_Class classinf[100];
 int i=0,j=0,count,mark,choose,markid[3],markname[3],k=0,classid,choose1,mark1,mark2,year,mon,day,hour,min,sec,test; 
 FILE *studentclass_file,*class_file;
 if((class_file=fopen("�γ���Ϣ.txt","r"))==NULL)
 {printf("�ļ��޷���\n"); 
  }
 while(fscanf(class_file,"%d %s %d %d %s %s %s %d %s %d %s %s %d",&classinf[j].classid, classinf[j].classname, &classinf[j].credit, &classinf[j].totaltime, classinf[j].type, classinf[j].teacher, classinf[j].term, &classinf[j].time, classinf[j].place, &classinf[j].limnum, classinf[j].briefinf, classinf[j].book, &classinf[j].numalready) != EOF)  
 {j++;
 }                           /*��ȡ�γ���Ϣ������ṹ*/ 
 count=j;                       /*��¼�γ�����*/ 
 if((studentclass_file=fopen("ѧ��ѡ�α�.txt","r"))==NULL)
 {printf("�ļ��޷���\n"); 
  }
 printf("\n�γ̱��        �γ�����");
 while(fscanf(studentclass_file,"%d %s %d",&student[i].id_file,student[i].name,&student[i].clas)!=EOF)   /*��ȡѧ����ѡ�γ���Ϣ������ṹ*/ 
 {if(id==student[i].id_file)
  {for(j=count;j>-1;j--)
   {if(classinf[j].classid==student[i].clas)
    {printf("\n%-10d      %-20s",student[i].clas,classinf[j].classname);      
	 markid[k]=i;                /*��¼��ѡ�γ̴洢λ��*/ 
     markname[k]=j;
     k++;
	}
   }
   mark=1;                        /*�ж��Ƿ�ѡ��γ�*/ 
  }
  i++;
 }
 fclose(studentclass_file);
 fclose(class_file);
 
 tm mytime;                   /*��ȡϵͳʱ��*/
 _getsystime(&mytime);      
 year=mytime.tm_year+1900;  
 mon=mytime.tm_mon+1;     
 day=mytime.tm_mday;   
 hour=mytime.tm_hour;  
 min=mytime.tm_min;   
 sec=mytime.tm_sec;
  if (year<YEAR)
 test = 1;
 else
 {
  if (year>YEAR)
  {
  	test = 0;
  }
  else 
  {
   if (mon<MON)
   {
   	test = 1;
   }
   else
   {
   	if (mon>MON)
   	{
   		test = 0;
	   }
	   else
	   {
	   	if (day<DAY)
	   	{
	   		test = 1;
		   }
		   else
		   {
		   	if (day>DAY)
		   	{
		   		test = 0;
			   }
			   else
			   {
			   	if (hour<HOUR)
			   	{
			   		test = 1;
				   }
				   else 
				   {
				   	if (min<MIN)
				   	{
				   		test = 1;
					   }
					   else 
					   {
					   	if (sec<SEC)
					   	{
					   		test = 1;
						   }
						   else
						   test = 0;
					   }
				   }
			   }
		   }
	   }
   }
  }
 }
 
    
 if(mark!=1)
 {printf("\nû��ѡ���κογ�");  
 }
 else if(test)    /*�ж�ʱ���Ƿ��ֹ*/
 {printf("\nɾ���γ�������1;�����������ַ��سɹ���¼����:");   
  scanf("%d",&choose);
  if(choose==1)
  {printf("\n����Ҫɾ���Ŀγ̱�ţ�");
   scanf("%d",&classid);
   if(classid==student[markid[0]].clas||classid==student[markid[1]].clas||classid==student[markid[2]].clas)  /*����Ѿ�ѡ��Ŀγ����Ƿ��������ŵĿγ�*/ 
  {printf("\n�Ƿ�ȷ��ɾ�����¿γ̣�"); 
   if(classid==student[markid[0]].clas)
   {printf("\n%-10d      %-20s",student[markid[0]].clas,classinf[markname[0]].classname);                    /*������ı������ѡ�γ������αȶԣ���ͬ���ӡ*/  
    mark1=markid[0];
	mark2=markname[0];}
   else if(classid==student[markid[1]].clas) 
   {printf("\n%-10d      %-20s",student[markid[1]].clas,classinf[markname[1]].classname);
    mark1=markid[1];
	mark2=markname[1];}
   else if(classid==student[markid[2]].clas)
   {printf("\n%-10d      %-20s",student[markid[2]].clas,classinf[markname[2]].classname);
    mark1=markid[2];
	mark2=markname[2];}
   printf("\nȷ��ɾ��������1��������������ȡ��ɾ����");
   scanf("%d",&choose1) ;
   if(choose1==1)
   {studentclass_file=fopen("ѧ��ѡ�α�.txt","w"); 
    class_file=fopen("�γ���Ϣ.txt","w");
    for(i=0;student[i].id_file;i++)     /*�����º����Ϣ����д��ѧ���ļ�*/ 
    {if(i!=mark1)                       /*д���ļ�ʱ����ɾ���Ŀγ�*/ 
	 {fprintf(studentclass_file,"%-16d%-12s%-d\n",student[i].id_file,student[i].name,student[i].clas);
	 }
	}
	classinf[mark2].numalready--;     /*��ɾ�����Ŀγ�������1*/ 
	for(j=0;j<count;j++)                  /*�����º����Ϣ����д��γ��ļ�*/ 
	{fprintf(class_file,"%d %s %d %d %s %s %s %d %s %d %s %s %d\n",classinf[j].classid, classinf[j].classname, classinf[j].credit, classinf[j].totaltime, classinf[j].type, classinf[j].teacher, classinf[j].term, classinf[j].time, classinf[j].place, classinf[j].limnum, classinf[j].briefinf, classinf[j].book, classinf[j].numalready) ;
	} 
	printf("\nɾ���γ̳ɹ���"); 
	fclose(studentclass_file);
    fclose(class_file);
   }
  }
  else 
  printf("\n��ѡ�γ��в��������ſγ̣�");
  }
 }
 else
 {printf("\nѡ�ν�ֹ��ѡ����Ϣ�޷��޸ģ�"); 
  printf("\n���ڽ����سɹ���¼����\n");
 }
}


void persclassinf(int id)/*��ʦ��ѯ���˿�����Ϣ�����ײ�*/ 
{
 FILE *classfile, *teacherfile;
 struct Classinf {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };
 struct Teacherinf {int teacherid; char school[30]; char teachername[20]; char mailaddr[30];  char password[10]; };
 
 teacherfile = fopen("��ʦ��Ϣ.txt", "r");
 int count1=0, a1;
 char a2[81], a3[81], a4[81], a5[81];/*aϵ�к���ֻ����ʱ����*/
 while(fscanf(teacherfile, "%d %s %s %s %s", &a1, a2, a3, a4, a5)!= EOF)/*��һ�ζ�ȡ�ļ���ȷ����Ϣ��Ŀ��*/
 {
 count1++;
 }
 fclose(teacherfile);
 
 teacherfile = fopen("��ʦ��Ϣ.txt", "r");
 struct Teacherinf teacherinf[count1];
 int i=0;
 while (fscanf(teacherfile, "%d %s %s %s %s", &teacherinf[i].teacherid, teacherinf[i].school, teacherinf[i].teachername, teacherinf[i].mailaddr, teacherinf[i].password)!= EOF)
 {
 i++;
 }
 char name[81];/*��ȡ��ʦ����*/
 for (i=0; i<count1; i++)
 {
  if (id == teacherinf[i].teacherid)
  {
  	strcpy(name, teacherinf[i].teachername);
  	break;
  }
 }
 
classfile = fopen("�γ���Ϣ.txt", "r");
int s1,s3,s4,s8,s10,s13, count2 = 0;
char s2[81], s5[81], s6[81], s7[81], s9[81], s11[81], s12[81];/*s[i]ϵ�еı���ֻ����ʱ����*/
while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d",&s1, s2, &s3, &s4, s5, s6, s7, &s8, s9, &s10, s11, s12, &s13) != EOF)/*��ȡ�γ��ļ���ȷ���ж������γ���Ϣ*/
count2 ++;
fclose (classfile);

classfile = fopen("�γ���Ϣ.txt", "r");
struct Classinf classinf[count2];
int j=0;
while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d", &classinf[j].classid, classinf[j].classname, &classinf[j].credit, &classinf[j].totaltime, classinf[j].type, classinf[j].teacher, classinf[j].term, &classinf[j].time, classinf[j].place, &classinf[j].limnum, classinf[j].briefinf, classinf[j].book, &classinf[j].numalready) != EOF)
{
j++;
}
fclose(classfile);

int count3=0;
printf("\n��������������Ŀγ���Ϣ��\n");
printf("\n");
printf("���   �γ�����   ѧ�� ѧʱ ���� ��ʦ ʱ�� �ص� �������� �̲� ��ѡ����\n");

for (i=0; i<count2; i++)/*�����γ���Ϣ�ҳ�ƥ����������ʾ��*/
{
  if (strcmp(name, classinf[i].teacher) == 0)
  {
  	printf("%d %s  %d  %d  %s %s %d %s %d %s %d\n", classinf[i].classid, classinf[i].classname, classinf[i].credit, classinf[i].totaltime, classinf[i].type, classinf[i].teacher, classinf[i].time, classinf[i].place, classinf[i].limnum, classinf[i].book, classinf[i].numalready);
  	count3++;
  }
}
if (count3 == 0)
{
	printf("\n��δ����γ̣�\n");
}
}


int teacher_checkin()/*��ʦ��¼�����ײ���*/ 
{struct Information_tea 
 {int id_file;char college[15];char name[10];char mail[30];char password_file[20]; };
 int id,i;
 char password[20];
 FILE *teacher_file;
 struct Information_tea teacher[16];
 if((teacher_file=fopen("��ʦ��Ϣ.txt","r"))==NULL)
 {printf("�ļ��޷���\n"); 
  }
 for(i=0;i<16;i++)   /*��ȡ��ʦ��Ϣ*/
 {fscanf(teacher_file,"%d %s %s %s %s",&teacher[i].id_file,teacher[i].college,teacher[i].name,teacher[i].mail,teacher[i].password_file);
 }
 while(i==16)
 {printf("\n�����빤�ţ�"); 
  scanf("%d",&id); 
  printf("\n���������룺");
  scanf("%s",password);
  fclose(teacher_file);
  for(i=0;i<16;i++)     /*�ȶԽ�ʦ���ż�����*/ 
  {if(id==teacher[i].id_file)
   {if(strcmp(password,teacher[i].password_file)==0)
    {printf("\n��¼�ɹ���");}
    else
    {printf("\n�����������������"); 
    i=16;
	}
    break;
   }
   if(i==15)
   printf("\n�ʺŲ����ڣ�����������");
  } 
 }
 return(id);    /*�������򷵻ؽ�ʦ����*/ 
}


void nameSearchStuinf()/*��ѧ���������Һ����ײ���*/ 
{
 FILE *studentfile;
 struct Studentinf {int studentid; char school[20]; char major[20]; char name[10]; char gender[5]; char phone[15]; char password[10]; char mailaddr[20];};
 char name[81];
 
 printf("\n������ѧ�����������Ϣ���ң� ");
 scanf("%s", name);
 
 studentfile= fopen("ѧ����Ϣ.txt", "r");
 int count1=0;
 int b1, i;
 char b2[81], b3[81], b4[81], b5[81], b6[81], b7[81], b8[81];
 while(fscanf(studentfile, "%d %s %s %s %s %s %s %s", &b1, b2, b3, b4, b5, b6, b7, b8)!=EOF)/*��count1ȷ��ѧ����Ϣ��Ŀ��*/
{
 count1++;
}
 fclose(studentfile);
 
 struct Studentinf studentinf[count1];
 studentfile= fopen("ѧ����Ϣ.txt", "r");
	  i = 0;
	  while(fscanf(studentfile, "%d %s %s %s %s %s %s %s", &studentinf[i].studentid, studentinf[i].school, studentinf[i].major, studentinf[i].name, studentinf[i].gender, studentinf[i].phone, studentinf[i].password, studentinf[i].mailaddr)!=EOF)
	  {
	  	i++;
      }  
 
  int test;
 for (i=0, test=1; i<count1; i++)/*����Ƿ��и�ѧ����Ϣ*/
 {
 	if(strcmp(name, studentinf[i].name)== 0)
 	{
 	  printf("%d  %s  %s  %s  %s\n", studentinf[i].studentid, studentinf[i].school, studentinf[i].major, studentinf[i].name, studentinf[i].gender);
 	  test = 0;
 	  break;
	 }
 }
 
 if (test)
 printf("\nû�и�ѧ����\n");
 
}


void orderclassinf(int id)/*ͳ��ѡ����Ϣ�����ײ���*/
{
 FILE *classfile, *teacherfile;
 struct Classinf {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };
 struct Teacherinf {int teacherid; char school[30]; char teachername[20]; char mailaddr[30];  char password[10]; };
 
 teacherfile = fopen("��ʦ��Ϣ.txt", "r");
 int count1=0, a1;
 char a2[81], a3[81], a4[81], a5[81];/*aϵ�к���ֻ����ʱ����*/
 while(fscanf(teacherfile, "%d %s %s %s %s", &a1, a2, a3, a4, a5)!= EOF)/*��һ�ζ�ȡ�ļ���ȷ����Ϣ��Ŀ��*/
 {
 count1++;
 }
 fclose(teacherfile);
 
 teacherfile = fopen("��ʦ��Ϣ.txt", "r");
 struct Teacherinf teacherinf[count1];
 int i=0;
 while (fscanf(teacherfile, "%d %s %s %s %s", &teacherinf[i].teacherid, teacherinf[i].school, teacherinf[i].teachername, teacherinf[i].mailaddr, teacherinf[i].password)!= EOF)
 {
 i++;
 }
 
 char name[81];/*��ȡ��ʦ����*/
 for (i=0; i<count1; i++)
 {
  if (id == teacherinf[i].teacherid)
  {
  	strcpy(name, teacherinf[i].teachername);
  	break;
  }
 }
 
classfile = fopen("�γ���Ϣ.txt", "r");
int s1,s3,s4,s8,s10,s13, count2 = 0;
char s2[81], s5[81], s6[81], s7[81], s9[81], s11[81], s12[81];/*s[i]ϵ�еı���ֻ����ʱ����*/
while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d",&s1, s2, &s3, &s4, s5, s6, s7, &s8, s9, &s10, s11, s12, &s13) != EOF)/*��ȡ�γ��ļ���ȷ���ж������γ���Ϣ*/
count2 ++;
fclose (classfile);

classfile = fopen("�γ���Ϣ.txt", "r");
struct Classinf classinf[count2];
int j=0;
while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d", &classinf[j].classid, classinf[j].classname, &classinf[j].credit, &classinf[j].totaltime, classinf[j].type, classinf[j].teacher, classinf[j].term, &classinf[j].time, classinf[j].place, &classinf[j].limnum, classinf[j].briefinf, classinf[j].book, &classinf[j].numalready) != EOF)
{
j++;
}
fclose(classfile);

int count3=0;/*���ÿ���γ���Ŀ����*/

for (i=0; i<count2; i++)/*�����γ���Ϣȷ�Ͽ�����Ŀ*/
{
  if (strcmp(name, classinf[i].teacher) == 0)
  {
  	count3++;
  }
}

printf("\n���ѿ���%d�ſγ�,���潫��ѡ����������\n", count3);
printf("\n���   ����         ѧ�� ѧʱ ����  ��ʦ   ʱ��  �ص�  ��������  �̲�  ��ѡ����\n");

if (count3 == 0)
{
	printf("\n��δ����γ̣�\n");
}

if (count3 == 1)
{
  for (i=0; i<count2; i++)
  {
  	if (strcmp(name, classinf[i].teacher) == 0)
  	{
    printf("%d %s  %d  %d  %s %s %d %s %d %s %d\n", classinf[i].classid, classinf[i].classname, classinf[i].credit, classinf[i].totaltime, classinf[i].type, classinf[i].teacher, classinf[i].time, classinf[i].place, classinf[i].limnum, classinf[i].book, classinf[i].numalready);
    break;
	}
   }
 } 
 
 if(count3 == 2)
 {
 	struct Classinf personalclass[count3], temp;
 	for (i=0, j=0; i<count2; i++)
 	{
 	 if (strcmp(name, classinf[i].teacher) == 0)
 	 {
 	 	personalclass[j] = classinf[i];
 	 	j++;
	  }
	 }
	 if (personalclass[0].numalready < personalclass[1].numalready)
	 {
	 	temp = personalclass[0];
	 	personalclass[0] = personalclass[1];
	 	personalclass[1] = temp;
	 }
	 
	 for (i=0; i<count3; i++)
	 {
	  printf("%d %s  %d  %d  %s %s %d %s %d %s %d\n", personalclass[i].classid, personalclass[i].classname, personalclass[i].credit, personalclass[i].totaltime, personalclass[i].type, personalclass[i].teacher, personalclass[i].time, personalclass[i].place, personalclass[i].limnum, personalclass[i].book, personalclass[i].numalready);
	 }
	 
 }
 
}


void classSearchStuinf()/*���γ�����ѯѧ����Ϣ�����ײ���*/ 
{
 FILE *classfile, *student_classfile,  *studentfile; 
 struct Classinf {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };
 struct Classpicked {int studentid; char studentname[10]; int classid;};
 struct Studentinf {int studentid; char school[20]; char major[20]; char name[10]; char gender[5]; char phone[15]; char password[10]; char mailaddr[20];};
 
 char name[81];
 printf("\n������γ������ṩ����ѡ��ѧ����Ϣ: ");
 scanf("%s", name);
 
classfile = fopen("�γ���Ϣ.txt", "r");
int s1,s3,s4,s8,s10,s13, count1=0;
char s2[81], s5[81], s6[81], s7[81], s9[81], s11[81], s12[81];/*s[i]ϵ�еı���ֻ����ʱ����*/
while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d",&s1, s2, &s3, &s4, s5, s6, s7, &s8, s9, &s10, s11, s12, &s13) != EOF)/*��ȡ�γ��ļ���ȷ���ж������γ���Ϣ*/
count1 ++;
fclose (classfile);

classfile = fopen("�γ���Ϣ.txt", "r");
struct Classinf classinf[count1];
int j=0;
while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d", &classinf[j].classid, classinf[j].classname, &classinf[j].credit, &classinf[j].totaltime, classinf[j].type, classinf[j].teacher, classinf[j].term, &classinf[j].time, classinf[j].place, &classinf[j].limnum, classinf[j].briefinf, classinf[j].book, &classinf[j].numalready) != EOF)
{
j++;
}
fclose(classfile);

int i, search,cid;
for (i = 0, search = 1; i < count1 && search; i++)/*�����Ƿ��иÿγ�*/ 
{
 if (strcmp(name, classinf[i].classname)== 0)
 {
 	cid = classinf[i].classid;
 	search = 0;
 	break;
 }
}
if (search)
printf("\n����γ�������\n");

 
else
{ 
 student_classfile = fopen("ѧ��ѡ�α�.txt","r");/*ȷ��ѧ��ѡ�α���Ϣ����*/
 int a1, a3, count2=0;
 char a2[81];/*a[i]ϵ�б���ֻ����ʱ����*/
 while (fscanf(student_classfile, "%d %s %d", &a1, a2, &a3)!= EOF)
 count2++;
 fclose (student_classfile);
 
 student_classfile = fopen("ѧ��ѡ�α�.txt","r");
 struct Classpicked classpicked[count2];
 i = 0;
 while(fscanf(student_classfile, "%d %s %d", &classpicked[i].studentid, classpicked[i].studentname, &classpicked[i].classid)!= EOF)
 {
  i++;
 }

int count3=0;/*�ü�����������ȷ�ϸÿγ�ѡ������*/
for (i=0; i<count2; i++)
{
 if (cid == classpicked[i].classid)
 {
  count3++;
  } 
}

int sid[count3], j;/*����ѧ��������*/
for (i=0, j=0; i<count2; i++)
{
 if (cid == classpicked[i].classid)
 {
  sid[j] = classpicked[i].studentid;
  j++;
 }
}

studentfile= fopen("ѧ����Ϣ.txt", "r");
int count4=0;
int b1;
char b2[81], b3[81], b4[81], b5[81], b6[81], b7[81], b8[81];
while(fscanf(studentfile, "%d %s %s %s %s %s %s %s", &b1, b2, b3, b4, b5, b6, b7, b8)!=EOF)/*��count4ȷ��ѧ����Ϣ��Ŀ��*/
{
count4++;
}
fclose(studentfile);

struct Studentinf studentinf[count4];
studentfile= fopen("ѧ����Ϣ.txt", "r");
i = 0;
while(fscanf(studentfile, "%d %s %s %s %s %s %s %s", &studentinf[i].studentid, studentinf[i].school, studentinf[i].major, studentinf[i].name, studentinf[i].gender, studentinf[i].phone, studentinf[i].password, studentinf[i].mailaddr)!=EOF)
{
i++;
}

printf("\n������ѡ��ÿε�����ѧ����Ϣ��\n");
for(i=0; i<count3; i++)
{
	for(j=0; j<count4; j++)
	{
	  if (sid[i] == studentinf[j].studentid)
	  {
	  	printf("%d  %s  %s  %s  %s\n", studentinf[j].studentid, studentinf[j].school, studentinf[j].major, studentinf[j].name, studentinf[j].gender);
	  	break;
	  }
	}
  }  
}	

}


void addClass(int id)/*�γ���Ӻ����ײ���*/
{
FILE *classfile, *teacherfile;
struct Classinf {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };
struct Teacherinf {int teacherid; char school[30]; char teachername[20]; char mailaddr[30];  char password[10]; };

 teacherfile = fopen("��ʦ��Ϣ.txt", "r");/*������ʦ��Ϣ�ṹ����*/
 int count1=0, a1;
 char a2[81], a3[81], a4[81], a5[81];/*aϵ�к���ֻ����ʱ����*/
 while(fscanf(teacherfile, "%d %s %s %s %s", &a1, a2, a3, a4, a5)!= EOF)/*��һ�ζ�ȡ�ļ���ȷ����Ϣ��Ŀ��*/
 {
 count1++;
 }
 fclose(teacherfile);
 
 teacherfile = fopen("��ʦ��Ϣ.txt", "r");
 struct Teacherinf teacherinf[count1];
 int i=0;
 while (fscanf(teacherfile, "%d %s %s %s %s", &teacherinf[i].teacherid, teacherinf[i].school, teacherinf[i].teachername, teacherinf[i].mailaddr, teacherinf[i].password)!= EOF)
 {
 i++;
 }
 
 char name[81];/*����id��ȡ��ʦ����*/
 for (i=0; i<count1; i++)
 {
  if (id == teacherinf[i].teacherid)
  {
  	strcpy(name, teacherinf[i].teachername);
  	break;
  }
  } 

 classfile = fopen("�γ���Ϣ.txt", "r");/*�����γ���Ϣ�ṹ����*/
 int s1,s3,s4,s8,s10,s13, count2 = 0;
 char s2[81], s5[81], s6[81], s7[81], s9[81], s11[81], s12[81];/*s[i]ϵ�еı���ֻ����ʱ����*/
 while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d",&s1, s2, &s3, &s4, s5, s6, s7, &s8, s9, &s10, s11, s12, &s13) != EOF)/*��ȡ�γ��ļ���ȷ���ж������γ���Ϣ*/
 count2 ++;
 fclose (classfile);

 classfile = fopen("�γ���Ϣ.txt", "r");
 struct Classinf classinf[count2];
 int j=0;
 while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d", &classinf[j].classid, classinf[j].classname, &classinf[j].credit, &classinf[j].totaltime, classinf[j].type, classinf[j].teacher, classinf[j].term, &classinf[j].time, classinf[j].place, &classinf[j].limnum, classinf[j].briefinf, classinf[j].book, &classinf[j].numalready) != EOF)
{
j++;
}
fclose(classfile);

int classnum=0, classtime;
/*�õ��ѿ���Ŀγ���Ŀ*/
for (i=0; i<count2; i++)
{
 if (strcmp(name, classinf[i].teacher) == 0)
 {
 classnum++;
 classtime = classinf[i].time;
}
}

if (classnum >= 2)
printf("\n��������γ���Ŀ����\n\n");
else/*���Կ���*/
{
 if (classnum == 0)/*��û�п���γ̵����*/ 
 { 
  printf("\n�밴��ʾ����γ���Ϣ\n");
  struct Classinf classs;
  printf("\n������6λ�γ̱�ţ�");
test1: 
   do
  {
  	scanf("%d", &classs.classid);
  	if (classs.classid>999999 || classs.classid<100000)
	  printf("\n������6λ�����������룺"); 
   } while(classs.classid>999999 || classs.classid<100000);
   
   int test;
   for (i=0, test=0; i<count2; i++)
   {
   	if (classs.classid == classinf[i].classid)
   	{
	test = 1;
   	printf("\n�����пγ̱���ظ������������룺");
   	break;
   }
   }
   if (test)
   goto test1;/*���ÿγ̱��*/
   
   do
   {
   printf("\n������γ�����");
   scanf("%s", classs.classname);
   for(i=0, test=0; i<count2; i++)
   {
   	if(strcmp(classs.classname, classinf[i].classname)==0)
   	{
	test = 1;
   	printf("\n�����пγ����ظ�����Ҫ��������\n");
   	break;
   }
   }
   }while(test);/*���ÿγ���*/
   
   do
   {
   	test = 0;
   	printf("\n������ѧ�֣�");
   	scanf("%d", &classs.credit);
   	if(classs.credit>4||classs.credit<1)
   	{
	   test = 1;
	   printf("\nѧ��Ϊ1��4�֣�����������\n");
    }
   }while(test);/*����ѧ��*/
   
   do
   {
   	test = 0;
    printf("\n������ѧʱ��16����32����");
    scanf("%d", &classs.totaltime);
    if (classs.totaltime!=16 && classs.totaltime!=32)
    {
    	test =1;
    	printf("\nѧʱ��ʽ����������������\n");
	}
   }while(test);/*����ѧʱ*/
   
   do
   {
   	test = 0;
   	printf("\n������γ����ʣ�ѡ�޻��߱��ޣ���");
   	scanf("%s", classs.type);
   	if (strcmp(classs.type, "ѡ��")!=0 && strcmp(classs.type, "����")!=0)
   	{
   		test = 1;
   		printf("\n�γ����ʲ��������������룺\n");
	   }
	} while(test);/*���ÿγ�����*/
	
	strcpy(classs.teacher, name);/*���ý�ʦ*/
	
	printf("\n������γ���ֹʱ�䣬��ʽΪ201*-201*ѧ���*ѧ�ڵ�*��-��*�ܣ�");
	scanf("%s", classs.term);/*������ֹʱ��*/
	
	do
	{
	test = 0;
	printf("\n�������Ͽ�ʱ���Ӧ����\n1--8:00-8:50\n2--9:00-9:50\n3--10:00-10:50\n4--11:00-11:50\n5--13:30-14:20\n6--14:30-15:20\n7--15:30-16:20\n8--16:30-17:20\n9--18:30-19:20\n10--19:30-20:20\n���룺");
	scanf("%d", &classs.time);
	if (classs.time<1 || classs.time>10)
	{
	 test = 1;
	 printf("\nʱ��������������������\n");
	}
    }while(test);/*�����Ͽ�ʱ��*/
	
	printf("\n�������Ͽεص㣬��ʽΪ¥��-����ţ�");
	scanf("%s", classs.place);/*�����Ͽεص�*/
	
	do
	{
	 test = 0;
	 printf("\n������γ�����������80��100����");
	 scanf("%d", &classs.limnum);
	 if (classs.limnum!=80 && classs.limnum!=100)
	 {
	  test = 1;
	  printf("\n�γ���������������������������\n");
	 }
	}while(test);/*������������*/
	
	printf("\n������γ̼�飨35�����ڣ�:");
	scanf("%s", classs.briefinf);/*������*/
	
	printf("\n������̲����ƣ���ʽΪ����������");
	scanf("%s", classs.book);/*����̲���*/
	
	classs.numalready = 0;/*��ʼ����ѡ����*/
	
	classfile = fopen("�γ���Ϣ.txt", "a");
	fprintf(classfile,"\n");
	fprintf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d", classs.classid, classs.classname, classs.credit, classs.totaltime, classs.type, classs.teacher, classs.term, classs.time, classs.place, classs.limnum, classs.briefinf, classs.book, classs.numalready);/*������*/   
	printf("\n���γɹ�\n");
    fclose(classfile);
 } 
 
 else/*�ѿ�����һ��*/
 {
  printf("\n�밴��ʾ����γ���Ϣ\n");
  struct Classinf classs;
  printf("\n������6λ�γ̱�ţ�");
test3: 
   do
  {
  	scanf("%d", &classs.classid);
  	if (classs.classid>999999 || classs.classid<100000)
	  printf("\n������6λ�����������룺"); 
   } while(classs.classid>999999 || classs.classid<100000);
   
   int test;
   for (i=0, test=0; i<count2; i++)
   {
   	if (classs.classid == classinf[i].classid)
   	{
	test = 1;
   	printf("\n�����пγ̱���ظ������������룺");
   	break;
   }
   }
   if (test)
   goto test3;/*���ÿγ̱��*/
   
   do
   {
   printf("\n������γ�����");
   scanf("%s", classs.classname);
   for(i=0, test=0; i<count2; i++)
   {
   	if(strcmp(classs.classname, classinf[i].classname)==0)
   	{
	test = 1;
   	printf("\n�����пγ����ظ�����Ҫ��������\n");
   	break;
   }
   }
   }while(test);/*���ÿγ���*/
   
   do
   {
   	test = 0;
   	printf("\n������ѧ�֣�");
   	scanf("%d", &classs.credit);
   	if(classs.credit>4||classs.credit<1)
   	{
	   test = 1;
	   printf("\nѧ��Ϊ1��4�֣�����������\n");
    }
   }while(test);/*����ѧ��*/
   
   do
   {
   	test = 0;
    printf("\n������ѧʱ��16����32����");
    scanf("%d", &classs.totaltime);
    if (classs.totaltime!=16 && classs.totaltime!=32)
    {
    	test =1;
    	printf("\nѧʱ��ʽ����������������\n");
	}
   }while(test);/*����ѧʱ*/
   
   do
   {
   	test = 0;
   	printf("\n������γ����ʣ�ѡ�޻��߱��ޣ���");
   	scanf("%s", classs.type);
   	if (strcmp(classs.type, "ѡ��")!=0 && strcmp(classs.type, "����")!=0)
   	{
   		test = 1;
   		printf("\n�γ����ʲ��������������룺\n");
	   }
	} while(test);/*���ÿγ�����*/
	
	strcpy(classs.teacher, name);/*���ý�ʦ*/
	
	printf("\n������γ���ֹʱ�䣬��ʽΪ201*-201*ѧ���*ѧ�ڵ�*��-��*�ܣ�");
	scanf("%s", classs.term);/*������ֹʱ��*/
	
	test4:
	do
	{
	test = 0;
	printf("\n�������Ͽ�ʱ���Ӧ����\n1--8:00-8:50\n2--9:00-9:50\n3--10:00-10:50\n4--11:00-11:50\n5--13:30-14:20\n6--14:30-15:20\n7--15:30-16:20\n8--16:30-17:20\n9--18:30-19:20\n10--19:30-20:20\n���룺");
	scanf("%d", &classs.time);
	if (classs.time<1 || classs.time>10)
	{
	 test = 1;
	 printf("\nʱ��������������������\n");
	}
    }while(test);/*�����Ͽ�ʱ��*/
    if (classs.time == classtime)
    { 
    printf("\n���ѿ���ʱ���ͻ���������趨\n");
    goto test4;
    } 
    
	
	printf("\n�������Ͽεص㣬��ʽΪ¥��-����ţ�");
	scanf("%s", classs.place);/*�����Ͽεص�*/
	
	do
	{
	 test = 0;
	 printf("\n������γ�����������80��100����");
	 scanf("%d", &classs.limnum);
	 if (classs.limnum!=80 && classs.limnum!=100)
	 {
	  test = 1;
	  printf("\n�γ���������������������������\n");
	 }
	}while(test);/*������������*/
	
	printf("\n������γ̼�飨35�����ڣ�:");
	scanf("%s", classs.briefinf);/*������*/
	
	printf("\n������̲����ƣ���ʽΪ����������");
	scanf("%s", classs.book);/*����̲���*/
	
	classs.numalready = 0;/*��ʼ����ѡ����*/
	
	classfile = fopen("�γ���Ϣ.txt", "a");
	fprintf(classfile,"\n");
	fprintf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d", classs.classid, classs.classname, classs.credit, classs.totaltime, classs.type, classs.teacher, classs.term, classs.time, classs.place, classs.limnum, classs.briefinf, classs.book, classs.numalready);/*������*/
    printf("\n���γɹ�\n");
    fclose(classfile);
 }
 }
 }
 
 
 void modiclassinf(int id)/*�޸Ŀγ���Ϣ�����ײ���*/
{
 FILE *classfile, *teacherfile;
 struct Classinf {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };
 struct Teacherinf {int teacherid; char school[30]; char teachername[20]; char mailaddr[30];  char password[10]; };
 
 int cid, test;
 printf("\n���������޸ĵ���������γ̵ı�ţ�");
 scanf("%d", &cid);
 
 classfile = fopen("�γ���Ϣ.txt", "r");/*�����γ���Ϣ�ṹ����*/
 int s1,s3,s4,s8,s10,s13, count1 = 0;
 char s2[81], s5[81], s6[81], s7[81], s9[81], s11[81], s12[81];/*s[i]ϵ�еı���ֻ����ʱ����*/
 while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d",&s1, s2, &s3, &s4, s5, s6, s7, &s8, s9, &s10, s11, s12, &s13) != EOF)/*��ȡ�γ��ļ���ȷ���ж������γ���Ϣ*/
 count1 ++;
 fclose (classfile);

 classfile = fopen("�γ���Ϣ.txt", "r");
 struct Classinf classinf[count1];
 int j=0;
 while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d", &classinf[j].classid, classinf[j].classname, &classinf[j].credit, &classinf[j].totaltime, classinf[j].type, classinf[j].teacher, classinf[j].term, &classinf[j].time, classinf[j].place, &classinf[j].limnum, classinf[j].briefinf, classinf[j].book, &classinf[j].numalready) != EOF)
  {
 j++;
 }
 fclose(classfile);
 
 int i, count2= -1;/*�����Ƿ��иÿγ̣�����оͱ����������*/
 for (i=0; i<count1; i++)
 {
  if (cid == classinf[i].classid)
  {
   count2 = i;
   break;
  }
 }
 
 if (count2 == -1)
 printf("\nû�и����γ���Ϣ��\n");
 
 else
 {
   teacherfile = fopen("��ʦ��Ϣ.txt", "r");/*������ʦ��Ϣ�ṹ����*/
   int count3=0, a1;
   char a2[81], a3[81], a4[81], a5[81];/*aϵ�к���ֻ����ʱ����*/
   while(fscanf(teacherfile, "%d %s %s %s %s", &a1, a2, a3, a4, a5)!= EOF)/*��һ�ζ�ȡ�ļ���ȷ����Ϣ��Ŀ��*/
  {
  count3++;
  }
  fclose(teacherfile);
 
  teacherfile = fopen("��ʦ��Ϣ.txt", "r");
  struct Teacherinf teacherinf[count3];
  i=0;
  while (fscanf(teacherfile, "%d %s %s %s %s", &teacherinf[i].teacherid, teacherinf[i].school, teacherinf[i].teachername, teacherinf[i].mailaddr, teacherinf[i].password)!= EOF)
  {
  i++;
  }
 
 char name[81];/*����id��ȡ��ʦ����*/
 for (i=0; i<count3; i++)
 {
  if (id == teacherinf[i].teacherid)
  {
  	strcpy(name, teacherinf[i].teachername);
  	break;
  }
  } 
  fclose(teacherfile);
  
  if (strcmp(name, classinf[count2].teacher) != 0)
  {
   printf("\n�ÿγ̲����������裬�޷��޸ģ�\n");
  }
  
  else/*ȷ���Ǹý�ʦ����Ŀγ�*/
  {
  	if (classinf[count2].numalready == 0)/*��û����ѡ�ÿ�*/
  	{
  		printf("\n��û����ѡ�ÿΣ������޸Ľ̲ģ��γ̼�飬��������, �����������ʾ����޸�\n");
  		printf("\n�Ƿ��޸Ľ̲ģ��������Ӧ����: 1-�ǣ�2-��");
  		int chocode1;
  		scanf("%d", &chocode1);
  		if (chocode1 == 1)
  		{
  		 printf("\nԭ����%s, ����������̲���Ϣ��", classinf[count2].book);
         scanf("%s", classinf[count2].book); 
		  }
		  
		printf("\n�Ƿ��޸Ŀγ̼�飿�������Ӧ���֣�1-�ǣ�2-��");
		int chocode2;
		scanf("%d", &chocode2);
		if (chocode2 == 1)
		{
		 printf("\n������¼��γ̼�飺");
		 scanf("%s", classinf[count2].briefinf);
		}
		
		printf("\n�Ƿ��޸������������������Ӧ���֣�1-�ǣ�2-��");
		int chocode3;
		scanf("%d", &chocode3);
		if (chocode3 == 1)
		{
		 printf("\nԭ��������%d, ��������������������80��100��\n", classinf[count2].limnum);
		 do
	     {
	      test = 0;
	      printf("\n������γ�����������80��100����");
	      scanf("%d", &classinf[count2].limnum);
	      if (classinf[count2].limnum!=80 && classinf[count2].limnum!=100)
	     {
	       test = 1;
	       printf("\n�γ���������������������������\n");
	     }
	     }while(test);/*������������*/
		}
		
		classfile = fopen("�γ���Ϣ.txt", "w");/*��¼�γ���Ϣ*/
		for (i=0; i<count1; i++)
		{
		fprintf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d\n", classinf[i].classid, classinf[i].classname, classinf[i].credit, classinf[i].totaltime, classinf[i].type, classinf[i].teacher, classinf[i].term, classinf[i].time, classinf[i].place, classinf[i].limnum, classinf[i].briefinf, classinf[i].book, classinf[i].numalready);
	    }
		printf("\n�γ���Ϣ�޸ĳɹ���\n");		
	  }
	  
	  else/*�Ѿ�����ѡ��*/
	  {
	  	printf("\n������ѡ�ÿΣ�ֻ���޸���������\n");
	  	printf("\n�Ƿ��޸������������������Ӧ���֣�1-�ǣ�2-��");
	    int chocode4; 
	    scanf("%d", &chocode4);
	    if(chocode4 == 1)
	    {
	     printf("\nԭ��������%d, ��������������������80��100��\n", classinf[count2].limnum);
		 do
	     {
	      test = 0;
	      printf("\n������γ�����������80��100����");
	      scanf("%d", &classinf[count2].limnum);
	      if (classinf[count2].limnum!=80 && classinf[count2].limnum!=100)
	     {
	       test = 1;
	       printf("\n�γ���������������������������\n");
	     }
	     }while(test);/*������������*/
		}
		classfile = fopen("�γ���Ϣ.txt", "w");/*��¼�γ���Ϣ*/
		for (i=0; i<count1; i++)
		{
		fprintf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d\n", classinf[i].classid, classinf[i].classname, classinf[i].credit, classinf[i].totaltime, classinf[i].type, classinf[i].teacher, classinf[i].term, classinf[i].time, classinf[i].place, classinf[i].limnum, classinf[i].briefinf, classinf[i].book, classinf[i].numalready);
	    }
		printf("\n���\n");
	  }
  }	
  } 
}


void deleteclass(int id)/*��ʦɾ�κ����ײ���*/
{
 FILE *classfile, *teacherfile, *student_classfile; 
 struct Classinf {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };
 struct Teacherinf {int teacherid; char school[30]; char teachername[20]; char mailaddr[30];  char password[10]; };
 struct Classpicked {int studentid; char studentname[10]; int classid;};
 
 int cid, test;
 printf("\n���������޸ĵ���������γ̵ı�ţ�");
 scanf("%d", &cid);
 
 classfile = fopen("�γ���Ϣ.txt", "r");/*�����γ���Ϣ�ṹ����*/
 int s1,s3,s4,s8,s10,s13, count1 = 0;
 char s2[81], s5[81], s6[81], s7[81], s9[81], s11[81], s12[81];/*s[i]ϵ�еı���ֻ����ʱ����*/
 while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d",&s1, s2, &s3, &s4, s5, s6, s7, &s8, s9, &s10, s11, s12, &s13) != EOF)/*��ȡ�γ��ļ���ȷ���ж������γ���Ϣ*/
 count1 ++;
 fclose (classfile);

 classfile = fopen("�γ���Ϣ.txt", "r");
 struct Classinf classinf[count1];
 int j=0;
 while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d", &classinf[j].classid, classinf[j].classname, &classinf[j].credit, &classinf[j].totaltime, classinf[j].type, classinf[j].teacher, classinf[j].term, &classinf[j].time, classinf[j].place, &classinf[j].limnum, classinf[j].briefinf, classinf[j].book, &classinf[j].numalready) != EOF)
  {
 j++;
 }
 fclose(classfile);
 
 int i, count2= -1;/*�����Ƿ��иÿγ̣�����оͱ����������*/
 for (i=0; i<count1; i++)
 {
  if (cid == classinf[i].classid)
  {
   count2 = i;
   break;
  }
 }
 
 if (count2 == -1)
 printf("\nû�и����γ���Ϣ��\n");
 
 else
 {
   teacherfile = fopen("��ʦ��Ϣ.txt", "r");/*������ʦ��Ϣ�ṹ����*/
   int count3=0, a1;
   char a2[81], a3[81], a4[81], a5[81];/*aϵ�к���ֻ����ʱ����*/
   while(fscanf(teacherfile, "%d %s %s %s %s", &a1, a2, a3, a4, a5)!= EOF)/*��һ�ζ�ȡ�ļ���ȷ����Ϣ��Ŀ��*/
  {
  count3++;
  }
  fclose(teacherfile);
 
  teacherfile = fopen("��ʦ��Ϣ.txt", "r");
  struct Teacherinf teacherinf[count3];
  i=0;
  while (fscanf(teacherfile, "%d %s %s %s %s", &teacherinf[i].teacherid, teacherinf[i].school, teacherinf[i].teachername, teacherinf[i].mailaddr, teacherinf[i].password)!= EOF)
  {
  i++;
  }
 
 char name[81];/*����id��ȡ��ʦ����*/
 for (i=0; i<count3; i++)
 {
  if (id == teacherinf[i].teacherid)
  {
  	strcpy(name, teacherinf[i].teachername);
  	break;
  }
  } 
  fclose(teacherfile);
  
  if (strcmp(name, classinf[count2].teacher) != 0)
  {
   printf("\n�ÿγ̲����������裬�޷�ɾ����\n");
  }	
  
  else/*ȷ���Ǹý�ʦ����Ŀγ�*/
  {
  	if (classinf[count2].numalready != 0)
  	{
  	 printf("\n����ѧ��ѡ�ÿΣ�����ɾ��\n");
	  }
  	
  	else
  	{
  		printf("\nĿǰ����ѡ�ÿΣ�ִ��ɾ����\n");
  		classfile= fopen("�γ���Ϣ.txt", "w");
  		for (i=0; i<count1; i++)
  		{
  		 if (i != count2)
  		 {
  		 	fprintf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d\n", classinf[i].classid, classinf[i].classname, classinf[i].credit, classinf[i].totaltime, classinf[i].type, classinf[i].teacher, classinf[i].term, classinf[i].time, classinf[i].place, classinf[i].limnum, classinf[i].briefinf, classinf[i].book, classinf[i].numalready);
		   }
  			
		  }
		student_classfile = fopen("ѧ��ѡ�α�.txt","r");/*ȷ��ѧ��ѡ�α���Ϣ����*/
        int a1, a3, count4= 0;
        char a2[81];/*a[i]ϵ�б���ֻ����ʱ����*/
        while (fscanf(student_classfile, "%d %s %d", &a1, a2, &a3)!= EOF)
        count4++;
        fclose (student_classfile);
        
        student_classfile = fopen("ѧ��ѡ�α�.txt","r");
        struct Classpicked classpicked[count4];
        int k = 0;
        while (fscanf(student_classfile, "%d %s %d", &classpicked[k].studentid, classpicked[k].studentname, &classpicked[k].classid)!= EOF)
        {
         k++;
		}
        fclose(student_classfile);
        
        student_classfile = fopen("ѧ��ѡ�α�.txt", "w");
        for (k=0; k<count4; k++)
        {
         if (cid != classpicked[k].classid)
         {
          fprintf(student_classfile, "%-16d%-12s%-d\n", classpicked[k].studentid, classpicked[k].studentname, classpicked[k].classid);
		 }
		}
    
		  printf("\nɾ���ɹ���\n");
	  }
  	
  	
  	} 
 
 } 
}


void teacher_information(int id)/*��ʦ�޸ĸ�����Ϣ�����ײ���*/
{struct Information_tea 
{int id_file;char college[15];char name[10];char mail[30];char password_file[20]; };
 int i,choose,j=0,mark,choose1,count=0;
 int test1=0,test2=0,test3=0; 
 char password1[20],password2[20],mail[30];
 FILE *teacher_file;
 
 if((teacher_file=fopen("��ʦ��Ϣ.txt","r"))==NULL)
 {printf("�ļ��޷���\n"); 
  }

 else
 {
  struct Information_tea teacher1;
 while(fscanf(teacher_file,"%d %s %s %s %s",&teacher1.id_file,teacher1.college,teacher1.name,teacher1.mail,teacher1.password_file)!= EOF)
 {
 	count++;
 }
 fclose(teacher_file);
 
  teacher_file=fopen("��ʦ��Ϣ.txt","r");
  struct Information_tea teacher[count];
 printf("����       ѧԺ            ����       ����                           ����            \n"); /*���ļ��ж�ȡ����ӡ��ǰ�����½�ʦ��Ϣ*/ 
 for(i=0;i<count;i++) 
 {fscanf(teacher_file,"%d %s %s %s %s",&teacher[i].id_file,teacher[i].college,teacher[i].name,teacher[i].mail,teacher[i].password_file);
  if(id==teacher[i].id_file)
  {mark=i;
   printf("%9d %-15s %-10s %-30s %-20s\n",teacher[i].id_file,teacher[i].college,teacher[i].name,teacher[i].mail,teacher[i].password_file);
  }
 }
 i=mark;    /*��¼��ǰ��������Ϣ�洢λ��*/ 
 printf("\n�޸���Ϣ������1;�����������ַ��ص�¼�ɹ�ҳ�棺");
 scanf("%d",&choose1); 
 if(choose1==1)
 {printf("\n�޸ĸ�������������1���޸�����������2��");
  scanf("%d",&choose);
  if(choose==1)
  {while(!test1)
  {j=1;
   test3=0;
   printf("\n�����������䣺");     
   scanf("%s",mail);
   while(mail[j])      /*��֤�����ʽ*/
   {if(mail[j]=='@')
    {break;}
    j++;
   }
   j=j+2;
   while(mail[j])
   {if(mail[j]=='.')
    break;
    j++;
   }
   if (mail[0]=='@')
   test3=1;
   if((!mail[j+1])||(test3==1))
   {printf("\n�����ʽ�������������룺");
   }
   
   else
   {printf("\n�����޸ĳɹ���");
    strcpy(teacher[i].mail,mail);
    test1=1;
   }
  }
  }
  else if(choose==2)
  {while(!test2)
   {printf("\n����������룺");/*��֤����һ����*/ 
    scanf("%s",password1);
    if(strcmp(password1,teacher[i].password_file)==0)
    {while(!test1)
	 {printf("\n�����������루���벻�ɰ����ո񣩣�");   
      scanf("%s",password1);
      printf("\n���ٴ����������룺");
      scanf("%s",password2);
      if(strcmp(password1,password2)==0)
      {strcpy(teacher[i].password_file,password1);
       printf("\n�����޸ĳɹ���");
       break;
      }
	  else
	   printf("\n�����������벻һ�£�"); 
	 }
	 break;
    }
    else
    printf("\n�����������");
   }
  }
 fclose(teacher_file);
 if((teacher_file=fopen("��ʦ��Ϣ.txt","w"))==NULL)
 {printf("�ļ��޷���\n"); 
  }
  for(i=0;i<16;i++)     /*�����º����Ϣ����д���ļ�*/ 
  {fprintf(teacher_file,"%9d %-15s %-10s %-30s %-20s\n",teacher[i].id_file,teacher[i].college,teacher[i].name,teacher[i].mail,teacher[i].password_file);
  }
  fclose(teacher_file);
 }
}
}


void autodelete()/*�Զ�ɾ�����ź����ײ���*/
{
 int year,mon,day,hour,min,sec, test, count=0;	
 tm mytime;
  FILE *classfile, *student_classfile;
  struct Classinf {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };            
  struct Classpicked {int studentid; char studentname[10]; int classid;};
 
 _getsystime(&mytime);/*��ȡϵͳʱ��*/      
 year=mytime.tm_year+1900;  
 mon=mytime.tm_mon+1;     
 day=mytime.tm_mday;   
 hour=mytime.tm_hour;  
 min=mytime.tm_min;   
 sec=mytime.tm_sec;   
 

 if (year<YEAR)
 test = 1;
 else
 {
  if (year>YEAR)
  {
  	test = 0;
  }
  else 
  {
   if (mon<MON)
   {
   	test = 1;
   }
   else
   {
   	if (mon>MON)
   	{
   		test = 0;
	   }
	   else
	   {
	   	if (day<DAY)
	   	{
	   		test = 1;
		   }
		   else
		   {
		   	if (day>DAY)
		   	{
		   		test = 0;
			   }
			   else
			   {
			   	if (hour<HOUR)
			   	{
			   		test = 1;
				   }
				   else 
				   {
				   	if (min<MIN)
				   	{
				   		test = 1;
					   }
					   else 
					   {
					   	if (sec<SEC)
					   	{
					   		test = 1;
						   }
						   else
						   test = 0;
					   }
				   }
			   }
		   }
	   }
   }
  }
 }
 
 if (test == 1)
 printf("\nδ������ֹʱ��\n");
 else
 {
 	printf("\n����ѡ��ʱ�䣬����ɾ������С��2�Ŀγ�");
 	classfile = fopen("�γ���Ϣ.txt", "r");
 	struct Classinf classs;
 	while(fscanf(classfile,"%d %s %d %d %s %s %s %d %s %d %s %s %d",&classs.classid, classs.classname, &classs.credit, &classs.totaltime, classs.type, classs.teacher, classs.term, &classs.time, classs.place, &classs.limnum, classs.briefinf, classs.book, &classs.numalready) != EOF)  
   {
   	count ++;
   }                         
   fclose(classfile);
   
   classfile = fopen("�γ���Ϣ.txt", "r");
   struct Classinf classinf[count];
   int i =0;
   while(fscanf(classfile,"%d %s %d %d %s %s %s %d %s %d %s %s %d",&classinf[i].classid, classinf[i].classname, &classinf[i].credit, &classinf[i].totaltime, classinf[i].type, classinf[i].teacher, classinf[i].term, &classinf[i].time, classinf[i].place, &classinf[i].limnum, classinf[i].briefinf, classinf[i].book, &classinf[i].numalready) != EOF)
   {
   	i++;
   }
   fclose(classfile);
   
   classfile = fopen("�γ���Ϣ.txt", "w");
   int count1=0; 
   for (i=0; i<count; i++)
   {
   	if (classinf[i].numalready >= 2)
   	{
   		fprintf(classfile,"%d %s %d %d %s %s %s %d %s %d %s %s %d\n", classinf[i].classid, classinf[i].classname, classinf[i].credit, classinf[i].totaltime, classinf[i].type, classinf[i].teacher, classinf[i].term, classinf[i].time, classinf[i].place, classinf[i].limnum, classinf[i].briefinf, classinf[i].book, classinf[i].numalready);
	   }
	   else count1++;/*��¼ɾ���˼����γ�*/
	   }/*�ڿγ���Ϣ�ļ���ɾ���ÿγ�*/
	   fclose(classfile);
   
   int cid[count1], j;
   for (i=0, j=0; i<count; i++)
   {
   	if (classinf[i].numalready<2)
   	{
   		cid[j] = classinf[i].classid;
   		j++;
	   }
	} /*����ɾ���γ̵�ID����*/
   
    student_classfile = fopen("ѧ��ѡ�α�.txt","r");/*ȷ��ѧ��ѡ�α���Ϣ����*/
    int a1, a3, count2= 0;
    char a2[81];/*a[i]ϵ�б���ֻ����ʱ����*/
    while (fscanf(student_classfile, "%d %s %d", &a1, a2, &a3)!= EOF)
    count2++;
    fclose (student_classfile);
    
    student_classfile = fopen("ѧ��ѡ�α�.txt","r");
        struct Classpicked classpicked[count2];
        int k = 0;
        while (fscanf(student_classfile, "%d %s %d", &classpicked[k].studentid, classpicked[k].studentname, &classpicked[k].classid)!= EOF)
        {
         k++;
		}
        fclose(student_classfile);
        
        student_classfile = fopen("ѧ��ѡ�α�.txt","w");
        for (i=0; i<count2; i++)
        {
        	for (k=0, test=1; k<count1; k++)
        	 {
        	 	if (classpicked[i].classid == cid[k])
        	 	{
        	 	 test = 0;
        	 	 break;
				 }
			 }
			 if (test)
             fprintf(student_classfile, "%-16d%-12s%-d\n", classpicked[i].studentid, classpicked[i].studentname, classpicked[i].classid);
             
			
		}/*���ѧ��ѡ�α����¼*/
   fclose(student_classfile);
   printf("\nɾ����ɣ�\n");
   
   }
}


void student_information(int id)/*ѧ���޸ĸ�����Ϣ�����ײ���*/
{struct Information_stu 
 {int id_file;char college[15];char major[20];char name[10];char sex[3];char Tel[15];char password_file[20];char mail[30]; };
 int i,mark,choose,j=0,choose1, count=0;
 int test1=0,test2=0,test3=0; 
 char password1[20],password2[20],mail[30];  
 FILE *student_file;
 
 if((student_file=fopen("ѧ����Ϣ.txt","r"))==NULL)
 {printf("�ļ��޷���\n"); 
  }
  
  else
  {
  	struct Information_stu student1;
  	while(fscanf(student_file,"%d %s %s %s %s %s %s %s",&student1.id_file,student1.college,student1.major,student1.name,student1.sex,student1.Tel,student1.password_file,student1.mail)!= EOF)
 {
 	count++;
 }
 fclose(student_file);
 } 
  student_file=fopen("ѧ����Ϣ.txt","r");
  struct Information_stu student[count];
 printf("ѧ��       ѧԺ            רҵ                     ����    �Ա�   �ֻ�����\n");  /*���ļ��ж�ȡ����ӡ��ǰѧ����ѧ����Ϣ*/
 for(i=0;i<count;i++) 
 {fscanf(student_file,"%d %s %s %s %s %s %s %s",&student[i].id_file,student[i].college,student[i].major,student[i].name,student[i].sex,student[i].Tel,student[i].password_file,student[i].mail);
  if(id==student[i].id_file) 
  {printf("%9d %-15s %-20s %10s %3s %15s\n",student[i].id_file,student[i].college,student[i].major,student[i].name,student[i].sex,student[i].Tel); 
   printf("\n����                 ����         21                  \n");
   printf("%-20s %-30s\n",student[i].password_file,student[i].mail);
   mark=i;/*��¼��ǰѧ������Ϣ�洢λ��*/
  }
 }
 i=mark; 
 printf("\n�޸���Ϣ������1�������������ַ��ص�¼�ɹ�ҳ��:");
 scanf("%d",&choose1); 
 if(choose1==1)
 {printf("\n�޸ĸ�������������1���޸�����������2���޸ĵ绰����������3��");
  scanf("%d",&choose);
  if(choose==1)
  {while(!test1)
  {j=1; 
   test3=0;
   printf("\n�����������䣺");     
   scanf("%s",mail);
   while(mail[j])      /*��֤�����ʽ*/
   {if(mail[j]=='@')
    {break;}
    j++;
   }
   j=j+2;
   while(mail[j])
   {if(mail[j]=='.')
    break;
    j++;
   }
   if (mail[0]=='@')
   test3=1;
   if((!mail[j+1])||(test3==1))
   {printf("\n�����ʽ�������������룺");
   }
   else
   {printf("\n�����޸ĳɹ���");
    strcpy(student[i].mail,mail);
    test1=1;
   }
  }
  }
  else if(choose==2) 
  {while(!test2)
   {printf("\n����������룺"); /*��֤����һ����*/
    scanf("%s",password1);
    if(strcmp(password1,student[i].password_file)==0)
    {while(!test1)
	 {printf("\n�����������루���벻�ɰ����ո񣩣�");
      scanf("%s",password1);
      printf("\n���ٴ����������룺");
      scanf("%s",password2);
      if(strcmp(password1,password2)==0)
      {strcpy(student[i].password_file,password1);
       printf("\n�����޸ĳɹ���");
       break;
      }
	  else
	   printf("\n�����������벻һ�£�"); 
	 }
	 break;
    }
    else
    printf("\n�����������");
   }
  }
  else if(choose==3)
  {printf("\n���������ֻ����룺");
   scanf("%s",student[i].Tel);
   printf("\n�޸ĳɹ���");
  }
 fclose(student_file);
 if((student_file=fopen("ѧ����Ϣ.txt","w"))==NULL)
 {printf("�ļ��޷���\n"); 
 }
 for(i=0;i<39;i++)  /*�����º����Ϣ����д���ļ�*/ 
 {fprintf(student_file,"%9d %-15s %-20s %-10s %3s %15s %-20s %-30s\n",student[i].id_file,student[i].college,student[i].major,student[i].name,student[i].sex,student[i].Tel,student[i].password_file,student[i].mail);
 }
 fclose(student_file);
 }
}
