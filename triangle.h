#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <vector>
#include <QOpenGLShaderProgram>

class Triangle
{
private:
	std::vector<float>			m_verticies;
	std::vector<float>			m_colors;

	QOpenGLShaderProgram*		m_program;
	int							m_vertexAttr;
	int							m_colorAttr;

	// левая нижняя координата и размер +1
	float						m_x0;
	float						m_y0;
	float						m_size;


	void						initVerticies();
	void						initColors();

public:
	Triangle(QOpenGLShaderProgram* program,
			 int vertexAttr, int colorAttr);

	void						draw();

	void						setX0(float x);
	void						setY0(float y);
	void						setSize(float s);
	float						x0() const;
	float						y0() const;
};

#endif // TRIANGLE_H
