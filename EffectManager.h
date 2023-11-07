#pragma once
#include "ViewProjection.h"

#include "Bubble.h"


#include <list>

class EffectManager {
public:
	enum class Effect{
		kBubble,
	};

public:
	

	void Initialize(Effect effect,uint32_t count, const WorldTransform& worldTransform, const ViewProjection& viewProjection);

	void Update();

	void Draw(/*ViewProjection& viewProjection*/);

private:
	

private:
	std::list<Bubble*> bubbles_;

};
