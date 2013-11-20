//Marcas
boolean M0;
boolean M1;
boolean M2;
boolean M3;
boolean M4;
//variables
boolean lec_ok;
boolean error_d;
boolean d_ok;
boolean d_cargado;
boolean tx_ok;

boolean rl_boo;
boolean led_boo;

//datos
int toallas_g;
int toallas_m;
int pequenas_p;



void setup(){
  
M0 = true;
M1 = false;
M2 = false;
M3 = false;
M4 = false;

rl_boo = false;
led_boo = false;


  
}
void loop(){

marcas();

salidas();

entradas();

rl();

led();

ldr();

}

void salidas(){
  if (M0) iniciar_rfid();
  if (M1) analizar_d();
  if (M2) cargar_ldr();
  if (M3){
    inicio_tx();
    rl_boo = false;
    led_boo = false;
  
  } 
  if (M4) {
    inicio_tx();
    rl_boo = true;
    led_boo= true;
  }
}

void entradas(){


}

void marcas(){
  
  if ((M0)&&(lec_ok)){
    M1 = true;
    M0 = false;
  }
  
  if ((M1)&&(error_d)){
    M0 = true;
    M1 = false;
  }
  if ((M1)&&(d_ok)){
    M2 = true;
    M1 = false;
  }
  if ((M1)&&(!d_ok)){
    M3 = true;
    M1 = false;
  }
  
  if ((M2)&&(d_cargado)){
    M4 = true;
    M2 = false;
  }
  
  if ((M3)&&(tx_ok)){
    M0 = true;
    M3 = false;
  }
  
  if ((M4)&&(tx_ok)){
    M0 = true;
    M4 = false;
  }


}
