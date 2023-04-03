/**
 * **Clinic Management System**
 * Author:     Omar Mohamed Yamany
 * Created:    01.01.2023
 * Group ID:   0225112210
 * Student ID: 022511221010
 * Made for IMT School for educational use only
 * All copyrights are reserved
 **/

// you can select "Fold All" from view menu to get better visibility of the functions

#include<stdio.h>
#include<stdlib.h>
#include<string.h> // for strcpy and strcspn
#include<conio.h> // for getch
#include"data_types.h"

extern patient *head; //external pointer from main.c
extern patient *tail; //external pointer from main.c
// time_slot *time_head = NULL; //head of timeslots linked list
// time_slot *time_tail = NULL; //tail of timeslots linkedlist

int exit_app() //quit exit for the system
{
	system("cls");
	printf("Thanks for using our system.");
	printf("\nGood Bye");
	return 0;
}

void import_patients_data() //reads patients' linked list to patients_data.txt
{
	FILE *file = fopen("patients_data.txt","r");
	if (file == NULL)
	{
		printf("Error! Couldn't import data (file not found!)\n");
		return;
	}
	patient n;
	while(fread(&n,sizeof(patient),1,file))
	{
		if(head == NULL) //insert at first
		{
			head = (patient*)malloc(sizeof(patient));
			head->next = NULL;
			head->ID = n.ID;
			strcpy(head -> name,n.name);
			strcpy(head -> gender,n.gender);
			head -> age = n.age;
			tail = head;
			
		}
		else //insert at end
		{
			patient *temp = (patient*)malloc(sizeof(patient));
			tail->next = temp;
			tail = temp;
			temp->next = NULL;
			temp->ID = n.ID;
			strcpy(temp -> name,n.name);
			strcpy(temp -> gender,n.gender);
			temp -> age = n.age;
		}
	}
	fclose(file);
	printf("***Patients' data imported successfully***\n");
}

void export_patients_data() //saves patients' linked list to patients_data.txt
{
	patient *index = head;
	FILE *file = fopen("patients_data.txt","w");
	
	while(index!=NULL)
	{
		fwrite(index,sizeof(patient),1,file);
		index = index->next;
	}
	printf("***Patients' data was saved successfully***\n");
	fclose(file);
}

void display_as_table() //displays all nodes in linked list in a table
{
	printf("***************************************************************************\n");
	printf("*  ID \t\t Age \t Gender \t Name\n*\n");
	for(patient *index = head ; index!=NULL ; index=index->next)
	{
		printf("*  %-10d \t %d \t %-5s \t\t %-10s\n", index->ID, index->age, index->gender, index->name);
	}
	printf("***************************************************************************\n");
	printf("Press any key to continue...");
	getch();
}

void display_single_node(patient *node) //displays data of a single node in a linked list
{
	printf("ID: %d\n", node->ID);
	printf("Name: %s\n", node->name);
	printf("Gender: %s\n", node->gender);
	printf("Age: %d\n\n", node->age);
}

u16 unique_ID_check(u32 sent_ID) //function that returns 0 if ID was found at any node in linked list, returns 1 if ID is unique
{
	patient *index = head;
	while(index!=NULL)
	{
		if(index->ID == sent_ID)
		{
			return 0;
		}
		index = index->next;
	}
	return 1;
}

void insert_new_record() //Add new patient record (inserts at first if head points to null, and inserts at end otherwise)
{
	system("cls");
	printf("Add new patient record\n");
	printf("----------------------\n\n");
	patient *n = (patient*)malloc(sizeof(patient));
	if(head == NULL) //insert at first
	{
		head = n;
		n->next = NULL;
		tail = n;
		printf("Enter ID: ");
		scanf("%d", &n->ID);
		getchar(); //to stop the next fgets from taking \n as input
		// u8 unique_ID_flag;
		// unique_ID_flag = unique_ID_check(n->ID);
		// if(unique_ID_flag==0)
		// {
			// printf("ID is not unique, please try again with another ID\n\n");
			// free(n);
			// printf("Press any key to continue...");
			// getch();
			// return;
		// }
		printf("Enter name: ");
		fgets(n->name,200,stdin);
		n->name[strcspn(n->name, "\n")] = '\0'; //remove \n at the end of the input
		printf("Enter gender: ");
		fgets(n->gender,7,stdin);
		n->gender[strcspn(n->gender, "\n")] = '\0'; //remove \n at the end of the input
		printf("Enter age: ");
		scanf("%d", &n->age);
	}
	else //insert at end
	{
				printf("Enter ID: ");
		scanf("%d", &n->ID);
		getchar(); //to stop the next fgets from taking \n as input
		// u8 unique_ID_flag;
		// unique_ID_flag = unique_ID_check(n->ID);
		if(!unique_ID_check(n->ID))
		{
			printf("ID is not unique, please try again with another ID\n\n");
			free(n);
			printf("Press any key to continue...");
			getch();
			return;
		}
		u16 unique_ID_flag;
		unique_ID_flag = unique_ID_check(n->ID);
		if(unique_ID_flag==0)
		{
			free(n);
			return;
		}
		printf("Enter name: ");
		fgets(n->name,200,stdin);
		n->name[strcspn(n->name, "\n")] = '\0'; //remove \n at the end of the input
		printf("Enter gender: ");
		fgets(n->gender,10,stdin);
		n->gender[strcspn(n->gender, "\n")] = '\0'; //remove \n at the end of the input
		printf("Enter age: ");
		scanf("%d", &n->age);
		tail->next = n;
		tail = n;
		n->next = NULL;
	}
	// export_patients_data(); //save linked list
	printf("Press any key to continue...");
	getch();
	system("cls");
}


