#ifndef Morse_h
#define Morse_h
 
#include "WProgram.h"
#include "Arduino.h"
class LibA4988{
	public:
		LibA4988(int 1A, int 2A, int 1B, int 2B,int step, int ms1, int ms2, int ms3, int en = -1, int dir = 1);
	private:
		int _1A;
		int _2A;
		int _1B;
		int _2B;
		int _step;
		int _ms1;
		int _ms2;
		int _ms3;
		int _en;
		int _dir;
}
#endif