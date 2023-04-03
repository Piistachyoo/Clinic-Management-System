void exit_app(); //quit exit for the system
void insert_new_record(); //Add new patient record
u16 unique_ID_check(u32 sent_ID); //unique ID check
void edit_patient_record(); //edit menu
void import_patients_data(); //reads patients' linked list to patients_data.txt
void export_patients_data(); //saves patients' linked list to patients_data.txt
void display_as_table(); //displays all nodes in linked list in a table
void display_single_node(patient *node); //displays data of a single node in a linked list
void edit_age(u32 ID, u8 new_age); //edit age of user with sent ID
void edit_ID(u32 ID, u32 new_ID); //edit ID of user with sent ID
void edit_gender(u32 ID, u8 new_gender[]); //edit gender of user with sent ID
void edit_name(u32 ID, u8 new_name[]); //edit name of user with sent ID
void reserve_slot(); //reserve a time slot with the doctor
void initialize_timeslots(); //initialize time slots with reserve = false and corresponding time as string
void export_reservations_data(); //saves reservations linked list to reservations_data.txt
void import_reservations_data(); //reads reservations linked list to reservations_data.txt

void insert_new_record_old();