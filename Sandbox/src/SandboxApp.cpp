#include <Hazel.h>

class Sandbox : public Hazel::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}
	void Run() {
		int i = 0;
		while (i < 10) {
			printf("Hazel Running.....\n");
			i++;
		}
	}

};

Hazel::Application* Hazel::CreateApplication() {
	return new Sandbox();
}

