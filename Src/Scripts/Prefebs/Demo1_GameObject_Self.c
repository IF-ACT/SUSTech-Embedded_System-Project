#include "Demo1_GameObject_Self.h"
#include "mygpio.h"

void Demo1_Init(
	Demo1_GameObject_Self* self,
	unsigned life,
	uint16_t pos_x, uint16_t pos_y,
	uint16_t collider,
	uint16_t width, uint16_t height,
	Color* img,
	char* name
){
	// 调用父类初始化方法(不用做修改)
	GameObject_Self_Init(
		&self->base,
		life,
		pos_x, pos_y,
		collider,
		width, height,
		img
	);
	// 初始化自定义属性
	self->name = name;
}

void Demo1_OnCreate(Demo1_GameObject_Self* self)
{
	// 在这里写的脚本会在物体被创建时执行
	printlnf("%s created", self->name);
	// 之后记得调用一下父类的OnCreate
	GameObject_Self_OnCreate(&self->base);
}

void Demo1_OnUpdate(Demo1_GameObject_Self* self)
{
	// 在这里写的脚本每一帧都会执行

	// 之后记得调用一下父类的OnUpdate,
	// 父类的OnUpdate会根据当前速度移动物体,
	// 也就是说不需要自己实现物体的移动
	GameObject_Self_OnUpdate(&self->base);
}

void Demo1_OnDestroy(Demo1_GameObject_Self* self)
{
	// 在这里写的脚本会在物体销毁时被执行

	// 记得释放内存
	free(self);
}

void Demo1_OnRender(Demo1_GameObject_Self* self, Color** screen)
{
	// 定义渲染器行为
	// 直接调用就好，没有特殊需求不用修改
	GameObject_Self_OnRender(&self->base, screen);
}
