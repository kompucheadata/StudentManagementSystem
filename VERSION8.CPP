#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<dir.h>
#include<string.h>
#include<stdlib.h>
#include<alloc.h>
#include<ctype.h>
#define log "c:/log/users/user.txt"
#define ver_log "c:/ass/fix/ver.txt"
#define local "c:/log/data/student.txt"
#define localcpy "c:/log/data/temp.txt"
#define locals "c:/log/data/subject.txt"
#define localp "c:/log/data/score.txt"
#define localde "c:/log/data/department.txt"
#define localy1 "c:/log/data/y1.txt"
#define localy2 "c:/log/data/y2.txt"
#define localy3 "c:/log/data/y3.txt"
#define localy4 "c:/log/data/y4.txt"


	struct depart{
	char name[20];
	char date[20];
	};
	struct stu{
	char id[10];
	char name[20];
	char sex[7];
	char ngai[5];
	char khae[5];
	char jnam[5];
	char subjects[20];
	char room[7];
	char year[7];
};
	struct score_st{
	char subject[25];
	char score[5];

	};
	struct sub{
	char depa[10];
	char title1[20];
	char title2[20];
	char title3[20];
	char title4[20];
	char title5[20];
	char title6[20];
	char title7[20];
	char title8[20];

};
struct vertify{
	char name[20],pass[20];
};
struct user{
	char name[20],pass[20];
};                  int action=0;
	depart de;
	stu p,p1,p2;score_st pt;
	sub s;
	FILE *fp,*fp1,*fp2,*name,*fscore,*fde;

int a,j,b,b1,l,leng[8];char k,c,d,d1,ch,key;
void main();
void ver_comp();
void reg_user();
void login_user();
void clear(int a1,int a2,int b1,int b2);
void start();
void drop(char *d1,char *d2,char *d3,char *d4,int x,int y1,int y2,int y3,int y4);
void background(int,int,int,int,int color);
void loading();
void TABLE(int,int,int,int,int,int);
void ARROW_UP();
void ARROW_DOWN();
void SHOW_ARROW_DOWN(char *c1,char *c2,char *c3,char *c4,int x);
void SHOW_ARROW_UP();
void menu();
void department();
void student();
void score();
void subject();
void about();
void year1();
void year2();
void year3();
void year4();
void year1s();
void year2s();
void year3s();
void year4s();
void insert_sub(int year);
void show_sub(int year);
void msg(){

	background(17,63,10,14,2);
	TABLE(17,63,10,14,15,2);
	gotoxy(19,12);textcolor(15);cprintf(" PRESS ANYKEY FOR CONTINUE OR ESC FOR EXIT ");
}
void actio(){
	gotoxy(24,21);textbackground(3);textcolor(1);
	cprintf(" PRESS ARROW TO CONTINUE ECS TO BACK ");
	delay(1500);clear(24,60,21,21);textcolor(15);
}
void sort(){    int i,k,n;
		fp=fopen(local,"rb");
		n=ftell(fp)/sizeof(stu);
		for(i=0;i<n;i++){
			fseek(fp,i * sizeof(stu), SEEK_SET);
			fread(&p1,sizeof(stu),1,fp);
			for(j=i+1;j<n;j++){
				fseek(fp, j *sizeof(stu),SEEK_SET);
				fread(&p2,sizeof(stu),1,fp);
				if(strcmp(p1.name,p2.name)>0){

				rewind(fp);
				fp1=fopen("temp.txt","wb");
				for(k=0;k<n;k++){
				fread(&p,sizeof(stu),1,fp);
				if(k==i)
					p=p2;
				if(k==j)
					p=p1;

				fwrite(&p,sizeof(stu),1,fp1);
				}

				fclose(fp); fclose(fp1);
				remove(local);
				rename(localcpy,local);
				fp=fopen(local,"rb");
				p1=p2;

				}


			}
		}
		background(17,63,10,14,2);
		TABLE(17,63,10,14,15,2);
		gotoxy(31,12);textcolor(15);cprintf("Sort Completed"); getch();



		}
void Show_Edit(){
			if(l<=0)l=6;
			if(l>=7)l=1;
			switch(l){

			  case 1:gotoxy(9,8);textcolor(15);textbackground(2);cprintf("      NAME      ");break;
			  case 2:gotoxy(9,10);textcolor(15);textbackground(2);cprintf("      SEX       "); break;
			  case 3:gotoxy(9,12);textcolor(15);textbackground(2);cprintf("     D-O-B      ");break;
			  case 4:gotoxy(9,14);textcolor(15);textbackground(2);cprintf("    SUBJECT     ");break;
			  case 5:gotoxy(9,16);textcolor(15);textbackground(2);cprintf("     CLASS      ");break;
			  case 6:gotoxy(9,18);textcolor(15);textbackground(2);cprintf("     YEAR       ");;break;

			}}

void input(char *st,int length){
      char ch;
      int leng=0,i=0;
      do{
		ch=getch();
		if(ch==27)main();
		if(ch>='0'&&ch<='9'|| ch==8){
			if(ch!=8){
				st[i]=ch;i++;
				leng=strlen(st);
					if(leng<length)
						printf("%c",ch);
					else{
						i--;
						st[i]='\0';
					    }
			}else{
				if(i>0){
					i--;
					st[i]='\0';
					printf("\b \b");
					}
				}
						}
      }while(ch!=13||i==0);

}

void input2(char *st,int length){
      char ch;int leng=0,i=0;
      do{
	ch=getch();
	if(ch==27)main();
	if(isalpha(ch)||isdigit(ch)||ch==32|| ch==8){

	if(ch!=8){
	    st[i]=ch;i++;
	    leng=strlen(st);
	    if(leng<length)
	    printf("%c",ch);
	    else{
	    i--;
	    st[i]='\0';
	    }
	}else{
	if(i>0){
	i--;
	st[i]='\0';
	printf("\b \b");
	}
	}
	}
      }while(ch!=13);

}
void input3(char *st,int length){
      char ch;
      int leng=0,i=0;
      do{
      ch=getch();
      if(ch==27)main();
      if(ch>='a'&&ch<='z'||isdigit(ch)||ch==32|| ch==8){
	if(ch!=8){
st[i]=ch;i++;
leng=strlen(st);
	if(leng<length)printf("*",ch);
	else{
i--;st[i]='\0';}
	}else{
if(i>0){i--;st[i]='\0';printf("\b \b");}}}
if(ch==27)break;
      }while(ch!=13);

}


void check(){ user u; char ch;
	     action=1;
 clrscr();
	    FILE *check;
	    check=fopen(log,"r+b");
	    if(check==NULL){
		  fclose(check);
		 reg_user();
		 }else{
		 fclose(check);
		 ver_comp();
		 clrscr();
		 login_user();
		 }

}

