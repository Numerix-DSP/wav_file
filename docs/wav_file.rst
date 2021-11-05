# .wav File Library

This is a header-only C/C++ library to read and write .wav files.

## Usage

To use this library::

    #include "wav_file.h"


## Introduction

The following functions are used to read and write .wav files. These functions require a
structure of type WAV_FILE_INFO, which is defined as :

typedef struct
{
	int	SampleRate;
	int	NumberOfSamples;
	int	NumberOfChannels;
	int	WordLength;
	int	BytesPerSample;
	int	DataFormat;
} WAV_FILE_INFO;


This structure can be accessed directly from any program however functions are supplied for
reading and writing to it.

Note : when writing a stream to a .wav file it is first necessary to write the header using the
function wav_write_header () then the data can be written to the file. Once all of the data has
been written and the exact number of samples is known then the number of samples can be
re-written to the header and the function wav_write_header should be called again.

For multi-channel wav files, the data is returned with the channels multiplexed into a single
array so the array length must equal the NumberOfSamples*NumberOfChannels. The SigLib DSP library
includes functions for multiplexing and de-multiplexing data streams.


### wav_read_data

FUNCTION NAME
		wav_read_data


FUNCTION PROTOTYPE AND PARAMETER DESCRIPTION

int wav_read_data (double *,			Destination data pointer
	FILE *,				File pointer
	const WAV_FILE_INFO,		Wave file information structure
	const int) 				Array length


FUNCTION DESCRIPTION

The wav_read_data function reads a array of wave file data from the disk.


NOTES ON USE

This function operates in a stream oriented mode and will read successive blocks of data from the
file until the end of the file is reached.

This function will zero pad any arrays if there is not sufficient data in the remainder of the
file to fill the array.

The function returns the number of samples read from the file.

The file must be opened prior to using this function.

Returns WavInfo.NumberOfSamples = 0 on error.


FUNCTION CROSS REFERENCE

	wav_write_data, wav_read_word, wav_read_long, wav_write_word, wav_write_long,
wav_read_header, wav_write_header, wav_display_info, wav_set_info, wav_file_length,
wav_read_file, wav_write_file, wav_write_file_scaled.

### wav_write_data

FUNCTION NAME
		wav_write_data


FUNCTION PROTOTYPE AND PARAMETER DESCRIPTION

void wav_write_data (const double *,	Source data pointer
	FILE *,				File pointer
	const WAV_FILE_INFO,		Wave file information structure
	const int)				Array length


FUNCTION DESCRIPTION

The wav_write_data function writes a array of wave file data to the disk.


NOTES ON USE

This function operates in a stream oriented mode and will append successive blocks of to the end
of the file.

The file must be opened prior to using this function.


FUNCTION CROSS REFERENCE

	wav_read_data, wav_read_word, wav_read_long, wav_write_word, wav_write_long, wav_read_header,
wav_write_header, wav_display_info, wav_set_info, wav_file_length, wav_read_file,
wav_write_file, wav_write_file_scaled.

### wav_read_word

FUNCTION NAME
		wav_read_word


FUNCTION PROTOTYPE AND PARAMETER DESCRIPTION

int wav_read_word (FILE *)			File pointer


FUNCTION DESCRIPTION

The wav_read_word function reads a word of data from a wave file.

The file must be opened prior to using this function.


NOTES ON USE

The function returns the word read from the file.


FUNCTION CROSS REFERENCE

	wav_read_data, wav_write_data, wav_read_long, wav_write_word, wav_write_long,
wav_read_header, wav_write_header, wav_display_info, wav_set_info, wav_file_length,
wav_read_file, wav_write_file, wav_write_file_scaled.

### wav_read_long

FUNCTION NAME
		wav_read_long


FUNCTION PROTOTYPE AND PARAMETER DESCRIPTION

int wav_read_long (FILE *)			File pointer


FUNCTION DESCRIPTION

