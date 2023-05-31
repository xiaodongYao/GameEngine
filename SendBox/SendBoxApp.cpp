#include <Hazel.h>

class SendBox :public Hazel::Application
{
public:
	SendBox() {};

	~SendBox() {};
};



int main()
{
	SendBox* sendBox = new SendBox();
	sendBox->run();
	delete sendBox;
}