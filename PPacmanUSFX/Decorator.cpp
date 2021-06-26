#include "Decorator.h"

Decorator::Decorator(Pared* _widget) {
	widget = _widget;
}

void Decorator::update() {
	widget->update();
}