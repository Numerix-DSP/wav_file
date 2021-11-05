// test_wav.c
// Copyright (C) 2020 Sigma Numerix Ltd. All rights reserved.

// Include files
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "wav_file.h"

// Define constants
#define IO_LENGTH           5
#define SAMPLE_LENGTH       10

// Declare global variables and arrays
double          inputData[SAMPLE_LENGTH];           // Data array pointers
double          srcData[SAMPLE_LENGTH] = {10., 11., 12., 13., 14., 15., 16., 17., 18., 19.};
WAV_FILE_INFO   WavInfo;

int main (void)

{
    int     sampleCount;
    FILE    *fpInputFile, *fpOutputFile;

    WavInfo.SampleRate = 8000;                      // .wav file parameters
    WavInfo.NumberOfSamples = SAMPLE_LENGTH;
    WavInfo.NumberOfChannels = 1;
    WavInfo.WordLength = 16;
    WavInfo.BytesPerSample = 2;
    WavInfo.DataFormat = 1;

    printf ("Opening and writing to test_file.wav file\n");

    if ((fpOutputFile = fopen ("test_file.wav", "wb")) == NULL) {   // Note this file is binary
        printf ("Error opening output .wav file\n");
        exit (1);
    }

    wav_write_header (fpOutputFile, WavInfo);                   // Write header - must be done ahead of writing data
    wav_write_data (srcData, fpOutputFile, WavInfo, IO_LENGTH); // Write successive blocks of data
    wav_write_data (srcData+IO_LENGTH, fpOutputFile, WavInfo, IO_LENGTH);
    wav_write_header (fpOutputFile, WavInfo);                   // Write header - done at the end to update the number of samples written
    fclose (fpOutputFile);

    printf ("Opening and reading from test_file.wav file\n");

    if ((fpInputFile = fopen ("test_file.wav", "rb")) == NULL) {    // Note this file is binary
        printf ("Error opening input .WAV file\n");
        exit (1);
    }

    WavInfo = wav_read_header (fpInputFile);
    if (WavInfo.NumberOfChannels == 0) {                        // Check how many channels
        printf ("Error reading .wav file header\n");
        exit (1);
    }

    wav_display_info (WavInfo);

    while ((sampleCount = (int)wav_read_data (inputData, fpInputFile, WavInfo, IO_LENGTH)) == IO_LENGTH) {
        for (int i = 0; i < sampleCount; i++)
            printf ("%lf, ", inputData[i]);
    }

    fclose (fpInputFile);
    printf ("\n\n");

    return (0);
}

