#ifndef Morse_h
#define Morse_h
 
#include "WProgram.h"
#include "Arduino.h"
class LibA4988{
	public:
		LibA4988(int 1A, int 2A, int 1B, int 2B,int step, int ms1, int ms2, int ms3, int en = -1, int dir = 1);
		void stepSplit(int s);
		void direction(int n);
	private:
		int _1A, _2A, _1B, _2B, _step, _ms1, _ms2, _ms3, _en, _dir;
		int x_0, x_n;
}
#endif