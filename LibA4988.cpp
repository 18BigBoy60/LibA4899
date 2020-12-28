#include "Arduino.h"
#include "LibA4988.h"

LibA4988::LibA4988(int step, int ms1, int ms2, int ms3, int dir = 1){
		_step = step;
		pinMode(_step, OUTPUT);
		_ms1 = ms1;
		pinMode(_ms1, OUTPUT);
		_ms2 = ms2;
		pinMode(_ms2, OUTPUT);
		_ms3 = ms3;
		pinMode(_ms3, OUTPUT);
		_dir = dir;	
		pinMode(_dir, OUTPUT);
		_x_0 = 0;
		_x_n = 0;
		_x_s = 0;
		_st = 0;
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
		digitalWrite(_dir, 1);
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
	_x_n = abs(_x_n);
	for(int x = 0; x < _x_n; x++) {
		digitalWrite(_step, HIGH);
		delayMicroseconds(1000);
		digitalWrite(_step, LOW);
		delayMicroseconds(1000);
	}
}


void LibA4988::setZeroPosition(){
	_x_0 = _x_s;
	_x_s = 0;
}


void LibA4988::setDegree(int degree){
	degree = abs(degree);
	int d = (degree / 1.8) * _st;
	for(int x = 0; x < d; x++) {
		digitalWrite(_step, HIGH);
		delayMicroseconds(1000);
		digitalWrite(_step, LOW);
		delayMicroseconds(1000);
	}
}

int LibA4988::xNow(){
	return _x_s;
}


