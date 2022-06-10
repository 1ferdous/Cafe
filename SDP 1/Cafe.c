//-----------------Declaring header files------------------------


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<time.h>


//---------------STRUCTURE: Creating new data type---------------


//users information
typedef struct registrationlist {
	unsigned long int serial_num;
	char id[13];
	char pass[30];
	char uname[30];
	char mail[30];
	char phone[12];
	int status;
} regls;

//foods information
typedef struct foodlist {
	int serial;
	int price;
	int quantity;
	int available;
	char fname[100];
	char type[40];
} foody;


//------------Declaring User defined function segment------------


// string returning functions......
char* fetchtime();

// int value returning fuction......
int Admin();
int gpuUSER(char id[]);
int gpuFOOD_ITEM(char id[]);
int reg_progress(char id[]);
int reg_available(char id[]);
int adminLOGin(char username[],char pass[]);
int login(char id[],char pass[]);


// all void functions...........
void clear();
void Color(int ForgC);
void gpuBUBT();
void gpuHoption();
void exeHOME();
void gpuType(char ch[],int speed);
void gpuLOGin();
void gpuIDSEARCH();
void gpuNotice();
void noticeRead();
void contact();
void aboutUS();
void gpuDev();
void devnames();
void gpuExit();
void Endexe();
void gpuTEXT();
void search_user(char id[]);
void gpuORDERHISTORY(char id[]);
void reportPROBLEM(char id[]);
void readREPORT();
void setting();


//------------------Defining CONSTANT variables------------------


#define vanish 0
#define red 20
#define cyan 11
#define green 26
#define orange 28
#define blue 1
#define purple 29
#define yellow 22
#define ash 24
#define silver 7
#define white 15


//------------------------Main Function--------------------------

int main()

