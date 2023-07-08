#include "mesh.h"

namespace Lucent {
	Mesh Mesh::QuadMesh{
		{
			{{0.5f, 0.5f, 0.0f}, { 1.0f, 1.0f }},
			{ {0.5f, -0.5f, 0.0f},  {1.0f, 0.0f} },
			{ {-0.5f, -0.5f, 0.0f},  {0.0f, 0.0f} },
			{ {-0.5f,  0.5f, 0.0f},  {0.0f, 1.0f} }
		},
	{
		0, 1, 3,
		1, 2, 3
	}
	};
}