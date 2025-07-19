
#define in1 7
#define in2 8
#define in3 9
#define in4 10
#define ena 6
#define enb 11

#define OUT1 5
#define OUT2 4
#define OUT3 3
#define OUT4 2
#define OUT5 12

int giatri1, giatri2, giatri3, giatri4, giatri5;

void setup() 
{
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);

  pinMode(OUT1, INPUT); //Cảm biến nhận tín hiệu
  pinMode(OUT2, INPUT);
  pinMode(OUT3, INPUT);
  pinMode(OUT4, INPUT);
  pinMode(OUT5, INPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  giatri1 = digitalRead(5) ; //Đọc giá trị cảm biến s1 và gán vào biến giatri1
  giatri2 = digitalRead(4);
  giatri3 = digitalRead(3);
  giatri4 = digitalRead(2);
  giatri5 = digitalRead(12);

  Serial.print("OUT1: ");
  Serial.print(giatri1); Serial.print(" ");
  Serial.print("OUT2: ");
  Serial.print(giatri2); Serial.print(" ");
  Serial.print("OUT3: ");
  Serial.print(giatri3); Serial.print(" ");
  Serial.print("OUT4: ");
  Serial.print(giatri4); Serial.print(" ");
  Serial.print("OUT5: ");
  Serial.print(giatri5); Serial.print(" ");

  if((giatri1 == 1) && (giatri2 == 1) && (giatri3 == 0) && (giatri4 == 1) && (giatri5 == 1)){toi();}
  
  if((giatri1 == 1) && (giatri2 == 0) && (giatri3 == 0) && (giatri4 == 0) && (giatri5 == 1)) // Gặp line lớn hơn rẻ phải xong dừng
  {
    PHAI();
    delay(1200);
    dung();
    delay(5000);  
  }
  if((giatri1 == 0) && (giatri2 == 0) && (giatri3 == 0) && (giatri4 == 0) && (giatri5 == 0)) // Gặp ngã 3 rẻ trái
  {
    TRAI();
    delay(1500);
  }


  if((giatri1 == 1) && (giatri2 == 0) && (giatri3 == 1) && (giatri4 == 1) && (giatri5 == 1)){TRAI();}
  if((giatri1 == 0) && (giatri2 == 1) && (giatri3 == 1) && (giatri4 == 1) && (giatri5 == 1)){TRAI();}
  if((giatri1 == 1) && (giatri2 == 0) && (giatri3 == 0) && (giatri4 == 1) && (giatri5 == 1)){TRAI();}
  if((giatri1 == 0) && (giatri2 == 0) && (giatri3 == 1) && (giatri4 == 1) && (giatri5 == 1)){TRAI();}
  if((giatri1 == 0) && (giatri2 == 0) && (giatri3 == 0) && (giatri4 == 1) && (giatri5 == 1)){TRAI();}
  if((giatri1 == 0) && (giatri2 == 0) && (giatri3 == 0) && (giatri4 == 0) && (giatri5 == 1)){TRAI();}

  if((giatri1 == 1) && (giatri2 == 1) && (giatri3 == 1) && (giatri4 == 0) && (giatri5 == 1)){PHAI();}
  if((giatri1 == 1) && (giatri2 == 1) && (giatri3 == 1) && (giatri4 == 1) && (giatri5 == 0)){PHAI();}  
  if((giatri1 == 1) && (giatri2 == 1) && (giatri3 == 0) && (giatri4 == 0) && (giatri5 == 1)){PHAI();}
  if((giatri1 == 1) && (giatri2 == 1) && (giatri3 == 0) && (giatri4 == 0) && (giatri5 == 0)){PHAI();}
  if((giatri1 == 1) && (giatri2 == 0) && (giatri3 == 0) && (giatri4 == 0) && (giatri5 == 0)){PHAI();}
  if((giatri1 == 1) && (giatri2 == 1) && (giatri3 == 1) && (giatri4 == 0) && (giatri5 == 0)){PHAI();}

  if((giatri1 == 1) && (giatri2 == 1) && (giatri3 == 1) && (giatri4 == 1) && (giatri5 == 1))
  {
    dung();
    delay(300);
    lui();
    delay(800);
  }


} 

void toi()
{
  analogWrite(ena, 70);
  analogWrite(enb, 65);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void TRAI()
{
  analogWrite(ena, 90);
  analogWrite(enb, 0);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void PHAI()
{
  analogWrite(ena, 0);
  analogWrite(enb, 90);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void dung()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void lui()
{
  analogWrite(ena, 70);
  analogWrite(enb, 65);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