{
	//this command will set the console resulation size.....
	//to use this please uncomment.......
	//system("mode con:cols=160 lines=3000");

	int counter=0;
	char xyz[100];
	regls ls_1[10000];
	int option_home=0;
position_1:

	counter++;

	exeHOME();
	scanf("%d",&option_home);


	if(option_home==1) {
		int a=Admin();
		if(a=5) {
			clear();
			goto position_1;
		}
	} else if(option_home==2) {
		clear();
		gpuBUBT();
		int attempt=0;
		char id[20],pass[30];
login:
		Color(white);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		gpuLOGin();
		Color(green);
		gpuType("\n\t\t\t\t\tEnter your ID number:",1);
		scanf("%s",&id);
		gpuType("\n\n\t\t\t\t\tEnter your password:",1);
		Color(vanish);
		scanf("%s",&pass);
		Color(green);
		if(attempt>=3) {
			gpuType("\n\t\t\t\t\tToo many attempts.You are restricted for 15 seconds!!!",1);
			Sleep(15000);
			attempt=1;
			clear();
			goto login;
		}

		if(login(id,pass)==1) {
			clear();
			int jus=0;
gu:
			jus=gpuUSER(id);
			if(jus==1) {

				int x=gpuFOOD_ITEM(id);
				goto gu;

			} else if(jus==2) {
				gpuORDERHISTORY(id);
				goto gu;
			} else if(jus==3) {
				reportPROBLEM(id);
				clear();
				goto gu;
			}

			else if(jus==4) {
				clear();
				int ax=0;
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n   \t\t\t\t\t\t           Are you sure to log out?\n\n\n\t\t\t\t\t\t\t1.Yes\t\t\t2.No\n\t\t\t\t\t\t\t");

				scanf("%d",&ax);
				Color(white);
				if(ax==1) {
					clear();
					goto position_1;
				} else {
					clear();
					goto gu;
				}
			} else {
				goto gu;
			}
		} else if(login(id,pass)==0) {
			gpuType("\n\t\t\t\t\tInvalid User ID/Password!!!",40);
			clear();
			attempt++;
			goto login;
		} else if(reg_progress(id)==1) {
			gpuType("\n\t\t\t\t\tThis IDs' Registration is in progress!!!",1);
			Sleep(2000);
			goto position_1;
		}
	} else if(option_home==3) {
		clear();
pass:
		gpuBUBT();
		Color(white);
		printf("\t\t\t\t\tEnter your student/employee ID no:");
		scanf("%s",&ls_1[1].id);



		if(reg_available(ls_1[1].id)==0) {
			gpuType("ID already registered!!!",1);
			Sleep(2000);
			goto position_1;
		}

		printf("\n\t\t\t\t\tEnter a password for your account:");
		Color(vanish);
		scanf("%s",&ls_1[1].pass);
		Color(white);
		printf("\n\t\t\t\t\tRetype your password:");
		Color(vanish);
		scanf("%s",&ls_1[9000].pass);
		Color(white);

		if(strcmp(ls_1[1].pass,ls_1[9000].pass)==0) {
			printf("\n\t\t\t\t\tEnter your user name:");
			getchar();
			fgets(xyz,100,stdin);
			int len=strlen(xyz);
			char newe[100];
			for(int i=0; i<=len; i++) {
				if((xyz[i]>=97&&xyz[i]<=122)||(xyz[i]>=65&&xyz[i]<=90)) {
					newe[i]=xyz[i];
				} else if(xyz[i]==32) {
					newe[i]='_';
				} else {
					break;
				}
			}
			strcpy(ls_1[1].uname,newe);
			printf("\n\t\t\t\t\tEnter your mail address:");
			scanf("%s",&ls_1[1].mail);
			printf("\n\t\t\t\t\tEnter your phone number:");
			scanf("%s",ls_1[1].phone);
			Color(green);
			clear();
			gpuBUBT();
			gpuType("\n\n\n\n\t\t\t\t\tMake sure that given information are correct:",1);
			printf("\n\n\t\t\t\t\tID:%s   \n\t\t\t\t\tPASS:%s   \n\t\t\t\t\tUserNAME:%s   \n\t\t\t\t\tMAIL:%s   \n\t\t\t\t\tPHONE:%s",ls_1[1].id,ls_1[1].pass,ls_1[1].uname,ls_1[1].mail,ls_1[1].phone);
			int regopt;
			getchar();
			printf("\n\n\t\t\t\t\t1.Proceed registration request\n\t\t\t\t\t2.Try again\n\t\t\t\t\tSelect:");
			scanf("%d",&regopt);
			if(regopt==1) {
				FILE *fpreg=fopen("registration_list.txt","a");
				fprintf(fpreg,"\n%s %s %s %s %s %d",ls_1[1].id,ls_1[1].uname,ls_1[1].pass,ls_1[1].mail,ls_1[1].phone,0);
				fclose(fpreg);
				gpuType("\t\t\t\t\tRegistration successful",80);
				clear();
				goto position_1;
			} else {
				clear();
				goto pass;
			}
		} else {
			clear();
			gpuType("\t\t\t\t\tPassword was not matched... Please try again!\n\n\n",30);
			goto pass;
		}
	} else if(option_home==4) {
		clear();
		gpuNotice();
		Color(white);
		noticeRead();
		getch();
		clear();
		goto position_1;
	} else if(option_home==5) {
		contact();
		goto position_1;
	} else if(option_home==6) {
		setting();
		clear();
		goto position_1;
	} else if(option_home==7) {
		clear();
		gpuBUBT();
		aboutUS();
	} else if(option_home==8) {
		clear();
		gpuDev();
		devnames();
		getch();
		clear();
		goto position_1;
	} else if(option_home==9) {

		option_home=0;
		gpuExit();
		scanf("%d",&option_home);
		if(option_home==1) {
			Endexe();
		} else if(option_home==2) {
			clear();
			goto position_1;
		}
	} else {
		system("cls");
		goto position_1;
	}

	return 0;

}



char* fetchtime() {
	time_t current_time;
	char* c_time_string;

	/* Obtain current time. */
	current_time = time(NULL);

	if (current_time == ((time_t)-1)) {
		(void) fprintf(stderr, "Failure to obtain the current time.\n");
		exit(EXIT_FAILURE);
	}

	/* Convert to local time format. */
	c_time_string = ctime(&current_time);

	if (c_time_string == NULL) {
		(void) fprintf(stderr, "Failure to convert the current time.\n");
		exit(EXIT_FAILURE);
	}
	return c_time_string;
}


