#pragma once

#define SWAP_ROWS_DOUBLE(a, b) { double *_tmp = a; (a) = (b); (b) = _tmp; }
#define SWAP_ROWS_FLOAT(a, b) { float *_tmp = a; (a) = (b); (b) = _tmp; }
#define MAT(m, r, c) (m)[(c) * 4 + (r)]

class OpenGl_Legacy
{
public:
	static int glhProjectf(float objx, float objy, float objz, float *modelview, float *projection, int *viewport, float *windowCoordinate);
	static int glhUnProjectf(float winx, float winy, float winz, float *modelview, float *projection, int *viewport, float *objectCoordinate);
private:
	static void MultiplyMatrices4by4OpenGL_FLOAT(float *result, float *matrix1, float *matrix2);
	static void MultiplyMatrixByVector4by4OpenGL_FLOAT(float *resultvector, const float *matrix, const float *pvector);
	static int glhInvertMatrixf2(float *m, float *out);
};

