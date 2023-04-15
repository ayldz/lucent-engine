#include <iostream>
#include <Lucent.h>

class MyScript : public Script {
private:
	float speed = 1000.0f;
	Transform* transform = nullptr;

public:
	MyScript(const std::string& n) : Script(n) {}

	void Start() {
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

class MyScene : public Scene {
	void Start() override {
		Resources::LoadTexture("./res/container.jpg", false, "container");
		Resources::LoadShader("./res/shaders/sprite.vert", "./res/shaders/sprite.frag", nullptr, "sprite");

		for (int j = 0; j < 60; j++) {
			for (int i = 0; i < 60; i++) {
				Entity* entity = new Entity();
				entity->AddComponent<SpriteRenderer>("SpriteRenderer");
				entity->AddComponent<MyScript>("Script");


				Transform& transform = entity->AddComponent<Transform>("Transform");
				transform.SetPosition(glm::vec3(70 * j, 55 * i, 0));
				transform.SetScale(glm::vec3(50.0f, 50.0f, 0.0f));

				this->AddEntity(*entity);
			}
		}
		
	}

	void Update(double dt) override {

	}
};

Game& game = Game::Instance();
int main()
{
	game.Init();
	MyScene* my_scene = new MyScene();

	game.SetScene(my_scene);

	game.Run();

	return 0;
}
