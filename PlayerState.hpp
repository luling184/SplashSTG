#pragma once

enum class MoveDirection {
	Up,
	Down,
	Left,
	Right,
	Non,
};

struct PlayerState {
	MoveDirection moveDirection;
	bool isOnBlock;
	bool isJumping;
};
