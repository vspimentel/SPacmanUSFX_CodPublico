#include "Decorator.h"

Decorator::Decorator(GameObject* _widget) {
	widget = _widget;
}

void Decorator::update() {
	widget->update();
}

void Decorator::draw() {
	widget->draw();
}

void Decorator::render() {
	widget->render();
}