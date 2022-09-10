 
/****************************************************************************
 ****************************************************************************
 *******************   SWC    :        ADMIN.c           ********************                            
 *******************    By    : Youssef Mostafa Mohamed  ********************                            
 *******************   Date   :       21/8/2022          ********************                           
 *******************  Version :          V1.0            ********************                           
 ****************************************************************************
 ***************************************************************************/



#include "STD_Types.h"
#include "private.h"
#include "Admin.h"
#include <stdio.h>
#include <stdlib.h>

void adminmenue(){
    printf("|=============================================|\n");
    printf("|                 |ADMIN MENU|                |\n");            
    printf("|                 ------------                |\n");             
    printf("|                                             |\n");
    printf("|       1 -> Add a new patient record         |\n");
    printf("|       2 -> Edit patient record.             |\n");
    printf("|       3 -> Reserve a slot with the doctor.  |\n");
    printf("|       4 -> Cancel reservation.              |\n");
    printf("|       5 -> Exit admin mode.                 |\n");
    printf("|                                             |\n");
    printf("|=============================================|\n");

}

/****************************************************************/

void suggest_id(st_patient** first){
  char sug[5];
  int id=0;
  for(int i =0;i<5;){
    if (check_id(first,id)==NULL){
      sug[i]=id;
      i++;
      id++;
    }
    else
      id++;
    }
  printf("\nhere is some suggested id: <");
  for(int i =0;i<5;i++)
    printf(" %d",sug[i]);

  printf(" >\nyour id:");
}

/****************************************************************/

enum Error_status log_in(u16 pass){
  if(pass == password)
    return login;
  return wrong_pass;
}

/****************************************************************/

enum Error_status add_patient_record(st_patient **first, s16 id, u8* name, s16 age, u8 gender){
  st_patient* patient_pointer = check_id(first,id);
  if(patient_pointer != NULL)
    return invalid_id;
  else if (id<0)
    return negative_id;
  else if (age <0 )
    return invalid_Age;
  else if (gender != 'F' && gender !='f' && gender != 'm' && gender !='M')
    return invalid_gender;
  if (*first == NULL) {
     (*first) = (st_patient*) malloc(sizeof(st_patient));
     (*first)->id =id;
     (*first)->age=age;
     (*first)->gender=gender;
     for(int i =0;i<75;i++)
        (*first)->name[i]=name[i];
	   (*first)->slot=0;
   	 (*first)->next = NULL;
   	 (*first)->prev = NULL;
  }else{
    st_patient *New = (st_patient *)malloc(sizeof(st_patient));
	  (New)->id=id;
    (New)->age=age;
    (New)->gender=gender;
    for(int i =0;i<75;i++)
      (New)->name[i]=name[i];
    (New)->slot=0;
	  (New)->next = NULL;
    st_patient *Last = *first;
    while (Last->next != NULL)
      Last = Last->next;
    Last->next = New;
    New->prev = Last;
   }
	return completed_add;
}

/***************************************************************/

st_patient *check_id(st_patient **first, s16 id){
	st_patient *patient_pointer =*first;
	while (patient_pointer!=NULL){
		if(patient_pointer->id==id){
			return patient_pointer;
		}
		patient_pointer=patient_pointer->next;
	}
	return NULL;
}

/****************************************************************/

void Editmenue(){
    printf("|=============================================|\n");
    printf("|                 |Edit MENU|                 |\n");            
    printf("|                 -----------                 |\n");             
    printf("|                                             |\n");
    printf("|          1 -> Change ID                     |\n");
    printf("|          2 -> Change Age                    |\n");
    printf("|          3 -> Change Name                   |\n");
    printf("|          4 -> Change Gender                 |\n");
    printf("|                                             |\n");
    printf("|=============================================|\n");
}

/****************************************************************/

enum Error_status change_name(st_patient* patient_pointer, u8* name){
  for(int i =0;i<100;i++)
    (patient_pointer)->name[i]=name[i];
  return completed_name;
}

/****************************************************************/

enum Error_status change_age (st_patient* patient_pointer, s16 age){
  if (age <0)
    return invalid_Age;
  (patient_pointer)->age=age;
  return completed_age;
}

/****************************************************************/

enum Error_status change_gender(st_patient * patient_pointer ,u8 gender){
  if(gender != 'M' && gender!='m'&& gender!='F'&& gender!='f')
    return invalid_gender;
  (patient_pointer)->gender=gender;
  return completed_gender;
}

/****************************************************************/

enum Error_status change_id(st_patient ** first ,st_patient* patient_pointer ,s16 id ){
  st_patient* temp =check_id(first,id);
  if(temp==NULL){
    patient_pointer->id=id;
    return completed_id;
  }
  else 
    return invalid_id;
}

/****************************************************************/

enum Error_status reserve_slot(st_patient* patient_pointer, u8* slots_reserve, s16 id, u8 slot_number){
     if(slot_number>5 || slot_number <1 || slots_reserve[slot_number-1] !=0 )
       return invalid_slot;
        patient_pointer->slot=slot_number;
        slots_reserve[slot_number-1]=1;
    return completed_reserve;
 }

/****************************************************************/

enum Error_status cancel_reservation(st_patient* patient_pointer, u8* slots_reserve, s16 id){
			slots_reserve[patient_pointer->slot-1]=0;
			patient_pointer->slot=0;
      return completed_cancel;
}


