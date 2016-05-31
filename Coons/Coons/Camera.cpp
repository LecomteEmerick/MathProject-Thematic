#include "Camera.h"

#include "GL\glew.h"

float Camera::Pos_X;
float Camera::Pos_Y;
float Camera::Pos_Z;
float Camera::Rot_X;
float Camera::Rot_Y;
float Camera::Rot_Z;
float Camera::Speed = 10.0f;
float Camera::AngleSpeed = 0.1f;
float Camera::ZoomFactor = 10.0f;
//
//void Camera::Add_Zoom_Factor(float value)
//{
//	ZoomFactor += value;
//
//	if (ZoomFactor > 40.0f)
//	{
//		ZoomFactor = 40.0f;
//	}
//	if (ZoomFactor < -40.0f)
//	{
//		ZoomFactor = -40.0f;
//	}
//}

void Camera::SetRot_X(float angle)
{
	Rot_X += angle;

	if (Rot_X > 360)
	{
		Rot_X -= 360;
	}
	if (Rot_X < 0)
	{
		Rot_X += 360;
	}
}

void Camera::SetRot_Y(float angle)
{
	Rot_Y += angle;

	if (Rot_Y > 360)
	{
		Rot_Y -= 360;
	}
	if (Rot_Y < 0)
	{
		Rot_Y += 360;
	}
}

void Camera::GetCamera()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW_MATRIX);
	glTranslatef(Pos_X, Pos_Y, Pos_Z);

	glRotatef(Rot_X, 0, 1, 0);
	glRotatef(Rot_Y, 1, 0, 0);
	glRotatef(Rot_Z, 0, 0, 1);
}

