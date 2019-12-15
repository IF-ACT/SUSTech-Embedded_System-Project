#include "GameObject_Self.h"

#include "Img_TestImages.h"
#include "Time.h"
#include "mygpio.h"

void GameObject_Self_OnCreate(GameObject_Self* self)
{
	self->life = 1;
	GameObject_Initialize(&(self->base), 100, 100, 10, 10, 10, Img_GreenBlock_10x10);

	
}

void GameObject_Self_OnUpdate(GameObject_Self* self)
{
	GameObject_OnUpdate(&(self->base));
}

void GameObject_Self_OnDestroy(GameObject_Self* self)
{
	println("self destroyed");
	GameObject_OnDestroy(&(self->base));

	free(self);
}

void GameObject_Self_OnRender(GameObject_Self* self, Color** screen)
{

}