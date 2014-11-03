
#include <stdio.h>
#include <math.h>

#define GET_H	0x01
#define GET_D	0x02
#define GET_T	0x04
#define END	0x08
#define DONE	0x07

#define DEBUG	0
#define EXP	2.718281828 

#define CHECK_H(x)  ((x)&GET_H)
#define CHECK_D(x)  ((x)&GET_D)
#define CHECK_T(x)  ((x)&GET_T)
#define CHECK_E(x)  ((x)&END)
#define CHECK_DONE(x) ((x)&DONE)

double	Temper, Humidex, Dewpoint;
double  Mid_e,  Mid_h;

int SetMode( char indicator, int old_mode)
{
  int new_mode;


  new_mode = old_mode;
	
  switch(indicator)
  {
    case 'T':
      new_mode|=GET_T;
      scanf("%lf", &Temper);
      getchar();
      break;
    case 'D':
      new_mode|=GET_D;
      scanf("%lf", &Dewpoint);
      getchar();
      break;
    case 'H':
      new_mode|=GET_H;
      scanf("%lf", &Humidex);
      getchar();
      break;
    case 'E':
      new_mode|=END;
      break;
    default:
      printf("Error in mode.\n");
      break;
  }	

#if DEBUG
  printf("In SetMode. indicator:%c old_mode:%d\n", indicator, new_mode);
#endif
	
  return new_mode;
}

int ResolvMode(int cur_mode)
{
   double tmp;

   if(CHECK_H(cur_mode)&&CHECK_T(cur_mode))
   {
	Mid_h = Humidex - Temper;
	Mid_e = Mid_h/0.5555 + 10;
	Mid_e = Mid_e/6.11;

	tmp = log(Mid_e);
	Dewpoint = 5417.7530/(19.833625-tmp)-273.16;
	
       return DONE; 
   }

  //gets here means, must have Dewpoint
  tmp = 5417.7530*Dewpoint/(pow(273.16, 2)+Dewpoint*273.16);
  Mid_e = 6.11*pow(EXP, tmp);	
  Mid_h = 0.5555*(Mid_e-10);

  if(CHECK_T(cur_mode))//now, we have Dewpoint
    Humidex = Temper + Mid_h;

  if(CHECK_H(cur_mode))
    Temper = Humidex - Mid_h;

  return DONE;
}

int main()
{
  int	res_get;
  char	indicate;

  while(1)
  {
    res_get = 0;
    Temper = 0;
    Humidex = 0;
    Dewpoint = 0;

    scanf("%c", &indicate);
    getchar();
    res_get = SetMode(indicate, res_get);

    if(CHECK_E(res_get))// Input E, break
	break;

    scanf("%c", &indicate);
    getchar();
    res_get = SetMode(indicate, res_get); //Now, we get two resources

    res_get = ResolvMode(res_get); 
    printf("T %.1f D %.1f H %.1f\n", Temper, Dewpoint, Humidex);
  }

  return 0;
}
