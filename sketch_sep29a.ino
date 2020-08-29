/*****************************************************************************
 *****************************************************************************
 * @author Tianyu Shen
 * @date   Mon Oct 7 2019
 *****************************************************************************
 *****************************************************************************/
unsigned long starttime;
unsigned long stoptime;
unsigned long looptime;
int TrigPin=11;
int EchoPin=10;
float distance;
int Rpin = 3;
int Gpin = 5;
int Bpin = 6;
int button=7;
int redled=2;
int x=0;
int y=0;
int z=0;
int a=0;
int b=0;
int c=0;
long int ti_me=0;
int bu_tt=0;
int bu_tt2=0;
int laststate=0;
int clickclick=0;
long int xuanzeshijian=1800000;//初始设定闹铃时间
int reset=0;//超声传感器重置时的防抖
int dis_state=0;//发光时的防抖
int dis_state_old;
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(TrigPin,OUTPUT);
  pinMode(EchoPin, INPUT);
  pinMode(Rpin ,  OUTPUT);
  pinMode(Gpin ,  OUTPUT);
  pinMode(Bpin ,  OUTPUT);
  pinMode(button,  INPUT);
  pinMode(redled,OUTPUT);
}
void loop()
{
  //put your main code here, to run repeatedly:
  starttime = millis();//开始的时间
 
    
  //玩乐模块
  digitalWrite(TrigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin,LOW);
  distance=pulseIn(EchoPin,HIGH)/58.0;
//监视参数
  Serial.print(ti_me);
  Serial.print(' ');
  Serial.print(distance);
  Serial.print(' ');
  Serial.print(xuanzeshijian);
  Serial.print('\n');
  bu_tt=digitalRead(button);

  if(bu_tt==1)
  {
    digitalWrite(redled,HIGH);
  }
  else
  digitalWrite(redled,LOW);
  if(bu_tt!=laststate)//按钮需要防抖
  {
    delay(20);
    bu_tt2=digitalRead(button);
    if(bu_tt2==bu_tt)
    {
      laststate=bu_tt;
      clickclick++;
    }
  }
  if(clickclick==2)
  {
    clickclick=0;
    xuanzeshijian=xuanzeshijian+1800000;//每按一下按钮加的时间
  }
  if(distance>2800||distance<=4)//①超声传感器防抖，状态改变瞬间会有>2800的瞬时值
                   //②超声传感器被完全遮挡时测距会>3000cm
  {
      ti_me=0;//重置计时
    xuanzeshijian=1800000;//重置倒计时设定时间
    reset=0;
  }
  
  
  
  if(ti_me<xuanzeshijian)
  {
      
 
  if(distance<=4||distance>40)
  {
   dis_state=0; 
  }
  else
  dis_state=1;
 
  
  
  
  
  if(dis_state==0)//熄灯
  {
     analogWrite(Rpin, 0);
     analogWrite(Gpin, 0);
     analogWrite(Bpin, 0);
  }
  
   

    
    
  else
    {
      analogWrite(Rpin, x);
      analogWrite(Gpin, y);
      analogWrite(Bpin, z);
      
    }
    
   
   {//渐变光子模块
     if(x>230)a=0;
     if(x<20)a=1;
     if(y>230)b=0;
     if(y<20)b=1;
     if(z>230)c=0;
     if(z<20)c=1;
   
     if(a==0)
     {x=x-6;}
     if(a==1)
     {x=x+6;}
     if(b==0)
     {y=y-9;}
     if(b==1)
     {y=y+9;}    
     if(c==0)
     {z=z-15;}  
     if(c==1)
     {z=z+15;}
   }
   delay(1);
    
   if(distance>15&&distance<40)
    {
      delay((distance-15)*5);
      
    }
    }
else
   //闹钟模块
  {
      analogWrite(Rpin, 0);
      analogWrite(Gpin, 0);
      analogWrite(Bpin, 0);
      delay(100);
      analogWrite(Rpin, x);
      analogWrite(Gpin, y);
      analogWrite(Bpin, z);
      delay(100);
       {//渐变光子模块
     if(x>200)a=0;
     if(x<40)a=1;
     if(y>200)b=0;
     if(y<40)b=1;
     if(z>240)c=0;
     if(z<40)c=1;
   
     if(a==0)
     {x=x-30;}
     if(a==1)
     {x=x+30;}
     if(b==0)
     {y=y-30;}
     if(b==1)
     {y=y+30;}    
     if(c==0)
     {z=z-30;}  
     if(c==1)
     {z=z+30;}
   }
  }

   stoptime = millis();
   looptime = stoptime - starttime;//结束的时间
   ti_me=ti_me+looptime;
}
