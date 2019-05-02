/*
 * ********************************************************
 * ********************************************************
 * *************   HAXARD/STROBO 4 MODE   *****************
 * ***  CODE INI DIBUAT OLEH mfahrudinafif89@gmail.com  ***
 * ********************************************************
 * ********************************************************
 */

 
//insialisasi pin led
int led1=8;   
int led2=9;

int button=2;       //pushbutton terhubung dengan pin 2
int buttonState;    //variabel untuk menahan pushbutton
int val;            //variabel untuk membaca status pin
int val2;           //variabel untuk membaca sattus delay

int lightMode=0;             //mode led

void setup()
{
  pinMode(button, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  buttonState=digitalRead(button);
}

void loop() 
{
  val=digitalRead(button);  //membaca nilai input dan menyimpannya di variabel val
  delay(10);
  val2=digitalRead(button); //membaca nilai inputannya lagi untuk memeriksa nilai setelah ditekan
 
  if(val==val2) //untuk membuat kita mendapatkan 2 bacaan yang konsitan 
  {
    if(val!=buttonState) //nilai button state telah berubah
    {
      if(val==LOW) //jika push button di tekan
      {
       if(lightMode==0){lightMode=1; } //jika mode 1
        else
        {if(lightMode==1){lightMode=2;}  //jika mode 2
          else
          {if(lightMode==2){lightMode=3; } //jika mode 3
            else
            { if(lightMode==3){lightMode=4; } //jika mode 4
             else
             {if(lightMode==4){lightMode=0;} //jika mode 0
            }
          }
        }
      }
    }
   buttonState=val;
  }
  }

//menentukan lighMode sesuka kita

  if(lightMode==0)  //mode semua mati
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }

  if(lightMode==1)
  {
    digitalWrite(led2, LOW); //led 2 of
    delay(200);
    digitalWrite(led1, HIGH); //led 1 on
    delay(100);
    digitalWrite(led1, LOW); //led 1 of
    delay(100);
    digitalWrite(led1, HIGH); //led 1 on
    delay(100);
    digitalWrite(led1, LOW); //led 1 of
    delay(100);
    digitalWrite(led1, HIGH); //led 1 on
    delay(100);
    digitalWrite(led1, LOW); //led 1 of
    delay(200);
    digitalWrite(led2, HIGH); //led 2 on
    delay(100);
    digitalWrite(led2, LOW); //led 2 of
    delay(100);
    digitalWrite(led2, HIGH); //led 2 on
    delay(100);
    digitalWrite(led2, LOW); //led 2 of
    delay(100);
    digitalWrite(led2, HIGH); //led 2 on
    delay(100); 
  }

  if(lightMode==2)  //mode 2
  {
    digitalWrite(led2, LOW); //of
    delay(200);
    digitalWrite(led1, HIGH); //on
    delay(100);
    digitalWrite(led1, LOW); //of
    delay(100);
    digitalWrite(led1, HIGH); //on
    delay(100);
    digitalWrite(led1, LOW); //of
    delay(200);
    digitalWrite(led2, HIGH); 
    delay(100);
    digitalWrite(led2, LOW); //of
    delay(100);
    digitalWrite(led2, HIGH); //on
    delay(100);
  }

  if(lightMode==3)  //mode 3
  {
    digitalWrite(led2, LOW);
    digitalWrite(led1, HIGH);
    delay(200);
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    delay(200);
  }

  if(lightMode==4)  //mode 4
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    delay(200);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    delay(200);
  }

}
