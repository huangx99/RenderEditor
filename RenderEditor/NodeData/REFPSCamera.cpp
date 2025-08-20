#include "REFPSCamera.h"
#include <QDebug>

REFPSCamera::REFPSCamera(QVector3D startPos, float startYaw, float startPitch)
	: position(startPos), yaw(startYaw), pitch(startPitch)
{
	updateCameraVectors();
}

QMatrix4x4 REFPSCamera::getViewMatrix() const {
	QMatrix4x4 view;
	view.lookAt(position, position + front, up);
	return view;
}

void REFPSCamera::processKeyboard(Qt::Key key, float deltaTime) {
	float velocity = movementSpeed * deltaTime;
	if (key == Qt::Key_W) position += front * velocity;
	if (key == Qt::Key_S) position -= front * velocity;
	if (key == Qt::Key_A) position -= right * velocity;
	if (key == Qt::Key_D) position += right * velocity;
}

void REFPSCamera::processMouseMovement(float xoffset, float yoffset, bool constrainPitch) {
	xoffset *= mouseSensitivity;
	yoffset *= mouseSensitivity;

	yaw += xoffset;
	pitch += yoffset;
	if (constrainPitch) {
		if (pitch > 89.0f) pitch = 89.0f;
		if (pitch < -89.0f) pitch = -89.0f;
	}

	updateCameraVectors();
}

void REFPSCamera::updateCameraVectors() {
	QVector3D f;
	f.setX(cos(qDegreesToRadians(yaw)) * cos(qDegreesToRadians(pitch)));
	f.setY(sin(qDegreesToRadians(pitch)));
	f.setZ(sin(qDegreesToRadians(yaw)) * cos(qDegreesToRadians(pitch)));
	front = f.normalized();

	right = QVector3D::crossProduct(front, worldUp).normalized();
	up = QVector3D::crossProduct(right, front).normalized();
}
