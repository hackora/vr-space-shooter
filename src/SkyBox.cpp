#include "../include/SkyBox.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

SkyBox::SkyBox(std::shared_ptr<Camera> camera)
{
	privateInit();
	cam_ = camera;
}

SkyBox::~SkyBox()
{
}

void SkyBox::privateInit()
{

	skyboxShader.initShaders("/home/ghada/code/Space-Shooter/shaders/skybox");
	GLint texSampler;
	texSampler = glGetUniformLocation(skyboxShader.getProg(), "skybox");
	glUniform1i(texSampler, 0);

	faces_.push_back("/home/ghada/code/Space-Shooter/img/skybox/right.jpg");
	faces_.push_back("/home/ghada/code/Space-Shooter/img/skybox/left.jpg");
	faces_.push_back("/home/ghada/code/Space-Shooter/img/skybox/top.jpg");
	faces_.push_back("/home/ghada/code/Space-Shooter/img/skybox/bottom.jpg");
	faces_.push_back("/home/ghada/code/Space-Shooter/img/skybox/back.jpg");
	faces_.push_back("/home/ghada/code/Space-Shooter/img/skybox/front.jpg");

	glActiveTexture(GL_TEXTURE0);
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

	int width,height;
	unsigned char* image;  
	for(GLuint i = 0; i < faces_.size(); i++){
    	image = SOIL_load_image(faces_[i], &width, &height, 0, SOIL_LOAD_RGB);
    	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 
        0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	}

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

	skyboxShader.disable();

}

void SkyBox::privateRender()
{
	/*glDepthMask(GL_FALSE);// Remember to turn depth writing off

	// skybox cube
    glBindVertexArray(skyboxVAO);
    glActiveTexture(GL_TEXTURE0);
    glUniform1i(glGetUniformLocation(skyboxShader.getProg(), "skybox"), 0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
	glDepthMask(GL_TRUE);*/

	glColor3f(1.0, 1.0, 1.0);

	skyboxShader.enable();
	glFrontFace(GL_CW);
	glDisable(GL_DEPTH_TEST);
	glActiveTexture(GL_TEXTURE0);
	glEnable(GL_TEXTURE_CUBE_MAP);
	glBindTexture(GL_TEXTURE_CUBE_MAP,textureID);

	//glScalef(50,50,50);

	float v[8][3] = {
		{ -1.0f, -1.0f,  1.0f },
		{ 1.0f, -1.0f,  1.0f },
		{ 1.0f,  1.0f,  1.0f },
		{ -1.0f,  1.0f,  1.0f },
		{ -1.0f, -1.0f, -1.0f },
		{ 1.0f, -1.0f, -1.0f },
		{ 1.0f,  1.0f, -1.0f },
		{ -1.0f,  1.0f, -1.0f },
	};

	unsigned int i[24] = {
		0,1,2,3,
		1,5,6,2,
		5,4,7,6,
		4,0,3,7,
		0,4,5,1,
		2,6,7,3
	};

	glBegin(GL_QUADS);
	for (int k = 0; k < 24; ++k) {
		glTexCoord3f(v[i[k]][0], v[i[k]][1], v[i[k]][2]);
		glVertex3f(v[i[k]][0], v[i[k]][1], v[i[k]][2]);
	}
	glEnd();

	glDisable(GL_TEXTURE_CUBE_MAP);
	glActiveTexture(GL_TEXTURE0);
	glEnable(GL_DEPTH_TEST);
	glFrontFace(GL_CCW);
	skyboxShader.disable();


}

void SkyBox::privateUpdate()
{
	matrix_[3][0] = -cam_->getMatrix()[3][0];
	matrix_[3][1] = -cam_->getMatrix()[3][1];
	matrix_[3][2] = -cam_->getMatrix()[3][2];
}