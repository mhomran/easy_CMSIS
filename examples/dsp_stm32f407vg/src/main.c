#include "DSP/Include/dsp/statistics_functions.h"

int main () {
	float32_t vec[] = {1, 2, 3};
	float32_t result;
	arm_mean_f32(vec, sizeof(vec)/sizeof(*vec), &result);
	
	while(1);
}
