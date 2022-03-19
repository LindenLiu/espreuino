/**
 * MIT License
 *
 * Copyright (c) 2022 Linden Liu
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#pragma once

#include <RBDdimmer.h>
#include "Dimmer.h"

class RBDDimmerActor : public Dimmer
{
private:
  dimmerLamp *dimmer;
public:
  RBDDimmerActor(uint8_t pin, uint8_t zc_pin);
  ~RBDDimmerActor();
  void begin() override;
  void setPower(int power) override;
  int getPower() override;
  void setOn(bool isOn) override;
  bool isOn() override; 
};

RBDDimmerActor::RBDDimmerActor(uint8_t pin, uint8_t zc_pin)
{
  #if   defined(ARDUINO_ARCH_AVR)
	  dimmer = new dimmerLamp(pin);
  #elif defined(ARDUINO_ARCH_ESP32)
    dimmer = new dimmerLamp(pin, zc_pin);
  #endif
}

RBDDimmerActor::~RBDDimmerActor()
{
  delete dimmer;
}

void RBDDimmerActor::begin() 
{
  dimmer->begin(NORMAL_MODE, OFF);
}

void RBDDimmerActor::setPower(int power) 
{
  dimmer->setPower(power);
}

int RBDDimmerActor::getPower() 
{
  return dimmer->getPower();
}

void RBDDimmerActor::setOn(bool isOn) 
{
  dimmer->setState(isOn ? ON : OFF);
}

bool RBDDimmerActor::isOn() 
{
  return dimmer->getState() == ON;
}
