#include "Stage.h"

//const���g�p����int�ϐ����Œ肷�遨�萔
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
//�������g���ƊԈႢ�₷���A�����ɂ�����HEIGHT,WIDTH���g�����ƂŁA�ς��ƌ��ŗ������₷��


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
	 
	�@�l�I�ɗ������₷���v���O���~���O
	�@�c�ɂW�A���ɂW�A�v�U�S���ׂ�
	�@

	 �v���O���~���O�́A�c�����̏��ŏ���


	//�c�ɂW���ׂ�
	for (int j = 0; j < 8; j++) {
		DrawRectGraph(100, 100 + j * 42, 0, 40, 40, 40, hImage, TRUE);

		//�c�ɂW���ׂ�ꂽ���̂��牡�ɂW���ׂ�
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
