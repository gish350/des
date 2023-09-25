#pragma once

int* make_ip(int initial_64[]);
int* make_pc1(int ip_64[]);
void split_pc1(int pc1[], int* outH, int* outL);