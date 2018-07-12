#pragma once
#include "Adapter.h"

class AdapterListener {

	Adapter *adapter;

public:

	AdapterListener() {}

	virtual void update(int data) = 0;
	virtual void updateAdapter(Adapter* adapter) = 0;

protected:

	void attatchViewListener(Adapter *adapter) {
		this->adapter = adapter;
	}

	Adapter *getView() {
		return adapter;
	}

};