void reg_user(){  char pass_again[20];
		  vertify v;
		  user u;
		  FILE *reg;
		  FILE *fv;
		  mkdir("c:/log");
		  mkdir("c:/log/users");
		  mkdir("c:/ass");
		  mkdir("c:/ass/fix");
		  textbackground(15);
		  clrscr();
		  _setcursortype(2);
		  background(15,65,5,17,1);
		  background(34,54,9,9,2);
		  background(34,54,11,11,2);
		  background(34,54,13,13,2);
		  TABLE(15,65,5,17,15,1);
		  gotoxy(32,5);textcolor(15);cprintf("REGISTER NEW USER");
		  gotoxy(24,9);textcolor(15);cprintf("USERNAME: ");
		  gotoxy(24,11);textcolor(15);cprintf("PASSWORD: ");
		  gotoxy(16,13);textcolor(15);cprintf("CONFIRM PASSWORD: ");
		  char users[20]="";
		  gotoxy(35,9);input2(users,7);
     agai:                  char pass1[20]="";
		  gotoxy(35,11);input3(pass1,15);
		  char pass2[20]="";
		  gotoxy(35,13);input3(pass2,15);
		  if(strcmp(pass1,pass2)!=0){
		  gotoxy(21,20);
		  textcolor(15);
		  cprintf("YOUR ENTER NOT MATCH");clear(35,50,13,13);clear(35,50,11,11);goto agai;

		  }
		  else{

		  clrscr();
		  _setcursortype(0);
		  gotoxy(28,12);textcolor(BLINK +15);cprintf("REGISTER SUCCESSFULLY");
		  gotoxy(1,25);printf("ESC TO EXIT");
		  delay(2000);clear(1,20,25,25);
		  strcpy(u.name,users);strcpy(u.pass,pass1);
		  }
		  //vertify file
		  strcpy(v.name,u.name);strcpy(v.pass,u.pass);
		  fv=fopen(ver_log,"w+b");
		  fwrite(&v,sizeof(vertify),1,fv);
		  fclose(fv);
		  //end vertify file


		  reg=fopen(log,"w+b");
		  fwrite(&u,sizeof(user),1,reg);
		  fclose(reg);main();

}
void ver_comp(){  user u; vertify v;
		char ch, u_name[20],u_pass[20],v_name[20],v_pass[20];
		  FILE *comp_u,*comp_v;
		  comp_u=fopen(log,"r+b");
		  comp_v=fopen(ver_log,"r+b");
		 while(fread(&u,sizeof(user),1,comp_u)==1){strcpy(u_name,u.name);strcpy(u_pass,v.pass);}
		 while(fread(&v,sizeof(vertify),1,comp_v)==1){strcpy(v_name,v.name);strcpy(v_pass,v.pass);}
		 if(strcmp(v_name,u_name)==0){
		 _setcursortype(0);
			if(strcmp(v_pass,v_pass)==0){
			textbackground(15);
			clrscr();
			background(11,69,11,13,1);
			TABLE(11,69,11,13,15,1);
			gotoxy(16,12);
			textcolor(15);
			cprintf("USER INFO IS IN PROTECTED PLEASE");
			gotoxy(49,12);
			textcolor(BLINK +14);cprintf("WAIT 2 SECOND");
			delay(2000);
			textcolor(15);
			}else{
			fclose(comp_u);fclose(comp_v);
			gotoxy(8,23);
			textcolor(4);
			cprintf("YOUR SYSTEM WAS HACKED PLEASE CONTACT DEVELOPER TO FIX");
			ch=getch();
			if(ch!=0){exit(0);}}
		  }else{
		  fclose(comp_u);fclose(comp_v);
		  gotoxy(8,23);
		  textcolor(4);
		  cprintf("YOUR SYSTEM WAS HACKED PLEASE CONTACT DEVELOPER TO FIX");
		  ch=getch();
		  if(ch==13) exit(0);
}		  }
void login_user(){ char g_name[20],g_pass[20],l_name[20],l_pass[20];
		  user u; char ch;
		FILE *flog;
		flog=fopen(log,"r+b");
		while(fread(&u,sizeof(user),1,flog)==1){
		strcpy(l_name,u.name); strcpy(l_pass,u.pass);
		}
     again:     char name[20]="";char pas[20]="";
		textbackground(15);
		clrscr();
		background(18,61,8,14,1);
		background(30,50,10,10,2);
		background(30,50,12,12,2);
		TABLE(18,61,8,14,15,1);
		gotoxy(32,8);
		textcolor(15);
		cprintf("LOGIN USER INFO");
		gotoxy(20,10);textcolor(15);cprintf("USERNAME : ");
		gotoxy(20,12);textcolor(15);cprintf("PASSWORD : ");
		_setcursortype(2);
		gotoxy(32,10);input2(name,7);strcpy(g_name,name);
		gotoxy(32,12);input3(pas,10);strcpy(g_pass,pas);
		if(strcmp(l_name,g_name)==0&&strcmp(l_pass,g_pass)==0){

			_setcursortype(0);
			background(15,65,11,15,3);
			TABLE(15,65,11,15,1,3);
			gotoxy(32,13);textbackground(3);textcolor(1);cprintf("LOGIN SUCCESSFULLY ! ");
			getch();//delay(1500);



		}else{  int h;
			textbackground(15);
			clrscr();
			_setcursortype(0);
			background(15,65,5,17,1);
			TABLE(15,65,5,17,15,1);
				gotoxy(28,5);textbackground(1);textcolor(15);cprintf(" USERNAME IS IN CORRECT ");
				gotoxy(33,9);textbackground(15);textcolor(0);cprintf("   TRY AGAIN   ");
				gotoxy(33,11);textbackground(15);textcolor(0);cprintf("      EXIT     ");
			 switch(h){
				case 1:gotoxy(33,9);textbackground(2);textcolor(15);cprintf("   TRY AGAIN   ");break;
				case 2:gotoxy(33,11);textbackground(2);textcolor(15);cprintf("      EXIT     ");break;

				}

			 do{

			 ch=getch();
			 if(ch==80)h++;
			 if(ch==72)h--;
				gotoxy(33,9);textbackground(15);textcolor(0);cprintf("   TRY AGAIN   ");
				gotoxy(33,11);textbackground(15);textcolor(0);cprintf("      EXIT     ");

			 if(h<1)h=2;
			 if(h>2)h=1;
			 switch(h){
				case 1:gotoxy(33,9);textbackground(2);textcolor(15);cprintf("   TRY AGAIN   ");break;
				case 2:gotoxy(33,11);textbackground(2);textcolor(15);cprintf("      EXIT     ");break;

			 }
			 if(h==1&&ch==13)goto again;
			 if(h==2&&ch==13)exit(0);
			 }while(ch!=27&&ch!=13);

		}
}
void change_user(){ user u;
		char ch_pass[20],cg_pass[20],ch;
		    vertify v;
		  FILE *check1;
		  FILE *change;
		  FILE *ch_ver;
		  check1=fopen(log,"r+b");
		  while(fread(&u,sizeof(user),1,check1)==1){
			strcpy(ch_pass,u.pass);
						}

		  char new1[20]="",new2[20]="";
		  textbackground(15);
		  clrscr();
		  _setcursortype(2);
		  background(15,65,5,17,1);
		  background(34,54,9,9,2);
		  background(34,54,11,11,2);
		  background(34,54,13,13,2);
		  TABLE(15,65,5,17,15,1);
		  gotoxy(32,5);
		  textcolor(15);
		  cprintf("CHANGE USER INFO");
		  gotoxy(17,9);textcolor(15);cprintf("OLD PASSWORD ");


			fclose(check1);
			gotoxy(17,11);textcolor(15);cprintf("NEW USERNAME ");
			gotoxy(17,13);textcolor(15);cprintf("NEW PASSWORD ");
		   old:	char old[20]="";
			gotoxy(35,9);input3(old,10);
			if(strcmp(old,ch_pass)==0)strcpy(cg_pass,old);
			else {
				gotoxy(20,22);
				printf("PASSWORD IN CORRECT PLEASE INPUT AGAIN");
				clear(20,55,22,22);
				goto old;
			}
			gotoxy(35,11);input2(new1,10);strcpy(u.name,new1);
			gotoxy(35,13);input3(new2,10);strcpy(u.pass,new2);
			strcpy(v.name,u.name);strcpy(v.pass,u.pass);
			change=fopen(log,"w+b");
			ch_ver=fopen(ver_log,"w+b");
			fwrite(&u,sizeof(user),1,change);
			fwrite(&v,sizeof(vertify),1,ch_ver);
			fclose(change);
			fclose(ch_ver);
			}