The wav_read_long function reads an int word of data from a wave file.


NOTES ON USE

The function returns the int word read from the file.

The file must be opened prior to using this function.


FUNCTION CROSS REFERENCE

	wav_read_data, wav_write_data, wav_read_word, wav_write_word, wav_write_long,
wav_read_header, wav_write_header, wav_display_info, wav_set_info, wav_file_length,
wav_read_file, wav_write_file, wav_write_file_scaled.

### wav_write_word

FUNCTION NAME
		wav_write_word


FUNCTION PROTOTYPE AND PARAMETER DESCRIPTION

void wav_write_word (const int,		Data word to write
	FILE *)				File pointer


FUNCTION DESCRIPTION

The wav_write_word function writes a word of data to the disk.


NOTES ON USE

The file must be opened prior to using this function.


FUNCTION CROSS REFERENCE

	wav_read_data, wav_write_data, wav_read_word, wav_read_long, wav_write_long, wav_read_header,
wav_write_header, wav_display_info, wav_set_info, wav_file_length, wav_read_file,
wav_write_file, wav_write_file_scaled.

### wav_write_long

FUNCTION NAME
		wav_write_long


FUNCTION PROTOTYPE AND PARAMETER DESCRIPTION

void wav_write_long (const int,		Long data word to write
	FILE *)				File pointer


FUNCTION DESCRIPTION

The wav_write_long function writes a int word of data to the disk.


NOTES ON USE

The file must be opened prior to using this function.


FUNCTION CROSS REFERENCE

	wav_read_data, wav_write_data, wav_read_word, wav_read_long, wav_write_word, wav_read_header,
wav_write_header, wav_display_info, wav_set_info, wav_file_length, wav_read_file,
wav_write_file, wav_write_file_scaled.

### wav_read_header

FUNCTION NAME
		wav_read_header


FUNCTION PROTOTYPE AND PARAMETER DESCRIPTION

WAV_FILE_INFO wav_read_header (FILE *)	File pointer


FUNCTION DESCRIPTION

The wav_read_header function reads the header information from a wave file and returns it in the
WAV_FILE_INFO structure.


NOTES ON USE

The file must be opened prior to using this function.

Returns WavInfo.NumberOfSamples = 0 on error.


FUNCTION CROSS REFERENCE

	wav_read_data, wav_write_data, wav_read_word, wav_read_long, wav_write_word, wav_write_long,
wav_write_header, wav_display_info, wav_set_info, wav_file_length, wav_read_file,
wav_write_file, wav_write_file_scaled.

### wav_write_header

FUNCTION NAME
		wav_write_header


FUNCTION PROTOTYPE AND PARAMETER DESCRIPTION

void wav_write_header (FILE *,		File pointer
const WAV_FILE_INFO)			Wave file information structure


FUNCTION DESCRIPTION

The wav_write_header function writes the header information to a wave file from the WAV_FILE_INFO
structure.


NOTES ON USE

The file must be opened prior to using this function.


FUNCTION CROSS REFERENCE

	wav_read_data, wav_write_data, wav_read_word, wav_read_long, wav_write_word, wav_write_long,
wav_read_header, wav_display_info, wav_set_info, wav_file_length, wav_read_file,
wav_write_file, wav_write_file_scaled.

### wav_display_info

FUNCTION NAME
		wav_display_info


FUNCTION PROTOTYPE AND PARAMETER DESCRIPTION

void wav_display_info (const WAV_FILE_INFO)  Wave file information structure


FUNCTION DESCRIPTION

The wav_display_info function prints out the header information stored in the WAV_FILE_INFO
structure.


NOTES ON USE


FUNCTION CROSS REFERENCE

	wav_read_data, wav_write_data, wav_read_word, wav_read_long, wav_write_word, wav_write_long,
wav_read_header, wav_write_header, wav_set_info, wav_file_length, wav_read_file,
wav_write_file, wav_write_file_scaled.

