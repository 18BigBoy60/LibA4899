#include "Arduino.h"
#include "LibA4988.h"

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
		stepSplit();
		direction();
}


void LibA4988::stepSplit(int s = 1){
	_st = s;
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


void LibA4988::direction(int n = 1){
	if (n == 1){
		digitalWrite(_dir, 1)
	}
	if (n == -1){
		digitalWrite(_dir, 0);
	}
}


void LibA4988::goTo(int x_n){
	_x_n = x_n;
	if (_x_n < 0){
		direction(-1);
	}
	if (_x_n > 0){
		direction(1);
	}
	for(int x = 0; x < abs(_x_n); x++) {
		digitalWrite(_step, HIGH);
		delayMicroseconds(1000);
		digitalWrite(_step, LOW);
		delayMicroseconds(1000);
	}
}


void setZeroPosition(){
	_x_0 = _x_s;
	_x_s = 0;
}


void setDegree(int degree){
	int x = (degree / 1.8) * _st;
	for(x = 0; x < abs(_x_n); x++) {
		digitalWrite(_step, HIGH);
		delayMicroseconds(1000);
		digitalWrite(_step, LOW);
		delayMicroseconds(1000);
	}
}

int LibA4988::xNow(){
	return _x_s;
}