void in_depart(){
         int kkk;
         fde=fopen(localde,"r+b");
         fseek(fde,0,SEEK_END);
         kkk=ftell(fde)/sizeof(depart);
if(kkk<15){

         do{
	textbackground(1);
	clrscr();start();
	background(2,79,3,22,3);
	background(34,56,10,10,1);
	background(34,40,13,13,1);
	TABLE(2,79,3,22,0,3);
	gotoxy(15,10);textcolor(15);cprintf("INSERT DEPARTMENT ");
	gotoxy(15,13);textcolor(15);cprintf("    YEAR INSERTED ");
            fp=fopen(localde,"a+b");
            fde=fopen(localde,"r+b");
	fseek(fde,0,SEEK_END);
	kkk=ftell(fde)/sizeof(depart);
            if(kkk<15){
         gg:	char part[20]="";
	_setcursortype(2);
	gotoxy(35,10);input2(part,20);

	rewind(fde);while(fread(&de,sizeof(depart),1,fde)==1){

	if(strcmp(part,de.name)==0){
		clear(34,56,10,10);
		gotoxy(32,21);printf("THIS PARTMENT IS ALREADY");
		goto gg;

	}
	}fclose(fde);

	clear(32,60,21,21);
	strcpy(de.name,part);

        dk:	char date[20]="";
	int yeard=0;
	gotoxy(35,13);input(date,5);yeard=strlen(date);
		if(atoi(date)<1920||yeard!=4){
			clear(35,40,13,13);goto dk;
		}else
			strcpy(de.date,date);_setcursortype(0);msg();
	}else{
		textbackground(1);start();
		background(2,79,3,22,3);
		TABLE(2,79,3,22,0,3);
		gotoxy(25,12);printf("DEPARTMENT CAN'T OVER 15 DATA");
		getch();clrscr();main();
		}
	 ch=getch();
	fwrite(&de,sizeof(depart),1,fp);fclose(fp);
           }while(ch!=27);textbackground(1);start();department();
}else{
		textbackground(1);start();
		background(2,79,3,22,3);
		TABLE(2,79,3,22,0,3);
		gotoxy(25,12);printf("DEPARTMENT CAN'T OVER 15 DATA");
		getch();clrscr();main();
            }
}
void out_depart(){

	textbackground(1);
	start();
	background(2,79,3,22,3);
	TABLE(2,79,3,22,0,3);
	TABLE(40,40,3,22,0,3);

	gotoxy(12,4);textbackground(2);textcolor(15);cprintf("    DEPARTMENT    ");
	gotoxy(51,4);textbackground(2);textcolor(15);cprintf("   YEAR INSERTED   ");
	int i=1,y=5,co;
	fde=fopen(localde,"r+b");
	fseek(fde,0,SEEK_END);
	co=ftell(fde)/sizeof(depart);
	if(co>0){
	rewind(fde);
	while(fread(&de,sizeof(depart),1,fde)==1){
	gotoxy(14,y+i);textcolor(15);printf("%d.%s\n",i,de.name);
	gotoxy(53,y+i);textcolor(15);printf("YEAR : %s\n",de.date);
	i++;
	}}else{
		textbackground(1);
	start();
	background(2,79,3,22,3);
	TABLE(2,79,3,22,0,3);
	gotoxy(35,12);printf("DATA EMPTY");

	}
	getch();fclose(fde);
	textbackground(1);start();department();
}
void del_depart(){
	textbackground(1);clrscr();start();
do{
	background(2,79,3,22,3);
	background(37,57,12,12,1);
	TABLE(2,79,3,22,0,3);
	gotoxy(15,12);printf("ENTER NAME TO DELETE");
	char dd[20]="";
	_setcursortype(2);
	gotoxy(38,12);input2(dd,20);
	b=0;
	fde=fopen(localde,"r+b");
	rewind(fde);
		fp1=fopen(localcpy,"wb");
		while(fread(&de,sizeof(depart),1,fde)==1){
			if(strcmp(de.name,dd)==0) b=1;
			else fwrite(&de,sizeof(depart),1,fp1);
			}
		fclose(fp1);fclose(fde); remove(localde);
		rename(localcpy,localde);
		_setcursortype(0);
		if(b==0){
		background(17,63,10,14,2);
		TABLE(17,63,10,14,15,2);
		gotoxy(31,12);textcolor(15);cprintf("DELETE NOT COMPLETE");}
		else	{
		background(17,63,10,14,2);
		TABLE(17,63,10,14,15,2);
		gotoxy(33,12);textcolor(15);cprintf("DELETE COMPLETED");}
	       ch=getch();
	        }while(ch!=27);textbackground(1);clrscr();start();department();
}




void search(){
	textbackground(1);
	clrscr();start();
	clear(2,79,3,22);
	background(2,79,3,22,3);
	TABLE(2,79,3,22,0,15);
	_setcursortype(2);
	gotoxy(19,5);
	textcolor(15);
	textbackground(3);
	cprintf(" ENTER ID TO SEARCH ");
	background(38,58,5,5,15);
	gotoxy(39,5);
	char x[20]="";
	input2(x,5);
	_setcursortype(0);
		b=0;
		fp=fopen(local,"r+b");
		rewind(fp);

		while(fread(&p,sizeof(stu),1,fp)==1){
		    if(strcmp(p.id,x)==0)b=1;
		    else b=0;
		        if(b==1){
				textbackground(1);
				_setcursortype(0);
				gotoxy(40,8);printf(" NAME");background(53,73,8,8,15);
				gotoxy(54,8);printf("%s",p.name);
				gotoxy(40,10);printf(" SEX");background(53,73,10,10,15);
				gotoxy(54,10);printf("%s",p.sex);
				gotoxy(40,12);printf(" D-O-B");background(53,56,12,12,15);
				gotoxy(54,12);printf("%s",p.ngai);background(58,61,12,12,15);
				gotoxy(59,12);printf("%s",p.khae);background(63,68,12,12,15);
				gotoxy(64,12);printf("%s",p.jnam);
				gotoxy(40,14);printf(" DEPARTAMENT");background(53,73,14,14,15);
				gotoxy(54,14);printf("%s",p.subjects);
				gotoxy(40,16);printf(" CLASS");background(53,73,16,16,15);
				gotoxy(54,16);printf("%s",p.room);
				gotoxy(40,18);printf(" YEAR");background(53,73,18,18,15);
				gotoxy(54,18);printf("%s",p.year);
				getch();textbackground(1);clrscr();start();
			    }
			}if(b==0){
				textbackground(1);
				clrscr();start();
				background(2,79,3,22,3);
				TABLE(2,79,3,22,0,15);
				background(17,63,10,14,2);
				TABLE(17,63,10,14,15,2);
				gotoxy(33,12);textcolor(15);cprintf("ID NOT FOUND");
				getch();textbackground(1);clrscr();start();
			}



 }

