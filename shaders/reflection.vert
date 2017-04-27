
uniform vec4 camPos;

varying vec3 normal;
varying vec3 incident;

void main(void)
{

  normal = gl_Normal;
  
  vec4 position = gl_Vertex;
  
  // Calculate incident vector
  incident = normalize(position.xyz - camPos.xyz);
  
  // vertex position
  gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}
