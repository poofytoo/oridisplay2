#include "frame_view.h"
// #include "image.h"
#include "DIALOG.h"

static sFONT *LCD_Currentfonts;

void draw_view(void)
{
  /* Configure system clock (SYSCLK) to 180 MHz, at this stage the USB is not used.
     Please note that the USB is not functional if the system clock is set to 180 MHz. */
  // SetSYSCLK_180();

  /* Reconfigure the SysTick following SYSCLK frequency change */
  if (SysTick_Config(SystemCoreClock / 1000))
  { 
    /* Capture error */ 
    while (1);
  }
   
  /* Initialize LEDs, User Button and LCD on STM32F429I-Disco */
  // STM_EVAL_LEDInit(LED3);
  // STM_EVAL_LEDInit(LED4);
  // STM_EVAL_PBInit(BUTTON_USER, BUTTON_MODE_EXTI); 
  
  /* Display message on LCD */ 
  
  // LowLevel_Init();
  
  LCD_Init();
  LCD_LayerInit();
  
  // LTDC reload configuration
  LTDC_ReloadConfig(LTDC_IMReload);
  
  // Enable the LTDC 
  LTDC_Cmd(ENABLE);
  
  // LCD display message 
  LCD_Clear(LCD_COLOR_BLACK);
  // LCD_SetTextColor(LCD_COLOR_BLACK); 
  // LCD_DisplayStringLine(LCD_LINE_3,(uint8_t*)"    V1.0.1     ");
  // LCD_DisplayStringLine(LCD_LINE_5,(uint8_t*)"      PUSH     ");
  // LCD_DisplayStringLine(LCD_LINE_7,(uint8_t*)"  USER BUTTON  ");
  // LCD_DisplayStringLine(LCD_LINE_9,(uint8_t*)"    TO START   ");
  
    
  /* Wait for User button to be pressed */
  //while (STM_EVAL_PBGetState(BUTTON_USER) != Bit_SET)
  
  LCD_SetLayer(LCD_FOREGROUND_LAYER);


  LCD_SetTextColor(0xFFFF);
  LCD_DrawFullCircle(120, 180, 2);

  LCD_SetTextColor(0x632c);
  LCD_DrawCircle(120, 180, 20);
  LCD_DrawCircle(120, 180, 60);
  LCD_DrawCircle(120, 180, 100);
     
  LCD_SetTextColor(0xe8ec * 6/5);
  LCD_DrawFullCircle(100, 60, 21);
  LCD_SetTextColor(0xe8ec);
  LCD_DrawFullCircle(100, 60, 20);

  LCD_SetFont(&Avenir);
  LCD_SetTextColor(0xFFFF);
  LCD_Currentfonts = &Avenir;
  LCD_DrawChar(50,85,&LCD_Currentfonts->table[18 * LCD_Currentfonts->Height]); // 50
  LCD_DrawChar(50,100,&LCD_Currentfonts->table[17 * LCD_Currentfonts->Height]);
  LCD_DrawChar(50,115,&LCD_Currentfonts->table[16 * LCD_Currentfonts->Height]);
  LCD_DrawChar(50,130,&LCD_Currentfonts->table[15 * LCD_Currentfonts->Height]);
  LCD_DrawChar(50,145,&LCD_Currentfonts->table[12 * LCD_Currentfonts->Height]);

  //LCD_DrawChar(50,101,&LCD_Currentfonts->table[2 * LCD_Currentfonts->Height]); // 38

  
  while(1)
  {}
}