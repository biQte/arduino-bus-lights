#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;
#include <TouchScreen.h>

const int XP=9,XM=A3,YP=A2,YM=8;
const int TS_LEFT=136,TS_RT=907,TS_TOP=110,TS_BOT=942;

TouchScreen ts = TouchScreen(XP,YP,XM,YM,300);
TSPoint tp;

#define MINPRESSURE 50
#define MAXPRESSURE 1000
#define BLACK 0x0000
#define GREEN 0x07E0
#define RED 0xF800
#define WHITE 0xFFFF

bool kabina = false;
bool drzwiBok = false;
bool paka = false;
bool drzwiTyl = false;
bool tylZewn = false;
bool zewn1 = false;
bool zewn2 = false;
bool zewn3 = false;

const int kabinaPin = 37;
const int drzwiBokPin = 35;
const int pakaPin = 33;
const int drzwiTylPin = 31;
const int tylZewnPin = 29;
const int zewn1Pin = 27;
const int zewn2Pin = 25;
const int zewn3Pin = 23;

int16_t BUTTONWIDTH = 110;
int16_t BUTTONHEIGHT = 100;
int16_t SPACEVERTICAL = 10;
int16_t SPACEHORIZONTAL = 60;
int16_t ID;

//extern uint8_t logoFord[];

//void show_logo(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color)
//{
//  int16_t i,j,byteWidth = (w + 7) / 8;
//  uint8_t byte;
//
//  for(j=0;j<h;j++){
//    for(i=0;i<w;i++){
//      if(i & 7) byte <<= 1;
//      else byte = pgm_read_byte(bitmap + j * byteWidth + i / 8);
//      if(byte & 0x80) tft.drawPixel(x+i, y+j, color);
//    }
//  }
//}

