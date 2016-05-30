varying vec3 v_normal;
varying vec4 v_color;

uniform sampler2D textureSampler;

#define VERTEX_LIGHTING 1

const vec3 c_lightDirection = vec3(0.0, 1.0, 0.0);

void main(void)
{
#if VERTEX_LIGHTING
    gl_FragColor = v_color;
#else
    vec3 N = normalize(v_normal);
	vec3 L = normalize(c_lightDirection);
	float NdotL = max(dot(N, L), 0.0);

  	gl_FragColor = v_color * NdotL;
#endif
}