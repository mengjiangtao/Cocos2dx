#ifndef _ROCKET_H
#define _ROCKET_H

#include "cocos2d.h"
#include "GameSprite.h"

USING_NS_CC;

enum{
	ROTATE_NONE,
	ROTATE_CLOCKWISE,
	ROTATE_COUNTER
};

class Rocket : public GameSprite{

private:
	float _targetRotation;
	float _dr;
	float _ar;
	float _vr;
	float _rotationSpring;
	float _rotationDamping;

public:
	CC_SYNTHESIZE(CCPoint, _vector, Vector);
	CC_SYNTHESIZE(CCPoint, _pivot, Pivot);
	CC_SYNTHESIZE(float, _speed, Speed);
	CC_SYNTHESIZE(float, _angularSpeed, AngularSpeed);
	CC_SYNTHESIZE(int, _rotationOrientation, RotationOrientation);

	Rocket(void);
	~Rocket(void);

	static Rocket* create();
	void update(float dt);
	void reset(void);
	void select(bool flag);
	bool collidedWithSides(void);
	inline void setTargetRotation(float value){
		_targetRotation = value;
	}

	inline void setRotationFromVector(){
		this->setTargetRotation(CC_RADIANS_TO_DEGREES(atan2(-_vector.y, _vector.x)));
	}
};
#endif