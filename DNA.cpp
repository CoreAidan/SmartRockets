#include "DNA.h"
#include <iostream>

CoreAidan::DNA::DNA(){
	size = 400;
	createDNA();
}

CoreAidan::DNA::DNA(std::vector<Vector2d*> genes){
	size = genes.size();
	_genes = genes;
}

CoreAidan::DNA::~DNA(){
}

CoreAidan::DNA CoreAidan::DNA::crossover(DNA partner){
	std::vector<Vector2d*> newGenes;
	int midPoint = rand() % size;

	for (int i = 0; i < size; i++) {
		if (i > midPoint) {
			newGenes.push_back(_genes.at(i));
		}
		else {
			newGenes.push_back(partner._genes.at(i));
		}
	}
	//std::cout << "new genes size: " << newGenes.size() << std::endl;
	return DNA(newGenes);
}

void CoreAidan::DNA::createDNA(){
	//srand(time(0));
	for (int i = 0; i < size; i++) {
		_genes.push_back(new Vector2d(-.1f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (.1f - -.1f)))
			, -.1f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (.1f - -.1f)))));
	}
}
