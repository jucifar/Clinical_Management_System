 
/****************************************************************************
 ****************************************************************************
 *******************   SWC    :        Main_Func.c       ********************                            
 *******************    By    : Youssef Mostafa Mohamed  ********************                            
 *******************   Date   :       21/8/2022          ********************                           
 *******************  Version :          V1.0            ********************                           
 ****************************************************************************
 ***************************************************************************/


#include "STD_Types.h"
#include "private.h"
#include <stdio.h>
#include <stdlib.h>
#include "Admin.h"
#include "User.h"
#include "main_func.h"




void mainmenue(){

        printf("|=============================================|\n");
        printf("|                 |MAIN MENU|                 |\n");
        printf("|                 -----------                 |\n");
        printf("|                                             |\n");
        printf("|          A -> Enter admin mode.             |\n");
        printf("|          U -> Enter user mode.              |\n");
        printf("|          Q -> Quit.                         |\n");
        printf("|                                             |\n");
        printf("|=============================================|\n");
}

/****************************************************************/

enum Error_status Admin(st_patient** first){
      u8 flag=0,counter=0;;
      u16 pass;
      printf("Please Enter The password to enter Admin mode:");
      while (counter<3){
      scanf(" %hd",&pass);
      Error_status Es =log_in(pass);
      if(Es ==0 ){
        flag=1;
        break;
      }
      counter++;
      printf("Wrong password please Try again you have %d more times.", 3-counter); 
      if(counter==3)
        printf("\n");
      }
      if (flag) {
        u8 op;
        adminmenue();
        printf("your choice:");
        scanf(" %hhd", &op);
        switch(op){
          case 1:{
              Error_status Es=0;
              u8 name[100],gender;
              s16 id,age; 
              printf("Please Enter The New patient Name:");
              scanf(" %[^\n]s",name);
              printf("please Enter The New patient id (Must be  unique) ");
              suggest_id(first);
              scanf(" %hd",&id);
              printf("Please Enter The New patient age (Must be greater than 0):");
              scanf(" %hd",&age);
              printf("Please Enter The New patient gender (M for Male F for female):");
              scanf(" %c",&gender);
              Es=(add_patient_record(first,id,name,age,gender));
              return Es;
          }
          case 2:{
              Error_status Es=0;
              s16 id,age;
              u8 name[100],gender,op;
              printf("Please Enter the patient id:");
              scanf(" %hd",&id);
              st_patient* patient_pointer = check_id(first,id);
              if(patient_pointer!=NULL){
                Editmenue();
                printf("Your choice:");
                scanf(" %hhd",&op);
                switch(op){
                  case 1:{
                   printf("Please Enter The New patient id ");
                   suggest_id(first);
                   scanf(" %hd",&id);
                   Es=  (change_id(first,patient_pointer,id));
                   return Es;
                   break;
                    }
                 case 2:{
                   printf("Please Enter The New patient age:");
                   scanf(" %hd",&age);
                   Error_status Es=  (change_age(patient_pointer,age));
                   return Es;
                   break;
                    }  
                 case 3:{
                    printf("Please Enter The New patient Name:");
                    scanf(" %[^\n]s",name);
                    Error_status Es=  (change_name(patient_pointer,name));
                    return Es;
                    break;
                    }
                 case 4:{
                    printf("Please Enter The New patient gender:");
                    scanf(" %c",&gender);
                    enum Error_status Es=  (change_gender(patient_pointer,gender));
                    return Es;
                    break;
                    }
                 default: {return invalid_op; break;}
                }
            }else{return invalid_id;}
          }
        case 3:{
            Error_status Es=0;
            s16 id;
            u8 slot_number;
            printf("Please Enter The patient id to reserve a slot:");
            scanf(" %hd",&id);
            st_patient* patient_pointer= check_id(first,id);
            if(patient_pointer !=NULL){
              if(patient_pointer->slot != 0){
                u8 j= patient_pointer->slot,op;
                printf("you already reserve this slot < %s > do you want to change ?\npress 1 to change \npress 0 to keep it \nyour choice:",*(slots+j-1));
                scanf(" %hhd",&op);
                if(op==0)
                  printf("You keeped this slot < %s >\n",*(slots+j-1));
                else if(op==1){
                  slots_reserve[(patient_pointer->slot)-1]=0;
                  patient_pointer->slot=0;
                  printf("These slots are avaliable for you");
                  for (int i =0;i<5;i++){
                    if(slots_reserve[i]==0)
                      printf(" \n %d - %s ",i+1,*(slots+i));  
                  }
                  printf("\nplease Enter slot number to reserve:");
                  scanf(" %hhd",&slot_number);
                  Es = reserve_slot(patient_pointer,slots_reserve,id,slot_number);
                  if(Es==8)
                     printf("you change your slot and reserve this slot < %s > \n",*(slots+slot_number-1));
                  else 
                    return Es;
                }
                else
                  return invalid_op;
              }else if (patient_pointer->slot==0 ){
                  printf("These slots are avaliable for you");
                  for (int i =0;i<5;i++){
                    if(slots_reserve[i]==0)
                      printf(" \n %d - %s ",i+1,*(slots+i));  
                  }
                  printf("\nplease Enter slot number to reserve:");
                  scanf(" %hhd",&slot_number);
                  Error_status Es = reserve_slot(patient_pointer,slots_reserve,id,slot_number);
                  if(Es==8)
                     printf("you reserve this slot < %s > \n",*(slots+slot_number-1));
                  else 
                    return Es;
                }
          }else return invalid_id;
               break;
               }
        case 4:{
                s16 id;
                printf("please enter the patient id to cancel the reservation:");
                scanf(" %hd",&id);
                st_patient* patient_pointer =check_id(first,id);
                if(patient_pointer != NULL)
                  if(patient_pointer->slot==0)
                    printf("There are No reservation to cancel.\n");
                  else{
                    cancel_reservation(patient_pointer, slots_reserve, id);
                    printf("Resevation Canceled SUccessfully.\n");
                  }
                 else 
                  return invalid_id;
               break;
               }
          case 5: return quit;break;
          default: return invalid_op;break;
        }

      }else
        return wrong_pass;
}

/****************************************************************/

enum Error_status User(st_patient** first){
    Error_status Es;
    usermenue();
    u8 op;
    printf("your choice:");
    scanf(" %hhd",&op);
    if(op==1){
      s16 id;
      printf("please enter patient id:");
      scanf(" %hd",&id);
      Es=view_patient_Record(first,id);
    }
    else if(op==2)
      view_today_reservations(first);
    else if(op==3)
      return quit;
    else 
      return invalid_op;
    return Es;
}

