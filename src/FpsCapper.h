#ifndef HAPPYFPSCAP
#define HAPPYFPSCAP

#define MILISECONDSPERFRAME 16.667

// The milisecodnds at the start of the frame.
u64 frameStartMiliseconds;
//u64 numberOfFrames;
signed char capEnabled = 1;

void FpsCapStart(){
	frameStartMiliseconds = GetTicks();
}

void FpsCapWait(){
	if (capEnabled==1){
		// I just hope I only use this at the end of a frame....
		//numberOfFrames=numberOfFrames+1;
		u64 tempHold;
		tempHold = GetTicks();
		//printf("%llu;%llu\n",frameStartMiliseconds,tempHold);
		// LIMIT FPS
		if (tempHold-frameStartMiliseconds<MILISECONDSPERFRAME){
			Wait( MILISECONDSPERFRAME - (tempHold-frameStartMiliseconds));
		}else{
			//printf("Slowdown %llu\n", tempHold-frameStartMiliseconds);
			//printf("Slowdown %d\n",MILISECONDSPERFRAME - (tempHold-frameStartMiliseconds));
			//printf("Slowdown: %d\n",tempHold-frameStartMiliseconds-MILISECONDSPERFRAME);
		}
	}else{
		#if PLATFORM == PLAT_VITA
			sceKernelPowerTick(SCE_KERNEL_POWER_TICK_DISABLE_AUTO_SUSPEND);
		#endif
	}
}

#endif