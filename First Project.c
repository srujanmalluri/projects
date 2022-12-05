#include<stdio.h>
#include<string.h>
#include<conio.h>

struct account
	{
	char name[30],age[10],mail[30],pass[30];
	}a1;

FILE *fp,*ft,*fm;

char ml[30],ch,gc,gv[30],th[30],tm[30],mname[10],px[10];
int i,j,y,mt,cost,t,T,UB=250,LB=150,U,dt,a[5][5]={ 0 };

void login();
void signup();
void movie();
void theatre();
void tickets();
void display();
void book();
void select();
void payment();
void ticket();
void sys();

void main()
{ 
	int h,mv,s,np,cp;
	float cost;
	char mail[30],place[30];
	printf("\n\t\t\tBOOK MY SHOW\n");
	printf("------------------------------------------------------------\n\n");
	printf("* * IT ALL STARTS HERE * *\n");
		signup();
	//after entering into the homepage//
	do	{
		printf("CHOOSE  1. BOOK MOVIE TICKECTS\n\t2. CHECK THEATRES\n\t3. REPORT A PROBLEM / GIVE FEEDBACK\n\t4. CONTACT US\n\t5. EXIT\n");
		scanf("%c",&ch);
		switch (ch)
			{
			case '1':
				break;
			case '2':
					sys();
				ft=fopen("theatre.txt","r");
				while(fscanf(ft,"%s",&th)!=EOF)
				{
					printf("%s\n",th);
				}
				fclose(ft);
				printf("\n\n  PRESS ENTER TO CONTINUE\n");
				scanf("%c",&gc);
				scanf("%c",&gc);
					sys();
				goto rwd;
				break;
			case '3':
					sys();
				printf("\nPLEASE ENTER YOUR PROBLEM OR GIVE ANY FEEDBACK\n");
				gets(gv);
				gets(gv);
				printf("\nTHANK YOU FOR YOUR HELP\n\nWE WILL CONSIDER WHAT YOU ANSWERED\n");
				printf("\n\n  PRESS ENTER TO CONTINUE");
				scanf("%c",&gc);
				scanf("%c",&gc);
					sys();
				goto rwd;
				break;
			case '4':
					sys();
				printf("\n  OUR EMAIL: bms@gmail.com\n");
				printf("\n    PLEASE CONTACT US THROUGH EMAIL\n");
				printf("\n\n  PRESS ENTER TO CONTINUE\n");
				scanf("%c",&gc);
				scanf("%c",&gc);
					sys();
				goto rwd;
				break;
			case '5':
				y=73;
				goto rwd;
				break;
			default:
					sys();
				printf("    INVALID SELECTION\n");
				goto rwd;
				break;
			}		
			sys();
		printf("\nCHOOSE THE MOVIE THAT YOU WISHED TO WATCH\n");
			movie();
			theatre();
		printf("ENTER DATE: ");
		scanf("%d",&dt);
		printf("CHOOSE SHOW TIMINGS\n");
		time:
		printf("    1. 11:00\n    2. 2:00\n    3. 6:00\n    4. 9:00\n");
		scanf("%d",&t);
		if(t==1)
			t=11;
		else if(t==2)
			t=2;
		else if(t==3)
			t=6;
		else if(t==4)
			t=9;
		else
		{
			printf("INVALID SELECTION PLEASE CHOOSE AGAIN\n");
			goto time;
		}
		printf("YOU HAVE CHOSEN %d O'CLOCK SHOW\n",t);
				sys();
			tickets();
			display();
	    	book();
			payment();
			ticket();
		printf("\tDEAR %s ENJOY YOUR SHOW!",strupr(a1.name));
		printf("\n\n\n");
		rwd:
		printf("\n");
		sys();
	}while(y!=73);
}

void signup()
	{
	int x=0,s=0;
	char name[30],pw[30];
	fp=fopen("bms.txt","r");
	printf("PRESS '1' TO SIGNUP OR '2' TO LOGIN\n");
	scanf("%d",&s);
	printf("    ENTER YOUR EMAIL: ");
	scanf("%s",&a1.mail);
	while(fscanf(fp,"%s",ml)!=EOF)
		{
		if(strcmp(ml,a1.mail)==0)
			{
			x=1;
			break;
			}
		}
	fclose(fp);
	if(x==0)
	printf("EMAIL DOES NOT EXIST\n");
	if(x==1 || (s==2 && x!=0))
		{
		printf("    ENTER YOUR PASSWORD TO LOGIN: ");
			login();
		}
	else
		{
		printf("\tENTER YOUR DETAILS TO CONTINUE\n");
		char *px1,*px2;
		printf("    NAME: ");
		scanf("%s",&a1.name);
		printf("    AGE: ");
		scanf("%s",&a1.age);
		pass:
		printf("    CREATE A PASSWORD: ");
		scanf("%s",&pw);
		printf("\n    CONFIRM YOUR PASSWORDE: ");
		scanf("%s",&a1.pass);
		if(strcmp(pw,a1.pass) != 0)
			{
			printf("\nYOUR PASSWORDS DOESN'T MATCH, PLEASE TRY AGAIN\n");
			goto pass;
			}
				sys();
		printf("\n\tSIGNUP SUCCESSFUL\n");
		fp=fopen("bms.txt","a");
		fprintf(fp,"%s %s %s %s\n",a1.mail,a1.name,a1.age,a1.pass);
		fclose(fp);	
		}
	}

