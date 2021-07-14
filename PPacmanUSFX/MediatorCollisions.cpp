#include "MediatorCollisions.h"

void MediatorCollisions::notify(GameActor* sender, GameActor* receptor, string evento) const
{
	if (evento == "eliminar") 
		receptor->deleteGameObject();

	if (evento == "setDecorator") 
		((DecoratorAura*)receptor)->setWidget(sender);
}

bool MediatorCollisions::getBool(GameActor* sender, GameActor* receptor, string evento) const
{
	if (evento == "isSupermoneda") 
		return ((Moneda*)receptor)->getTipoPoderMoneda() == PODER_SUPERMONEDA;

	if (evento == "colision") 
		return sender->revisarColision(sender->getColisionador(), receptor->getColisionador());
	return false;
}
