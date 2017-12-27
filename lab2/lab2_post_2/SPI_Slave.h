/**
_filename: SPI_Slave.h
_description: Declaration file for a SPI slave class.
//=====================================================================
// ------------------------------------ SPI Slave Class Declaration --------------------------------------------------
// ____________________________________________________________________________
// xxxx This class defines a general layout for slave devices connected to the 
// xxxx master. Use this class a parent class for specific slave devices with which
// xxxx you communicate via SPI
//=====================================================================
@author Dylan DeSantis
@version 1.0.0
*/
#ifndef SPI_SLAVE_H
#define SPI_SLAVE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <chrono>
#include <ctime>
#include <sys/stat.h>
#include <linux/spi/spidev.h>
#include <sys/ioctl.h>
#include <deque>

//=====================================================================
// ------------------------------------ General Masks and File Paths --------------------------------------------------
//=====================================================================	
#define SPI0_CS0 "/dev/spidev0.0"	
#define SPI0_CS1 "/dev/spidev0.1"

typedef enum{
	SYNC = 0,
	SEQ = 1
	} xferTiming;

class SPI_Slave
{
private:
	int spi_fd; //file descriptor for the open spi driver 
	int spi_mode;// the mode of sampling and toggling the data lines
	int spi_cs_delay;//the delay needed for toggling the CS line for signaling a new transfer
	int spi_max_speed; //max transfer speed in Hz
public:
//=====================================================================
// --------------------------------------MEM: Buffers to Read/Write  --------------------------------------------------
//=====================================================================
	std::deque<unsigned char>  stream_in;//used to receive and hold data of any length
	std::deque<unsigned char> stream_out;// used to send  and hold data of any length
	std::deque<int> transmit_len; // double ended queue of each of the transmitted messages
	std::deque<int> receive_len;// double eneded queue of each of the received messages
//=====================================================================
// -------------------------------------- METH: Open/closing and utilities -------------------------------------------
//=====================================================================
	int spiBegin(); 
	int spiEnd();
	void spiDelay(int);// delay in millisecond
	void spiPutBlkCmds(unsigned char*, unsigned char *, unsigned char*,  int, int);
	void spiClearQueues(); //clear the deques 
//=====================================================================
// -------------------------------------- METH: Read/ Write  ----------------------------------------------------------------
//=====================================================================
	void spiTransfer( int , int, xferTiming ); 
//=====================================================================
// -------------------------------------- METH: Constructor/ Destructor----------------------------------------------
//=====================================================================
	SPI_Slave(int fd, int mode, int cs_delay, int max_speed):
		spi_fd(fd),
		spi_mode(mode),
		spi_cs_delay(cs_delay),
		spi_max_speed(max_speed)
	{
		
	}
	~SPI_Slave()
	{
	
	}	
};
#endif



