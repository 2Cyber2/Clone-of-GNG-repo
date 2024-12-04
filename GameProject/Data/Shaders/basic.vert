attribute vec2 a_position;
attribute vec4 a_colour;
attribute vec2 a_UV;

varying vec2 v_UV;
varying vec4 v_colour;

uniform vec2 u_offset;
uniform vec2 u_Resolution;
uniform vec2 u_CameraPosition;

//uniform float u_green;
//uniform float u_red;
//uniform float u_blue;
//uniform float u_alpha;
//uniform float u_scale;

//uniform float u_rotation
//uniform float u_Time;
//uniform vec2 u_Resolution
//uniform float u_Time;

//uniform vec2 objScale;
//uniform vec2 u_ObjTranslation;
//uniform vec2 u_CamPos;
uniform vec2 u_Zoom;
//

void main()
{
//	vec2 pos = a_position + u_offset;
//	//pos.x *= sin(u_time);
//	//pos.y *= atan(u_time);
//	gl_Position = vec4(pos, 0, 1);
//	//glViewPort(pos, u_Resolution)

	vec2 objectScale = vec2(1, 1);
	vec2 objectTranslation = u_offset;
	vec2 cameraPosition = u_CameraPosition;
	vec2 zoom = u_Zoom;

	float aspect = u_Resolution.x/u_Resolution.y;

	vec2 objectSpacePosition = a_position;
	vec2 worldSpacePosition = objectSpacePosition * objectScale + objectTranslation;
	vec2 viewSpacePosition = worldSpacePosition - cameraPosition;
	vec2 clipSpacePosition = viewSpacePosition * zoom;
	clipSpacePosition.x =clipSpacePosition.x / aspect;

	gl_Position = vec4 (clipSpacePosition, 0, 1);

	v_UV = a_UV;
	v_colour = a_colour;
}
