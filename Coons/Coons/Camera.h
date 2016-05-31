#pragma once
class Camera
{
public:
	static void Camera::Add_Zoom_Factor(float value);
	static void Camera::SetRot_X(float angle);
	static void Camera::SetRot_Y(float angle);
	static void GetCamera();
	static float Pos_X, Pos_Y, Pos_Z, Rot_X, Rot_Y, Rot_Z, Speed, AngleSpeed, ZoomFactor;
};

