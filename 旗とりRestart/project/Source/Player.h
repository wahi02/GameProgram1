#pragma once
#include "../Library/gameObject.h"
#include "Vector2.h"

class Player : public GameObject {
public:
	Player();
	~Player();
	void Update() override;
	void Draw() override;

	void CryAnimation(); // ���������֐������

	int hImage; // �摜

	VECTOR2 position;
	VECTOR2 speed;

	int patternX; // �A�j���[�V�����̊G
	int patternY;
	int frameCounter;

	bool crying; // �����Ă�Ƃ�true

	bool prevKey; // �O�̃L�[��ۑ�����
};