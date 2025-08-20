#pragma once
#include <QMatrix4x4>
#include <QVector3D>
#include <QtMath>
#include <Qt>

class REFPSCamera {
public:
	REFPSCamera(QVector3D startPos = { 0.0f, 0.0f, 3.0f },
		float startYaw = -90.0f,
		float startPitch = 0.0f);

	QMatrix4x4 getViewMatrix() const;

	void processKeyboard(Qt::Key key, float deltaTime);
	void processMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);

	QVector3D position;

private:
	QVector3D front;
	QVector3D up;
	QVector3D right;
	QVector3D worldUp = { 0.0f, 1.0f, 0.0f };

	float yaw;
	float pitch;
	float movementSpeed = 0.9f;
	float mouseSensitivity = 0.005f;

	void updateCameraVectors();
};
