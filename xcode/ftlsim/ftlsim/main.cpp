//
//  main.cpp
//  ftlsim
//
//  Created by ansonn.wang on 8/24/17.
//  Copyright © 2017 Ansonn. All rights reserved.
//
#include "ssd.h"

#define SIZE 130

using namespace ssd;

int main()
{
    load_config();
    print_config(NULL);
    //printf("Press ENTER to continue...");
    //getchar();
    printf("\n");
    
    Ssd *ssd = new Ssd();
    
    double result;
    
    //	// Test one write to some blocks.
    //	for (int i = 0; i < SIZE; i++)
    //	{
    //		/* event_arrive(event_type, logical_address, size, start_time) */
    //		result = ssd -> event_arrive(WRITE, i*100000, 1, (double) 1+(250*i));
    //
    //		printf("Write time: %.20lf\n", result);
    ////		result = ssd -> event_arrive(WRITE, i+10240, 1, (double) 1);
    ////
    //	}
    //	for (int i = 0; i < SIZE; i++)
    //	{
    //		/* event_arrive(event_type, logical_address, size, start_time) */
    //		result = ssd -> event_arrive(READ, i*100000, 1, (double) 1+(500*i));
    //		printf("Read time : %.20lf\n", result);
    ////		result = ssd -> event_arrive(READ, i, 1, (double) 1);
    ////		printf("Read time : %.20lf\n", result);
    //	}
    
    //	// Test writes and read to same block.
    //	for (int i = 0; i < SIZE; i++)
    //	{
    //		result = ssd -> event_arrive(WRITE, i%64, 1, (double) 1+(250*i));
    //
    //		printf("Write time: %.20lf\n", result);
    //	}
    //	for (int i = 0; i < SIZE; i++)
    //	{
    //		result = ssd -> event_arrive(READ, i%64, 1, (double) 1+(500*i));
    //		printf("Read time : %.20lf\n", result);
    //	}
    
    // Test random writes to a block
    result = ssd -> event_arrive(WRITE, 5, 1, (double) 0.0);
    printf("Write time: %.20lf\n", result);
    result = ssd -> event_arrive(WRITE, 4, 1, (double) 300.0);
    printf("Write time: %.20lf\n", result);
    result = ssd -> event_arrive(WRITE, 3, 1, (double) 600.0);
    printf("Write time: %.20lf\n", result);
    result = ssd -> event_arrive(WRITE, 2, 1, (double) 900.0);
    printf("Write time: %.20lf\n", result);
    result = ssd -> event_arrive(WRITE, 1, 1, (double) 1200.0);
    printf("Write time: %.20lf\n", result);
    result = ssd -> event_arrive(WRITE, 0, 1, (double) 1500.0);
    printf("Write time: %.20lf\n", result);
    
    for (int i = 0; i < SIZE-6; i++)
    {
        /* event_arrive(event_type, logical_address, size, start_time) */
        result = ssd -> event_arrive(WRITE, 6+i, 1, (double) 1800+(300*i));
        printf("Write time: %.20lf\n", result);
    }
    
    // Force Merge
    result = ssd -> event_arrive(WRITE, 10 , 1, (double) 0.0);
    printf("Write time: %.20lf\n", result);
    //	for (int i = 0; i < SIZE; i++)
    //	{
    //		/* event_arrive(event_type, logical_address, size, start_time) */
    //		result = ssd -> event_arrive(READ, i%64, 1, (double) 1+(500*i));
    //		printf("Read time : %.20lf\n", result);
    //	}
    
    delete ssd;
    return 0;
}
