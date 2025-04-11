#pragma once
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
class camera
{
public:

	camera() {
		//z: -1.0f estamos viendo al cuadrado que esta en -z por uOffset
		mEye = glm::vec3(0.0f, 0.0f, 0.0f);
		mViewDirection = glm::vec3(0.0f, 0.0f, -1.0f);
		mUpVector = glm::vec3(0.0f, 1.0f, 0.0f);
	}

	glm::mat4 GetViewMatrix()const {
		return glm::lookAt(mEye,mEye+mViewDirection,mUpVector);
	}
	void MoveForward(float speed);
	void MoveBackward(float speed);
	void MoveLatLeft(float speed);
	void MoveLatRigth(float speed);
	void MouseMovement(float mouseX, float mouseY);

private:
	glm::vec3 mEye;
	glm::vec3 mViewDirection;
	glm::vec3 mUpVector;

	glm::mat4 mViewMatrix;
};

