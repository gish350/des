#pragma once

int* make_ip(int initial_64[]);
int* make_pc1(int ip_64[]);
void split_block(int pc1[], int treshold, int* outH, int* outL);