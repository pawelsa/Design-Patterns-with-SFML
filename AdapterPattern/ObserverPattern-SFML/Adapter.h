#pragma once
#include "MouseSubject.h"


class Adapter {
protected:
	MouseSubject mouse;

public:

	Adapter(MouseSubject &mouse):mouse(mouse){}

	virtual void mousePressed() = 0;
	//virtual void registerDataSetObserver(DataSetObserver observer) = 0;
	//virtual void unregisterDataSetObserver(DataSetObserver observer) = 0;
	virtual int getCount() = 0;
	//virtual T getItem(int position) = 0;
	virtual bool isEmpty() = 0;
	virtual void display() = 0;
}; 