void setup(void) {
  // put your setup code here, to run once:
  pinMode(kabinaPin, OUTPUT);
  pinMode(drzwiBokPin, OUTPUT);
  pinMode(pakaPin, OUTPUT);
  pinMode(drzwiTylPin, OUTPUT);
  pinMode(tylZewnPin, OUTPUT);
  pinMode(zewn1Pin, OUTPUT);
  pinMode(zewn2Pin, OUTPUT);
  pinMode(zewn3Pin, OUTPUT);

  digitalWrite(kabinaPin, HIGH);
  digitalWrite(drzwiBokPin, HIGH);
  digitalWrite(pakaPin, HIGH);
  digitalWrite(drzwiTylPin, HIGH);
  digitalWrite(tylZewnPin, HIGH);
  digitalWrite(zewn1Pin, HIGH);
  digitalWrite(zewn2Pin, HIGH);
  digitalWrite(zewn3Pin, HIGH);
  
  int16_t tmp;
  
  tft.reset();
  ID = tft.readID();
  tft.begin(ID);
  Serial.begin(9600);
  tft.setRotation(1);
//  tft.fillScreen(WHITE);
//  show_logo(0,0,logoFord,480,320,BLACK);
  tft.fillScreen(BLACK);
  tft.fillRect(SPACEVERTICAL / 2, SPACEHORIZONTAL / 2, BUTTONWIDTH, BUTTONHEIGHT, GREEN);
  tft.fillRect((SPACEVERTICAL * 1.5) + BUTTONWIDTH, SPACEHORIZONTAL / 2, BUTTONWIDTH, BUTTONHEIGHT, GREEN);
  tft.fillRect((SPACEVERTICAL * 2.5) + (BUTTONWIDTH * 2), SPACEHORIZONTAL / 2, BUTTONWIDTH, BUTTONHEIGHT, GREEN);
  tft.fillRect((SPACEVERTICAL * 3.5) + (BUTTONWIDTH * 3), SPACEHORIZONTAL / 2, BUTTONWIDTH, BUTTONHEIGHT, GREEN);
  tft.fillRect(SPACEVERTICAL / 2, (SPACEHORIZONTAL * 1.5) + BUTTONHEIGHT, BUTTONWIDTH, BUTTONHEIGHT, GREEN);
  tft.fillRect((SPACEVERTICAL * 1.5) + BUTTONWIDTH, (SPACEHORIZONTAL * 1.5) + BUTTONHEIGHT, BUTTONWIDTH, BUTTONHEIGHT, GREEN);
  tft.fillRect((SPACEVERTICAL * 2.5) + (BUTTONWIDTH * 2), (SPACEHORIZONTAL * 1.5) + BUTTONHEIGHT, BUTTONWIDTH, BUTTONHEIGHT, GREEN);
  tft.fillRect((SPACEVERTICAL * 3.5) + (BUTTONWIDTH * 3), (SPACEHORIZONTAL * 1.5) + BUTTONHEIGHT, BUTTONWIDTH, BUTTONHEIGHT, GREEN);
  tft.setCursor(25,75);
  tft.setTextSize(2);
  tft.print(F("Kabina"));
  tft.setCursor(130,75);
  tft.print(F("Drzwi bok"));
  tft.setCursor(275,75);
  tft.print(F("Paka"));
  tft.setCursor(370,75);
  tft.print(F("Drzwi tyl"));
  tft.setCursor(15,235);
  tft.print(F("Tyl zewn"));
  tft.setCursor(145,235);
  tft.print(F("Zewn 1"));
  tft.setCursor(265,235);
  tft.print(F("Zewn 2"));
  tft.setCursor(385,235);
  tft.print(F("Zewn 3"));
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t xpos,ypos;
  tp = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  if(tp.z > MINPRESSURE && tp.z < MAXPRESSURE) {
    xpos = map(tp.y,TS_TOP,TS_BOT,0,tft.width());
    ypos = map(tp.x,TS_RT,TS_LEFT,0,tft.height());
    if(ypos > 30 && ypos < 130){
      if(xpos > 5 && xpos < 115){
        if(!kabina){
          tft.fillRect(SPACEVERTICAL / 2, SPACEHORIZONTAL / 2, BUTTONWIDTH, BUTTONHEIGHT, RED);  
          kabina = true;
          digitalWrite(kabinaPin, LOW);
        } else {
          tft.fillRect(SPACEVERTICAL / 2, SPACEHORIZONTAL / 2, BUTTONWIDTH, BUTTONHEIGHT, GREEN);  
          kabina = false;
          digitalWrite(kabinaPin, HIGH);
        }
        tft.setCursor(25,75);
        tft.print(F("Kabina"));
      } else if(xpos > 125 && xpos < 235){
        if(!drzwiBok){
          tft.fillRect((SPACEVERTICAL * 1.5) + BUTTONWIDTH, SPACEHORIZONTAL / 2, BUTTONWIDTH, BUTTONHEIGHT, RED);
          drzwiBok = true;
          digitalWrite(drzwiBokPin, LOW);
        } else {
          tft.fillRect((SPACEVERTICAL * 1.5) + BUTTONWIDTH, SPACEHORIZONTAL / 2, BUTTONWIDTH, BUTTONHEIGHT, GREEN);
          drzwiBok = false;
          digitalWrite(drzwiBokPin, HIGH);
        }
        tft.setCursor(130,75);
        tft.print(F("Drzwi bok"));
      } else if(xpos > 245 && xpos < 355){
        if(!paka){
         tft.fillRect((SPACEVERTICAL * 2.5) + (BUTTONWIDTH * 2), SPACEHORIZONTAL / 2, BUTTONWIDTH, BUTTONHEIGHT, RED);
         paka = true; 
         digitalWrite(pakaPin, LOW);
        } else {
          tft.fillRect((SPACEVERTICAL * 2.5) + (BUTTONWIDTH * 2), SPACEHORIZONTAL / 2, BUTTONWIDTH, BUTTONHEIGHT, GREEN);
          paka = false; 
          digitalWrite(pakaPin, HIGH);
        }
        tft.setCursor(275,75);
        tft.print(F("Paka"));
      } else if(xpos > 365 && xpos < 475){
        if(!drzwiTyl){
         tft.fillRect((SPACEVERTICAL * 3.5) + (BUTTONWIDTH * 3), SPACEHORIZONTAL / 2, BUTTONWIDTH, BUTTONHEIGHT, RED);
         drzwiTyl = true; 
         digitalWrite(drzwiTylPin, LOW);
        } else {
          tft.fillRect((SPACEVERTICAL * 3.5) + (BUTTONWIDTH * 3), SPACEHORIZONTAL / 2, BUTTONWIDTH, BUTTONHEIGHT, GREEN);
          drzwiTyl = false;
          digitalWrite(drzwiTylPin, HIGH);
        }
        tft.setCursor(370,75);
        tft.print(F("Drzwi tyl"));
      } 
    } else if(ypos > 190 && ypos < 290){
      if(xpos > 5 && xpos < 115){
        if(!tylZewn){
         tft.fillRect(SPACEVERTICAL / 2, (SPACEHORIZONTAL * 1.5) + BUTTONHEIGHT, BUTTONWIDTH, BUTTONHEIGHT, RED);
         tylZewn = true; 
         digitalWrite(tylZewnPin, LOW);
        } else {
          tft.fillRect(SPACEVERTICAL / 2, (SPACEHORIZONTAL * 1.5) + BUTTONHEIGHT, BUTTONWIDTH, BUTTONHEIGHT, GREEN);
          tylZewn = false;
          digitalWrite(tylZewnPin, HIGH);
        }
        tft.setCursor(15,235);
        tft.print(F("Tyl zewn"));
      } else if(xpos > 125 && xpos < 235){
        if(!zewn1){
         tft.fillRect((SPACEVERTICAL * 1.5) + BUTTONWIDTH, (SPACEHORIZONTAL * 1.5) + BUTTONHEIGHT, BUTTONWIDTH, BUTTONHEIGHT, RED);
         zewn1 = true; 
         digitalWrite(zewn1Pin, LOW);
        } else {
          tft.fillRect((SPACEVERTICAL * 1.5) + BUTTONWIDTH, (SPACEHORIZONTAL * 1.5) + BUTTONHEIGHT, BUTTONWIDTH, BUTTONHEIGHT, GREEN);
          zewn1 = false;
          digitalWrite(zewn1Pin, HIGH);
        }
         tft.setCursor(145,235);
         tft.print(F("Zewn 1"));
      } else if(xpos > 245 && xpos < 355){
        if(!zewn2){
         tft.fillRect((SPACEVERTICAL * 2.5) + (BUTTONWIDTH * 2), (SPACEHORIZONTAL * 1.5) + BUTTONHEIGHT, BUTTONWIDTH, BUTTONHEIGHT, RED);
         zewn2 = true; 
         digitalWrite(zewn2Pin, LOW);
        } else {
          tft.fillRect((SPACEVERTICAL * 2.5) + (BUTTONWIDTH * 2), (SPACEHORIZONTAL * 1.5) + BUTTONHEIGHT, BUTTONWIDTH, BUTTONHEIGHT, GREEN);
          zewn2 = false;
          digitalWrite(zewn2Pin, HIGH);
        }
        tft.setCursor(265,235);
        tft.print(F("Zewn 2"));
      } else if(xpos > 365 && xpos < 475){
        if(!zewn3){
          tft.fillRect((SPACEVERTICAL * 3.5) + (BUTTONWIDTH * 3), (SPACEHORIZONTAL * 1.5) + BUTTONHEIGHT, BUTTONWIDTH, BUTTONHEIGHT, RED);
          zewn3 = true;
          digitalWrite(zewn3Pin, LOW);
        } else {
          tft.fillRect((SPACEVERTICAL * 3.5) + (BUTTONWIDTH * 3), (SPACEHORIZONTAL * 1.5) + BUTTONHEIGHT, BUTTONWIDTH, BUTTONHEIGHT, GREEN);
          zewn3 = false;
          digitalWrite(zewn3Pin, HIGH);
        }
        tft.setCursor(385,235);
        tft.print(F("Zewn 3"));
      }
    }
  }

}
