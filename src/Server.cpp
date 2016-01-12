#include <Server.hpp>
#include <Poco/Thread.h>
#include <Poco/Net/HTTPServerParams.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Glob.h>

#include <fstream>
#include <iostream>
#include <unistd.h>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

using namespace Poco::Net;

namespace {
  const std::string PATH="/mnt/ramdisk/webcam/*.jpg";
}

Server::Server() : httpServer_(new HandlerFactory(), ServerSocket(8000), new HTTPServerParams()){}

void Server::run() {
  httpServer_.start();
  for(;;) {
    pause();
  }
}

HTTPRequestHandler * HandlerFactory::createRequestHandler(const HTTPServerRequest & request) {
  return new WebcamHandler();
}

void WebcamHandler::handleRequest(HTTPServerRequest & request, HTTPServerResponse & response) {
  std::set<std::string> files;
  Poco::Glob::glob(PATH, files);
  std::ostream& ostr = response.send();
  if(files.size() == 0) {
    ostr << "No files found" << std::endl;
  } else {
    std::ifstream fin(*files.rbegin());
    std::copy(std::istreambuf_iterator<char>(fin),
	      std::istreambuf_iterator<char>(),
	      std::ostreambuf_iterator<char>(ostr));
  }
}