int Admin() {
retry:
	clear();
	gpuBUBT();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	Color(green);
	gpuLOGin();
	char username[50],pass[55];

	printf("\n\t\t\t\t\tEnter user name:");
	scanf("%s",username);
	printf("\n\t\t\t\t\tEnter password:");
	scanf("%s",pass);
	int varify=adminLOGin(username,pass);
	if(varify==1) {
ff:
		clear();
		gpuBUBT();
		Color(silver);
		printf("\n\t\t\t\t\t1.Order request");
		printf("\n\t\t\t\t\t2.Registration request");
		printf("\n\t\t\t\t\t3.Search ID");
		printf("\n\t\t\t\t\t4.Publish notice");
		printf("\n\t\t\t\t\t5.Publish about BUBT Cafe Management System");
		printf("\n\t\t\t\t\t6.Report Box");
		printf("\n\t\t\t\t\t7.LogOUT");
		int FF=0;
		Color(red);
		printf("\n\t\t\t\t\tSelect option:");
		scanf("%d",&FF);
		if(FF==1) {
			clear();
			gpuBUBT();
			int i=0;
			regls user[1000];
			foody food[1000];
			int quantity[1000];
			int totalprice[1000];
			char read[500];
			FILE *fp=fopen("order_list.txt","r");
			if(fp==NULL) {
				printf("\n\t\t\t\t\tFile:order_list.txt is missing!");
			}
			while(!feof(fp)) {
				if(fgets(read,1000,fp)==NULL) {
					break;
				}
				sscanf(read,"%s %s %d %d %d",user[i].id,food[i].fname,&quantity[i],&food[i].price,&totalprice[i]);
				i++;
			}
			fclose(fp);
			for(int j=0; j<i; j++) {
				printf("\n\t\t\t\t\t%s %s %d %d %d",user[j].id,food[j].fname,quantity[j],food[j].price,totalprice[j]);
			}
			getch();
			goto ff;
		} else if(FF==2) {
			regls user[1000];
			char read[1000];
			clear();
			gpuBUBT();
			int p=0;
			FILE *regis=fopen("registration_list.txt","r");
			if(regis==NULL) {
				printf("\n\t\t\t\t\tFile:registration_list.txt is missing!");
			}
			while(!feof(regis)) {
				if(fgets(read,1000,regis)==NULL) {
					break;
				}
				sscanf(read,"%s %s %s %s %s %d",user[p].id,user[p].uname,user[p].pass,user[p].mail,user[p].phone,&user[p].status);
				p++;
			}
			fclose(regis);
			int start,end;
			char confirm;
			int total_select;
			for(int q=0; q<p; q++) {
				printf("\n%d. %s %s %s %s %s %d",q+1,user[q].id,user[q].uname,user[q].pass,user[q].mail,user[q].phone,user[q].status);
			}
there:
			printf("\n\n\n\nSelect start index for accept:");
			scanf("%d",&start);
			printf("\n\n\n\nSelect end index for accept:");
			scanf("%d",&end);
			printf("\n\n\nAre you sure to accept following requests:");
			start=start-1;
			total_select=0;
			for(int n=start; n<end; n++) {
				total_select++;
				printf("\n%d. %s %s %s %s %s %d",n+1,user[n].id,user[n].uname,user[n].pass,user[n].mail,user[n].phone,user[n].status);
			}
			printf("\n\n\n Confirm request(y/n):");
			scanf("%c",&confirm);
			scanf("%c",&confirm);
			if(confirm=='y'||confirm=='Y') {
				FILE *cus=fopen("customer_info.txt","a");
				if(cus==NULL) {
					printf("\n\t\t\t\t\tFile:customer_info.txt is missing!");
				}
				for(int m=start; m<end; m++) {
					fprintf(cus,"\n%s %s %s %s %s %d",user[m].id,user[m].uname,user[m].pass,user[m].mail,user[m].phone,1);
				}
				gpuType("Request accepted...",50);
				fclose(cus);
			} else {
				goto there;
			}
			getch();
			goto ff;
		} else if(FF==3) {
			gpuIDSEARCH();
			goto ff;
		} else if(FF==4) {
			clear();
			gpuBUBT();
			char notice[3000];
			printf("%s",fetchtime());
			printf("Write notice:");
			gets(notice);
			gets(notice);
			printf("\n\nPress enter to Publish.");
			getch();
			FILE *noticepublish=fopen("notice.txt","a");
			if(noticepublish==NULL) {
				printf("\n\t\t\t\t\tFile:notice.txt is missing!");
			}
			fprintf(noticepublish,notice);
			fclose(noticepublish);
			gpuType("Notice published successfully..",10);
			getch();
			goto ff;
		} else if(FF==5) {
			clear();
			gpuBUBT();
			char AU[3000];
			printf("%s",fetchtime());
			printf("Write About BUBT Cafe Management System:");
			gets(AU);
			gets(AU);
			printf("\n\nPress enter to Publish.");
			getch();
			FILE *publishAU=fopen("about_Us.txt","a");
			if(publishAU==NULL) {
				printf("\n\t\t\t\t\tFile:about_Us.txt is missing!");
			}
			fprintf(publishAU,AU);
			fclose(publishAU);
			gpuType("Description published successfully..",10);
			getch();
			goto ff;
		} else if(FF==6) {
			clear();
			gpuBUBT();
			readREPORT();
			getch();
		}


		else if(FF==7) {
			return 7;
		}
	} else {
		goto retry;
	}
}


