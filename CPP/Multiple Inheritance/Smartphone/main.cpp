#include <iostream>
using namespace std;

class Camera {
public:
    void clickPhoto() { cout << "Photo clicked!\n"; }
};

class MusicPlayer {
public:
    void playMusic() { cout << "Playing music!\n"; }
};

class Smartphone : public Camera, public MusicPlayer {};

int main() {
    Smartphone phone;
    phone.clickPhoto();
    phone.playMusic();
    return 0;
}
