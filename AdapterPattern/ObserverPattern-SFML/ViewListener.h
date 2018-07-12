#pragma once
#include "View.h"

class ViewListener {

	View *view;

public:

	ViewListener() {}

	virtual bool update(int ID) = 0;

	~ViewListener() {
		delete view;
	}

protected:

	void attatchViewListener(View *view) {
		this->view = view;
	}

	View *getView() {
		return view;
	}

};