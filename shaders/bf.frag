#version 120

varying vec2 texCoord;
uniform sampler2D color;

void main(void)
{   
	gl_FragColor = gl_Color * texture2D(color, texCoord.xy);
}