void login()
	{
	char pf[20];
	fp=fopen("bms.txt","r");
	while(fscanf(fp,"%s",ml)!=EOF)
		{
		if(strcmp(ml,a1.mail)==0)
			break;
		}
	fscanf(fp,"%s",a1.name);
	fscanf(fp,"%s",a1.age);
	fscanf(fp,"%s",a1.pass);
	scanf("%s",&pf);
	if(strcmp(a1.pass,pf)==0)
		{
		printf("\n\tYOU ARE SUCCESSFULLY LOGGED IN\n\n");
		}
	else
		{
		printf("\n\nINVALID MAIL OR PASSWORD\n");
	    printf("\tRE-ENTER YOUR PASSWORD: ");
	    login();
	    }
	printf("PROCESSING PLEASE WAIT\n");
	}

void movie()
{
	int mn;
	printf("    1. MOVIE1\n    2. MOVIE2\n    3. MOVIE3\n");
   	scanf("%d",&mn);
   	
   	if(mn==1)
   	{
   		printf("YOU HAVE CHOSEN  MOVIE1\n");
	}
   	else if(mn==2)
   	{
   		printf("YOU HAVE CHOSEN MOVIE2\n");
	}
   	else if(mn==3)
   	{
   		printf("YOU HAVE CHOSEN MOVIE3\n");
   	}
   	else
   	{
   			sys();
	printf("INVALID SELECTION PLEASE CHOOSE THE MOVIE NAME AGAIN\n");
	movie();
	}
	printf("\n\n  PRESS ENTER TO CONTINUE\n");
	scanf("%c",&gc);
	fm=fopen("movie.txt","r");
	for(i=0;i<mn;i++)
	{
		fscanf(fm,"%s",&mname);
	}
		sys();
}

void theatre()
{
	int j=1;
	printf("\nCHOOSE A THEATRE\n");
	ft=fopen("theatre.txt","r");
	while(fscanf(ft,"%s",th)!=EOF)
	{
		printf("%d. %s\n",j++,th);
	}
	scanf("%d",&mt);
	fclose(ft);
	ft=fopen("theatre.txt","r");
	for(i=0;i<mt;i++)
	{
		fscanf(ft,"%s",&tm);
	}
		sys();
}

void tickets()
{
	printf("ENTER NO.OF TICKETS\n");
	scanf("%d",&T);
	printf("CHOOSE 1. UPPER BALCONY OR 2. LOWER BALCONY\n");
	scanf("%d",&U);
	if (U==1)
		cost=T*UB;
	else if(U==2)
		cost=T*LB;
	printf("COST OF BOOKING IS: %d/-",cost);
		sys();
}

void book()
    {  
	printf("NOTE: * *FIRST TWO ROWS ARE UPPER BALCONY* *\n");
	printf("      * *NEXT THREE ROWS ARE LOWER BALCONY* *\n");
	printf("      * *'1' DENOTES YOUR BOOKED SEAT\n\n* *\n");
    select();
    }

void select()
    {
	int row,col,tx;
	tx=T;
    while(tx--)
		{
			s:
			printf("CHOOSE ROW: ");
        	scanf("%d",&row);
        	printf("CHOOSE COLOUMN: ");
        	scanf("%d",&col);
        	if(row>5||col>5)
        	{
            	printf("INVALID SELECTION!! PLEASE SELECT AGAIN\n");
           		goto s;
        	}
        	else if(a[row-1][col-1]!=0)
        	{
            	printf("SEATS ARE ALREADY BOOKED, PLEASE SELECT AGAIN\n");
            	goto s;
        	}
        	else 
			{
            	a[row-1][col-1]=1;
            	printf("YOUR SELECTION IS CONFIRMED\n");
            	display();
        	}   
    	}
    	printf("\n\n  PRESS ENTER TO CONTINUE\n");
		scanf("%c",&gc);
		scanf("%c",&gc);
    }

void display()
{
    int i,j;
    printf("COLOUMN: 1 2 3 4 5\n\n");
    for(i=0;i<5;i++)
    {
        printf("ROW : %d  ",i+1);
        for(j=0;j<5;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void payment()
{
	int s,k,cd,ed,cvv,upi;
	char app[30],cn[30];
		sys();
	printf("PAY THROUGH\n1. DEBIT CARD / CREDIT CARD\n2. ONLINE PAYMENT\n");
	scanf("%d",&k);
		sys();
	if(k==1 || k==2)
	switch(k)
	{
		case 1:
			printf("ENTER CARD NUMBER\n");
			scanf("%d",&cd);
			printf("EXPIRY DATE\n");
			scanf("%d",&ed);
			printf("ENTER CVV\n");
			scanf("%d",&cvv);
			printf("ENTER NAME ON CARD\n");
			scanf("%s",&cn);
			printf("PAY RUPEES: %d/-\n",cost);
			break;
		case 2:
			printf("CHOOSE AN APP\n");
			printf("1. GPAY\n2. PHONEPAY\n3. PAYTM\n");
			scanf("%d",&s);
			printf("Enter UPI\n");
			scanf("%d",&upi);
			printf("Pay Rupee: %d/-\n",cost);
			break;		
	}
	else
	{
		printf("\n\nINVALID SELECTION PLEASE CHOOSE AGAIN\n");
		payment();
	}
	printf("\n\n  PRESS ENTER TO CONTINUE\n");
	scanf("%c",&gc);
}

void ticket()
{
		sys();
	printf("\nTICKET CONFIRMATION\n\n");
	printf("\t%s |  2D\n\t Date:%d  | %d:00\n\t%s\n\tHYDERABAD\n",mname,dt,t,tm);
	printf("______________________________________\n");
	printf("NO.OF TICKETS: %d\t",T);
	if(U==1)
	printf("UPPER BALCONY\n");
	else
	printf("LOWER BALCONY\n");
	printf("\n\n  PRESS ENTER TO CONTINUE\n");
	scanf("%c",&gc);
	
}

void sys()
{
	system("cls");
	printf("\n\t\t\tBOOK MY SHOW\n");
	printf("------------------------------------------------------------\n\n");
}

//THE END
