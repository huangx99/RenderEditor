#include "Mesh.h"

Mesh::Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures, QOpenGLFunctions_3_3_Core* func)
{
	this->vertices = vertices;
	this->indices = indices;
	this->textures = textures;

	_func = func;

	// now that we have all the required data, set the vertex buffers and its attribute pointers.
	setupMesh();
}

void Mesh::Draw(std::shared_ptr<QOpenGLShaderProgram> shader)
{
	shader->bind();
	// bind appropriate textures
	unsigned int diffuseNr = 1;
	unsigned int specularNr = 1;
	unsigned int normalNr = 1;
	unsigned int heightNr = 1;
	for (unsigned int i = 0; i < textures.size(); i++)
	{
		_func->glActiveTexture(GL_TEXTURE0 + i); // active proper texture unit before binding
		// retrieve texture number (the N in diffuse_textureN)
		string number;
		string name = textures[i].type;
		if (name == "texture_diffuse")
			number = std::to_string(diffuseNr++);
		else if (name == "texture_specular")
			number = std::to_string(specularNr++); // transfer unsigned int to string
		else if (name == "texture_normal")
			number = std::to_string(normalNr++); // transfer unsigned int to string
		else if (name == "texture_height")
			number = std::to_string(heightNr++); // transfer unsigned int to string

		// now set the sampler to the correct texture unit
		shader->setUniformValue((name + number).c_str(), i);
		// and finally bind the texture
		_func->glBindTexture(GL_TEXTURE_2D, textures[i].id);
	}

	// draw mesh
	_func->glBindVertexArray(VAO);
	_func->glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
	_func->glBindVertexArray(0);

	// always good practice to set everything back to defaults once configured.
	_func->glActiveTexture(GL_TEXTURE0);
}

void Mesh::clear()
{
	_func->glDeleteBuffers(0, &VBO);
	_func->glDeleteBuffers(0, &EBO);
	_func->glDeleteVertexArrays(0, &VAO);
}

void Mesh::setupMesh()
{
	// create buffers/arrays
	_func->glGenVertexArrays(1, &VAO);
	_func->glGenBuffers(1, &VBO);
	_func->glGenBuffers(1, &EBO);

	_func->glBindVertexArray(VAO);
	// load data into vertex buffers
	_func->glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// A great thing about structs is that their memory layout is sequential for all its items.
	// The effect is that we can simply pass a pointer to the struct and it translates perfectly to a glm::vec3/2 array which
	// again translates to 3/2 floats which translates to a byte array.
	_func->glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	_func->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	_func->glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	// set the vertex attribute pointers
	// vertex Positions
	_func->glEnableVertexAttribArray(0);
	_func->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	// vertex normals
	_func->glEnableVertexAttribArray(1);
	_func->glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
	// vertex texture coords
	_func->glEnableVertexAttribArray(2);
	_func->glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
	// vertex tangent
	_func->glEnableVertexAttribArray(3);
	_func->glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Tangent));
	// vertex bitangent
	_func->glEnableVertexAttribArray(4);
	_func->glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Bitangent));
	// ids
	_func->glEnableVertexAttribArray(5);
	_func->glVertexAttribIPointer(5, 4, GL_INT, sizeof(Vertex), (void*)offsetof(Vertex, m_BoneIDs));

	// weights
	_func->glEnableVertexAttribArray(6);
	_func->glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, m_Weights));
	_func->glBindVertexArray(0);
}
