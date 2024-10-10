#include "Stage.h"

//constを使用してint変数を固定する→定数
const int WIDTH = 12;
const int HEIGHT = 8;


int map[HEIGHT][WIDTH] = {
	{1,1,1,1,1,1,1,1,0,2,0,1},
	{1,1,1,1,1,1,1,1,0,0,0,1},
	{0,0,0,1,1,0,0,0,1,0,0,1},
	{0,0,0,1,1,0,0,1,1,0,0,1},
	{0,0,0,1,1,0,1,1,0,0,0,1},
	{2,0,0,1,1,1,1,1,0,0,0,1},
	{0,0,0,1,1,1,1,0,0,0,0,1},
	{0,0,0,1,1,1,0,0,2,0,0,1},

};
//数字を使うと間違いやすく、扱いにくい→HEIGHT,WIDTHを使うことで、ぱっと見で理解しやすい


Stage::Stage()
{
	hImage = LoadGraph("data/image/parts.png");
}

Stage::~Stage()
{
}

void Stage::Draw()
{
	/**********************************
	 
	　個人的に理解しやすいプログラミング
	　縦に８個、横に８個、計６４個並べる
	　

	 プログラミングは、縦→横の順で書く


	//縦に８個並べる
	for (int j = 0; j < 8; j++) {
		DrawRectGraph(100, 100 + j * 42, 0, 40, 40, 40, hImage, TRUE);

		//縦に８個並べられたものから横に８個並べる
		for (int i = 0; i < 8; i++) {
			DrawRectGraph(100 + i * 42, 100, 0, 40, 40, 40, hImage, TRUE);

		}
	}

	************************************/
	
	
	for (int j = 0; j < HEIGHT; j++) {
		int y = j * 40 + 100;

		for (int i = 0; i < WIDTH; i++) {
			int x = i * 40 + 100;

			if (map[j][i] == 1) {
				DrawRectGraph(x, y, 0, 40, 40, 40, hImage, TRUE);

			}
			if (map[j][i] == 2) {
				DrawRectGraph(x, y, 120, 0, 40, 40, hImage, TRUE);

			}
		}
	}
}
