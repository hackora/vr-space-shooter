#version 120



void main()
{
    vec3 Normal = gl_NormalMatrix * gl_Normal;
    vec4 Position = gl_Vertex;
    vec3 CameraPosition = vec3(0.0,0.0,1.0);
    vec3 Reflection = reflect(Position.xyz - CameraPosition, normalize(Normal));
    gl_TexCoord[0].stp = vec3(Reflection.x, -Reflection.yz);
    gl_Position = gl_ModelViewProjectionMatrix * Position;
}