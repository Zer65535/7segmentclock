#include <FlexiTimer2.h>
int i=0;
int j=0;
static int Num[4]={5,1,0,0};
//static bool dot=1;
void setup() {
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT);
  pinMode(13,OUTPUT);
  //pinMode(10,OUTPUT);

  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  
  digitalWrite(A0,1);
  digitalWrite(A1,1);
  digitalWrite(A2,1);
  digitalWrite(A3,1);
  digitalWrite(A4,1);
  digitalWrite(A5,1);
  digitalWrite(13,1);
  //digitalWrite(10,1);

  digitalWrite(6,0);
  digitalWrite(7,0);
  digitalWrite(8,0);
  digitalWrite(9,0);

  FlexiTimer2::set(1005,second);
  FlexiTimer2::start();

  attachInterrupt(0, Num_plus, FALLING);
  attachInterrupt(1, Num_less, FALLING);

}
void Num_plus(){
  refresh();
}

void Num_less(){
  if(Num[0]>0){//分个位
    Num[0]--;
  }
  else{
    Num[0]=9;
    if(Num[1]>0){//分十位
      Num[1]--;
    }
    else{
      Num[1]=5;
      if(Num[3]!=0){//时个位
        if(Num[2]>0){
          Num[2]--;
        }
        else{
          Num[2]=9;
          Num[3]--;
          goto lable;
        }
      }
      if(Num[3]==0){
        if(Num[2]>0){
          Num[2]--;
        }
        else{
          Num[2]=3;
          Num[3]=2;
        }
      }
        
    }
  }
lable: {;}
}


void second(){
  j++;
  if(j==59){
    j=0;
    refresh();
  }
}

void refresh(){
  if(Num[0]<9){//分个位
    Num[0]++;
  }
  else{
    Num[0]=0;
    if(Num[1]<5){//分十位
      Num[1]++;
    }
    else{
      Num[1]=0;
      if(Num[3]!=2){//时个位
        if(Num[2]<9){
          Num[2]++;
        }
        else{
          Num[2]=0;
          Num[3]++;
          goto lable;
        }
      }
      if(Num[3]==2){
        if(Num[2]<3){
          Num[2]++;
        }
        else{
          Num[2]=0;
          Num[3]=0;
        }
      }
        
    }
  }
lable: {;}
}

void loop() {
if(i>3){i=0;}
segment_Num(Num[i]);
segment_Add(i);
delay(1);
i++;
}

void segment_Add(int Add){
    switch(Add){
      case 0 :{
        digitalWrite(6,1);
        digitalWrite(7,0);
        digitalWrite(8,0);
        digitalWrite(9,0);
        break;
      }
      case 1 :{
        digitalWrite(6,0);
        digitalWrite(7,1);
        digitalWrite(8,0);
        digitalWrite(9,0);
        break;
      }
      case 2 :{
        digitalWrite(6,0);
        digitalWrite(7,0);
        digitalWrite(8,1);
        digitalWrite(9,0);
        break;
      }
      case 3 :{
        digitalWrite(6,0);
        digitalWrite(7,0);
        digitalWrite(8,0);
        digitalWrite(9,1);
        break;
      }
    }
}

void segment_Num(int Num){
  switch(Num){
    case 0 :{
      digitalWrite(A0,0);
      digitalWrite(A1,0);
      digitalWrite(A2,0);
      digitalWrite(A3,0);
      digitalWrite(A4,0);
      digitalWrite(A5,0);
      digitalWrite(13,1);
      break;
    }
    case 1 :{
      digitalWrite(A0,1);
      digitalWrite(A1,0);
      digitalWrite(A2,0);
      digitalWrite(A3,1);
      digitalWrite(A4,1);
      digitalWrite(A5,1);
      digitalWrite(13,1);
      break;
    }
    case 2 :{
      digitalWrite(A0,0);
      digitalWrite(A1,0);
      digitalWrite(A2,1);
      digitalWrite(A3,0);
      digitalWrite(A4,0);
      digitalWrite(A5,1);
      digitalWrite(13,0);
      break;
    }
    case 3 :{
      digitalWrite(A0,0);
      digitalWrite(A1,0);
      digitalWrite(A2,0);
      digitalWrite(A3,0);
      digitalWrite(A4,1);
      digitalWrite(A5,1);
      digitalWrite(13,0);
      break;
    }
    case 4 :{
      digitalWrite(A0,1);
      digitalWrite(A1,0);
      digitalWrite(A2,0);
      digitalWrite(A3,1);
      digitalWrite(A4,1);
      digitalWrite(A5,0);
      digitalWrite(13,0);
      break;
    }
    case 5 :{
      digitalWrite(A0,0);
      digitalWrite(A1,1);
      digitalWrite(A2,0);
      digitalWrite(A3,0);
      digitalWrite(A4,1);
      digitalWrite(A5,0);
      digitalWrite(13,0);
      break;
    }
    case 6 :{
      digitalWrite(A0,0);
      digitalWrite(A1,1);
      digitalWrite(A2,0);
      digitalWrite(A3,0);
      digitalWrite(A4,0);
      digitalWrite(A5,0);
      digitalWrite(13,0);
      break;
    }
    case 7 :{
      digitalWrite(A0,0);
      digitalWrite(A1,0);
      digitalWrite(A2,0);
      digitalWrite(A3,1);
      digitalWrite(A4,1);
      digitalWrite(A5,1);
      digitalWrite(13,1);
      break;
    }
    case 8 :{
      digitalWrite(A0,0);
      digitalWrite(A1,0);
      digitalWrite(A2,0);
      digitalWrite(A3,0);
      digitalWrite(A4,0);
      digitalWrite(A5,0);
      digitalWrite(13,0);
      break;
    }
    case 9 :{
      digitalWrite(A0,0);
      digitalWrite(A1,0);
      digitalWrite(A2,0);
      digitalWrite(A3,0);
      digitalWrite(A4,1);
      digitalWrite(A5,0);
      digitalWrite(13,0);
      break;
    }
  }
}
