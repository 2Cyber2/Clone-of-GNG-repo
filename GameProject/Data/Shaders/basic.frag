
uniform sampler2D u_texture;
varying vec4 v_colour;
varying vec2 v_UV;

uniform vec2 m_uvOffset;
uniform vec2 m_uvScale;

void main()
{
	vec4 colour = texture2D( u_texture, v_UV * m_uvScale + m_uvOffset);
	
	gl_FragColor = colour;
	//gl_FragColor = v_colour;
}