void del(){


	//DELETE
	fp=fopen(local,"rb");
	char x[20]="";
	textbackground(1);
	clrscr();start();
	clear(2,79,3,22);
	background(2,79,3,22,3);
	TABLE(2,79,3,22,0,15);

	gotoxy(20,13);
	_setcursortype(2);
	textcolor(15);
	printf("INPUT ID :");
	background(31,51,13,13,15);
	gotoxy(32,13);
	input(x,20);
		b=0;
		rewind(fp);
		fp1=fopen(localcpy,"wb");
		while(fread(&p,sizeof(stu),1,fp)==1){
			if(strcmp(p.id,x)==0) b=1;
			else fwrite(&p,sizeof(stu),1,fp1);
			}
		fclose(fp1);fclose(fp); remove(local);
		rename(localcpy,local);
		_setcursortype(0);
		if(b==0){
		background(17,63,10,14,2);
		TABLE(17,63,10,14,15,2);
		gotoxy(31,12);textcolor(15);cprintf("DELETE NOT COMPLETE");}
		else	{
		background(17,63,10,14,2);
		TABLE(17,63,10,14,15,2);
		gotoxy(33,12);textcolor(15);cprintf("DELETE COMPLETED");}
	       getch();
}
void sco(){
	  char kh;
	  do{
		textbackground(1);start();clear(3,77,4,21);
		background(2,79,3,22,3);
		background(38,58,5,5,15);
		TABLE(2,79,3,22,0,15);
	_setcursortype(2);
	gotoxy(16,5);textcolor(15);textbackground(3);cprintf(" ENTER ID TO INSERT ");
	char xd[20]="";
		gotoxy(39,5);input(xd,5);
		_setcursortype(0);
		b=0;
		rewind(fp);
		fp=fopen(local,"r+b");
		while(fread(&p,sizeof(stu),1,fp)==1){
		    if(strcmp(p.id,xd)==0)b=1;
		    else b=0 ;
		    if(b==1){ fclose(fp);
			do{ textbackground(1);clrscr();
			start();
			background(2,79,3,22,3);
			TABLE(2,79,3,22,0,15);
			background(17,37,9,9,1);
			background(17,22,11,11,1);
			gotoxy(7,9);printf("SUBJECT :");
			gotoxy(7,11);printf("SCORE   :");
		     _setcursortype(2);
			fscore=fopen(localp,"a+b");
				char ject[25]="";
					gotoxy(18,9);input2(ject,20);strcpy(pt.subject,ject);

			    ko:	char pin[4]="";
					gotoxy(18,11);input(pin,4);
				if(atoi(pin)>100){
					clear(18,23,11,11);goto ko;
				}else strcpy(pt.score,pin);
				fseek(fscore,0,SEEK_END);
				fwrite(&pt,sizeof(score_st),1,fscore);
				_setcursortype(0);
				background(17,63,10,14,2);
				TABLE(17,63,10,14,15,2);
				gotoxy(19,12);textcolor(15);cprintf(" PRESS ANYKEY FOR CONTINUE OR ESC FOR EXIT ");

				ch=getch();
			   }while(ch!=27);main();


			}else{
			background(17,63,10,14,2);
			TABLE(17,63,10,14,15,2);
			gotoxy(33,12);textcolor(15);cprintf("ID NOT FOUND");
			}

			}
	kh=getch();
	}while(kh!=27&&ch!=27); main();
}
	void main(){
		  mkdir("c:/log");
		  mkdir("c:/log/users");
		  mkdir("c:/ass");
		  mkdir("c:/ass/fix");
		  mkdir("c:/log/data");
	if(action==0){
	    check();}
	    user u; char ch;
	    textbackground(1);
	    clrscr();
		//loading();
		textbackground(1);
		_setcursortype(0);
		clrscr();
		start();
		do{
		c=getch();
			textbackground(0);
			ARROW_UP();
			start();
			if(a==1&&c==13) menu();
			if(a==2&&c==13) department();
			if(a==3&&c==13) student();
			if(a==4&&c==13) subject();
			if(a==5&&c==13) score();
			if(a==6&&c==13) exit(0);
		   }while(1);  }
