
uniform samplerCube cubeMap;

varying vec3 normal;
varying vec3 incident;

void main(void)
{
  vec3 normalVec = normalize(normal);
  vec3 incidentVec = normalize(incident);
  
  // Calculate reflection color
  vec3 reflectColor = textureCube(cubeMap, reflect(incidentVec, normalVec)).xyz;
  
  // Fragment color
  gl_FragColor = vec4(reflectColor, 1.0);
}