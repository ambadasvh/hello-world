//Author: Ambadas Hibare
//Compilation: g++ -o IPv4_Test IPv4_Test.cpp -Wall -Werror

///////////////////////////////////////////
// includes
///////////////////////////////////////////
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>

///////////////////////////////////////////
// defines
///////////////////////////////////////////
/*
#define u_8  unsigned char
#define u_16 unsigned short
#define u_32 unsigned int
#define s_8  char				
#define s_16 short				
#define s_32 int					
*/
///*
typedef unsigned char	u_8;
typedef unsigned short	u_16;
typedef unsigned int	u_32;
typedef char			s_8;
typedef short			s_16;
typedef int				s_32;
//*/

///////////////////////////////////////////
// foward declarations
///////////////////////////////////////////
s_32 ip2dec(u_32 *aDec, s_8 *aIp);
s_32 dec2ip(u_32 *aDec, s_8 *aIp);
u_32 parseIPV4string(char const * ipAddress);
u_32 h2nl(u_32 aH);
u_32 n2hl(u_32 aH);


///////////////////////////////////////////
// main
///////////////////////////////////////////
int main(int argc, char *argv[])
{
	if(argc != 2) {
		std::cout << "Usage:\n" << argv[0] << " <IP_Addr>\n\n";
		exit(0);
	}

	u_32 dec=0, h=0, n=0;
	struct in_addr addr;
	
	ip2dec(&dec, argv[1]);
	printf("TESTING: ip=%s \t parseIPV4string(ip)=%u \t ip2dec(ip)=%u\n", argv[1], parseIPV4string(argv[1]), dec);
	
	inet_pton(AF_INET, argv[1], (void*)&addr);
	printf("TESTING: inet_pton(%s) = %u\n", argv[1], addr.s_addr);
	
	h = dec;
	printf("TESTING: h=%x \t htonl(h)=%x \t h2nl(h)=%x \n", h, htonl(h), h2nl(h));
	
	n = htonl(h);
	printf("TESTING: n=%x \t ntohl(n)=%x \t n2hl(n)=%x \n", n, ntohl(n), n2hl(n));
	
	//puts("\n");
	return 0;
}

s_32 ip2dec(u_32 *aDec, s_8 *aIp)
{
	if(aIp == NULL) {
		printf("Error ip2dec: aIp is NULL\n");
		return -1;
	}

	char ip[16]={0};
	memcpy(&ip, aIp, 15);
	
	/* //Non-Efficient method:
	unsigned char octets[4]={0};
	char *tok=NULL, *saveptr1;
	tok = strtok_r(ip, ".", &saveptr1);
	if(tok != NULL)
		octets[0] = (unsigned char) atoi(tok);

	for(int i=1; (tok!=NULL && i<4); ++i)
	{
		tok = strtok_r(NULL, ".", &saveptr1);
		octets[i] = (unsigned char) atoi(tok);
	} */

	unsigned int octets[4]={0};
	sscanf(ip, "%u.%u.%u.%u", &octets[0], &octets[1], &octets[2], &octets[3]);

	/* for(int i=0; i<4; ++i)
		printf("TESTING: octets[%d] = %u\n", i, octets[i]); */

	*aDec = ((octets[0] << 24) | (octets[1] << 16) | (octets[2] << 8) | (octets[3] << 0));
	
	return 0;
}

s_32 dec2ip(u_32 *aDec, s_8 *aIp)
{
	//TODO
	return 0;
}

u_32 h2nl(unsigned int aH)
{
	u_32 n=0;
	
	/* //Non-Efficient method:
	u_32 a=0, b=0, c=0, d=0;
	u_32 q=0, w=0, e=0, r=0;
	a = (aH & 0xff);
	b = (aH & 0xff00);
	c = (aH & 0xff0000);
	d = (aH & 0xff000000);
	
	q = (a << 24);
	w = (b << 8);
	e = (c >> 8);
	r = (d >> 24);
	
	printf("TESTING: a=%u \t b=%u \t c=%u \t d=%u \n", a, b, c, d);
	printf("TESTING: a=%x \t b=%x \t c=%x \t d=%x \n", a, b, c, d);
	printf("TESTING: q=%x \t w=%x \t e=%x \t r=%x \n\n", q, w, e, r);
	
	n = q|w|e|r; */

	u_8* c = (u_8*)&aH;
	
	printf("TESTING: (DEC) \t a=%u \t b=%u \t c=%u \t d=%u \n", c[0], c[1], c[2], c[3]);
	printf("TESTING: (HEX) \t a=%x \t b=%x \t c=%x \t d=%x \n", c[0], c[1], c[2], c[3]);
	
	return n = ((c[0] << 24) | (c[1] << 16) | (c[2] << 8) | c[3]);
}

u_32 n2hl(unsigned int aN)
{
	u_32 h=0;
	u_8 *c = (u_8*)&aN;
	
	printf("TESTING: (DEC) \t a=%u \t b=%u \t c=%u \t d=%u \n", c[0], c[1], c[2], c[3]);
	printf("TESTING: (HEX) \t a=%x \t b=%x \t c=%x \t d=%x \n", c[0], c[1], c[2], c[3]);

	return h = ((c[0] << 24) | (c[1] << 16) | (c[2] << 8) | c[3]);
}

unsigned int parseIPV4string(char const * ipAddress)
{
	unsigned int ip[4];

	if ( 4 != sscanf(ipAddress, "%u.%u.%u.%u", &ip[0], &ip[1], &ip[2], &ip[3]) )
		return 0;   // or some other indicator or error

	return ip[3] + ip[2] * 0x100 + ip[1] * 0x10000ul + ip[0] * 0x1000000ul;
}

//eof
