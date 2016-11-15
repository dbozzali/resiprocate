#if !defined(RESIP_HEPSIPMESSAGELOGGINGHANDLER_HXX)
#define RESIP_HEPSIPMESSAGELOGGINGHANDLER_HXX

#include "resip/stack/SipMessage.hxx"
#include "resip/stack/Transport.hxx"
#include "resip/stack/Tuple.hxx"
#include "rutil/Data.hxx"
#include "rutil/Socket.hxx"
#include "rutil/hep/HepAgent.hxx"

namespace resip
{

class HEPSipMessageLoggingHandler : public Transport::SipMessageLoggingHandler
{
   public:
<<<<<<< HEAD
      HEPSipMessageLoggingHandler(SharedPtr<HepAgent> agent);
=======
      HEPSipMessageLoggingHandler(const Data &captureHost, int capturePort, int captureAgentID);
>>>>>>> Added HOMER SIP capture support for Windows
      virtual ~HEPSipMessageLoggingHandler();
      virtual void outboundMessage(const Tuple &source, const Tuple &destination, const SipMessage &msg);
      virtual void outboundRetransmit(const Tuple &source, const Tuple &destination, const SendData &data);
      virtual void inboundMessage(const Tuple& source, const Tuple& destination, const SipMessage &msg);
   protected:
      virtual void sendToHOMER(const Tuple& source, const Tuple& destination, const SipMessage &msg);
   private:
      SharedPtr<HepAgent> mHepAgent;
};


}

#endif


/* ====================================================================
 *
 * Copyright 2016 Daniel Pocock http://danielpocock.com  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. Neither the name of the author(s) nor the names of any contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR(S) OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * ====================================================================
 *
 *
 */
