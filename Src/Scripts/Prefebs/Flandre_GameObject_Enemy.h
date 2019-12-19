#ifndef __FLANDRE_GAMEOBJECT_ENEMY_H
#define __FLANDRE_GAMEOBJECT_ENEMY_H

#include "GameObject_Enemy.h"

typedef struct Flandre_GameObject_Enemy
{
	GameObject_Enemy base;
	int create_time;
	/**skill
	 * 0: normal
	 * 1: Laevatain
	 * 2: KagomeKagome
	 * 3: StarbowBreak
	 * 4: Catadioptric
	*/
	int skill;
	int skill_param;
	bool* SB_Active;
	uint16_t aim;

} Flandre_GameObject_Enemy;

Flandre_GameObject_Enemy* Flandre_Init();

void Flandre_OnCreate(Flandre_GameObject_Enemy* self);
void Flandre_OnUpdate(Flandre_GameObject_Enemy* self);
void Flandre_OnDestroy(Flandre_GameObject_Enemy* self);
void Flandre_OnRender(Flandre_GameObject_Enemy* self, Color** screen);

#endif