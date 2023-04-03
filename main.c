/**
 * **Clinic Management System**
 * Author:     Omar Mohamed Yamany
 * Created:    01.01.2023
 * Group ID:   0225112210
 * Student ID: 022511221010
 * Made for IMT School for educational use only
 * All copyrights are reserved
 **/

#include<stdio.h>
#include<stdlib.h>
#include"data_types.h" //library for data types
#include"functions.h" //library for linked list functions
#include<string.h>
#include<conio.h>

patient *head = NULL; //head of patients linked list
patient *tail = NULL; //tail of patients linked list

int main(void) //used int for main to terminate with return 0
{
	while(1)
	{
		system("cls");
		printf("Welcome to your Clinic Management System\n");
		printf("----------------------------------------\n");
		/*if(head==NULL)
		{
			import_patients_data(); //read linked list
		}*/
		//import_reservations_data();
		u8 mode=0;
		while(mode==0) //loop until user choose admin or user mode
		{
			printf("\nEnter 1 to access admin mode, or 2 to access user mode!\n");
			printf("Your entry: ");
			scanf("%d", &mode);
			
			switch(mode) 
			{
				case 1:
				printf("Admin mode activated!\n\n");
				break;
				
				case 2:
				printf("User mode activated!\n\n");
				break;
				
				default:
				printf("Wrong entry\n");
				mode=0;
				break;
			}
		}
		
		if(mode==1) //admin mode
		{
			u8 flag_password=0, wrong_psw_count=0;
			u16 entered_password;
			while(flag_password==0) //wait to enter correct password or terminate main
			{
				if(wrong_psw_count>=3) //after 3 wrong trials program terminates
				{
					printf("You entered wrong password 3 times, terminating...");
					return 0;
				}
				
				printf("Enter password to access admin mode: ");
				scanf("%d", &entered_password);
				if(entered_password == 1234) //correct password exit while loop
				{
					flag_password = 1;
					printf("Correct password!\n\n");
				}
				
				else //wrong password loop again 
				{
					wrong_psw_count++;
					printf("Incorrect password! (%d trials remaining)\n\n", (3-wrong_psw_count));
				}
				
			}
			
			u8 choosed_option=99; //initializing to avoid garbage value with 0
			
			while(choosed_option!=0) //main menu of admin mode
			{
				system("cls");
				// printf("%d", head->ID);
				printf("What do you want to do?\n");
				printf("-----------------------\n\n");
				printf("1.Add new patient record.\n");
				printf("2.Edit patient record.\n");
				printf("3.Reserve a slot with the doctor.\n");
				printf("4.Cancel reservation.\n");
				printf("5.View clients data.\n");
				printf("0.Exit program.\n");
				printf("8.Import data.\n"); //for debug purposes only
				printf("9.Export data.\n"); //for debug purposes only
				printf("Your entry: ");
				scanf("%d", &choosed_option);
				
				switch(choosed_option) //do choosed option
				{
					case 1: //Add new patient record
						
						insert_new_record();
					break;
					
					case 2: //Edit patient record
						edit_patient_record();
					break;
					
					case 3: //Reserve a slot with the doctor.
						
					break;
					
					case 4: //Cancel reservation.
						
					break;
					
					case 5: //Cancel reservation.
						display_as_table();
					break;
					
					case 0: //Exit program
						exit_app();
					break;
					
					case 9:
						export_patients_data();
					break;
					
					case 8:
						import_patients_data();
					break;
					
					default:
						printf("\nWrong entry\n\n");
					break;
				}
			}
		}
		
		else if(mode==2) //user mode
		{
		u8 choosed_option=99; //initializing to avoid garbage value with 0
		
		while(choosed_option!=0) //main menu of user mode
		{
			system("cls");
			printf("What do you want to do?\n");
			printf("-----------------------\n\n");
			printf("1.View patient record.\n");
			printf("2.View today's reservations.\n");
			printf("0.Logout of user mode.\n");
			printf("Your entry: ");
			scanf("%d", &choosed_option);
			
			switch(choosed_option)
			{
				case 1:
					u32 patient_ID;
					system("cls");
					printf("Enter patient ID to show his/her information: ");
					scanf("%d", &patient_ID);
					if(unique_ID_check(patient_ID))
					{
						printf("Error! ID was not found.\n");
						printf("Press any key to continue...");
						getch();
						break;
					}
					for(patient *index = head;index!=NULL;index=index->next)
					{
						if(index->ID == patient_ID)
						{
							display_single_node(index);
							printf("Press any key to continue...");
							getch();
							break;
						}
					}
				break;
				
				case 2:
				
				break;
				
				default:
					printf("\nWrong entry\n\n");
				break;
			}
		}
	}
	}
	
}