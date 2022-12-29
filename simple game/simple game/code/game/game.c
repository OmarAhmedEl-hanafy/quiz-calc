#include <avr/io.h>
#include "timer.h"
#include "LCD.h"
#include "keypad_driver.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

volatile int flag1=0,flag2=0;

int main(void)
{
        int x;
        keypad_vInit();
        LCD_vInit();
		while (1)
		{
		
			LCD_vSend_string("3+...=8 value=");
			timer_CTC_init_interrupt();
        
				do{                
							   if(flag1>=1000)
							   {
									   flag2=1;
							   }
						   x=keypad_u8check_press();
								_delay_ms(20);
					   }while(x==NOTPRESSED && flag2==0);                        
                                
									if(x==NOTPRESSED)
									{
											_delay_ms(2000);
											LCD_clearscreen();
											LCD_movecursor(2,4);
											LCD_vSend_string("Time over");
									}
									else if(x=='A')
									{
										
										LCD_clearscreen()
									}
									else if (x=='5')
									{
											LCD_vSend_string("5");
											//LCD_clearscreen();
											LCD_movecursor(2,4);
											_delay_ms(20);
											LCD_vSend_string("Well done");
											_delay_ms(50);
											LCD_clearscreen();
											LCD_vSend_string("2+5=... value=");
											do{
													if(flag1>=1000)
													{
															flag2=1;
													}
													x=keypad_u8check_press();
													_delay_ms(20);
											}while(x==NOTPRESSED && flag2==0);
                                        
											if(x==NOTPRESSED)
											{
													LCD_clearscreen();
													LCD_movecursor(2,4);
													LCD_vSend_string("Time over");
											}
											else if (x=='7')
											{
													LCD_vSend_string("7");
													//LCD_clearscreen();
													LCD_movecursor(2,4);
													_delay_ms(30);
													LCD_vSend_string("Well done");
													_delay_ms(50);
													LCD_clearscreen();
													LCD_vSend_string("...*2=6 value=");
													do{
															if(flag1>=1000)
															{
																	flag2=1;
															}
															x=keypad_u8check_press();
															_delay_ms(20);
													}while(x==NOTPRESSED && flag2==0);
                                                
													if(x==NOTPRESSED)
													{
															_delay_ms(20);
															LCD_clearscreen();
															LCD_movecursor(2,4);
															LCD_vSend_string("Time over");
													}
													else if (x=='3')
													{
															LCD_vSend_string("3");
															//LCD_clearscreen();
															_delay_ms(20);
															LCD_movecursor(2,4);
															LCD_vSend_string("Well done");
															_delay_ms(80);
															LCD_clearscreen();
															LCD_vSend_string("18/2=... value=");
															do{
																	if(flag1>=1000)
																	{
																			flag2=1;
																	}
																	x=keypad_u8check_press();
																	_delay_ms(20);
															}while(x==NOTPRESSED && flag2==0);
                                                        
															if(x==NOTPRESSED)
															{
																	_delay_ms(20);
																	LCD_clearscreen();
																	LCD_movecursor(2,4);
																	LCD_vSend_string("Time over");
															}
															else if (x=='9')
															{
																	LCD_vSend_string("9");
																	LCD_movecursor(2,4);
																	_delay_ms(20);
																	LCD_vSend_string("Well done");
																	_delay_ms(80);
																	LCD_clearscreen();
															}
															else
															{
																	LCD_clearscreen();
																	LCD_movecursor(2,3);
																	LCD_vSend_string("Wrong answer");
															}
													}
													else
													{
															LCD_clearscreen();
															LCD_movecursor(2,3);
															LCD_vSend_string("Wrong answer");
													}
											}
											else
											{
													LCD_clearscreen();
													LCD_movecursor(2,3);
													LCD_vSend_string("Wrong answer");
											}
									}else
									{
											LCD_clearscreen();
											LCD_movecursor(2,3);
											LCD_vSend_string("Wrong answer");
									}
                                                        
}
											}
ISR(TIMER0_COMP_vect)
{
        flag1++;
}