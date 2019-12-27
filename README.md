# 南方科技大学嵌入式Project & 东方Project

English version: [README_EN](./README_EN.md) (not complicated yet)

## 使用环境

- 硬件：
  - STM32F103RC开发板
  - J-Link或ST-Link传输线
- 软件：
  - STM32CubeIDE集成开发环境（1.1.0或更高版本）
  - FlyMcu二进制文件下载软件

## 使用方式

- 下载到本地
  - 直接下载zip文件：右上角Clone or download -> Download ZIP
  - 复制项目到本地：`git clone git@github.com:IF-ACT/SUSTech-Embedded_System-Project.git`

- 安装STM32CubeIDE后，直接双击[.project](./.project)打开

- 请勿使用STM32CubeIDE的自动生成代码功能，因为代码路径已经改变，环境为手动配置，使用自动生成会破坏当前环境，导致编译失败
- 编译后在[Debug](./Debug)文件夹下会生成[后缀名为hex的二进制文件](./Debug/LCD_Module.hex)
- FlyMcu配置如图，将文件烧录到开发板上![FlyMcu配置](.\ReadmeInfo\FlyMcu配置.png)

- 开发板点击Awake按钮后即可开始游戏

## 游戏截图

<img src=".\ReadmeInfo\GameCapture\IMG_20191224_024022.jpg" alt="IMG_20191224_024022" style="zoom:10%;" /><img src=".\ReadmeInfo\GameCapture\IMG_20191224_024029.jpg" alt="IMG_20191224_024029" style="zoom:10%;" /><img src=".\ReadmeInfo\GameCapture\@]U_KFEAPTS56$@P{0~SLJ2.jpg" alt="aU_KFEAPTS56$@P{0~SLJ2" style="zoom:41%;" /><img src=".\ReadmeInfo\GameCapture\IMG_20191224_023713.jpg" alt="IMG_20191224_023713" style="zoom:10%;" /><img src=".\ReadmeInfo\GameCapture\IMG_20191224_023809.jpg" alt="IMG_20191224_023809" style="zoom:10%;" /><img src=".\ReadmeInfo\GameCapture\IMG_20191224_023914.jpg" alt="IMG_20191224_023914" style="zoom:10%;" /><img src=".\ReadmeInfo\GameCapture\IMG_20191224_023926.jpg" alt="IMG_20191224_023926" style="zoom:10%;" />

