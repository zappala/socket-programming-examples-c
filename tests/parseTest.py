import optparse
import socket
import sys

class Tester:
    def __init__(self):
        self.server = None
        self.cache = ''
        self.messages = {}
        self.size = 1024
        self.parse_options()
        self.run()

    def parse_options(self):
        parser = optparse.OptionParser(usage = "%prog [options]",
                                       version = "%prog 0.1")

        parser.add_option("-p","--port",type="int",dest="port",
                          default=3000,
                          help="port to connect to")

        parser.add_option("-s","--server",type="string",dest="host",
                          default='localhost',
                          help="server to connect to")

        (options,args) = parser.parse_args()
        self.host = options.host
        self.port = options.port

    def open_socket(self):
        """ Setup the socket for the server """
        try:
            self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR,1)
            self.server.connect((self.host,self.port))
        except socket.error, (value,message):
            print "Could not open socket: " + message
            sys.exit(1)

    def close_socket(self):
        self.server.close()

    def run(self):
        self.testProtocol()

    def testProtocol(self):
        self.open_socket()
        file = open('test-messages.txt')
        for line in file.readlines():
            self.server.sendall(line)
        self.close_socket()


if __name__ == '__main__':
    s = Tester()
