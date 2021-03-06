#pragma once

#include "State.h"

class EnemyOne;
class EnemyIdle : public State<EnemyOne> {
public:
	EnemyIdle()
		:
		State()
	{}
public:
	// singleton reference
	static std::shared_ptr<EnemyIdle> Instance();
	virtual void Enter(EnemyOne*& entity) override;
	virtual void Execute(EnemyOne*& entity) override;
	virtual void Exit(EnemyOne*& entity) override;
};