void insert_new_record_old() //Add new patient record (inserts at first if head points to null, and inserts at end otherwise)
{
	system("cls");
	printf("Add new patient record\n");
	printf("----------------------\n\n");
	patient *n = (patient*)malloc(sizeof(patient));
	if(head == NULL) //insert at first
	{
		head = n;
		n->next = NULL;
		tail = n;
		printf("Enter ID: ");
		scanf("%d", &n->ID);
		getchar(); //to stop the next fgets from taking \n as input
		printf("Enter name: ");
		fgets(n->name,200,stdin);
		n->name[strcspn(n->name, "\n")] = '\0'; //remove \n at the end of the input
		printf("Enter gender: ");
		fgets(n->gender,7,stdin);
		n->gender[strcspn(n->gender, "\n")] = '\0'; //remove \n at the end of the input
		printf("Enter age: ");
		scanf("%d", &n->age);
	}
	else //insert at end
	{
		printf("Enter ID: ");
		scanf("%d", &n->ID);
		getchar(); //to stop the next fgets from taking \n as input
		printf("%d", n->ID);
		if(!unique_ID_check(n->ID))
		{
			printf("ID is not unique, please try again with another ID\n\n");
			free(n);
			printf("Press any key to continue...");
			getch();
			return;
		}
		printf("%d", n->ID);
		printf("Enter name: ");
		fgets(n->name,200,stdin);
		n->name[strcspn(n->name, "\n")] = '\0'; //remove \n at the end of the input
		printf("Enter gender: ");
		fgets(n->gender,10,stdin);
		n->gender[strcspn(n->gender, "\n")] = '\0'; //remove \n at the end of the input
		printf("Enter age: ");
		scanf("%d", &n->age);
		tail->next = n;
		tail = n;
		n->next = NULL;
	}
	export_patients_data(); //save linked list
	printf("Press any key to continue...");
	getch();
	system("cls");
}

void edit_age(u32 ID, u8 new_age)
{
	for(patient *temp = head;temp!=NULL;temp = temp->next)
	{
		if(temp->ID == ID)
		{
			temp->age = new_age;
			break;
		}
	}
	printf("Patient's age is now changed!\n");
	printf("Press any key to continue...");
	getch();
	system("cls");
	return;
}

void edit_ID(u32 ID, u32 new_ID)
{
	for(patient *temp = head;temp!=NULL;temp = temp->next)
	{
		if(temp->ID == ID)
		{
			temp->ID = new_ID;
			break;
		}
	}
	printf("Patient's ID is now changed!\n");
	printf("Press any key to continue...");
	getch();
	system("cls");
	return;
}

void edit_gender(u32 ID, u8 new_gender[])
{
	for(patient *temp = head;temp!=NULL;temp = temp->next)
	{
		if(temp->ID == ID)
		{
			strcpy(temp->gender, new_gender);
			break;
		}
	}
	printf("Patient's gender is now changed!\n");
	printf("Press any key to continue...");
	getch();
	system("cls");
	return;
}

void edit_name(u32 ID, u8 new_name[])
{
	for(patient *temp = head;temp!=NULL;temp = temp->next)
	{
		if(temp->ID == ID)
		{
			strcpy(temp->name, new_name);
			break;
		}
	}
	printf("Patient's name is now changed!\n");
	printf("Press any key to continue...");
	getch();
	system("cls");
	return;
}

