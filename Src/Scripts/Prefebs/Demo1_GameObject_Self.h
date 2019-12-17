#ifndef __DEMO1_GAME_OBJECT_SELF_H
#define __DEMO1_GAME_OBJECT_SELF_H

#include "GameObject_Self.h"

// 结构体命名规则：名字_继承的父类名
typedef struct Demo1_GameObject_Self
{
	// 自机的基本属性
	GameObject_Self base;
	// 想要添加的属性
	char* name; // 例如起个名字，游戏结束打印出来？

} Demo1_GameObject_Self; // 这里需要重复一遍结构体名，否则无法直接使用

/*以下是作为游戏物体必须实现的方法
* 示例实现查看 Demo1_GameObject_Self.c
*/

void Demo1_Init(
	// 指向自身的指针
	Demo1_GameObject_Self* self,
	// 初始生命值
	unsigned life,
	// 初始横纵坐标
	uint16_t pos_x, uint16_t pos_y,
	// 碰撞判断点大小
	uint16_t collider,
	// 图片宽高
	uint16_t width, uint16_t height,
	// 图片
	Color* img,
	// 自定义的需要初始化的属性
	char* name
);

void Demo1_OnCreate(Demo1_GameObject_Self* self);
void Demo1_OnUpdate(Demo1_GameObject_Self* self);
void Demo1_OnDestroy(Demo1_GameObject_Self* self);
void Demo1_OnRender(Demo1_GameObject_Self* self, Color** screen);

/*下面的方法直接调用对应父类方法即可，不需要做修改*/

bool __Demo1_Created(Demo1_GameObject_Self* self);

bool __Demo1_ToDestroy(Demo1_GameObject_Self* self);

#endif
