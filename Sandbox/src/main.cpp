#include <iostream>
#include <Lucent.h>

class MyScript : public Script
{
private:
	float speed = 10.0f;
	Transform *transform = nullptr;

public:
	MyScript(const std::string &n) : Script(n) {}

	void Start()
	{
		transform = &(entity->GetComponent<Transform>());
	}

	void Update(float dt) override
	{
		if (Input::GetButton(KeyCode::LeftArrow))
		{
			glm::vec3 p = transform->GetPosition();
			glm::vec3 newPos = glm::vec3(p.x - (1.0f * speed * dt), p.y, p.z);
			transform->SetPosition(newPos);
		}

		else if (Input::GetButton(KeyCode::RightArrow))
		{
			glm::vec3 p = transform->GetPosition();
			glm::vec3 newPos = glm::vec3(p.x + (1.0f * speed * dt), p.y, p.z);
			transform->SetPosition(newPos);
		}

		if (Input::GetButton(KeyCode::UpArrow))
		{
			glm::vec3 p = transform->GetPosition();
			glm::vec3 newPos = glm::vec3(p.x, p.y + (1.0f * speed * dt), p.z);
			transform->SetPosition(newPos);
		}

		else if (Input::GetButton(KeyCode::DownArrow))
		{
			glm::vec3 p = transform->GetPosition();
			glm::vec3 newPos = glm::vec3(p.x, p.y - (1.0f * speed * dt), p.z);
			transform->SetPosition(newPos);
		}
	}
};

class MyScene : public Scene
{
	void Start() override
	{
		Texture containerTex = Resources::LoadTexture("./res/container.jpg", false, "container");
		Shader defaultShader = Resources::LoadShader("./res/shaders/sprite.vert", "./res/shaders/sprite.frag", nullptr, "sprite");

		for (int j = 0; j < 12; j++)
		{
			for (int i = 0; i < 12; i++)
			{
				Entity *entity = new Entity();
				SpriteRenderer &sp = entity->AddComponent<SpriteRenderer>("SpriteRenderer");
				sp.SetTexture(containerTex);
				sp.SetShader(defaultShader);

				entity->AddComponent<MyScript>("Script");

				Transform &transform = entity->AddComponent<Transform>("Transform");
				transform.SetPosition(glm::vec3(1.2 * j, 1.2 * i, 0));

				this->AddEntity(*entity);
			}
		}
	}

	void Update(double dt) override
	{
		const float cameraSpeed = 0.5f; 
		if (Input::GetButton(KeyCode::W))
		{
			camera.Move(cameraSpeed * glm::vec3(0, 1, 0));
		}
		if (Input::GetButton(KeyCode::S))
		{
			camera.Move(cameraSpeed * glm::vec3(0, -1, 0));
		}
		if (Input::GetButton(KeyCode::A))
		{
			camera.Move(cameraSpeed * glm::vec3(-1, 0, 0));
		}
		if (Input::GetButton(KeyCode::D))
		{
			camera.Move(cameraSpeed * glm::vec3(1, 0, 0));
		}

		if (Input::GetButton(KeyCode::E))
		{
			camera.Rotate(glm::vec3(0, 0, glm::radians(-0.5)));
		}

		if (Input::GetButton(KeyCode::Q))
		{
			camera.Rotate(glm::vec3(0, 0, glm::radians(0.5)));
		}
	}
};

Game &game = Game::Instance();
int main()
{
	game.Init();
	MyScene *my_scene = new MyScene();
	
	game.SetScene(my_scene);

	game.Run();

	return 0;
}