### wav_set_info

FUNCTION NAME
		wav_set_info


FUNCTION PROTOTYPE AND PARAMETER DESCRIPTION

WAV_FILE_INFO wav_set_info (const int,	Sample rate
	const int,				Number of samples
	const int,				Number of channels
	const int,				Word length
	const int,				Bytes per sample
	const int)				Data format


FUNCTION DESCRIPTION

The wav_set_info function generates a WAV_FILE_INFO structure from the supplied data.


NOTES ON USE


FUNCTION CROSS REFERENCE

	wav_read_data, wav_write_data, wav_read_word, wav_read_long, wav_write_word, wav_write_long,
wav_read_header, wav_write_header, wav_display_info, wav_file_length, wav_read_file,
wav_write_file, wav_write_file_scaled.


### wav_file_length

FUNCTION NAME
		wav_file_length


FUNCTION PROTOTYPE AND PARAMETER DESCRIPTION

int wav_file_length (const char *) 		Filename


FUNCTION DESCRIPTION

This function returns the number of samples in the .wav file.


NOTES ON USE



FUNCTION CROSS REFERENCE

	wav_write_data, wav_read_word, wav_read_long, wav_write_word, wav_write_long,
wav_read_header, wav_write_header, wav_display_info, wav_set_info, wav_file_length,
wav_read_file, wav_write_file, wav_write_file_scaled

### wav_read_file

FUNCTION NAME
		wav_read_file


FUNCTION PROTOTYPE AND PARAMETER DESCRIPTION

WAV_FILE_INFO wav_read_data (double *,	Destination data pointer
	const char *) 				Filename


FUNCTION DESCRIPTION

This function reads the contents of the .wav file data from the disk.


NOTES ON USE

It is important to ensure that the destination array is long enough to receive the data.

Returns the WAV_FILE_INFO structure for the data read, with the number of samples read set to -1
on file read error.


FUNCTION CROSS REFERENCE

	wav_write_data, wav_read_word, wav_read_long, wav_write_word, wav_write_long,
wav_read_header, wav_write_header, wav_display_info, wav_set_info, wav_file_length,
wav_read_file, wav_write_file, wav_write_file_scaled.


### wav_write_file

FUNCTION NAME
		wav_write_file


FUNCTION PROTOTYPE AND PARAMETER DESCRIPTION

int wav_write_file (double *,			Source data pointer
	const char *, 				Filename
	const WAV_FILE_INFO, 		Wave file information structure
	const int)				Array length


FUNCTION DESCRIPTION

This function writes the contents of the array to the .wav file.


NOTES ON USE

Returns the number of samples written, -1 for file open error.


FUNCTION CROSS REFERENCE

	wav_write_data, wav_read_word, wav_read_long, wav_write_word, wav_write_long,
wav_read_header, wav_write_header, wav_display_info, wav_set_info, wav_file_length,
wav_read_file, wav_write_file, wav_write_file_scaled.


### wav_write_file_scaled

FUNCTION NAME
		wav_write_file_scaled


FUNCTION PROTOTYPE AND PARAMETER DESCRIPTION

int wav_write_file_scaled (double *,			Destination data pointer
	const char *, 				Filename
	const WAV_FILE_INFO, 		Wave file information structure
	const int)				Array length


FUNCTION DESCRIPTION

This function writes the contents of the array to the .wav file. The output is scaled to a
magnitude of 32767.0


NOTES ON USE

Returns the number of samples written, -1 for file open error.


FUNCTION CROSS REFERENCE

	wav_write_data, wav_read_word, wav_read_long, wav_write_word, wav_write_long,
wav_read_header, wav_write_header, wav_display_info, wav_set_info, wav_file_length,
wav_read_file, wav_write_file, wav_write_file_scaled.


Copyright (C) 2000 to 2021 Sigma Numerix Ltd. All rights reserved.

