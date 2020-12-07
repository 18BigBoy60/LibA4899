#include "Arduino.h"
#include "lib_A4988.h"

LibA4988::LibA4988(int 1A, int 2A, int 1B, int 2B,int step, int ms1, int ms2, int ms3, int en = -1, int dir = 1){
		_1A = 1A;
		pinMode(_1A, OUTPUT);
		_2A = 2A;
		pinMode(_2A, OUTPUT);
		_1B = 1B;
		pinMode(_1B, OUTPUT);
		_2B = 2B;
		pinMode(_2B, OUTPUT);
		_step = step;
		pinMode(_step, OUTPUT);
		_ms1 = ms1;
		pinMode(_ms1, OUTPUT);
		_ms2 = ms2;
		pinMode(_ms2, OUTPUT);
		_ms3 = ms3;
		pinMode(_ms3, OUTPUT);
		_en = en;
		pinMode(_en, OUTPUT);
		_dir = dir;	
		pinMode(_dir, OUTPUT);
}


void LibA4988::stepSplit(int s = 1){
	if (s == 1){
		digitalWrite(_ms1, 0);
		digitalWrite(_ms2, 0);
		digitalWrite(_ms3, 0);
	}
	if (s == 2){
		digitalWrite(_ms1, 1);
		digitalWrite(_ms2, 0);
		digitalWrite(_ms3, 0);
	}
	if (s == 4){
		digitalWrite(_ms1, 0);
		digitalWrite(_ms2, 1);
		digitalWrite(_ms3, 0);
	}
	if (s == 8){
		digitalWrite(_ms1, 1);
		digitalWrite(_ms2, 1);
		digitalWrite(_ms3, 0);
	}
	if (s == 16){
		digitalWrite(_ms1, 1);
		digitalWrite(_ms2, 1);
		digitalWrite(_ms3, 1);
	}
}