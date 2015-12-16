#include "ofMain.h"
#include "ofxDirectShowPlayer.h"

class ofApp : public ofBaseApp {

	// ofDirectShowPlayer player;
	ofxDirectShowPlayer player;
	ofTexture tex;

public:

	void setup() {
		player.load("test-ng.mov");
		player.play();
	}
	void update() {

		player.update();
		if (player.isFrameNew()) {
			tex.loadData(player.getPixels());
		}
	}
	void draw() {
		if (tex.isAllocated()) {
			tex.draw(0, 0);
		}
	}
};


int main() {

	ofSetupOpenGL(1920, 1080, OF_WINDOW);
	ofRunApp(new ofApp());

}

