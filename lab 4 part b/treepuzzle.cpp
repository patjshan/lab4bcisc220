/*
 * TreePuzzle.cpp
 *
 *  Created on: Apr 1, 2018
 *      Author: Debras
 */

#include <iostream>
#include <stdlib.h>
#include <fstream>

#include "treepuzzle.hpp"
using namespace std;

treePuzzle::treePuzzle(int x, string sarr[], int k) {
	cout << "entered treepuzzle" << endl;
	tree = new BSTY();
	//cout << "made bsty on heap" << endl;
	for(int i = 0; i < x; i++) {
		cout << sarr[i] << " in loop" << endl;
		tree->insertit(sarr[i]);
	}
	if (k == 0) {
		cout << "entereing runmine1" << endl;
		runMine1(true);
	}
	cout << endl<<"*******************************"<<endl<<"PREORDER " << endl;
	tree->printTreePre();
	cout << "*******************************"<<endl<<"INORDER " << endl;
	tree->printTreeIO();
	cout << "*******************************"<<endl<<"POSTORDER " << endl;
	tree->printTreePost();
	cout << endl;

	if (k == 0) {
		runMine1(false);
	}
	else if (k ==1){
		runMine2();
	}
}
treePuzzle::treePuzzle(string fname,int k) {
	tree = new BSTY();
	readFile2(fname,k);
	cout << "*******************************"<<endl<<"INORDER " << endl;
	tree->printTreeIO();
	cout <<endl << "*******************************FIND" << endl;
	tree->find("pichiciego")->printNode();
	tree->find("falanouc")->printNode();
	tree->find("blauwbok")->printNode();
	tree->find("dibatag")->printNode();
	tree->find("gharial")->printNode();
	tree->find("duarf")->printNode();
	tree->find("kinkajou")->printNode();
	tree->find("zyzzyva")->printNode();
	tree->find("tucutucu")->printNode();
	tree->find("tabanid")->printNode();
	tree->find("solenodon")->printNode();
	tree->find("axolotl")->printNode();
}
void treePuzzle::readFile2(string fname, int size) {
	ifstream file(fname.c_str());
	string word;
	string def;
	int ct = 0;
	while (!file.eof() && ct < size) {
		file >> word;
		cout << word << endl;
		getline(file,def);
		def = def.substr(2);
		tree->insertit(word, def);

		cout << def << endl;
	}

}

void treePuzzle::runMine1(bool flag) {
	if (flag) {
		cout << "Mine " << endl;
		tree->myPrint();
	}
	else {
		cout << endl << "PART TWO " << endl;
		tree->find("ocelot");
		tree->find("perforated");
		tree->find("sibylic");
		tree->find("go");
	}
}
void treePuzzle::runMine2() {
	cout << "Mine2 " << endl;
	cout << endl << "EXTRA CREDIT " << endl;
	tree->remove("apple");
	cout << "AFTER REMOVE:" << endl;
	tree->printTreeIO();
	cout <<endl << "NOW REMOVING " ;
	tree->remove("noon");
	cout << "AFTER REMOVE:" << endl;
	tree->printTreeIO();
	cout <<endl << "NOW REMOVING " ;
	tree->remove("jack");
	cout << "AFTER REMOVE:" << endl;
	tree->printTreeIO();
	cout <<endl << "NOW REMOVING " ;
	tree->remove("xray");
	cout << "AFTER REMOVE:" << endl;
	tree->printTreeIO();
	cout << endl << "MineEC: " << endl;
	tree->myPrintEC();
}
treePuzzle::~treePuzzle() {
	delete tree;
}


