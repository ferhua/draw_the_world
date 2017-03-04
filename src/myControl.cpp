#include "myControl.h"

myControl::myControl(){
	WIDTH=ofGetWidth();
	HEIGHT=ofGetHeight();
}

bool myControl::intersect(int x,int y,ofRectangle r)
{
	if(x>=r.getMinX()&&x<=r.getMaxX()
		&&y>=r.getMinY()&&y<=r.getMaxY())
		return true;
	else 
		return false;
}

//--------------------------------------------------------------
void myControl::initSequenceRiver(string path ,vector<ofImage>ani){ 
	ofDirectory dir;
	int nFiles = dir.listDir(path);
	if(nFiles&&ani.size()==0) 
		for(int i=0; i<dir.numFiles(); i++) { 
			string filePath = dir.getPath(i);
			ani.push_back(ofImage());
			ani.back().loadImage(filePath);
		}


	else printf("Could not find folder\n");
}

string myControl::intTostring(int i)
{
	stringstream s;
	s<<i;

	return s.str();
}
