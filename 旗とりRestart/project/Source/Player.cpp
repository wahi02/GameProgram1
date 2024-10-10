#include "Player.h"
#include "config.h"
#include "Bird.h"
#include "Stone.h"

Player::Player()
{
	hImage = LoadGraph("data/image/aoi.png");
	position.x = 10;
	position.y = 100;
	speed.x = 0.0;
	speed.y = 0.0f;
	patternX = 0;
	patternY = 0;
	frameCounter = 0;
	crying = false;
}

Player::~Player()
{
	DeleteGraph(hImage);
}

void Player::Update()
{
	if (crying) {
		CryAnimation();
	}
	else {
		bool move = false;
		if (CheckHitKey(KEY_INPUT_D)) {
			speed.x += 0.1f;
			if (speed.x > 2.0f) {
				speed.x = 2.0f;
			}
			move = true;
		}
		else if (CheckHitKey(KEY_INPUT_A)) {
			speed.x -= 0.1f;
			if (speed.x < -2.0f) {
				speed.x = -2.0f;
			}
			move = true;
		}
		else {
			if (speed.x >= 0.1f) {
				speed.x -= 0.1f;
			}
			else if (speed.x <= -0.1f) {
				speed.x += 0.1f;
			}
			else {
				speed.x = 0.0f;
			}
		}
		position.x += speed.x;
		if (position.x < 0) {
			position.x = 0;
		}
		if (position.x > SCREEN_WIDTH - 64) {
			position.x = SCREEN_WIDTH - 64;
		}

		if (CheckHitKey(KEY_INPUT_W)) {
			speed.y -= 0.1f;
			if (speed.y < -2.0f) {
				speed.y = -2.0f;
			}
			move = true;
		}
		else if (CheckHitKey(KEY_INPUT_S)) {
			speed.y += 0.1f;
			if (speed.y > 2.0f) {
				speed.y = 2.0f;
			}
			move = true;
		}
		else {
			if (speed.y >= 0.1f) {
				speed.y -= 0.1f;
			}
			else if (speed.y <= -0.1f) {
				speed.y += 0.1f;
			}
			else {
				speed.y = 0.0f;
			}
		}
		position.y += speed.y;
		if (position.y < 0) {
			position.y = 0;
		}
		if (position.y > SCREEN_HEIGHT - 64) {
			position.y = SCREEN_HEIGHT - 64;
		}

		if (move) {
			frameCounter = (frameCounter + 1) % 15;
			if (frameCounter == 0) {
				patternX = (patternX + 1) % 4;
			}
		}
		else {
			patternX = 0;
			frameCounter = 0;
		}
		// �΂𓊂���
		if (CheckHitKey(KEY_INPUT_SPACE)) {
			if (prevKey == false) {
				Stone* st = Instantiate<Stone>();
				// ������Ă��瑫�����@
				st->position = position;
				st->position.x += 30;
				st->position.y += 5;
				// ������鎞�ɑ������@
				st->position.x = position.x + 30;
				st->position.y = position.y + 5;
				// �����܂ŁA�ǂ��炩���g��
			}
			prevKey = true;
		}
		else {
			prevKey = false;
		}

		// ���Ɠ��Ă�
		std::list<Bird*> birds = FindGameObjects<Bird>();
		for (Bird* b : birds) {
			if (CircleHit(position, b->position, 56)) {
				// position��bird->position�̋�����56��菬������
				patternY = 4; // ����
				crying = true;
			}
		}

	}
}

void Player::Draw()
{
	DrawRectGraph(position.x, position.y, patternX*64, patternY*64, 64, 64, hImage, TRUE);
}

void Player::CryAnimation()
{
	frameCounter = (frameCounter + 1) % 10;
	if (frameCounter == 0) {
		patternX = (patternX + 1) % 2;
	}
}
