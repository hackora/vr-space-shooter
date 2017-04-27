#version 120

varying vec2 texCoord;
uniform sampler2D height;

void main()
{
	texCoord = gl_MultiTexCoord0.xy;
        gl_FrontColor = gl_Color;
	vec4 pos = gl_Vertex;
	pos.y = (texture2D(height, texCoord)*200.0).x-200.0;
        gl_Position = gl_ModelViewProjectionMatrix * pos;
}
