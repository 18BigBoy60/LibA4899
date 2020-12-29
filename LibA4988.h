#pragma once

#include "Arduino.h"

class LibA4988
{
	public:
		LibA4988(int step, int ms1, int ms2, int ms3, int dir);
		void stepSplit(int s = 1);
		void direction(int n = 1);
		int xNow();
		void goTo(int x_n);
		void setZeroPosition();
		void setDegree(int degree);
		void steper();
		void setAcceleration(int a);
		void setSpeed(int speed);
	private:
		int _step, _ms1, _ms2, _ms3, _dir, _speed, _a;
		int _x_0, _x_n, _x_s, _st;
};
