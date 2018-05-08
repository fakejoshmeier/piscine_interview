#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	printf("boss: gais we need more energy, pls add more energy\n");
	sleep(2);
	printf("me: ok\n");
	sleep(1);
	printf("me: tankPush(1)\n");
	tankPush(tank, 1);
	usleep(100000);
	printf("me: tankPush(1)\n");
	tankPush(tank, 1);
	usleep(100000);
	printf("me: tankPush(1)\n");
	tankPush(tank, 1);
	usleep(100000);
	printf("me: tankPush(1)\n");
	tankPush(tank, 1);
	usleep(100000);
	printf("me: tankPush(1)\n");
	tankPush(tank, 1);
	usleep(100000);
	printf("me: tankPush(1)\n");
	tankPush(tank, 1);
	usleep(100000);
	printf("me: tankPush(1)\n");
	tankPush(tank, 1);
	usleep(100000);
	printf("me: tankPush(1)\n");
	tankPush(tank, 1);
	usleep(100000);
	printf("me: tankPush(1)\n");
	tankPush(tank, 1);
	usleep(100000);
	sleep(2);
	printf("boss: gais there's no energy in the tank, wtf r u doin\n");
	sleep(2);
	printf("me: what\n");
	sleep(1);
	printf("me: tankPop() => %d\n", tankPop(tank));
	sleep(2);
	printf("me: wait, fuck, hold on\n");
	sleep(1);
	printf("me: tank->stacks[0]->sum => %d\n", tank->stacks[0]->sum);
	sleep(1);
	printf("me: lmao i can fix\n");
	sleep(1);
	printf("boss: u little shit u had one job\n");
	sleep(1);
	printf("me: tankPush(10)\n");
	tankPush(tank, 10);
	sleep(2);
	printf("boss: did u do it\n");
	sleep(1);
	printf("me: ye\n");
	sleep(1);
	printf("boss: tank->stacks[0]->sum => %d\n", tank->stacks[0]->sum);
	sleep(2);
	printf("boss: r u fuckin srs\n");
	sleep(2);
	printf("boss: fuck this\n");
	sleep(1);
	printf("boss: tankPush(100)\n");
	tankPush(tank, 100);
	usleep(100000);
	printf("boss: tankPush(100)\n");
	tankPush(tank, 100);
	usleep(100000);
	printf("boss: tankPush(100)\n");
	tankPush(tank, 100);
	usleep(100000);
	printf("boss: tankPush(100)\n");
	tankPush(tank, 100);
	usleep(100000);
	printf("boss: tankPush(100)\n");
	tankPush(tank, 100);
	usleep(100000);
	printf("boss: tankPush(100)\n");
	tankPush(tank, 100);
	usleep(100000);
	printf("boss: tankPush(100)\n");
	tankPush(tank, 100);
	usleep(100000);
	printf("boss: tankPush(100)\n");
	tankPush(tank, 100);
	usleep(100000);
	printf("boss: tankPush(100)\n");
	tankPush(tank, 100);
	sleep(1);
	printf("boss: tank->stacks[0]->sum => %d\n", tank->stacks[0]->sum);
	sleep(1);
	printf("boss: fuckin finally\n");
	sleep(2);
	printf("boss: im gonna fill the next tank too\n");
	sleep(1);
	printf("boss: tankPush(100)\n");
	tankPush(tank, 100);
	usleep(100000);
	printf("boss: tankPush(100)\n");
	tankPush(tank, 100);
	usleep(100000);
	printf("boss: tankPush(100)\n");
	tankPush(tank, 100);
	usleep(100000);
	printf("boss: tankPush(100)\n");
	tankPush(tank, 100);
	usleep(100000);
	printf("boss: tankPush(100)\n");
	tankPush(tank, 100);
	usleep(100000);
	printf("boss: tankPush(100)\n");
	tankPush(tank, 100);
	usleep(100000);
	printf("boss: tankPush(100)\n");
	tankPush(tank, 100);
	usleep(100000);
	printf("boss: tankPush(100)\n");
	tankPush(tank, 100);
	usleep(100000);
	printf("boss: tankPush(100)\n");
	tankPush(tank, 100);
	usleep(100000);
	printf("boss: tankPush(100)\n");
	tankPush(tank, 100);
	sleep(1);
	printf("boss: tank->stacks[1]->sum => %d\n", tank->stacks[1]->sum);
	sleep(1);
	printf("boss: we should be good to go now\n");
	sleep(2);
	printf("me: let me check\n");
	sleep(1);
	printf("me: tankPop() => %d\n", tankPop(tank));
	sleep(2);
	printf("me: o nice\n");
	sleep(1);
	printf("me: tankPop() => %d\n", tankPop(tank));
	usleep(100000);
	printf("me: tankPop() => %d\n", tankPop(tank));
	usleep(100000);
	printf("me: tankPop() => %d\n", tankPop(tank));
	usleep(100000);
	printf("me: tankPop() => %d\n", tankPop(tank));
	usleep(100000);
	printf("me: tankPop() => %d\n", tankPop(tank));
	usleep(100000);
	printf("me: tankPop() => %d\n", tankPop(tank));
	usleep(100000);
	printf("me: tankPop() => %d\n", tankPop(tank));
	usleep(100000);
	printf("me: tankPop() => %d\n", tankPop(tank));
	usleep(100000);
	printf("me: tankPop() => %d\n", tankPop(tank));
	usleep(100000);
	printf("me: tankPop() => %d\n", tankPop(tank));
	sleep(2);
	printf("me: that's awesome\n");
	sleep(3);
	printf("me: tankPop() => %d\n", tankPop(tank));
	usleep(100000);
	printf("me: tankPop() => %d\n", tankPop(tank));
	usleep(100000);
	printf("me: tankPop() => %d\n", tankPop(tank));
	usleep(100000);
	printf("me: tankPop() => %d\n", tankPop(tank));
	usleep(100000);
	printf("me: tankPop() => %d\n", tankPop(tank));
	usleep(100000);
	printf("me: tankPop() => %d\n", tankPop(tank));
	usleep(100000);
	printf("me: tankPop() => %d\n", tankPop(tank));
	usleep(100000);
	printf("me: tankPop() => %d\n", tankPop(tank));
	usleep(100000);
	printf("me: tankPop() => %d\n", tankPop(tank));
	usleep(100000);
	printf("me: tankPop() => %d\n", tankPop(tank));
	sleep(3);
	printf("me: ...\n");
	sleep(3);
	printf("boss: why have we stopped\n");
	sleep(2);
	printf("boss: tank->stacks[0]->sum => %d\n", tank->stacks[0]->sum);
	sleep(2);
	printf("boss: omfg...\n");
	sleep(3);
	printf("boss: ur fuckin fired\n");

	return (0);

}



// Function used for the test
// Don't go further :)