- 视频链接：[bilibili](https://www.bilibili.com/video/av80469481?p=2)

## 设计结构

### 代码文件结构

- [/Img/](./Img) 以c数组形式储存的图片文件
- [/Inc/](./Inc) 框架及主要抽象游戏物体的.h文件
  - [OverAllEnv/](./Inc/OverAllEnv) STM32Cube自动生成的环境文件头文件
- [/Src/](./Src) 主要源码
  - [OverAllEnv/](./Src/OverAllEnv) STM32Cube自动生成的环境文件
  - [GameFrame/](./Src/GameFrame) 游戏框架及主要抽象游戏物体
  - [Util/](./Src/Util) 渲染器，计时器，随机数产生器，链表数据结构
  - [Scripts/](./Src/Scripts) 游戏脚本
    - [Prefebs/](./Src/Scripts/Prefebs) 游戏物体，定义了游戏中每个物体的行为
    - [Routines/](./Src/Scripts/Routines) 游戏进程，定义了游戏引擎的行为

### 游戏引擎概述

​	游戏涉及到许多物体分别的行为以及物体间的相互作用，如果简单地在一个循环中定义每个物体的行为并反映到屏幕上，这将是一个非常长的while循环，代码难以管理，而且难以定义物体的相互作用。

​	因此，使用游戏引擎，将每个游戏物体的行为单独抽象为一个脚本文件加以管理，然后在引擎的循环中依次调用每个物体的行为。这里定义了游戏物体的四个基本行为：`OnCreate`, `OnUpdate`, `OnDestroy` 和`OnRender`，游戏物体在被创建时会调用`OnCreate`，销毁时调用`OnDestroy`，每一次循环中调用`OnUpDate`，若在该循环中未被销毁，则会调用`OnRender`来将自身预渲染到下一帧的缓存中。根据调用游戏物体方法得到的结果，在每次循环时调用[Renderer.c](./Src/Util/Renderer.c)中的`Flush`方法，一次性刷新整个屏幕，避免了画面闪烁和撕裂的问题。

​	游戏引擎的基本行为可以概括为下图

<img src=".\ReadmeInfo\GameEngine.png" alt="GameEngine" style="zoom:50%;" />

## 脚本编写向导

### 创建一个游戏物体

​	与大多数c程序一样，游戏物体的脚本同样需要.h文件（头文件）和.c文件。如果对c语言的语法尚不清楚，[菜鸟教程](https://www.runoob.com/cprogramming/c-tutorial.html)是一个简明系统，易于入门的教学网站，有关c语言的一切都可以在这里学到。

​	**在STM32CubeIDE中**[^1]，在`/Src/Scripts/Prefebs/`目录下创建一个文件，命名规则为`{Name}_{FatherGameObject}.{c|h}`，其中`Name`是您自己的游戏物体名，`FatherGameObject`是要继承的父游戏物体名。关于父游戏物体，由于本Project以弹幕类游戏为设计目标，预设了三类父游戏物体，分别是表示自机的[`GameObject_Self`](./Inc/GameObject_Self.h)，表示敌机的[`GameObject_Enemy`](./Inc/GameObject_Enemy.h)，和表示子弹的[`GameObject_Bullet`](./Inc/GameObject_Bullet.h)。这三种`GameObject`都继承于一个父类[`GameObject`](./Inc/GameObject.h)。

​	以自机为例，我们来创建一个新的游戏物体。首先是.h文件，我们把它命名为`Demo1_GameObject_Self.h`，在代码中这个文件已经为您创建好了，如果想要跟着做一遍，请另外命名（如`MyTest_GameObject_Self.h`）。以下是`Demo1_GameObject_Self.h`的示例代码：

```c
// Demo1_GameObject_Self.h
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

#endif
```

​	需要注意的是，结构体中`GameObject_Self base`的声明必须放在结构体首行，且一定不能使用指针，这是为了游戏引擎能够无视类型直接从栈堆中读出您游戏物体的一些基本属性。这里`Demo1_Init`方法的声明使用的是较旧的版本，不推荐这样声明，推荐的声明方式如下：

```c
Demo1_GameObject_Self* Demo1_Init(
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
```

​	区别在于，返回了一个指向自身的指针，而去掉了第一个传入参数`self `，这样的写法更有利于后续的内存管理，两种写法的.c文件也有区别，后续将提到。

​	接下来我们创建.c文件，在同一目录下，命名为`Demo1_GameObject_Self.c`，在代码中这个文件已经也为您创建好了。示例代码如下：

```c
// Demo1_GameObject_Self.c
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
```

​	除`OnDestroy`方法外，每一个方法结尾都应该调用父类对应的方法，这些方法为您实现了游戏物体的基本功能，如移动、生命值计算、图像渲染等，敌机和子弹在生命值或`ttl`消耗完后即会自动销毁，自机可以设置生命次数和复活行为，如果想自行操作销毁方式，将其结构体所包含的`GameObject`结构体的`__to_destroy`属性设置为`true`，该物体将会在这一帧执行预渲染前被销毁。在`OnDestroy`方法的最后请**务必释放自身内存**，否则将会导致内存泄漏。

​	同样地，如果使用新版的`Init`方法声明，其实现应该写成这样：

```c
Demo1_GameObject_Self* Demo1_Init(
	unsigned life,
	uint16_t pos_x, uint16_t pos_y,
	uint16_t collider,
	uint16_t width, uint16_t height,
	Color* img,
	char* name
){
    // 分配内存
    Demo1_GameObject_Self* self = malloc(sizeof(Demo1_GameObject_Self));
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
    // 返回自身指针
    return self;
}
```

​	可以看到，新版的区别在于在初始化方法中同时分配了内存，与`OnDestroy`方法的释放内存对应，所有内存操作在游戏物体内部完成，更有利于内存管理，`Routine`文件也能写得更为简洁。

​	示例仅仅是一个简单，不执行任何操作的空游戏物体，想要让游戏物体执行任务，需要在`OnCreate`，`OnUpdate`，`OnDestroy`，和`OnRender`中编写您自己的代码。一个复杂的自机游戏物体示例可以查看[Remo_GameObject_Self.h](./Src/Scripts/Prefebs/Remo_GameObject_Self.h)和[Remo_GameObject_Self.c](./Src/Scripts/Prefebs/Remo_GameObject_Self.c)。这里是我们Project的自机~~（灵梦）~~魔理沙[^2]。

### 创建一个游戏进程

​	`Routine`文件定义了游戏的进程，即游戏关卡剧情。同样需要.c文件和一个简单的.h文件，文件应该创建在[/Src/Scripts/Routines](./Src/Scripts/Routines)目录下，命名规则为`{Name}_Routine.{c|h}`。

```c
// Demo4_Routine.h
#ifndef __DEMO4_ROUTINE_H
#define __DEMO4_ROUTINE_H

void Demo4_Routine();

#endif
```

​	.h文件中只需要声明一个与文件名相同的方法，并在[/Src/OverAllEnv/main.c](./Src/OverAllEnv/main.c)中调用即可。`Routine`文件是程序运行时直接被执行的文件，因此它负责创建游戏开始前的游戏物体，启动游戏引擎，和定义游戏引擎事件。具体的使用可以查看[Demo4_Routine.c](./Src/Scripts/Routines/Demo4_Routine.c)，这是我们Project演示时使用的`Routine`文件，它包含了自机的产生，boss的生成，在指定位置循环刷怪，以及一个通关画面。

​	`Routine`文件包含两个部分：在`mian`函数中被调用的主方法，和作为函数指针被传入`GameEngineLoop`方法的游戏事件方法。主方法只在您自己在`main`函数中调用时执行，而游戏事件方法在游戏引擎的每一帧都会执行。由于游戏事件方法每一帧执行，请**不要**在其中编写过于消耗时间的代码（如循环和复杂的计算），否则会导致运行卡顿。

#### 游戏事件

​	游戏物体被格式化为一个游戏事件后才可以加入游戏引擎所维护的游戏事件链表中被显示出来。游戏事件的定义在[/Inc/GameEvent.h](./Inc/GameEvent.h)中：

```c
// GameEvent.h
#ifndef __GAME_EVENT_H
#define __GAME_EVENT_H

#include <stdbool.h>
#include <stdlib.h>
#include "lcd.h"

typedef struct GameEvent
{
	void *game_object;

	void (*OnCreate)(void*);
	void (*OnUpdate)(void*);
	void (*OnDestroy)(void*);
	void (*OnRender)(void*, Color**);

} GameEvent;

GameEvent* RegistGameEvent
(
	void* game_object,
	void (*OnCreate)(void*),
	void (*OnUpdate)(void*),
	void (*OnDestroy)(void*),
	void (*OnRender)(void*, Color**)
);

#endif
```

​	这里就需要之前实现的游戏物体的四个方法，然后调用`RegistGameEvent()`来生成游戏事件，并使用`LinkedList.h`中的`Push`方法将您的自定义游戏物体加入到游戏引擎维护的对应链表中，使他们成为游戏的一部分。

### API讲解

​	在[/Src/Util](./Src/Util)中（头文件位于[/Inc](./Inc)中）和[GameEngine.h](./Inc/GameEngine.h)中，我们提供了许多好用的API，善用它们几乎可以解决您在一个简单的游戏编写过程中的一切问题。

`Random`

- 由于STM32开发板不支持`rand()`标准库函数，这里提供一个使用线性同余算法生成伪随机数的方法

- `void os_srand(unsigned seek)`
  - 输入：seek：任意值，类似于随机函数的种子
- `unsigned os_rand()`
  - 输出一个`0~__UINT32_MAX__`之间的伪随机数

`Render`

- 渲染器，使用Flush将缓存的一帧输出到屏幕

- 宏`TRANSPARENT`：透明色，该颜色不会被预渲染，默认为黑色

- 宏`__WDITH`，`__HEIGHT`，`__SCALE`：屏幕缓存的宽高和与实际屏幕像素的比例，对于STM32F103RC而言，比例最小为3，否则内存不足以缓存屏幕。应满足：

  $\_\_WIDTH \times \_\_SCALE \le 实际屏幕像素宽度$

  $\_\_HEIGHT \times \_\_SCALE \le 实际屏幕像素高度$

- `void Render(GameObject* game_object, Color** screen)`

  - 预渲染一个游戏物体
  - 输入`game_object`：要渲染的`GameObject`指针，也可以是任意继承[^3]`GameObject`的结构体的指针
  - 输入`screen`：表示屏幕缓存的二维数组，由`GameEngine`提供

- `void Render_Img(float pos_x, float pos_y, uint16_t width, uint16_t height, Color* img, Color** screen)`

  - 预渲染一副图像
  - 输入`pos_x`，`pos_y`：图片中心坐标
  - 输入`width`，`height`：图片宽高
  - 输入`img`：图片（c数组格式）
  - 输入`screen`：表示屏幕缓存的二维数组，由`GameEngine`提供

`Time`

- 与时间有关的函数，目前没有较好的办法获取时间，暂时用游戏引擎自启动开始的帧数替代
- `int delta_time`：上一帧运行所用时间
- `int GetTime()`：获取当前时间

`GameEngine`

- `unsigned Game_Life`：自机的复活次数
- `unsigned Game_KillCount`：杀敌数
- `unsigned Game_Score`：分数
- `unsigned Game_BombNum`：炸弹数量（未实现）
- `unsigned Game_ChapterNum`：当前关卡数
- `bool Game_ChapterPassed`：是否已经过关，在完成关卡目标后设为`true`即可退出`GameEngineLoop()`循环
- `GameEvent* Engine_SelfEvent`：自机游戏事件指针
- `LinkedList Engine_EnemyEvents`：存有敌机游戏事件指针的链表
- `LinkedList Engine_BulletEvents`：存有子弹游戏事件的链表
- `void GameEngineInit()`：初始化游戏引擎，在游戏开始是使用
- `void GameEngineLoop(void (*OnLoop)(void))`：启动游戏引擎
- `void GameOver()`：游戏结束时会被调用的方法，自机不存在会被自动调用，也可以手动调用，在`GameEngine.c`中，可以自行实现

`mygpio`串口调试

- 这个文件放在[/Src/OverAllEnv](./Src/OverAllEnv)中，用于进行串口调试输出
- 由于串口无法输出太长的字符串，下列方法的输出长度都被限制在50`char`以内
- `void println(const char* str)`：串口输出c字符串
- `void printlnf(const char* str, ...)`：格式化输出c字符串，与`printf`行为一致，格式查看[菜鸟教程-printf](https://www.runoob.com/cprogramming/c-function-printf.html)

## 进阶：使用游戏引擎编写其它类型的游戏

​	这个项目是为了制作弹幕类游戏而设计的，基本功能对于弹幕类游戏的设计比较友好，但游戏引擎同样可以用于其它类型游戏的编写，甚至非游戏的编写。只要您需要一个在STM32F103RC开发板上运行的，需要管理多个物体及其间关系的程序，都可以使用这个框架进行开发。

### 继承`GameObject`

​	除了之前示范的三种预设`GameObject`，直接继承基类`GameObject` 也是可行的。`GameObject`只定义了最基本的物体特征：

```c
// GameObject.h
#ifndef __GAME_OBJECT_H
#define __GAME_OBJECT_H

// abstruct class

#include <stdbool.h>
#include <stdlib.h>
#include "lcd.h"

typedef struct GameObject
{
	float speed_x;
	float speed_y;
	// center x
	float pos_x;
	// center y
	float pos_y;
	// size of collider
	uint16_t collider;
	// image width
	uint16_t width;
	// image height
	uint16_t height;
	Color *img;

	bool __created;
	bool __to_destroy;

} GameObject;

void GameObject_Initialize
(
	GameObject* self, uint16_t pos_x, uint16_t pos_y, 
	uint16_t collider, uint16_t width, uint16_t height,
	Color* img
);
void GameObject_OnCreate(GameObject* self);
void GameObject_OnUpdate(GameObject* self);
void GameObject_OnDestroy(GameObject* self);
void GameObject_OnRender(GameObject* self, Color** screen);

bool __GameObject_Created(GameObject* self);
bool __GameObject_ToDestroy(GameObject* self);

#endif
```

- `speed`：x和y方向上的速度，向下向右为正
- `pos`：x和y方向上的坐标，可以超出屏幕范围
- `collider`：碰撞器半径，用于在`GameEngine`不知道物体种类的情况下计算物体间碰撞
- `width`，`height`：物体图片的宽高
- `img`：物体图片

### 修改游戏引擎

​	现有的游戏引擎通过维护一个自机游戏事件指针和三个游戏事件链表（`Engine_EnemyEvents`，`Engine_BulletEvents`，和未使用的`Engine_UIEvents`）来进行游戏逻辑的运算和画面的刷新渲染。游戏引擎是单线程的，每次只能处理一个游戏物体，那么游戏物体所处的链表和在链表中所处的位置就决定了其刷新次序。本Project所用到的`GameEngine`行为是：先刷新自机事件，然后依次刷新敌机和子弹事件，并在子弹刷新的同时判断碰撞，计算伤害。根据需求可以自行修改。



[^1]: 注意，如果不在STM32CubeIDE中创建文件，由于该IDE包含文件目录的关系，创建的文件将无法被IDE读取
[^2]: 东方厨息怒，一开始设定自机是灵梦，子弹也是御币，但由于后来制作上的原因，自机改为魔理沙，导致游戏中图片为魔理沙，代码名称按照灵梦编写……~~这其实是主角组合体成功~~
[^3]: c不是一门面向对象语言，所以没有继承这种说法，这里是为了简略。我们先把这称之为继承，然后我们所说的继承表示了一个递归的实际含义：在结构体首行包含`GameObject`结构体或包含已经”如先前所述般继承“了`GameObject`结构体的结构体

