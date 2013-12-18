/* Nicolas Kniebihli INP-T ENSEEIHT */

#include <stdlib.h>
#include <stdio.h>

#include "log.h"

void log_init(){
  fichier = NULL;

  fichier = fopen("log.out","w");
  if(fichier == NULL){
    perror("erreur à l'ouverture\n");
  } else {
    fprintf(fichier,"time rota_accel_p rota_accel_q rota_accel_r rota_speed_p rota_speed_q rota_speed_r rota_pos_p rota_pos_q rota_pos_r lin_accel_x lin_accel_y lin_accel_z lin_speed_x lin_speed_y lin_speed_z ned_accel_x ned_accel_y ned_accel_z ned_speed_x ned_speed_y ned_speed_z ned_pos_x ned_pos_y ned_pos_z\n");
  }

}

void log_close(){
  fclose(fichier);
}

void log_add(const char * string){
  fputs(string,fichier);
}
