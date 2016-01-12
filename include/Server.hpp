#ifndef SERVER_HPP
#define SERVER_HPP

#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

class Server {
public:
  Server();
  void run();
private:
  Poco::Net::HTTPServer httpServer_;
};

class HandlerFactory : public Poco::Net::HTTPRequestHandlerFactory {
public:
  virtual Poco::Net::HTTPRequestHandler * createRequestHandler(const Poco::Net::HTTPServerRequest & request);
};

class WebcamHandler : public Poco::Net::HTTPRequestHandler {
  virtual void handleRequest(Poco::Net::HTTPServerRequest & request, Poco::Net::HTTPServerResponse & response); 
};
  
#endif //SERVER_HPP
