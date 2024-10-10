#pragma once
#include "../Library/gameObject.h"
#include "Vector2.h"

class Bird : public GameObject {
public:
	Bird();
	~Bird();
	void Update() override;
	void Draw() override;

	int hImage; // �摜
	VECTOR2 position;
	VECTOR2 speed;
	int patternX; // �A�j���[�V�����̊G
	int patternY;
	int frameCounter;

	int timer; // ���Ԃ𑪂邽��
	bool attacking; // �˓����Ă܂�

	bool dead; // ���񂾂�true
	int deadCounter; // ����ł鎞��
};