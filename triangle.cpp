#include "triangle.h"

Triangle::Triangle(QOpenGLShaderProgram* program,
				   int vertexAttr, int colorAttr)
	:m_program(program),
	 m_vertexAttr(vertexAttr),
	 m_colorAttr(colorAttr),
	 m_x0(-0.5f), m_y0(-0.5f), m_size(1.0f)
{
	initVerticies();
	initColors();
}

void Triangle::draw()
{
	m_program->setAttributeArray(m_vertexAttr, m_verticies.data(), 3);
	m_program->setAttributeArray(m_colorAttr, m_colors.data(), 3);

	m_program->enableAttributeArray(m_vertexAttr);
	m_program->enableAttributeArray(m_colorAttr);

		glDrawArrays(GL_TRIANGLES, 0, m_verticies.size()/3);

	m_program->disableAttributeArray(m_colorAttr);
	m_program->disableAttributeArray(m_vertexAttr);
}

void Triangle::setX0(float x)
{
	m_x0 = x;
	initVerticies();
}

void Triangle::setY0(float y)
{
	m_y0 = y;
	initVerticies();
}

void Triangle::setSize(float s)
{
	m_size = s;
}

float Triangle::x0() const
{
	return m_x0;
}

float Triangle::y0() const
{
	return m_y0;
}

void Triangle::initVerticies()
{
	m_verticies.resize(9);

	// 0
	m_verticies[0] = m_x0;
	m_verticies[1] = m_y0;
	m_verticies[2] = 0.0f;

	// 1
	m_verticies[3] = m_x0 + m_size;
	m_verticies[4] = m_y0;
	m_verticies[5] = 0.0f;

	// 2
	m_verticies[6] = m_x0 + m_size/2;
	m_verticies[7] = m_y0 + m_size;
	m_verticies[8] = 0.0f;
}

void Triangle::initColors()
{
	m_colors.resize(9);

	// 0
	m_colors[0] = 1.0f;
	m_colors[1] = 0.0f;
	m_colors[2] = 0.0f;

	// 1
	m_colors[3] = 0.0f;
	m_colors[4] = 1.0f;
	m_colors[5] = 0.0f;

	// 2
	m_colors[6] = 0.0f;
	m_colors[7] = 0.0f;
	m_colors[8] = 1.0f;
}
