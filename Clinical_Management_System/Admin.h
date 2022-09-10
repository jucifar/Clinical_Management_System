 
/****************************************************************************
 ****************************************************************************
 *******************   SWC    :        ADMIN.H           ********************                            
 *******************    By    : Youssef Mostafa Mohamed  ********************                            
 *******************   Date   :       21/8/2022          ********************                           
 *******************  Version :          V1.0            ********************                           
 ****************************************************************************
 ***************************************************************************/


#ifndef ADMIN_H
#define ADMIN_H

void adminmenue();
void suggest_id(st_patient** first);
void Editmenue();
enum Error_status add_patient_record(st_patient **first, s16 id, u8* name, s16 age, u8 gender);
enum Error_status log_in(u16 pass);
st_patient *check_id(st_patient **first, s16 id);
enum Error_status change_name(st_patient* patient_pointer, u8* name);
enum Error_status change_age (st_patient* patient_pointer, s16 age);
enum Error_status change_gender(st_patient * patient_pointer ,u8 gender);
enum Error_status change_id(st_patient ** first ,st_patient* patient_pointer ,s16 id );
enum Error_status reserve_slot(st_patient* patient_pointer, u8* slots_reserve, s16 id, u8 slot_number);
enum Error_status cancel_reservation(st_patient* patient_pointer, u8* slots_reserve, s16 id);

#endif
