#include "camera.h"
#include <gtx/rotate_vector.hpp>
#include <gtx/string_cast.hpp>

#include <iostream>

void camera::MoveForward(float speed) {
	mEye +=mViewDirection*speed;
	
}
void camera::MoveBackward(float speed) {
	mEye -= mViewDirection * speed;
}
void camera::MoveLatLeft(float speed) {
	mEye -= glm::cross((mViewDirection), mUpVector) * speed;
	
}
void camera::MoveLatRigth(float speed) {
	mEye += glm::cross((mViewDirection), mUpVector)*speed;
	

}

void camera::MouseMovement(float mouseX, float mouseY) {
	//sensibilidad
	mouseX = -mouseX * 0.2f;
	mouseY = -mouseY * 0.2f;
	std::cout << "mouse x: "<< mouseX << "\n";
	std::cout << "mouse y: " << mouseY << "\n";
	// si se aprita la d-a a la vez que se gira se modifica esto de manera trambolica
	mViewDirection = glm::rotate(mViewDirection, glm::radians(mouseX),mUpVector);
	mViewDirection = glm::rotate(mViewDirection, glm::radians(mouseY), glm::cross((mViewDirection),mUpVector));

}
