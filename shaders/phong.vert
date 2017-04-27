
uniform vec3 LightPosition;

varying vec3 norm;
varying vec3 lightVec;
varying vec3 viewVec;

void main(void)
{
    vec3 ecPosition = vec3(gl_ModelViewMatrix * gl_Vertex);
    norm      = normalize(gl_NormalMatrix * gl_Normal);
    lightVec   = normalize(LightPosition - ecPosition);
    viewVec    = normalize(-ecPosition);

    gl_Position     = ftransform();
}