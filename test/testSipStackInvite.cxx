#include "sip2/sipstack/SipStack.hxx"
#include "sip2/sipstack/Transport.hxx"
#include "sip2/sipstack/Uri.hxx"
#include "sip2/util/Logger.hxx"

#include "sip2/sipstack/Helper.hxx"
#include "sip2/util/DataStream.hxx"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


using namespace Vocal2;
using namespace std;

#define VOCAL_SUBSYSTEM Subsystem::APP
#define CRLF "\r\n"

char *registerMessage = 
"REGISTER sip:test.com SIP/2.0" CRLF
"Via: SIP/2.0/UDP client.test.com:5060;branch=z9hG4bK-kcD23" CRLF
"Max-Forwards: 70" CRLF
"From: Me <sip:user@test.com>;tag=62e0154b" CRLF
"To: You <sip:you@other.com>" CRLF
"Call-ID: b7e6fb02f0e8413d" CRLF
"CSeq: 1 REGISTER" CRLF
"Contact: <sip:me@123.123.123.123>" CRLF
"Content-Length: 0" CRLF CRLF;

int
main(int argc, char *argv[])
{
    Log::initialize(Log::COUT, Log::DEBUG, argv[0]);

    InfoLog( << "Starting up, making stack");

    SipStack *theStack = new SipStack();
    theStack->addTransport(Transport::UDP, 5060);

    int fd = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

    // create address to send to
    struct sockaddr_in sa;

    sa.sin_family = PF_INET;
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    sa.sin_port = htons(5060);

    DebugLog(<<"size="<<strlen(registerMessage) << endl << "message= " << endl << registerMessage );
    
    // send the test message to the stack
    int err = sendto(fd, registerMessage, strlen(registerMessage), 0, (struct sockaddr*) & sa, sizeof(sa));

    DebugLog(<<"errno="<<errno);
    
    assert (err == strlen(registerMessage));


    int count=0;
    while (1)
    {
       FdSet fdReadSet;
       
       theStack->buildFdSet(fdReadSet);
       
       fdReadSet.select(1000);
       
       theStack->process(fdReadSet);
       SipMessage* sipMessage = theStack->receive();
            
       if (sipMessage) 
       {
          count++;
          assert (count == 1);
          
          // InfoLog( << "got message " << *sipMessage);
          cout << "to header is " << sipMessage->header(h_To) << endl;
          cout << "to user is " << sipMessage->header(h_To).uri().user() << endl;
          cout << "cseq sequence is " << sipMessage->header(h_CSeq).sequence() << endl;
          cout << "cseq method is " << sipMessage->header(h_CSeq).method() << endl;
          cout << "contact header is " << sipMessage->header(h_Contacts).front() << endl;
          cout << "contact uri " << sipMessage->header(h_Contacts).front().uri().user() << endl;
          cout << "request line " << sipMessage->header(h_RequestLine) << endl;
          cout << "request line uri user" << sipMessage->header(h_RequestLine).uri().user() << endl;
       }

       theStack->process(fdReadSet);
       usleep(20);
    }

    return 0;

}
