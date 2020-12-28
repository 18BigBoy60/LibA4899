#ifndef LibA4988
#define LibA4988
 
#include "Arduino.h"

class LibA4988{
	public:
		LibA4988(int 1A, int 2A, int 1B, int 2B,int step, int ms1, int ms2, int ms3, int en = -1, int dir = 1);
		void stepSplit(int s);
		void direction(int n);
		void xNow();
		void goTo(int x_n);
		void setZeroPosition();
		void setDegree(int degree);
	private:
		int _1A, _2A, _1B, _2B, _step, _ms1, _ms2, _ms3, _en, _dir;
		int _x_0, _x_n, _x_s, _st;
}
#endif