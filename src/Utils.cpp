#include "Utils.h"

bool Utils::isStopCondition(size_t generation, size_t maxGeneration) {
	return generation > maxGeneration;
}

int Utils::selectIndex(float* scores, float totalScore) {
	float currValue = (float)rand() / RAND_MAX * totalScore;
	size_t scoresLength = sizeof(scores) / sizeof(*scores);
	int index = -1;
	do {
		currValue -= scores[++index];
		scoresLength--;
	} while (currValue > 1e-6 && scoresLength > 0);
	return index;
}

float Utils::getRandZeroToOne() {
	double randValue = ((double)rand()) / RAND_MAX;
	return (float)randValue;
}