void ARROW_UP(){
	if(c==77) a++;
	if(c==75) a--;
}
void ARROW_DOWN(){
	d=getch();
	if(d==80) b++;
	if(d==72) b--;
}
void ARROW_DOWN1(){
	d1=getch();
	if(d1==80) b1++;
	if(d1==72) b1--;
}
void SHOW_ARROW_UP(){
	if(a<=0) a=6;
	if(a>=7) a=1;
    switch(a){
	case 1 :gotoxy(1,1);textbackground(1);textcolor(15);cprintf(" ננ ");break;
	case 2 :gotoxy(7,1);textbackground(1);textcolor(15);cprintf(" DEPARTMENT ");break;
	case 3 :gotoxy(19,1);textbackground(1);textcolor(15);cprintf(" STUDENT ");break;
	case 4 :gotoxy(28,1);textbackground(1);textcolor(15);cprintf(" SUBJECT ");break;
	case 5 :gotoxy(37,1);textbackground(1);textcolor(15);cprintf(" SCORE ");break;
	case 6 :gotoxy(44,1);textbackground(1);textcolor(15);cprintf(" EXIT ");break;
    }
}
void SHOW_ARROW_DOWN(char *c1,char *c2,char *c3,char *c4,int x){
	if(b<=0) b=4;
	if(b>=5) b=1;
    switch(b)
    {
	case 1 : gotoxy(x,3);textbackground(1);textcolor(15);cprintf("%s",c1); break;
	case 2 : gotoxy(x,4);textbackground(1);textcolor(15);cprintf("%s",c2); break;
	case 3 : gotoxy(x,5);textbackground(1);textcolor(15);cprintf("%s",c3); break;
	case 4 : gotoxy(x,7);textbackground(1);textcolor(15);cprintf("%s",c4); break;

    }
}
void SHOW_ARROW_DOWN1(char *c1,char *c2,char *c3,char *c4,int x,int y1,int y2,int y3,int y4){
	if(b1<=0) b1=4;
	if(b1>=5) b1=1;
    switch(b1){
	case 1 : gotoxy(x,y1);textbackground(1);textcolor(15);cprintf("%s",c1); break;
	case 2 : gotoxy(x,y2);textbackground(1);textcolor(15);cprintf("%s",c2); break;
	case 3 : gotoxy(x,y3);textbackground(1);textcolor(15);cprintf("%s",c3); break;
	case 4 : gotoxy(x,y4);textbackground(1);textcolor(15);cprintf("%s",c4); break;
	}
}
void start(){
	user u;
	textbackground(1);
	background(2,79,3,22,0);
	background(1,80,1,1,15);
	TABLE(1,80,2,23,15,1);
	    gotoxy(70,1);
	    textbackground(14);
	    textcolor(14);
	    cprintf("%c         %c",179,179);
		name=fopen(log,"r+b");
	    while(fread(&u,sizeof(user),1,name)==1){
		gotoxy(72,1);textbackground(14);textcolor(14);cprintf("%s",u.name);
	    }fclose(name);
	gotoxy(1,1);textbackground(15);textcolor(0);cprintf(" ננ ");
	gotoxy(7,1);textbackground(15);textcolor(0);cprintf(" DEPARTMENT ");
	gotoxy(19,1);textbackground(15);textcolor(0);cprintf(" STUDENT ");
	gotoxy(28,1);textbackground(15);textcolor(0);cprintf(" SUBJECT ");
	gotoxy(37,1);textbackground(15);textcolor(0);cprintf(" SCORE ");
	gotoxy(44,1);textbackground(15);textcolor(0);cprintf(" EXIT ");
	SHOW_ARROW_UP();
}
	//END FOR USING MAIN PROGRAMS

	/*START SHOW DROP DOWN ;
	char *d1,char *d2,char *d3,char *d4 using for input value char.
	int x,int y1,int y2,int y3,int y4 using for input gotoxy()   */
    void drop(char *d1,char *d2,char *d3,char *d4,int x,int y1,int y2,int y3,int y4){
		background(x-1,x+11,y1-1,y4+1,15);
		TABLE(x-1,x+11,y1-1,y4+1,0,15);
		gotoxy(x,y1);textbackground(15);textcolor(0);cprintf("%s",d1);
		gotoxy(x,y2);textbackground(15);textcolor(0);cprintf("%s",d2);
		gotoxy(x,y3);textbackground(15);textcolor(0);cprintf("%s",d3);
		gotoxy(x,y4);textbackground(15);textcolor(0);cprintf("%s",d4);
	}
    void drop1(char *d1,char *d2,char *d3,char *d4,int x,int y1,int y2,int y3,int y4){
		background(x-1,x+9,y1-1,y4+1,3);
		TABLE(x-1,x+9,y1-1,y4+1,0,3);
		gotoxy(x,y1);textbackground(3);textcolor(0);cprintf("%s",d1);
		gotoxy(x,y2);textbackground(3);textcolor(0);cprintf("%s",d2);
		gotoxy(x,y3);textbackground(3);textcolor(0);cprintf("%s",d3);
		gotoxy(x,y4);textbackground(3);textcolor(0);cprintf("%s",d4);
	}
      void show_drop1(){
		drop1(" INSERT"," EDIT"," VIEW"," DELETE",38,4,5,6,7);
		SHOW_ARROW_DOWN1("  INSERT ","  EDIT   ","  VIEW   ","  DELETE ",38,4,5,6,7);
	}
      void show_drop2(){
		drop1(" INSERT"," EDIT"," VIEW"," SEARCH",47,4,5,6,7);
		SHOW_ARROW_DOWN1("  INSERT ","  EDIT   ","  VIEW   ","  SEARCH ",47,4,5,6,7);
	}

	//START SHOW DROP DOWN


	//start fuction menu
	void year1s(){
		show_drop1();
	do{
		ARROW_DOWN1();
		show_drop1();
		if(b1==1&&d1==13) insert_sub(1);
		if(b1==2&&d1==13) break;
		if(b1==3&&d1==13) show_sub(1);
		if(b1==4&&d1==13) break;
	}while(d1!=27);textbackground(1);start();subject();}
      void year2s(){
		show_drop1();
	do{
		ARROW_DOWN1();
		show_drop1();

		if(b1==1&&d1==13) insert_sub(2);
		if(b1==2&&d1==13) break;
		if(b1==3&&d1==13) show_sub(2);
		if(b1==4&&d1==13) break;
	}while(d1!=27);textbackground(1);start();subject();}
      void year3s(){
		show_drop1();
	do{
		ARROW_DOWN1();
		show_drop1();

		if(b1==1&&d1==13) insert_sub(3);
		if(b1==2&&d1==13) break;
		if(b1==3&&d1==13) show_sub(3);
		if(b1==4&&d1==13) break;
	}while(d1!=27);textbackground(1);start();subject();}

      void year4s(){
	            show_drop1();
	do{
		ARROW_DOWN1();
		show_drop1();
		if(b1==1&&d1==13) insert_sub(4);
		if(b1==2&&d1==13) break;
		if(b1==3&&d1==13) show_sub(4);
		if(b1==4&&d1==13) break;
	}while(d1!=27);textbackground(1);start();subject();}

	//start fuction menu
      void year1(){
		show_drop2();
	do{
		ARROW_DOWN1();
		show_drop2();
		if(b1==1&&d1==13) sco();
		if(b1==2&&d1==13) break;
		if(b1==3&&d1==13) break;
		if(b1==4&&d1==13) break;
	}while(d1!=27);textbackground(1);start();score();}

      void year2(){
		show_drop2();
	do{
		ARROW_DOWN1();
		show_drop2();
		if(b1==1&&d1==13) break;
		if(b1==2&&d1==13) break;
		if(b1==3&&d1==13) break;
		if(b1==4&&d1==13) break;
	}while(d1!=27);textbackground(1);start();score();}
      void year3(){
		show_drop2();
	do{
		ARROW_DOWN1();
		show_drop2();
		if(b1==1&&d1==13) break;
		if(b1==2&&d1==13) break;
		if(b1==3&&d1==13) break;
		if(b1==4&&d1==13) break;
	}while(d1!=27);textbackground(1);start();score();}


      void year4(){
		show_drop2();
	do{
		ARROW_DOWN1();
		show_drop2();
		if(b1==1&&d1==13) break;
		if(b1==2&&d1==13) break;
		if(b1==3&&d1==13) break;
		if(b1==4&&d1==13) break;
	}while(d1!=27);textbackground(1);start();score();}





	void menu(){
	drop(" REGISTER"," SEARCH"," SETTING"," ABOUT ",2,3,4,5,7);
	SHOW_ARROW_DOWN("  REGISTER ","  SEARCH   ","  SETTING  ","  ABOUT    ",2);
	do{
	ARROW_DOWN();

	drop(" REGISTER"," SEARCH"," SETTING"," ABOUT ",2,3,4,5,7);
	SHOW_ARROW_DOWN("  REGISTER ","  SEARCH   ","  SETTING  ","  ABOUT    ",2);
	if(b==1&&d==13) {reg_user();menu();}
	if(b==2&&d==13) {search();menu();}
	if(b==3&&d==13) break;
	if(b==4&&d==13) {about();menu();}


	}while(d!=27);textbackground(1);start();}
    void department(){
	drop(" INSERT"," VIEW"," EDIT"," DELETE",8,3,4,5,7);
	SHOW_ARROW_DOWN("  INSERT   ","  VIEW     ","  EDIT     ","  DELETE   ",8);
	do{
		ARROW_DOWN();
		drop(" INSERT"," VIEW"," EDIT"," DELETE",8,3,4,5,7);
		SHOW_ARROW_DOWN("  INSERT   ","  VIEW     ","  EDIT     ","  DELETE   ",8);
		if(b==1&&d==13) in_depart();
		if(b==2&&d==13) out_depart();
		if(b==3&&d==13) break;
		if(b==4&&d==13) del_depart();
	}while(d!=27);textbackground(1);start();}

	void student(){
	int leng[8];



		char ch,st;int i,j,n=0;


	drop(" INSERT"," VIEW"," EDIT"," DELETE",20,3,4,5,7);
	SHOW_ARROW_DOWN("  INSERT   ","  VIEW     ","  EDIT     ","  DELETE   ",20);
	do{
	ARROW_DOWN();
	drop(" INSERT"," VIEW"," EDIT"," DELETE",20,3,4,5,7);
	SHOW_ARROW_DOWN("  INSERT   ","  VIEW     ","  EDIT     ","  DELETE   ",20);
	if(b==1&&d==13){
	//start input code
		do{

			background(2,79,3,22,3);
			TABLE(2,79,3,22,0,15);
			textcolor(15);
			gotoxy(26,2);
			printf(" INSERT INFORMATION STUDENT");
			background(18,38,8,8,1);
			background(18,38,11,11,1);
			background(18,38,14,14,1);
			background(40,44,17,17,1);
			background(50,70,8,8,1);
			background(50,54,11,11,1);
			background(56,60,11,11,1);
			background(62,68,11,11,1);
			background(50,70,14,14,1);
			gotoxy(7,8);printf("ID");
			gotoxy(42,8);printf("NAME");
			gotoxy(7,11);printf("SEX");
			gotoxy(42,11);printf("BIRTH");
			gotoxy(51,11);printf("DD    MM    YYYY");
			gotoxy(7,14);printf("DEPARTMENT");
			gotoxy(42,14);printf("CLASS");
			gotoxy(34,17);printf("YEAR");
		     id:     long com;
			char num[20]="";
			_setcursortype(2);
			gotoxy(19,8);
			input2(num,20);

			fp=fopen(local,"rb");
			while(fread(&p,sizeof(stu),1,fp)==1){

			if(strcmp(num,p.id)==0){
				gotoxy(30,21);
				printf("ID HAS BEEN ALREADY");
				clear(18,37,8,8);goto id;
				}

			}
			fclose(fp);
			fp=fopen(local,"a+b");
			_setcursortype(2);
			clear(30,65,21,21);
			leng[0]=strlen(num);
			if(leng[0]!=4){
				gotoxy(30,21);
				printf("YOU CAN INPUT ONLY 4 DIGIT");
				clear(18,37,8,8);
				goto id;
			}
			else
				strcpy(p.id,num);

	     name:      char nam[20]="";
				gotoxy(51,8);
				input2(nam,18);
				clear(30,65,21,21);
				leng[1]=strlen(nam);
			if(leng[1]<4){
				gotoxy(30,21);
				printf("YOUR NAME IS INCORRECT");
				clear(51,70,8,8);
				goto name;
			}else strcpy(p.name,nam);
	     sex   :
			char se[20]="";
				gotoxy(19,11);
				input2(se,20);
			if(strcmp(se,"male")==0||strcmp(se,"MALE")==0||strcmp(se,"female")==0||strcmp(se,"FEMALE")==0){
				clear(18,62,20,20);
				strcpy(p.sex,se);
			}else{
				gotoxy(18,20);
				printf("YOUR INPUT IS INCORRECT");
				clear(18,38,11,11);
				goto sex;
			}

	     day:
			char da[20]="";
				gotoxy(51,11);
				input(da,3);
				leng[3]=strlen(da);

			if(atoi(da)>31||atoi(da)<1||leng[3]!=2){
				clear(51,53,11,11);
				goto day;
			}else strcpy(p.ngai,da);
				int months;
	     month:
			char mon[20]="";
			gotoxy(57,11);
			input(mon,3);
			leng[4]=strlen(mon);
			if(atoi(mon)>12||atoi(mon)<1||leng[4]!=2){
			clear(57,59,11,11);
			goto month;
			}
			else strcpy(p.khae,mon);
	     year:      char ye[20]="";
				gotoxy(63,11);
				input(ye,5);
			if(atoi(ye)<1950){
				clear(63,67,11,11);
				goto year;
			}else strcpy(p.jnam,ye);
			char sub[20]="";
				gotoxy(19,14);
				input2(sub,16);

				strcpy(p.subjects,sub);
			char roo[20]="";
				gotoxy(51,14);
				input2(roo,4);
				strcpy(p.room,roo);
		     yer:	char yer[20]="";
				gotoxy(41,17);
				input2(yer,2);
				if(atoi(yer)<1||atoi(yer)>4){
					gotoxy(18,20);
				printf("WRONG YEAR! EX : 1,2,3 OR 4");
				clear(40,44,17,17);
				goto yer;
				}
				else {
				strcpy(p.year,yer);
				clear(18,45,20,20);
				}

			_setcursortype(0);
			background(17,63,10,14,2);
			TABLE(17,63,10,14,15,2);
			gotoxy(19,12);textcolor(15);cprintf(" PRESS ANYKEY FOR CONTINUE OR ESC FOR EXIT ");
			ch=getch();
			textcolor(15);
			textbackground(1);
		       fseek(fp,0,SEEK_END);
		       fwrite(&p,sizeof(stu),1,fp); fclose(fp);

		}while(ch!=27);
		clrscr();
		start();
		student();
				 }
	   //end iput code
	if(b==2&&d==13){
		fp=fopen(local,"r+b");
		    char th;
		//start show

		int size;
		fseek(fp,0,SEEK_END); size=sizeof(stu);
		n=ftell(fp)/size;
		if(n>0){
		ch=80; i=0;
		textbackground(1);
		clrscr();
		start();
		background(2,79,5,22,3);
		TABLE(2,79,3,5,0,15);
		background(2,79,4,4,2);
		//background(2,79,3,3,15);
		TABLE(2,9,3,22,0,15);
		TABLE(9,26,3,22,0,15);
		TABLE(26,35,3,22,0,15);
		TABLE(35,48,3,22,0,15);
		TABLE(48,63,3,22,0,15);
		TABLE(63,71,3,22,0,15);
		TABLE(71,79,3,22,0,15);
		TABLE(2,79,3,22,0,15);


		clear(3,8,6,21);
		clear(11,25,6,21);
		clear(27,34,6,21);
		clear(36,47,6,21);
		clear(49,62,6,21);
		clear(64,70,6,21);
		clear(72,78,6,21);
		gotoxy(33,2);printf(" STUDENT REPORT ");
		gotoxy(5,4); printf("ID");
		gotoxy(16,4);printf("NAME");
		gotoxy(29,4);printf("SEX");
		gotoxy(39,4);printf("BIRTH");
		gotoxy(51,4);printf("DEPARTMENT");
		gotoxy(65,4);printf("CLASS");
		gotoxy(73,4);printf("YEAR");


		int Y=6;
		rewind(fp);
		while(fread(&p,size,1,fp)==1){
		gotoxy(4,Y+i); printf("%s\n",p.id);
		gotoxy(10,Y+i);printf("%s\n",p.name);
		gotoxy(28,Y+i);printf("%s\n",p.sex);
		gotoxy(37,Y+i);printf("%s\n",p.ngai);
		gotoxy(39,Y+i);printf("/%s\n",p.khae);
		gotoxy(42,Y+i);printf("/%s\n",p.jnam);
		gotoxy(49,Y+i);printf("%s\n",p.subjects);
		gotoxy(66,Y+i);printf("%s\n",p.room);
		gotoxy(73,Y+i);printf("%s\n",p.year);
		i++;
		    }

		   // gotoxy(11,24);printf("[F2]=DELETE  [ESC]=BACK  [F1]=SORT  [DEL]=DELETE  [F3]=SEARCH");

		 }else{
		 clrscr();
		 start();
		textcolor(15);
		textbackground(1);
		background(2,79,5,22,3);
		background(2,79,4,4,2);
		TABLE(2,79,3,22,0,15);

		gotoxy(35,13);printf("DATA EMPTY");
		gotoxy(33,2);printf(" STUDENT REPORT ");
		gotoxy(5,4); printf("ID");
		gotoxy(16,4);printf("NAME");
		gotoxy(29,4);printf("SEX");
		gotoxy(39,4);printf("DOB");
		gotoxy(52,4);printf("DEPARTMENT");
		gotoxy(65,4);printf("CLASS");
		gotoxy(73,4);printf("YEAR");

		 }
		fclose(fp);getch();
		textbackground(1);clrscr();start();student();
 }
		 //end show
	if(b==4&&d==13) {
	del();
	textbackground(1);clrscr();start();student();
	}

	if(b==3&&d==13){
	//start Edit
	do{
	clrscr();start();
	clear(2,79,3,22);
	background(2,79,3,22,3);
	TABLE(2,79,3,22,0,15);
	_setcursortype(2);
	gotoxy(19,5);
	textcolor(15);
	textbackground(3);
	cprintf(" ENTER ID TO EDIT ");
	background(38,58,5,5,15);
	gotoxy(39,5);
	char x[20]="";
	input(x,5);
	_setcursortype(0);
		b=0;
		fp=fopen(local,"rb");
		rewind(fp);
		fp1=fopen(localcpy,"wb");
		while(fread(&p,sizeof(stu),1,fp)==1){

		    if(strcmp(p.id,x)==0){
		    textbackground(1);
			_setcursortype(0);
			textcolor(15);
			gotoxy(30,2);
			printf(" INPUT NEW REPORT ");
			background(8,25,6,19,15);
			TABLE(8,25,7,19,0,15);
			gotoxy(8,6);
			textcolor(15);
			textbackground(1);
			cprintf("  OPTION TO EDIT  ");
			gotoxy(9,8);textcolor(0);textbackground(15);cprintf("      NAME      ");
			gotoxy(9,10);textcolor(0);textbackground(15);cprintf("      SEX       ");
			gotoxy(9,12);textcolor(0);textbackground(15);cprintf("     D-O-B      ");
			gotoxy(9,14);textcolor(0);textbackground(15);cprintf("    SUBJECT     ");
			gotoxy(9,16);textcolor(0);textbackground(15);cprintf("     CLASS      ");
			gotoxy(9,18);textcolor(0);textbackground(15);cprintf("     YEAR       ");Show_Edit();

		    do{
			 gotoxy(40,8);printf("NEW NAME");background(53,73,8,8,15);
			 gotoxy(54,8);printf("%s",p.name);
			 gotoxy(40,10);printf("NEW SEX");background(53,73,10,10,15);
			 gotoxy(54,10);printf("%s",p.sex);
			 gotoxy(40,12);printf("NEW D-O-B");background(53,56,12,12,15);
			 gotoxy(54,12);printf("%s",p.ngai);background(58,61,12,12,15);
			 gotoxy(59,12);printf("%s",p.khae);background(63,68,12,12,15);
			 gotoxy(64,12);printf("%s",p.jnam);
			 gotoxy(37,14);printf("NEW DEPARTMENT");background(53,73,14,14,15);
			 gotoxy(54,14);printf("%s",p.subjects);
			 gotoxy(40,16);printf("NEW CLASS");background(53,73,16,16,15);
			 gotoxy(54,16);printf("%s",p.room);
			 gotoxy(40,18);printf("NEW GRADE");background(53,73,18,18,15);
			 gotoxy(54,18);printf("%s",p.year);
			k=getch();
			if(k==80) l++;
			if(k==72) l--;

			gotoxy(9,8);textcolor(0);textbackground(15);cprintf("      NAME      ");
			gotoxy(9,10);textcolor(0);textbackground(15);cprintf("      SEX       ");
			gotoxy(9,12);textcolor(0);textbackground(15);cprintf("     D-O-B      ");
			gotoxy(9,14);textcolor(0);textbackground(15);cprintf("    SUBJECT     ");
			gotoxy(9,16);textcolor(0);textbackground(15);cprintf("     CLASS      ");
			gotoxy(9,18);textcolor(0);textbackground(15);cprintf("     YEAR       ");
			Show_Edit();
			 if(l==1&&k==13){
			 clear(54,74,8,8);
			_setcursortype(2);
			 na:	char nam[20]="";
				gotoxy(54,8);
				input2(nam,19);
				clear(30,65,21,21);
				leng[1]=strlen(nam);
			if(leng[1]<4){
				gotoxy(30,21);
				printf("YOUR NAME IS INCORRECT");
				clear(51,70,8,8);
				goto na;

			}else {
				strcpy(p.name,nam);
				_setcursortype(0);
				actio();
				}
			 }
			 if(l==2&&k==13){
			 clear(54,74,10,10);
			 _setcursortype(2);
			 sexs:	char se[20]="";
				gotoxy(54,10);
				input2(se,20);
			if(strcmp(se,"male")==0||strcmp(se,"MALE")==0||strcmp(se,"female")==0||strcmp(se,"FEMALE")==0){
				clear(18,62,20,20);
				strcpy(p.sex,se);
				_setcursortype(0);
				actio();

			}else{
				gotoxy(18,20);
				printf("YOUR INPUT IS INCORRECT");
				clear(18,38,11,11);
				goto sexs;
			}

			 }
			 if(l==3&&k==13){
			 clear(54,74,12,12);
			 _setcursortype(2);
		days:
			char da[20]="";
				gotoxy(54,12);
				input(da,3);
			if(atoi(da)>31||atoi(da)<1){
				clear(51,53,11,11);
				goto days;
			}else strcpy(p.ngai,da);
				int months;
	     months:
			char mon[20]="";
			gotoxy(59,12);
			input(mon,3);
			if(atoi(mon)>12||atoi(mon)<1){
			clear(57,59,11,11);
			goto months;
			}
			else strcpy(p.khae,mon);
	     years:
			char ye[20]="";
				gotoxy(64,12);
				input(ye,5);
			if(atoi(ye)<1950){
				clear(63,67,11,11);
				goto years;
			}else {strcpy(p.jnam,ye);
			_setcursortype(0);actio();}
			 }
			 if(l==4&&k==13){
			 clear(54,74,14,14);
			 _setcursortype(2);
			     char sub[20]="";
				gotoxy(54,14);
				input2(sub,16);
				strcpy(p.subjects,sub);
			 _setcursortype(0);actio();}
			 if(l==5&&k==13){
			  clear(54,74,16,16);
			  _setcursortype(2);
			 char roo[20]="";
				gotoxy(54,16);
				input2(roo,8);
				strcpy(p.room,roo);

			 _setcursortype(0);actio(); }
			 if(l==6&&k==13){
			  clear(54,74,18,18);
			  _setcursortype(2);
			 char yer[20]="";
				gotoxy(54,18);
				input2(yer,8);
				strcpy(p.year,yer);

			 _setcursortype(0);actio();}

			}while(k!=27);

			_setcursortype(0);
			b=1;
		    }
		    fwrite(&p,sizeof(stu),1,fp1);

		}
		fclose(fp1);fclose(fp); remove(local);
		rename(localcpy,local);
		if(b==0) {
		textbackground(1);
		background(17,63,10,14,2);
		TABLE(17,63,10,14,15,2);
		gotoxy(32,12);
		printf(" ID NOT FOUND ");
		delay(1300);break;
		}
		else{
		textbackground(1);
		background(17,63,10,14,2);
		TABLE(17,63,10,14,15,2);
		gotoxy(33,12);textcolor(15);cprintf("EDIT COMPLETE");
		delay(1300);break;}
		}while(1);textbackground(1);clrscr();start();drop(" INSERT"," VIEW"," EDIT"," DELETE",7,3,4,5,7);
		SHOW_ARROW_DOWN("  INSERT   ","  VIEW     ","  EDIT     ","  DELETE   ",7);

		}

	}while(d!=27);start();}

	//end fuction menu


	//start function SUBJECT
	void subject(){


		char ch;
	  drop(" YEAR1"," YEAR2"," YEAR3"," YEAR4",29,3,4,5,7);
		SHOW_ARROW_DOWN("  YEAR1    ","  YEAR2    ","  YEAR3    ","  YEAR4    ",29);
	  do{
		ARROW_DOWN();
		drop(" YEAR1"," YEAR2"," YEAR3"," YEAR4",29,3,4,5,7);
		SHOW_ARROW_DOWN("  YEAR1    ","  YEAR2    ","  YEAR3    ","  YEAR4    ",29);
			if(b==1&&d==13) year1s();
			if(b==2&&d==13) year2s();
			if(b==3&&d==13) year3s();
			if(b==4&&d==13) year4s();
	}while(d!=27);textbackground(1);start(); }
	  void score(){
		drop(" YEAR1"," YEAR2"," YEAR3"," YEAR4",38,3,4,5,7);
		SHOW_ARROW_DOWN("  YEAR1    ","  YEAR2    ","  YEAR3    ","  YEAR4    ",38);
	  do{
		ARROW_DOWN();
		drop(" YEAR1"," YEAR2"," YEAR3"," YEAR4",38,3,4,5,7);
		SHOW_ARROW_DOWN("  YEAR1    ","  YEAR2    ","  YEAR3    ","  YEAR4    ",38);
			if(b==1&&d==13) year1();
			if(b==2&&d==13) year2();
			if(b==3&&d==13) year3();
			if(b==4&&d==13) year4();
	}while(d!=27);textbackground(1);start();}
	//end function SUBJECT

 void about(){

	  textbackground(1);clrscr();start();
	  background(2,79,3,22,3);
	  background(10,70,8,17,3);
	  background(10,70,7,7,15);
	  background(10,70,18,18,15);
	  TABLE(10,70,8,17,15,1);
	  TABLE(2,79,3,22,0,3);
 do{
	  gotoxy(30,7);textcolor(15);cprintf("INFORMATION ABOUT US");
	  gotoxy(14,11);textcolor(1);cprintf("SYSTEM MANAGERMENT STUDENT");
	  gotoxy(12,13);textcolor(1);cprintf("CREATE BY IT STUDENT GROUP");
	  gotoxy(14,15);textcolor(1);cprintf("FOR ASSIGNMENT IN SEMESTER2");
	  gotoxy(46,9);textcolor(1);cprintf(" MEMBER DEVELOPER ");
	  gotoxy(47,10);textcolor(1);cprintf("1_MY SEY");
	  gotoxy(47,11);textcolor(1);cprintf("2_MEY KOSAL");
	  gotoxy(47,12);textcolor(1);cprintf("3_DUM NARIN");
	  gotoxy(47,13);textcolor(1);cprintf("4_CHY PANHA");
	  gotoxy(47,14);textcolor(1);cprintf("5_BAN SOTHEN");
	  gotoxy(47,15);textcolor(1);cprintf("6_MET TOUMINH");
	  gotoxy(47,16);textcolor(1);cprintf("7_PHOUEY PANHARITH");
	  gotoxy(13,18);textbackground(15);textcolor(15);cprintf(" OFFICIAL WEBSITE: WWW.IT-RUPP.ME %c COPYRIGHT (C) 2017 ",179);
	  ch=getch();
 }while(ch!=27);textbackground(1);clrscr();start();
 }
	//end function SUBJECT
	void loading(){
	clrscr();
	int i,k,j,gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	for(i=0;i<180;i++){ setcolor(15);
	for(j=0;j<10;j++)
	arc(300,200,0,i,100+j);
	delay(1);
	gotoxy(34,13);
	printf("LOADING...");
	}
	for(i=180;i<360;i++){ setcolor(14);
	for(j=0;j<10;j++)
	arc(300,200,0,i,100+j);

	delay(1);
	}
	closegraph();
	clrscr();
	gotoxy(35,12);
	textcolor(14+BLINK);
	cprintf("PRESS ANY KEY...");
	}

