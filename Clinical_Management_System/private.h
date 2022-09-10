 
/****************************************************************************
 ****************************************************************************
 *******************   SWC    :        private.h         ********************                            
 *******************    By    : Youssef Mostafa Mohamed  ********************                            
 *******************   Date   :       21/8/2022          ********************                           
 *******************  Version :          V1.0            ********************                           
 ****************************************************************************
 ***************************************************************************/


#ifndef PRIVATE_H
#define PRIVATE_H

#define password 1234

static u8 slots[5][20]={"2pm to 2:30pm",
         "2:30pm to 3pm" ,
         "3pm to 3:30pm",
         "4pm to 4:30pm",
         "4:30pm to 5pm"};
static u8 slots_reserve[5]={0};

typedef struct patient {

  char name[100];
  s16 age;
  s16 id;
  char gender;
  u8 slot;
  struct patient *next;
  struct patient *prev;

} st_patient;

typedef enum Error_status {
  login,
  quit,
  wrong_pass, //error
  completed_id,
  completed_name,
  completed_age,
  completed_gender,
  completed_add,
  completed_reserve,
  completed_cancel,
  //errors
  invalid_op,
  invalid_id,
  invalid_slot,
  invalid_Age,
  invalid_gender,
  negative_id
}Error_status;

#endif