int gpuUSER(char id[]) {
	clear();
	gpuBUBT();
	Color(white);
	printf("\n\n\n\n\n\t\t\t\t\t1. FOOD CORNER-->");
	printf("\n\t\t\t\t\t2. Order History-->");
	printf("\n\t\t\t\t\t3. Report a problem-->");
	printf("\n\t\t\t\t\t4. Log Out-->\n\n\n");
	int option;
	Color(cyan);
	printf("\n\t\t\t\t\tSelect option:");
	scanf("%d",&option);
	return option;
}


int gpuFOOD_ITEM(char id[]) {
	char read[1000];
	int i=0;
	foody f[100];
	int unit,cost,confirmation=0;
	int type;
	int item=0,opt=0;
	int val=0;
	FILE *fp=fopen("product_list.txt","r");
	if(fp==NULL) {
		printf("\n\t\t\t\t\tFile:product_list.txt is missing!");
	}
	while(!feof(fp)) {
		if(fgets(read,1000,fp)==NULL) {
			break;
		}
		sscanf(read,"%d %s %s %d %d",&f[i].serial,f[i].fname,f[i].type,&f[i].price,&f[i].available);
		i++;
	}
	fclose(fp);

back:
	clear();
	gpuBUBT();
	Color(white);
	printf("\n\n\n\t\t\t\t\t1. Drinks & Bevarages-->");
	printf("\n\t\t\t\t\t2. Fast Food-->");
	printf("\n\t\t\t\t\t3. Sweets & Desserts-->");
	printf("\n\t\t\t\t\t4. Meaty-->");
	printf("\n\t\t\t\t\t5. Ricey-->");
	Color(blue);
	printf("\n\n\n\t\t\t\t\tSelect item type:");
	scanf("%d",&type);
	clear();
	gpuBUBT();
	Color(white);
	if(type==1) {
		for(int j=0; j<=i; j++) {
			if(strcmp(f[j].type,"DRINKS_&_BEVARAGE")==0) {
				printf("\n\n\t\t\t\t\tFOOD_SN#%d NAME:%s  PRICE:%d TOTAL AVAIABLE:%d",f[j].serial,f[j].fname,f[j].price,f[j].available);
			}
		}
	} else if(type==2) {
		for(int j=0; j<=i; j++) {
			if(strcmp(f[j].type,"FAST_FOOD")==0) {
				printf("\n\n\t\t\t\t\tFood_SN#%d %s             Price:%d TK          Available:%d",f[j].serial,f[j].fname,f[j].price,f[j].available);
			}
		}
	} else if(type==3) {
		for(int j=0; j<=i; j++) {
			if(strcmp(f[j].type,"SWEETS_&_DESSERTS")==0) {
				printf("\n\n\t\t\t\t\tFood_SN#%d %s             Price:%d TK          Available:%d",f[j].serial,f[j].fname,f[j].price,f[j].available);
			}
		}
	} else if(type==4) {
		for(int j=0; j<=i; j++) {
			if(strcmp(f[j].type,"MEAT")==0) {
				printf("\n\n\t\t\t\t\tFood_SN#%d %s             Price:%d TK          Available:%d",f[j].serial,f[j].fname,f[j].price,f[j].available);
			}
		}
	} else if(type==5) {
		for(int j=0; j<=i; j++) {
			if(strcmp(f[j].type,"RICEY")==0) {
				printf("\n\n\t\t\t\t\tFood_SN#%d %s             Price:%d TK          Available:%d",f[j].serial,f[j].fname,f[j].price,f[j].available);
			}
		}
	}

	printf("\n\n\t\t\t\t\t1.Order Food");
	printf("\n\t\t\t\t\t2.Go back");
	printf("\n\t\t\t\t\t3.Go Home");
	Color(cyan);
	printf("\n\t\t\t\t\tSelect option:");
	scanf("%d",&opt);
	Color(white);
	if(opt==1) {
retry:
		Color(cyan);
		printf("\n\n\t\t\t\t\tOrder Food #serial_number:");
		scanf("%d",&item);

		for(int j=0; j<=i; j++) {

			if(item==f[j].serial) {
				Color(white);
				printf("\n\n\t\t\t\t\tYou ask for %s",f[j].fname);
				val=j;
			}
		}

		Color(white);
		printf("\n\n\t\t\t\t\tHow much unit do you want to order?:");
		scanf("%d",&unit);
		cost=unit*f[val].price;
		printf("\n\n\t\t\t\t\tHave a look please:\n\t\t\t\t\t%s  %dunit X %d tk ==total %d Taka\n\n\t\t\t\t\t1.Place order\n\t\t\t\t\t2.No, Retry\n\n\t\t\t\t\t",f[val].fname,unit,f[val].price,cost);
		scanf("%d",&confirmation);
		if(confirmation==1) {
			FILE *order=fopen("order_list.txt","a");
			fprintf(order,"\n%s %s %d %d %d",id,f[val].fname,unit,f[val].price,cost);
			fclose(order);
			FILE *FP=fopen("product_list.txt","w");
			for(int k=0; k<i; k++) {
				if(item==f[k].serial) {
					fprintf(FP,"\n%d %s %s %d %d",f[k].serial,f[k].fname,f[k].type,f[k].price,f[k].available-unit);
				} else {
					fprintf(FP,"\n%d %s %s %d %d",f[k].serial,f[k].fname,f[k].type,f[k].price,f[k].available);
				}
			}
			fclose(FP);
			Color(cyan);
			gpuType("\n\t\t\t\t\tCongratulation! Order request successful!!!",80);
			getch();
			return cost;
		} else if(confirmation==2) {
			clear();
			goto retry;
		}
	} else if(opt==2) {
		clear();
		goto back;
	} else if(opt==3) {
		return 3;
	}
}


