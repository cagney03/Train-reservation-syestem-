#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char name[50];
	int train_num;
	int num_of_seats;
}pd;
void reservation(void);
void viewdetails(void);
void printticket(char name[],int,int,float);
void specificbus(int);
float charge(int,int);
int main()

{
	
	printf("\t\t       ----------------------------------      \n");
	printf("\t\t            TRAIN TICKET RESERVATION            \n");
	printf("\t\t                    SYSTEM                     \n");
	printf("\t\t       ----------------------------------      \n");
	


  

	int menu_choice,choice_return;
	start:
	

	printf("\n1>> Reserve A Ticket");
	printf("\n_______________________");
	printf("\n2>> View All Available Train");
	printf("\n____________________________");
	printf("\n3>> Exit");
	printf("\n-->");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1:
			reservation();
			break;
		case 2:
			viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			//getch();
			break;
		case 3:
			return(0);
		default:
			printf("\nInvalid choice");
	}
	goto start;
	return(0);
}


void viewdetails(void)
{

	printf("------------------------------------------------------------------------------------------------------");
	printf("\nTrn.No\tName\t               \t\tDestinations                \tCharge    \t\tTime\n");
	printf("------------------------------------------------------------------------------------------------------");
	printf("\n1001\tMAS QLN SUVIDHA       \tCHENNAI CENTRAL To KOLLAM JN        \tRs.1050    \t\t22.00");
	printf("\n1002\tVISAKAPATNAM EXP      \tCHENNAI CENTRAL To VISAKHAPATNAM    \tRs.500  \t\t12:00");
	printf("\n1003\tMUMBAI EXPRESS        \tCHENNAI CENTRAL To MUMBAI           \tRs.3050   \t\t19.00");
	printf("\n1004\tKOLKATA EXPRESS       \tCHENNAI CENTRAL To KOLKATA          \tRs.2500   \t\t02.00");
	printf("\n1005\tERNAKULAM EXPRESS     \tCHENNAI CENTRAL To ERNAKULAM        \tRs.1250 \t\t04.00");
	printf("\n1006\tPALANI EXPRESS        \tCHENNAI CENTRAL TO PALANI           \tRs.400   \t\t09:30");
    printf("\n1007\tWEST COAST EXP        \tCHENNAI CENTRAL To MANGALORE        \tRs.1250   \t\t01:00");
    printf("\n1008\tHALDIA EXPRESS        \tCHENNAI CENTRAL To HALDIA           \tRs.750   \t\t04:00");
    printf("\n1009\tSHIRDI EXPRESS        \tCHENNAI CENTRAL To SAINAGAR SHIRDI  \tRs.1300  \t\t05:35");
    printf("\n1010\tLUCKNOW EXP           \tCHENNAI CENTRAL To LUCKNOW NR       \tRs.1600   \t\t04:15");

}


void reservation(void)
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");


	printf("\nEnter Your Name:> ");
	scanf("%s",passdetails.name);
	fflush(stdin);
	//gets(passdetails.name);
	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View Available Train<< \n");
	//getch();

	viewdetails();
	printf("\n\nEnter train number:> ");
	start1:
	scanf("%d",&passdetails.train_num);
	if(passdetails.train_num>=1001 && passdetails.train_num<=1010)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
	}
	else
	{
		printf("\nInvalid train Number! Enter again--> ");
		goto start1;
	}

	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n", passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
		printf("==================");
		printf("\nReservation Done\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	//getch();
}

float charge(int train_num,int num_of_seats)
{

	if (train_num==1001)
	
	{
		return(1050*num_of_seats);
	}
	if (train_num==1002)
	{
		return(500*num_of_seats);
	}
	if (train_num==1003)
	{
		return(3050*num_of_seats);
	}
	if (train_num==1004)
	{
		return(2500*num_of_seats);
	}
	if (train_num==1005)
	{
		return(1250*num_of_seats);
	}
	if (train_num==1006)
	{
		return(400*num_of_seats);
	}
	if (train_num==1007)
	{
		return(1250*num_of_seats);
	}
	if (train_num==1008)
	{
		return(750*num_of_seats);
	}
	if (train_num==1009)
	{
		return(1300*num_of_seats);
	}
	if (train_num==1010)
	{
		return(1600*num_of_seats);
	}
}

void printticket(char name[],int num_of_seats,int train_num,float charges)
{

	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nTrain Number:\t\t%d",train_num);
	specificbus(train_num);
	printf("\nCharges:\t\t%.2f",charges);
}


void specificbus(int train_num)
{

	if (train_num==1001)
	{
		printf("\nTrain:\t\t\tMAS QLN SUVIDHA");
		printf("\nDestination:\t\tCHENNAI CENTRAL To KOLLAM JN ");
		printf("\nDeparture:\t\t22.00");
	}
	if (train_num==1002)
	{
		printf("\nTrain:\t\t\tVISAKAPATNAM EXP");
		printf("\nDestination:\t\tCHENNAI CENTRAL To VISAKHAPATNAM");
		printf("\nDeparture:\t\t12:00");
	}
	if (train_num==1003)
	{
		printf("\nTrain:\t\t\tMUMBAI EXPRESS");
		printf("\nDestination:\t\tCHENNAI CENTRAL To MUMBAI");
		printf("\nDeparture:\t\t19.00");
	}
	if (train_num==1004)
	{
		printf("\nTrain:\t\t\tKOLKATA EXPRESS");
		printf("\nDestination:\t\tCHENNAI CENTRAL To KOLKATA ");
		printf("\nDeparture:\t\t02.00");
	}
	if (train_num==1005)
	{
		printf("\nTrain:\t\t\tERNAKULAM EXPRESS");
		printf("\nDestination:\t\tCHENNAI CENTRAL To ERNAKULAM ");
		printf("\nDeparture:\t\t04.00");
	}
	if (train_num==1006)
	{
		printf("\nTrain:\t\t\tPALANI EXPRESS ");
		printf("\nDestination:\t\tCHENNAI CENTRAL TO PALANI ");
		printf("\nDeparture:\t\t09:30");
	}
	if (train_num==1007)
	{
		printf("\nTrain:\t\t\tWEST COAST EXP");
		printf("\nDestination:\t\tCHENNAI CENTRAL To MANGALORE");
		printf("\nDeparture:\t\t01:00");
	}
	if (train_num==1008)
	{
		printf("\nTrain:\t\t\tHALDIA EXPRESS  ");
		printf("\n Destination:\t\tCHENNAI CENTRAL To HALDIA ");
		printf("\nDeparture:\t\t04:00");
	}
	if (train_num==1009)
	{
		printf("\nTrain:\t\t\tSHIRDI EXPRESS  ");
		printf("\nDestination:\t\tCHENNAI CENTRAL To SAINAGAR SHIRDI");
		printf("\nDeparture:\t\t05:35");
	}
	if (train_num==1010)
	{
		printf("\nTrain:\t\t\tLUCKNOW EXP ");
		printf("\nDestination:\t\tCHENNAI CENTRAL To LUCKNOW NR");
		printf("\nDeparture:\t\t04:15");
	}
}
