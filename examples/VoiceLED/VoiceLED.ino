/*============================================================

 *	Copyright:	DFRobot
 *	name:		VoiceLED.ino——Voice Recognition模块样例程序
 *      function:       通过语音控制LED灯亮灭
 *	Author:		Kelvin 
 *	Date:		2014-8-11
 
===========================================================*/
#include <VoiceRecognition.h>
VoiceRecognition Voice;
#define Led 8//定义Led引脚为8

void setup() {
    Serial.begin(9600);
    pinMode(Led,OUTPUT);//初始化LED引脚为输出模式
    digitalWrite(Led,LOW);//LED引脚低电平
    
    Voice.init();//初始化VoiceRecognition模块   
    Voice.addCommand("kai deng",0);//添加指令，参数（指令内容，指令标签（可重复））
    Voice.addCommand("guan deng",1);//添加指令，参数（指令内容，指令标签（可重复））
    Voice.start();//开始识别
}
void loop() {
  switch(Voice.read())//判断识别内容，在有识别结果的情况下Voice.Read()会返回该指令标签，否则返回-1
  {
    case 0://若是指令“kai deng”
	digitalWrite(Led,HIGH);//点亮LED
	Serial.println("received'kai deng',command flag'0'");//串口发送received"kai deng",command flag"0"
    break;
    case 1://若是指令“guan deng”
	digitalWrite(Led,LOW);//熄灭LED
	Serial.println("received'guan deng',command flag'1'");//串口发送"received"guan deng",command flag"1"
    break;   
  }
}