void clear() {
	system("cls");
}


void Color(int ForgC) {
	WORD wColor;
	//We will need this handle to get the current background attribute
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	//We use csbi for the wAttributes word.
	if (GetConsoleScreenBufferInfo(hStdOut, & csbi)) {
		//Mask out all but the background attribute, and add in the forgournd color
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;
}


void gpuBUBT() {
	printf("\n\n");
	Color(purple);
	printf("\t\t\t\t     ____      _   _     ____     _____                           ,...         \n");
	Color(ash);
	printf("\t\t\t\t  U | __\"\)u U |\"|u| | U | __\"\)u  |_ \" _|    .g8\"\"\"bgd            .d'\"\"         \n");
	printf("\t\t\t\t   \\|  _ \\/  \\| |\\| |  \\|  _ \\/    | |    .dP'     `M            dM`            \n");
	Color(blue);
	printf("\t\t\t\t    | |_\) |   | |_| |   | |_\) |   /| |\\   dM'       `  ,6\"Yb.   mMMmm   .gP\"Ya.  \n");
	printf("\t\t\t\t    |____/   <<\\___/    |____/   u |_|U  MM          8)   MM    MM    ,M'   Ybe' \n");
	Color(ash);
	printf("\t\t\t\t                                           MM.          ,pm9MM    MM    8M\"\"\"\"\"\"`` \n");
	printf("\t\t\t\t                                                `Mb.     ,' 8M  MM    MM    YM.    , \n");
	Color(purple);
	printf("\t\t\t\t  ==========================================`\"bmmmd'  `Moo9^Yo..JMML.   `Mbmmd'` \n");
	Color(cyan);
	printf("\t\t\t\t  Welcome To BUBT Cafe Management System");
	Color(cyan);
	printf("                    %s\n",fetchtime());
	Color(green);
	printf("\t\t\t\t\t============================================  version_1.0.0.1\n");
	Color(white);
}

void gpuHoption() {
	Color(ash);
	printf("\n\n\n\t\t\t\t\t1. Administration Section-->");
	printf("\n\t\t\t\t\t2. Customer Section-->");
	printf("\n\t\t\t\t\t3. Account Registration-->");
	printf("\n\t\t\t\t\t4. Notice-->");
	printf("\n\t\t\t\t\t5. Contact-->");
	printf("\n\t\t\t\t\t6. Setting-->");
	printf("\n\t\t\t\t\t7. About Us-->");
	printf("\n\t\t\t\t\t8. Developers-->");
	printf("\n\t\t\t\t\t9. Exit-->");
	Color(purple);
	printf("\n\n\n\t\t\t\t\tSelect option:");
}


void exeHOME() {
	gpuBUBT();
	gpuHoption();
}


void gpuType(char ch[],int speed) {
	int len;
	len=strlen(ch);

	for(int i=0; i<len; i++) {
		printf("%c",ch[i]);
		Sleep(speed);
	}
}


void gpuLOGin() {

	printf("\t\t\t\t\t\t   .           ._.     .__             .\n");
	printf("\t\t\t\t\t\t   |    _  _    | ._   [__\) _.._ ._  _ |\n");
	printf("\t\t\t\t\t\t   |___\(_\)\(_]  _|_[ \)  |   \(_][ \)[ \)\(/,|\n");
	printf("\t\t\t\t\t\t          ._|                           \n");
}


void gpuIDSEARCH() {
	char id[20];
	clear();
	gpuBUBT();
	gpuType("\n\t\t\t\t\tEnter your ID to search:",1);
	scanf("%s",&id);
	search_user(id);
	getch();
}


void gpuNotice() {
	Color(green);
	printf("\t\t\t\t\t      ___           ___                                   ___           ___      \n");
	printf("\t\t\t\t\t     /__/\\         /  /\\          ___       ___          /  /\\         /  /\\     \n");
	printf("\t\t\t\t\t     \\  \\:\\       /  /::\\        /  /\\     /  /\\        /  /:/        /  /:/_    \n");
	printf("\t\t\t\t\t      \\  \\:\\     /  /:/\\:\\      /  /:/    /  /:/       /  /:/        /  /:/ /\\   \n");
	printf("\t\t\t\t\t  _____\\__\\:\\   /  /:/  \\:\\    /  /:/    /__/::\\      /  /:/  ___   /  /:/ /:/_  \n");
	printf("\t\t\t\t\t /__/::::::::\\ /__/:/ \\__\\:\\  /  /::\\    \\__\\/\\:\\__  /__/:/  /  /\\ /__/:/ /:/ /\\ \n");
	printf("\t\t\t\t\t \\  \\:\\~~\\~~\\/ \\  \\:\\ /  /:/ /__/:/\\:\\      \\  \\:\\/\\ \\  \\:\\ /  /:/ \\  \\:\\/:/ /:/ \n");
	printf("\t\t\t\t\t  \\  \\:\\  ~~~   \\  \\:\\  /:/  \\__\\/  \\:\\      \\__\\::/  \\  \\:\\  /:/   \\  \\::/ /:/  \n");
	printf("\t\t\t\t\t   \\  \\:\\        \\  \\:\\/:/        \\  \\:\\     /__/:/    \\  \\:\\/:/     \\  \\:\\/:/   \n");
	printf("\t\t\t\t\t    \\  \\:\\        \\  \\::/          \\__\\/     \\__\\/      \\  \\::/       \\  \\::/    \n");
	printf("\t\t\t\t\t     \\__\\/         \\__\\/                                 \\__\\/         \\__\\/     \n");
	printf("========================================================================================================================================================================\n");

}


void noticeRead() {
	char read[1000];
	FILE *noticedetails=fopen("notice.txt","r");
	if(noticedetails==NULL) {
		printf("File:notice.txt not found!!!");
	}
	while(!feof(noticedetails)) {
		if(fgets(read,1000,noticedetails)==NULL) {
			break;
		}
		Color(ash);
		gpuType(read,50);
	}
	fclose(noticedetails);
}


void contact() {
	system("explorer https://www.facebook.com/mustahidul.islam.5/");
	clear();
}


void aboutUS() {
	char about[1000];
	FILE *description=fopen("about_Us.txt","r");
	if(description==NULL) {
		printf("FILE: about_Us file doesn't exist!");
	} else {
		while(!feof(description)) {
			if(fgets(about,1000,description)==NULL) {
				break;
			}
			Color(ash);
			gpuType(about,10);
		}
		fclose(description);
	}
}


void gpuDev() {
	Color(cyan);
	printf("\t\t\t_______ ______                 _____        ________                     ______                                      \n");
	printf("\t\t\t___    |___  /_ ______ ____  ____  /_       ___  __ \\_____ ___   _______ ___  /______ ________ _____ ________________\n");
	printf("\t\t\t__  /| |__  __ \\_  __ \\_  / / /_  __/       __  / / /_  _ \\__ | / /_  _ \\__  / _  __ \\___  __ \\_  _ \\__  ___/__  ___/\n");
	printf("\t\t\t_  ___ |_  /_/ // /_/ // /_/ / / /_         _  /_/ / /  __/__ |/ / /  __/_  /  / /_/ /__  /_/ //  __/_  /    _\(__  \) \n");
	printf("\t\t\t/_/  |_|/_.___/ \\____/ \\__,_/  \\__/         /_____/  \\___/ _____/  \\___/ /_/   \\____/ _  .___/ \\___/ /_/     /____/  \n");
	printf("\t\t\t                                                                                      /_/                            \n");
}


void devnames() {
	printf("\n\n\n\n\t\t\t\t\t\t\t\t\t");
	Color(silver);
	gpuType("  Mustahidul Islam Ferdous ",40);
	printf("\n\n\t\t\t\t\t\t\t\t\t");
	gpuType("  Sidratul Muntaha Meem ",40);
	printf("\n\n\t\t\t\t\t\t\t\t\t");
	gpuType("  Fakrul Islam Rafsan ",40);
	printf("\n\n\t\t\t\t\t\t\t\t\t");
}


void gpuExit() {
	clear();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tAre you sure to quit?\n\n\t\t\t\t\t\t1.YES\t\t\t\t2.NO\n\t\t\t\t\t\t");

}


void Endexe() {
	clear();
	Color(vanish);
	exit(0);
}


void search_user(char id[]) {
	regls data[1000];
	char read[1000];
	int i=0,flag=0;
	FILE *search=fopen("customer_info.txt","r");
	if(search==NULL) {
		printf("\n\t\t\t\t\tFile:customer_info.txt is missing!");
	}
	while(!feof(search)) {
		if(fgets(read,1000,search)==NULL) {
			break;
		}
		sscanf(read,"%s %s %s %s %s %d",data[i].id,data[i].uname,data[i].pass,data[i].mail,data[i].phone,&data[i].status);
		i++;
	}
	fclose(search);
	for(int j=0; j<=i; j++) {
		if(strcmp(id,data[j].id)==0) {
			printf("\n\n\t\t\t\t\tUsername: %s\n\n\t\t\t\t\tMail: %s\n\n\t\t\t\t\tPhone: %s\n\n\t\t\t\t\tAccount status: %d",data[j].uname,data[j].mail,data[j].phone,data[j].status);
			flag=1;
		}
	}
	if(flag==0) {
		printf("ID not found!!!");
	}
}


int reg_progress(char id[]) {
	regls data[1000];
	char read[1000];
	int i=0,ret=0;
	FILE *regfile=fopen("registration_list.txt","r");
	if(regfile==NULL) {
		printf("\n\t\t\t\t\tFile:registration_list.txt is missing!");
	}
	while(!feof(regfile)) {
		if(fgets(read,1000,regfile)==NULL) {
			break;
		}
		sscanf(read,"%s %s %s %s %s %d",data[i].id,data[i].uname,data[i].pass,data[i].mail,data[i].phone,&data[i].status);
		i++;
	}
	fclose(regfile);
	for(int j=0; j<=i; j++) {
		if(strcmp(id,data[j].id)==0) {
			ret=1;
		}
	}
	return ret;
}


int reg_available(char id[]) {
	regls data[1000];
	char read[1000];
	int i=0,ret=1;
	FILE *varified_file=fopen("customer_info.txt","r");
	if(varified_file==NULL) {
		printf("\n\t\t\t\t\tFile:registration_list.txt is missing!");
	}
	while(!feof(varified_file)) {
		if(fgets(read,1000,varified_file)==NULL) {
			break;
		}
		sscanf(read,"%s %s %s %s %s %d",data[i].id,data[i].uname,data[i].pass,data[i].mail,data[i].phone,&data[i].status);
		i++;
	}
	fclose(varified_file);
	for(int j=0; j<=i; j++) {
		if(strcmp(id,data[j].id)==0) {
			ret=0;
		}
	}
	return ret;
}



int adminLOGin(char username[],char pass[]) {
	clear();
	gpuLOGin();
	regls admin[1000];
	char read[1000];
	int i=0,ret=0;
	FILE *admn=fopen("admin_login.txt","r");
	if(admn==NULL) {
		printf("\n\t\t\t\t\tFile:admin_login.txt is missing!");
	}

	while(!feof(admn)) {
		if(fgets(read,1000,admn)==NULL) {
			break;
		}
		sscanf(read,"%s %s",admin[i].uname,admin[i].pass);
		i++;
	}
	fclose(admn);
	for(int j=0; j<=i; j++) {
		if(strcmp(username,admin[j].uname)==0&&strcmp(pass,admin[j].pass)==0)
			ret=1;
	}
	return ret;
}


int login(char id[],char pass[]) {
	regls data[1000];
	char read[1000];
	int i=0,ret=0;
	FILE *log=fopen("customer_info.txt","r");
	if(log==NULL) {
		printf("\n\t\t\t\t\tFile:customer_info.txt is missing!");
	}
	while(!feof(log)) {
		if(fgets(read,1000,log)==NULL) {
			break;
		}
		sscanf(read,"%s %s %s %s %s %d",data[i].id,data[i].uname,data[i].pass,data[i].mail,data[i].phone,&data[i].status);
		i++;
	}
	fclose(log);
	for(int j=0; j<=i; j++) {
		if(strcmp(id,data[j].id)==0&&strcmp(pass,data[j].pass)==0) {
			ret=1;
		}
	}
	return ret;

}



void gpuORDERHISTORY(char id[]) {
	char read[1000];
	int i=0;
	foody f[1000];
	regls user[1000];
	int total[1000];
	FILE *fd=fopen("order_list.txt","r");
	if(fd==NULL) {
		printf("\n\t\t\t\t\tFile:order_list.txt is missing!");
	}
	while(!feof(fd)) {
		if(fgets(read,1000,fd)==NULL) {
			break;
		}
		sscanf(read,"%s %s %d %d %d",user[i].id,f[i].fname,&f[i].quantity,&f[i].price,&total[i]);
		i++;
	}
	fclose(fd);
	int l=0,sum=0;
	clear();
	gpuBUBT();
	for(int j=0; j<=i; j++) {
		if(strcmp(id,user[j].id)==0) {
			l++;
			printf("\n\n\t\t\t\t\tOrder NO-%d : %s %dunit   %dTaka",l,f[j].fname,f[j].quantity,total[j]);
			sum=sum+total[j];

		}
	}
	if(l>0)
		printf("\n\n\t\t\t\t\tYou have placed total %d orders.That costs around %d Taka!",l,sum);
	else
		printf("\n\n\t\t\t\t\tNo order history found!!!");
	getch();
}



void reportPROBLEM(char id[]) {
	char report[200];
	printf("\n\n\t\t\t\t\tWrite your issues:");
	gets(report);
	gets(report);
	FILE *order=fopen("report.txt","a");
	fprintf(order,"\n%s %s %s",id,report,fetchtime());
	fclose(order);
	gpuType("\n\n\t\t\t\t\tReport recodrded!!! We'll contact with you soon...",20);

}



void readREPORT() {
	char read[300];
	FILE *details=fopen("report.txt","r");
	if(details==NULL) {
		printf("File:report.txt not found!!!");
	}
	while(!feof(details)) {
		if(fgets(read,1000,details)==NULL) {
			break;
		}
		Color(ash);
		gpuType(read,50);
	}
	fclose(details);
}



void setting() {
	clear();
	gpuBUBT();
	char read[1000],name[100],oldpass[55];
	char username[100];
	char pass[55];
	printf("\n\t\t\t\t\tEnter your user name/id:");
	scanf("%s",name);
	printf("\n\t\t\t\t\tEnter your old password:");
	scanf("%s",oldpass);
	int i=0;
	FILE *set=fopen("admin_login.txt","r");
	if(set==NULL) {
		printf("\n\t\t\t\t\tFile:admin_login.txt is missing!");
	}
	while(!feof(set)) {
		if(fgets(read,1000,set)==NULL) {
			break;
		}
		sscanf(read,"%s %s",username,pass);
		i++;
	}
	fclose(set);
	if(strcmp(name,username)==0&&strcmp(pass,oldpass)==0) {
		printf("\n\t\t\t\t\tEnter your new password:");
		scanf("%s",oldpass);
		FILE *sett=fopen("admin_login.txt","w");
		fprintf(sett,"%s %s",username,oldpass);
		fclose(sett);
		gpuType("\n\t\t\t\t\tPassword changed successfully!",1);
		getch();
	} else {
		gpuType("\n\t\t\t\t\tInvalid Password!!!",1);
		getch();
	}
}

