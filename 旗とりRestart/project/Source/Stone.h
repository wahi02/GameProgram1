#pragma once
#include "../Library/gameObject.h"
#include "Vector2.h"

class Stone : public GameObject {
public:
	Stone();
	~Stone();
	void Update() override;
	void Draw() override;

	int hImage; // �摜
	VECTOR2 position;
};