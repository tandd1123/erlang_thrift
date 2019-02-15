// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "ExampleService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <iostream>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::example;

class ExampleServiceHandler : virtual public ExampleServiceIf {
 public:
  ExampleServiceHandler() {
    // Your initialization goes here
  }

  void hello(Message& _return, const Message& m) {
    // Your implementation goes here
    printf("hello dear msg : %d %s\n", m.id, m.text.c_str());
    _return.id = m.id + 1;
    _return.text = "reply from ts : " + m.text;
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<ExampleServiceHandler> handler(new ExampleServiceHandler());
  shared_ptr<TProcessor> processor(new ExampleServiceProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  std::cout<<"Hello I am workding in " << port<<std::endl;
  
  server.serve();
  return 0;
}
