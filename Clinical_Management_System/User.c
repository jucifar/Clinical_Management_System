 
/****************************************************************************
 ****************************************************************************
 *******************   SWC    :        User.c            ********************                            
 *******************    By    : Youssef Mostafa Mohamed  ********************                            
 *******************   Date   :       21/8/2022          ********************                           
 *******************  Version :          V1.0            ********************                           
 ****************************************************************************
 ***************************************************************************/


#include "STD_Types.h"
#include "private.h"
#include <stdio.h>
#include <stdlib.h>
#include "User.h"



void usermenue(){

    printf("|=============================================|\n");
    printf("|                 |USER MENU|                 |\n");
    printf("|                 -----------                 |\n");
    printf("|                                             |\n");
    printf("|       1 -> View patient record              |\n");
    printf("|       2 -> View today reservations          |\n");
    printf("|       3 -> Exit user mode                   |\n");
    printf("|                                             |\n");
    printf("|=============================================|\n");
}

/****************************************************************/

Error_status view_patient_Record(st_patient** first,u16 id){
  st_patient *patient_pointer = (*first);
  u8 flag=0;
  while(patient_pointer!=NULL){
    if(patient_pointer->id==id){
      flag=1;
      break;
    }
    patient_pointer=patient_pointer->next;
  }              
  if(flag){
    printf("|=================================================|\n");
    printf("|                 |Patient Record|                |\n");
    printf("|                 ----------------                |\n");
    printf("|                                                 |\n");
    printf("|       patient id     : %d		          |\n",patient_pointer->id);
    printf("|       Patient Name   : %s                  |\n",patient_pointer->name);
    printf("|       Patient Age    : %d                       |\n",patient_pointer->age);
    printf("|       patient gender : %c                        |\n",patient_pointer->gender);
    if(patient_pointer->slot!=0)
      printf("|   patient reserve this slot  < %s >  |\n", *(slots+(patient_pointer->slot)-1));
    else
      printf("|       patient didn't reserve any slot           |\n");
    printf("|                                                 |\n");
    printf("|=================================================|\n");
  }else
    return invalid_id;
}

/****************************************************************/

void view_today_reservations(st_patient** first){
  u8 flag=0;
  st_patient * patient_pointer =(*first);
  while(patient_pointer !=NULL){
    if(patient_pointer->slot !=0){
       if(!flag){
           printf("|=====================================================|\n");
           printf("|                 Today's reservations                |\n");
           printf("|                ---------------------                |\n");
           
       }
           printf("|   This id :%d reserve this slot < %s >    |\n",patient_pointer->id,*(slots+(patient_pointer->slot)-1));
           flag=1;
    }
    patient_pointer=patient_pointer->next;
  }
  if(flag)
          printf("|=====================================================|\n");
  if(!flag)
    printf("There age no reservations for today.\n");
}


