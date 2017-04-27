
uniform vec3 ObjColor;

varying vec3 norm;
varying vec3 lightVec;
varying vec3 viewVec;

void main(void)
{   
	vec3 nVec = normalize(norm);
	vec3 lVec = normalize(lightVec);
	vec3 vVec = normalize(viewVec);
	
	float diffuse = clamp(dot(lVec, nVec), 0.0, 1.0);
	float specular = pow(clamp(dot(reflect(-vVec, nVec), lVec), 0.0, 1.0), 32.0);
	
	vec3 col = ObjColor * (diffuse+0.1) + (specular*0.9);
    gl_FragColor = vec4(col, 1.0);

   
}