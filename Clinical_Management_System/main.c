 
/****************************************************************************
 ****************************************************************************
 *******************   SWC    :        MAIN.c            ********************                            
 *******************    By    : Youssef Mostafa Mohamed  ********************                            
 *******************   Date   :       21/8/2022          ********************                           
 *******************  Version :          V1.0            ********************                           
 ****************************************************************************
 ***************************************************************************/


#include "STD_Types.h"
#include "private.h"
#include <stdio.h>
#include <stdlib.h>
#include "main_func.h"



void main(){
  st_patient* first=NULL;
  while(1){
    Error_status Es=0;
    mainmenue();
    u8 mode;
    printf("your choice:");
    scanf(" %c",&mode);
    if(mode=='A'||mode=='a')
       Es = Admin(&first);
    else if(mode=='u'||mode=='U')
       Es = User(&first);
    else if(mode=='q'||mode=='Q'){
      printf("Thank you.\n");
      return;
    }
    else
      printf("Invalid input\n");
    if(Es==1&& (mode=='A'||mode=='a'))
      printf("you exit Admin mode.\n");
    else if(Es==1&&(mode=='u'||mode=='U'))
      printf("you exit User mode.\n");
    else if(Es==2)
      printf("wrong password,no more trails.\n");
    else if(Es==3)
      printf("ID changed Successfully.\n");
    else if(Es==4)
      printf("Name changed Successfully.\n");
    else if(Es==5)
      printf("Age changed Successfully.\n");
    else if(Es==6)
      printf("Gender changed Successfully.\n");
    else if(Es==7)
      printf("patient Added SUccessfully.\n");
    else if(Es==8)
      printf("Slot reserved Sucessfully.\n");
    else if(Es==9)
      printf("Reservation Canceled Successfully.\n");
    else if(Es==10)
      printf("invalid OP.\n");
    else if(Es==11)
      printf("invalid ID.\n");
    else if(Es==12)
      printf("invalid Slot.\n");
    else if(Es==13)
      printf("Age Can't be negative number.\n");
    else if(Es==14)
      printf("invalid input for gender.\n");
    else if(Es==15)
      printf("ID can't be negative number.\n");
  }
}