void edit_patient_record() //Edit existing patient record
{
	while(1)
	{
		system("cls");
		printf("Edit mode:\n");
		printf("----------\n");
		u8 choice, found_flag=0;
		u32 entered_ID;
		printf("1.Display all nodes\n");
		printf("2.Choose a node with it's ID\n");
		printf("0.Exit edit mode\n");
		printf("Your entry: ");
		scanf("%d", &choice);
		patient *current = (patient*)malloc(sizeof(patient));
		current = head;
		switch(choice)
		{
			case 1:
				display_as_table();
				printf("\n");
			break;
			
			case 2:
				printf("Enter ID: ");
				scanf("%d", &entered_ID);
				if(unique_ID_check(entered_ID))
				{
					printf("Error! ID not found\n");
					printf("Press any key to continue...");
					getch();
					return;
				}
				printf("ID Found!\n"); 
				printf("---------\n");
				printf("ID: %d\n", current->ID);
				printf("Name: %s\n", current->name);
				printf("Gender: %s\n", current->gender);
				printf("Age: %d\n\n", current->age);
				printf("Pick the data you want to change: \n");
				printf("1.ID\n");
				printf("2.Name\n");
				printf("3.Gender\n");
				printf("4.Age\n");
				printf("0.Cancel\n");
				getchar();
				display_single_node(current);
				printf("Your entry: ");
				scanf("%d", &choice);
				printf("Your entry: ");
				scanf("%d", &choice);
				getchar();
				switch(choice)
				{
					case 1:
						u32 temp_ID;
						printf("Enter patient's ID after edit: ");
						scanf("%d", &temp_ID);
						// edit_age(current->ID,temp_age);
						edit_ID(entered_ID, temp_ID);
					break;
					
					case 2:
						u8 temp_name[200];
						printf("Enter patient's name after edit: ");
						fgets(temp_name,200,stdin);
						temp_name[strcspn(temp_name, "\n")] = '\0'; //remove \n at the end of the input
						edit_name(entered_ID, temp_name);
					break;
					
					case 3:
						u8 temp_gender[10];
						printf("Enter patient's gender after edit: ");
						fgets(temp_gender,10,stdin);
						temp_gender[strcspn(temp_gender, "\n")] = '\0'; //remove \n at the end of the input
						edit_gender(entered_ID, temp_gender);
					break;
					
					case 4:
						u8 temp_age;
						printf("Enter patient's age after edit: ");
						scanf("%d", &temp_age);
						// edit_age(current->ID,temp_age);
						edit_age(entered_ID, temp_age);
					break;
					
					case 0:
						//cancel
					break;
				}
			break;
			
			case 0:
				return;
		}
	}
}
/*
void export_reservations_data()
{
	
}


void initialize_timeslots() //initialize time slots with reserve = false and corresponding time as string
{
	time_slot *slot1 = (time_slot*) malloc(sizeof(time_slot));
	time_slot *slot2 = (time_slot*) malloc(sizeof(time_slot));
	time_slot *slot3 = (time_slot*) malloc(sizeof(time_slot));
	time_slot *slot4 = (time_slot*) malloc(sizeof(time_slot));
	time_slot *slot5 = (time_slot*) malloc(sizeof(time_slot));
	strcpy(slot1->slot_time, "2PM to 2:30PM");
	slot1->reserved_flag = 0;
	slot1->slot_number = 1;
	time_head = slot1;
	slot1->next = slot2;
	
	strcpy(slot2->slot_time, "2:30PM to 3PM");
	slot2->reserved_flag = 0;
	slot2->slot_number = 2;
	slot2 -> next = slot3;
	
	strcpy(slot3->slot_time, "3PM to 3:30PM");
	slot3->reserved_flag = 0;
	slot3->slot_number = 3;
	slot3 -> next = slot4;
	
	strcpy(slot4->slot_time, "4PM to 4:30PM");
	slot4->reserved_flag = 0;
	slot4->slot_number = 4;
	slot4 -> next = slot5;
	
	strcpy(slot5->slot_time, "4:30PM to 5PM");
	slot5->reserved_flag = 0;
	slot5->slot_number = 5;
	slot5 -> next = NULL;
	export_reservations_data();
}

void import_reservations_data()
{
	FILE *file = fopen("reservations_data.txt","r");
	if (file == NULL)
	{
		initialize_timeslots();
		return;
	}
	time_slot n;
	while(fread(&n,sizeof(time_slot),1,file))
	{
		if(time_head == NULL) //insert at first
		{
			time_head = (time_slot*)malloc(sizeof(time_slot));
			time_head->next = NULL;
			time_head->ID = n.ID;
			strcpy(time_head -> slot_time,n.slot_time);
			time_head -> reserved_flag = n.reserved_flag;
			time_head -> slot_number = n.slot_number;
			time_tail = time_head;
			
		}
		else //insert at end
		{
			time_slot *temp = (time_slot*)malloc(sizeof(time_slot));
			time_tail->next = temp;
			time_tail = temp;
			temp->next = NULL;
			temp->ID = n.ID;
			strcpy(temp -> slot_time,n.slot_time);
			temp -> reserved_flag = n.reserved_flag;
			temp -> slot_number = n.slot_number;
		}
	}
	fclose(file);
	printf("***Reservations data imported successfully***\n");
}




void reserve_slot() //reserve a time slot with the doctor
{
	system("cls");
	printf("Reserve a slot with the doctor:\n");
	printf("-------------------------------\n\n");
	printf("Available time slots:\n");
	// if(slot1->reserved_flag==0) //slot is available
	// {
		// printf("1. %s\n", slot1.slot_time);
	// }
	// if(slot2->reserved_flag==0) //slot is available
	// {
		// printf("2. %s\n", slot2.slot_time);
	// }
	// if(slot3->reserved_flag==0) //slot is available
	// {
		// printf("3. %s\n", slot3.slot_time);
	// }
	// if(slot4->reserved_flag==0) //slot is available
	// {
		// printf("4. %s\n", slot4.slot_time);
	// }
	// if(slot5->reserved_flag==0) //slot is available
	// {
		// printf("5. %s\n", slot5.slot_time);
	// }
	
	printf("0. Cancel reservation\n");
	u8 choice;
	printf("Enter slot number to reserve: ");
	scanf("%d", choice);
	
}


*/