void TABLE(int a1,int a2,int b1,int b2,int color,int color2){
	int i;
		textbackground(color2);
		textcolor(color);
	for(i=a1+1;i<a2;i++){
		gotoxy(i,b1); cprintf("%c",196);
		gotoxy(i,b2); cprintf("%c",196);
	}
	for(i=b1+1;i<b2;i++){
		gotoxy(a1,i); cprintf("%c",179);
		gotoxy(a2,i); cprintf("%c",179);
	}
gotoxy(a1,b1); cprintf("%c",218);
gotoxy(a2,b1); cprintf("%c",191);
gotoxy(a1,b2); cprintf("%c",192);
gotoxy(a2,b2); cprintf("%c",217);
}
void background(int a1,int a2,int b1,int b2,int color){
    int i,j;
    textbackground(color);
    for(i=a1;i<=a2;i++)
	for(j=b1;j<=b2;j++){
		gotoxy(i,j); cprintf(" ");
	}
    textbackground(0);
}
void clear(int a1,int a2,int b1,int b2){
    int i,j;
    for(i=a1;i<=a2;i++)
	for(j=b1;j<=b2;j++){
	    gotoxy(i,j); printf(" ");
	}
}

void insert_sub(int year){
		int cp;
		FILE *fsub;

		FILE *fdep;
do{
		textbackground(1);clrscr();start();
		background(2,79,3,22,3);
		TABLE(2,79,3,22,0,15);
		textcolor(15);gotoxy(30,2);printf(" INSERT SUBJECT ");
		background(7,42,9,15,15);
		background(20,40,11,11,1);
		background(20,40,13,13,1);
		TABLE(7,42,9,15,15,15);
		gotoxy(9,11);printf("DEPARTMENT ");
		gotoxy(9,13);printf("SUBJECT ");
		nd:
		_setcursortype(2);
		char id[20]="";gotoxy(21,11);input2(id,20);
		cp=0;
		fdep=fopen(localde,"r+b");
		rewind(fdep);
		while(fread(&de,sizeof(depart),1,fdep)==1){
if(strcmp(id,de.name)==0)cp=1;
}
if(cp==1){	if(year==1) fsub=fopen(localy1,"a+b");
		if(year==2) fsub=fopen(localy2,"a+b");
		if(year==3) fsub=fopen(localy3,"a+b");
		if(year==4) fsub=fopen(localy4,"a+b");




	background(55,74,6,6,15);
	background(55,74,7,19,1);
	TABLE(55,74,7,19,15,15);
	gotoxy(61,6);textbackground(15);
	textcolor(1);cprintf("SUBJECTS");
		int x=57;
		char title1[20]="";
		gotoxy(21,13);input2(title1,20);clear(20,40,13,13);
		gotoxy(x,9);printf(" 1_ %s",title1);
		char title2[20]="";
		gotoxy(21,13);input2(title2,20);clear(20,40,13,13);
		gotoxy(x,10);printf(" 2_ %s",title2);
		char title3[20]="";
		gotoxy(21,13);input2(title3,20);clear(20,40,13,13);
		gotoxy(x,11);printf(" 3_ %s",title3);
		char title4[20]="";
		gotoxy(21,13);input2(title4,20);clear(20,40,13,13);
		gotoxy(x,12);printf(" 4_ %s",title4);
		char title5[20]="";
		gotoxy(21,13);input2(title5,20);clear(20,40,13,13);
		gotoxy(x,13);printf(" 5_ %s",title5);
		char title6[20]="";
		gotoxy(21,13);input2(title6,20);clear(20,40,13,13);
		gotoxy(x,14);printf(" 6_ %s",title6);
		char title7[20]="";
		gotoxy(21,13);input2(title7,20);clear(20,40,13,13);
		gotoxy(x,15);printf(" 7_ %s",title7);
		char title8[20]="";gotoxy(21,13);input2(title8,20);
	strcpy(s.depa,id);
	strcpy(s.title1,title1);
	strcpy(s.title2,title2);
	strcpy(s.title3,title3);
	strcpy(s.title4,title4);
	strcpy(s.title5,title5);
	strcpy(s.title6,title6);
	strcpy(s.title7,title7);
	strcpy(s.title8,title8);clear(20,40,13,13);gotoxy(x,16);printf(" 8_ %s",title8);
		_setcursortype(0);
	fwrite(&s,sizeof(sub),1,fsub);
	background(17,63,10,14,2);
	TABLE(17,63,10,14,15,2);
	gotoxy(21,12);textcolor(15);cprintf("SUBJECT HAS BEEN SAVED SUCCESSFULLY");
}if(cp!=1){
	clear(20,40,11,11);
	gotoxy(30,21);printf("DEPARTMENT NOT MATCH!!");goto nd;
	}
	 ch=getch();fclose(fsub);fclose(fdep);
}while(ch!=27);main();
}
void show_sub(int year){
		FILE *fsub;
		if(year==1) fsub=fopen(localy1,"r+b");
		if(year==2) fsub=fopen(localy2,"r+b");
		if(year==3) fsub=fopen(localy3,"r+b");
		if(year==4) fsub=fopen(localy4,"r+b");
		int y=6,i=0,s_record,kn;
		s_record=sizeof(sub);

	fseek(fsub,0,SEEK_END);
	kn=ftell(fsub)/s_record;
		textbackground(1);clrscr();start();
		background(2,79,3,22,3);
		background(3,42,10,14,15);
		background(21,41,12,12,1);
		TABLE(2,79,3,22,0,15);
		TABLE(3,42,10,14,15,15);
		textcolor(15);gotoxy(4,12);printf("ENTER DEPARTMENT");
		textcolor(15);gotoxy(30,2);printf(" REPORT SUBJECT ");
		char v_sub[20]="";
		_setcursortype(2);
		gotoxy(22,12);input2(v_sub,20);
		b=0;
		_setcursortype(0);
		rewind(fsub);
		for(i=1;i<=kn;i++){
		fread(&s,s_record,1,fsub);
		 if(strcmp(s.depa,v_sub)==0)b=1;

		if(b==1){
			gotoxy(45,9); printf(" 1_ %s",s.title1);
			gotoxy(45,10);printf(" 2_ %s",s.title2);
			gotoxy(45,11);printf(" 3_ %s",s.title3);
			gotoxy(45,12);printf(" 4_ %s",s.title4);
			gotoxy(45,13);printf(" 5_ %s",s.title5);
			gotoxy(45,14);printf(" 6_ %s",s.title6);
			gotoxy(45,15);printf(" 7_ %s",s.title7);
			gotoxy(45,16);printf(" 8_ %s",s.title8);
		}
		 }fclose(fsub);
	if(b!=1) {
	     textbackground(1);clrscr();start();
	     background(2,79,3,22,3);
	     TABLE(2,79,3,22,0,15);
	     textcolor(15);gotoxy(30,2);printf(" REPORT SUBJECT ");
	     textcolor(15);gotoxy(33,12);printf(" DATA EMPTY ");
	}getch();main();
}
