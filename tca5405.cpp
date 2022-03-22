#include "tca5405.h"

int8_t TCA5405::transmit()
{
  // 2 cycle square wave for ramp up. low first
  digitalWrite(din_pin, LOW);
  TCA5405_TRAN_DELAY;
  digitalWrite(din_pin, HIGH);
  TCA5405_TRAN_DELAY;
  digitalWrite(din_pin, LOW);
  TCA5405_TRAN_DELAY;
  digitalWrite(din_pin, HIGH);
  TCA5405_TRAN_DELAY;

  digitalWrite(din_pin, _TCA5405_GET_BIT(output, 4));
  TCA5405_TRAN_DELAY;
  digitalWrite(din_pin, _TCA5405_GET_BIT(output, 3));
  TCA5405_TRAN_DELAY;
  digitalWrite(din_pin, _TCA5405_GET_BIT(output, 2));
  TCA5405_TRAN_DELAY;
  digitalWrite(din_pin, _TCA5405_GET_BIT(output, 1));
  TCA5405_TRAN_DELAY;
  digitalWrite(din_pin, _TCA5405_GET_BIT(output, 0));
  TCA5405_TRAN_DELAY;
  digitalWrite(din_pin, HIGH);
  
  return 0;
}

int8_t TCA5405::init(uint8_t pin, uint8_t delay_cycle)
{
  din_pin  = pin;
  dcycle = delay_cycle;
  pinMode(din_pin, OUTPUT);
  digitalWrite(din_pin, HIGH);
  return 0;
}

int8_t TCA5405::set_gpo(TCA5405_GPO gpo, int level)
{
  if (gpo >= TCQ5405_GPO_ERR) {
    return -1;
  }
  _TCA5405_CLR_BIT(output, gpo);
  if (level) {
    _TCA5405_SET_BIT(output, gpo);
  }

  return 0;
}
